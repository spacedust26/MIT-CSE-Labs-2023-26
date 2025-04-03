from django.shortcuts import render, redirect
from .models import Student
from .forms import StudentForm

def page1(request):
    if request.method == "POST":
        print("🚀 POST data received:", request.POST)  # Debugging
        form = StudentForm(request.POST)
        if form.is_valid():
            print("✅ Form is valid. Saving data...")
            form.save()
            return redirect('page2')  # Redirect after success
        else:
            print("❌ Form errors:", form.errors)  # Debugging
    else:
        form = StudentForm()  

    return render(request, 'fest/page1.html', {'form': form})  


def page2(request):
    students = Student.objects.all()
    return render(request, 'fest/page2.html', {'students': students}) 
