from django.db import models

class Vote(models.Model):
    OPTION_CHOICES = [
        ('good', 'Good'),
        ('satisfactory', 'Satisfactory'),
        ('bad', 'Bad'),
    ]
    choice = models.CharField(max_length=20, choices=OPTION_CHOICES, default='good')  # Set default value
