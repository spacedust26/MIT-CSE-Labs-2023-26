from django import forms

class ArithmeticForm(forms.Form):
    OPERATION_CHOICES = [
        ('add', 'Add'),
        ('subtract', 'Subtract'),
        ('multiply', 'Multiply'),
        ('divide', 'Divide'),
    ]

    num1 = forms.IntegerField(label="First Number")
    num2 = forms.IntegerField(label="Second Number")
    operation = forms.ChoiceField(choices=OPERATION_CHOICES, label="Operation")