from django import forms
from .models import Student

class StudentForm(forms.ModelForm):
    date_of_birth = forms.DateTimeField(
        widget=forms.DateTimeInput(attrs={'type': 'datetime-local'}),  # HTML5 DateTime Picker
        label="Date of Birth"
    )

    class Meta:
        model = Student
        fields = ['student_id', 'student_name', 'course_name', 'date_of_birth']
