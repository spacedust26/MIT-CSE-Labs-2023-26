# Web Programming Lab

[Lab Manual](https://github.com/spacedust26/MIT-CSE-Labs-2023-26/blob/main/SEM-6/WP/WP-LabManual.pdf)

### Creating a Virtual Environment
- Linux

```
sudo apt-get install python3-venv  
python3 -m venv .venv
source .venv/bin/activate
```

- macOS
```
python3 -m venv .venv
source .venv/bin/activate
```

- Windows
```
py -3 -m venv .venv
.venv\scripts\activate
```

### Locally using Bootstrap and JQuery
```
<script src="js/script.js"></script>
<link rel="stylesheet" href="css/bootstrap.min.css">
```

# Creating a Django Project

#### Step 0 - Activate the virtual environment and install django
- Activate virtual environment
```
pip install django
```
- To save the installed dependencies to a file  
```
pip freeze > requirements.txt
```
- To install the dependencies in another system
```
pip install -r requirements.txt
```
#### Step 1 - Create a new Django project and app
```
django-admin startproject project_name
cd project_name
djano-admin startapp app_name
```
#### Step 2 - Add app to INSTALLED_APPS in settings.py
#### Step 3 - Configure urls.py
#### Step 4 - Define the models
#### Step 5 - Perform migration changes
```
python manage.py makemigrations
python manage.py migrate
```
#### Step 6 - Define the form in forms.py
#### Step 7 - Create a view in views.py
#### Step 8 - Create templates
#### Step 9 - Register Models in Admin Panel
#### Step 10 - Create super admin
```
python manage.py createsueruser
```
#### Step 11 - Start the django server
```
python manage.py runserver
```