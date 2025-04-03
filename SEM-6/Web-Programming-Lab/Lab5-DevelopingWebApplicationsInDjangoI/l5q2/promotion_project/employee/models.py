from django.db import models

class Employee(models.Model):
  emp_id = models.CharField(max_length = 10, unique = True)
  date_of_joining = models.DateTimeField()

  def __str__(self):
    return self.emp_id
