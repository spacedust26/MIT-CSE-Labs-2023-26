from django.shortcuts import render
def car_form(request):
  # List of car manufacturers for dropdown list
  manufacturers = ['Toyota', 'Ford', 'BMW', 'Honda', 'Audi']
  if request.method == 'POST':
      manufacturer = request.POST.get('manufacturer')
      model = request.POST.get('model')
      return render(request, 'car/car_result.html', {'manufacturer': manufacturer, 'model': model})
  return render(request, 'car/car_form.html', {'manufacturers': manufacturers})
def car_result(request):
  manufacturer = request.GET.get('manufacturer', '')
  model = request.GET.get('model', '')
  return render(request, 'car/car_result.html', {'manufacturer': manufacturer, 'model': model})