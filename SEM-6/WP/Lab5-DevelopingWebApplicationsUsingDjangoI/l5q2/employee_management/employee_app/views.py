from django.shortcuts import render
from .forms import PromotionForm

def promotion_view(request):
    form = PromotionForm()
    result = None

    if request.method == "POST":
        form = PromotionForm(request.POST)
        if form.is_valid():
            result = form.check_promotion_eligibility()

    return render(request, 'employee_app/promotion.html', {'form': form, 'result': result})
