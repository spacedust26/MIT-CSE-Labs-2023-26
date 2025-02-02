from django.shortcuts import render
from django.http import JsonResponse
import random
import string
from io import BytesIO
from PIL import Image, ImageDraw, ImageFont
import base64

# Store the failed attempts count
attempts = 0

# Generate a random CAPTCHA text
def generate_captcha_text(length=5):
    return ''.join(random.choices(string.ascii_uppercase + string.digits, k=length))

# Create CAPTCHA image
def generate_captcha():
    captcha_text = generate_captcha_text()
    image = Image.new('RGB', (150, 60), color=(255, 255, 255))
    draw = ImageDraw.Draw(image)

    # Load a default font (adjust path if necessary)
    try:
        font = ImageFont.truetype("arial.ttf", 40)  # Change this if you have a custom font
    except IOError:
        font = ImageFont.load_default()

    draw.text((20, 10), captcha_text, font=font, fill=(0, 0, 0))

    # Save image to a bytes buffer
    buffer = BytesIO()
    image.save(buffer, format="PNG")
    image_base64 = base64.b64encode(buffer.getvalue()).decode()

    return captcha_text, f"data:image/png;base64,{image_base64}"

# View to render the form
def captcha_view(request):
    global attempts
    if request.method == "POST":
        user_input = request.POST.get("captcha_input")
        correct_captcha = request.session.get("captcha_text", "")

        if user_input == correct_captcha:
            message = "✅ Correct CAPTCHA! Access Granted."
            attempts = 0  # Reset attempts
        else:
            attempts += 1
            message = f"❌ Incorrect CAPTCHA! Attempt {attempts}/3"

        if attempts >= 3:
            message = "🚫 Too many failed attempts. Try again later."

        # Generate a new CAPTCHA for the next attempt
        new_captcha_text, new_captcha_image = generate_captcha()
        request.session["captcha_text"] = new_captcha_text

        return JsonResponse({
            "message": message,
            "captcha_image": new_captcha_image,
            "disable_input": attempts >= 3
        })

    # Initial CAPTCHA generation
    captcha_text, captcha_image = generate_captcha()
    request.session["captcha_text"] = captcha_text
    attempts = 0  # Reset attempts on refresh

    return render(request, "captcha_app/captcha.html", {"captcha_image": captcha_image})

