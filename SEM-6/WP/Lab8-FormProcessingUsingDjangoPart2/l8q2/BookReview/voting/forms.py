from django import forms
from .models import Vote

class VoteForm(forms.ModelForm):
    class Meta:
        model = Vote
        fields = ['choice']
        widgets = {
            'choice': forms.RadioSelect
        }

    def __init__(self, *args, **kwargs):
        super(VoteForm, self).__init__(*args, **kwargs)
        # Manually set choices to remove the empty default option
        self.fields['choice'].choices = [
            ('good', 'Good'),
            ('satisfactory', 'Satisfactory'),
            ('bad', 'Bad')
        ]
