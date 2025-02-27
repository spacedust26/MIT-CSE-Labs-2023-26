from django.shortcuts import render, redirect

# Define prices for Mobile and Laptop
PRICES = {
    "Mobile": 10000,  # Base price
    "Laptop": 50000   # Base price
}

def input_page(request):
    if request.method == "POST":
        brand = request.POST.get("brand")
        items = request.POST.getlist("items")  # Get multiple values
        quantity = int(request.POST.get("quantity", 0))

        # Store data in session
        request.session["brand"] = brand
        request.session["items"] = items
        request.session["quantity"] = quantity

        return redirect("bill_page")  # Redirect to bill page

    return render(request, "billing/input_page.html")

def bill_page(request):
    brand = request.session.get("brand", "Unknown")
    items = request.session.get("items", [])
    quantity = request.session.get("quantity", 0)

    total_amount = sum(PRICES[item] for item in items) * quantity  # Calculate total price

    return render(request, "billing/bill_page.html", {
        "brand": brand,
        "items": items,
        "quantity": quantity,
        "total_amount": total_amount
    })
