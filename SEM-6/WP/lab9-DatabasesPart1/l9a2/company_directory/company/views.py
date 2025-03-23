# company/views.py
from django.shortcuts import render
from .forms import WorksForm, LivesForm, CompanySearchForm
from .models import Works, Lives

def insert_works_data(request):
    if request.method == 'POST':
        form = WorksForm(request.POST)
        if form.is_valid():
            form.save()
            message = "Work data inserted successfully!"
            return render(request, 'company/insert_works_data.html', {'form': form, 'message': message})
    else:
        form = WorksForm()
    return render(request, 'company/insert_works_data.html', {'form': form})

def insert_lives_data(request):
    if request.method == 'POST':
        form = LivesForm(request.POST)
        if form.is_valid():
            form.save()
            message = "Lives data inserted successfully!"
            return render(request, 'company/insert_lives_data.html', {'form': form, 'message': message})
    else:
        form = LivesForm()
    return render(request, 'company/insert_lives_data.html', {'form': form})

def search_company(request):
    if request.method == 'POST':
        form = CompanySearchForm(request.POST)
        if form.is_valid():
            company_name = form.cleaned_data['company_name']
            works = Works.objects.filter(company_name=company_name)
            people = []
            for work in works:
                person_name = work.person_name
                # Get related city information
                person_lives = Lives.objects.filter(person_name=person_name).first()
                if person_lives:
                    city = person_lives.city
                    people.append({'name': person_name, 'city': city})
                else:
                    people.append({'name': person_name, 'city': 'No city found'})
            return render(request, 'company/search_result.html', {'people': people, 'company_name': company_name})
    else:
        form = CompanySearchForm()
    return render(request, 'company/search_company.html', {'form': form})
