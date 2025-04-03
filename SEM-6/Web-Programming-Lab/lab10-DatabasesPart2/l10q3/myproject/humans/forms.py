from django import forms
from .models import Human

class HumanForm(forms.ModelForm):
    class Meta:
        model = Human
        fields = ['first_name', 'last_name', 'phone', 'address', 'city']
