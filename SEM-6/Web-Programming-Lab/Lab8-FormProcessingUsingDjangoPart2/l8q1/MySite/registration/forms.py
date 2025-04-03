from django import forms

class RegisterForm(forms.Form):
    username = forms.CharField(label="Username", max_length=100, required=True)
    password = forms.CharField(label="Password", widget=forms.PasswordInput, required=False)
    email = forms.EmailField(label="Email", required=False)
    contact = forms.CharField(label="Contact Number", required=False)
