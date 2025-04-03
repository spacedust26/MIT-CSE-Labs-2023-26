# company/admin.py
from django.contrib import admin
from .models import Works, Lives

# Register the Works model
admin.site.register(Works)

# Register the Lives model
admin.site.register(Lives)
