from django.shortcuts import render
# Dummy list of grocery items and their prices
grocery_items = [
  {"name": "Apple", "price": 1.5},
  {"name": "Banana", "price": 0.8},
  {"name": "Carrot", "price": 1.2},
  {"name": "Potato", "price": 0.5},
  {"name": "Tomato", "price": 1.0},
]
def grocery_checklist(request):
  if request.method == "POST":
      # Get selected items from the form
      selected_items = request.POST.getlist('items')
      selected_items_data = []
      # Find the corresponding item data
      for item in grocery_items:
          if item['name'] in selected_items:
              selected_items_data.append(item)
      return render(request, 'checklist/grocery_checklist.html', {
          'grocery_items': grocery_items,
          'selected_items': selected_items_data
      })
  return render(request, 'checklist/grocery_checklist.html', {
      'grocery_items': grocery_items,
      'selected_items': []
  })