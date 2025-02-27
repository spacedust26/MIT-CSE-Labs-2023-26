from django.shortcuts import render

def feedback_form(request):
    message = ""
    if request.method == "POST":
        name = request.POST.get("name")
        email = request.POST.get("email")
        course = request.POST.get("course")
        comments = request.POST.get("comments")

        message = f"Thank you {name} for your feedback on {course}!"

    return render(request, "feedback/form.html", {"message": message})
