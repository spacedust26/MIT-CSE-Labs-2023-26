from django.shortcuts import render, redirect

def input_page(request):
    if request.method == "POST":
        name = request.POST.get("name")
        total_marks = request.POST.get("total_marks")

        # Store data in session
        request.session["name"] = name
        request.session["total_marks"] = total_marks

        return redirect("result_page")  # Redirect to result page

    return render(request, "calculator/input_page.html")

def result_page(request):
    # Retrieve data from session
    name = request.session.get("name", "Unknown")
    total_marks = request.session.get("total_marks", 0)

    try:
        cgpa = float(total_marks) / 10  # Calculate CGPA
    except ValueError:
        cgpa = 0

    return render(request, "calculator/result_page.html", {"name": name, "cgpa": cgpa})
