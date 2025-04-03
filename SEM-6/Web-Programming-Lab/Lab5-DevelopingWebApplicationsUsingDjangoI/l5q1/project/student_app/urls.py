from django.urls import path
from .views import student_form_view

urlpatterns = [
    path('', student_form_view, name='student_form'),
]
