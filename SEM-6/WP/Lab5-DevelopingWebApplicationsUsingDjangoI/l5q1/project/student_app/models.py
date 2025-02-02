from django.db import models

class Student(models.Model):
    name = models.CharField(max_length=100)
    date_of_birth = models.DateField()
    address = models.TextField()
    contact_number = models.CharField(max_length=15)
    email = models.EmailField()
    english_marks = models.FloatField()
    physics_marks = models.FloatField()
    chemistry_marks = models.FloatField()

    def total_percentage(self):
        return (self.english_marks + self.physics_marks + self.chemistry_marks) / 3
