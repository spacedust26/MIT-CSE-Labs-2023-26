from django import forms

class StudentForm(forms.Form):
    name = forms.CharField(widget=forms.TextInput(attrs={'class': 'form-control'}))
    date_of_birth = forms.DateField(widget=forms.DateInput(attrs={'class': 'form-control', 'type': 'date'}))
    address = forms.CharField(widget=forms.Textarea(attrs={'class': 'form-control', 'rows': 3}))
    contact_number = forms.CharField(widget=forms.TextInput(attrs={'class': 'form-control'}))
    email = forms.EmailField(widget=forms.EmailInput(attrs={'class': 'form-control'}))
    english_marks = forms.FloatField(widget=forms.NumberInput(attrs={'class': 'form-control'}))
    physics_marks = forms.FloatField(widget=forms.NumberInput(attrs={'class': 'form-control'}))
    chemistry_marks = forms.FloatField(widget=forms.NumberInput(attrs={'class': 'form-control'}))
