from django.db import models

# Create your models here.
class Student(models.Model):
  gender_choice = [
    ('Male', 'Male'),
    ('Female', 'Female'),
    ('Other', 'Other'),
  ]
  name = models.CharField(max_length=100)
  roll_number = models.CharField(max_length=15, unique=True)
  gender = models.CharField(max_length=10, choices=gender_choice)
  email_address = models.EmailField(unique=True)
  department = models.CharField(max_length=50)

  def __str__(self):
    return self.name