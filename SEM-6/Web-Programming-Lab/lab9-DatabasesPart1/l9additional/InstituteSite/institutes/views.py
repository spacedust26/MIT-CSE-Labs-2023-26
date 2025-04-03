from django.shortcuts import render
from .models import Institute

def institute_list(request):
    institutes = Institute.objects.all()
    return render(request, 'institutes/list.html', {'institutes': institutes})
