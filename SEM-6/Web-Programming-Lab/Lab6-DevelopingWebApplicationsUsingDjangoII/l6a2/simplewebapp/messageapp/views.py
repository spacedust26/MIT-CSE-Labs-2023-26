from django.shortcuts import render
from django.utils.safestring import mark_safe  # Ensures HTML formatting is preserved

def home(request):
    formatted_message = ""
    name = ""
    message = ""

    if request.method == 'POST':
        name = request.POST.get('name')
        message = request.POST.get('message')
        format_options = request.POST.getlist('format')
        color = request.POST.get('color', 'black')  # Default to black

        # Format the message display
        formatted_message = f"Name: {name}<br>Message: {message}"

        # Apply formatting
        if 'bold' in format_options:
            formatted_message = f"<b>{formatted_message}</b>"
        if 'italic' in format_options:
            formatted_message = f"<i>{formatted_message}</i>"
        if 'underline' in format_options:
            formatted_message = f"<u>{formatted_message}</u>"

        # Apply selected text color
        formatted_message = f'<span style="color:{color};">{formatted_message}</span>'

        # Mark as safe to prevent escaping
        formatted_message = mark_safe(formatted_message)

    return render(request, 'home.html', {'formatted_message': formatted_message, 'name': name, 'message': message})
