from django import forms
from datetime import date

EMPLOYEE_IDS = [
    ('E001', 'E001'),
    ('E002', 'E002'),
    ('E003', 'E003'),
    ('E004', 'E004'),
    ('E005', 'E005'),
]

class PromotionForm(forms.Form):
    employee_id = forms.ChoiceField(choices=EMPLOYEE_IDS, widget=forms.Select(attrs={'class': 'form-control'}))
    date_of_joining = forms.DateField(
        widget=forms.DateInput(attrs={'class': 'form-control', 'type': 'date'})
    )

    def check_promotion_eligibility(self):
        joining_date = self.cleaned_data['date_of_joining']
        today = date.today()
        experience = today.year - joining_date.year - ((today.month, today.day) < (joining_date.month, joining_date.day))
        return "YES" if experience >= 5 else "NO"
