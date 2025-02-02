from django.shortcuts import render
from .forms import StudentForm

def student_form_view(request):
    form = StudentForm()
    submitted_data = None
    percentage = None

    if request.method == "POST":
        form = StudentForm(request.POST)
        if form.is_valid():
            submitted_data = form.cleaned_data
            total_marks = (
                submitted_data['english_marks'] + 
                submitted_data['physics_marks'] + 
                submitted_data['chemistry_marks']
            )
            percentage = round((total_marks / 300) * 100, 2)  # Assuming each subject is out of 100

    return render(request, 'student_app/form.html', {
        'form': form,
        'submitted_data': submitted_data,
        'percentage': percentage
    })
