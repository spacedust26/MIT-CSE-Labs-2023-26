# Count the number of users logged on to the system. Display the output as Number of users logged into the system.

echo "The number of users logged onto the system is $(who | wc -l)"