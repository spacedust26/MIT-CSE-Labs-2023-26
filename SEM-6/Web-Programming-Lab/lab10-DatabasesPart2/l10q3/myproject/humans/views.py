from django.shortcuts import render, get_object_or_404
from django.http import JsonResponse
from .models import Human
from .forms import HumanForm

def index(request):
    humans = Human.objects.all()
    return render(request, 'humans/index.html', {'humans': humans})

def get_human_details(request, human_id):
    human = get_object_or_404(Human, id=human_id)
    data = {
        'last_name': human.last_name,
        'phone': human.phone,
        'address': human.address,
        'city': human.city,
    }
    return JsonResponse(data)

def update_human(request, human_id):
    human = get_object_or_404(Human, id=human_id)
    form = HumanForm(request.POST, instance=human)
    if form.is_valid():
        form.save()
        return JsonResponse({'status': 'Updated successfully!'})
    return JsonResponse({'status': 'Failed to update'})

def delete_human(request, human_id):
    human = get_object_or_404(Human, id=human_id)
    human.delete()
    return JsonResponse({'status': 'Deleted successfully!'})
