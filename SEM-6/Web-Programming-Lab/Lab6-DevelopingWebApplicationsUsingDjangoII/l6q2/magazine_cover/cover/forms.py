from django import forms

class CoverForm(forms.Form):
    BACKGROUND_COLORS = [
        ('#FFFFFF', 'White'),
        ('#000000', 'Black'),
        ('#FF0000', 'Red'),
        ('#00FF00', 'Green'),
        ('#0000FF', 'Blue'),
    ]

    FONT_FAMILIES = [
        ('Arial', 'Arial'),
        ('Times New Roman', 'Times New Roman'),
        ('Courier New', 'Courier New'),
        ('Verdana', 'Verdana'),
    ]
    image_choices = [
        ('magazine.jpg', 'Cover 1'),
        ('magazine.jpg', 'Cover 2'),
    ]
    image = forms.ChoiceField(choices=image_choices, label='Select Cover Image')
    background_color = forms.ChoiceField(choices=BACKGROUND_COLORS, label="Background Color")
    font_family = forms.ChoiceField(choices=FONT_FAMILIES, label="Font Family")
    font_size = forms.IntegerField(label="Font Size", min_value=10, max_value=100)
    font_color = forms.CharField(label="Font Color", widget=forms.TextInput(attrs={'type': 'color'}))
    message = forms.CharField(label="Message", widget=forms.Textarea)