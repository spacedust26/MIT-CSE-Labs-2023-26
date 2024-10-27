# SHELL SCRIPTING 2
# LAB EXERCISE

# 1. Find whether the given number is even or odd.
echo "Enter number: "
read num
if [ $((num % 2)) -eq 0 ]; then #keep space inside [] brackets
	echo "Even Number"
else 
	echo "Odd Number"
fi

# 2. Print the first ‘n’ odd numbers.
echo "Enter number: "
read num
i=1
echo The first n odd numbers are 
while [ $i -le $num ]; do
	echo $i
	i=`expr $i + 2`
done

# 3. Find all the possible quadratic equation roots using case.
echo "A quadratic equation is of the form ax^2 + bx + c"
echo "Enter a, b, c:"
read a
read b
read c

# Check if `a` is zero (not a quadratic equation)
if [ "$a" -eq 0 ]; then
    echo "Not a quadratic equation since a = 0"
    exit 1
fi

# Calculate the discriminant
d=$((b * b - 4 * a * c))
echo "The discriminant D is: $d"

# Determine the discriminant type and assign it to a variable
if [ "$d" -gt 0 ]; then
    disc_type="positive"
elif [ "$d" -eq 0 ]; then
    disc_type="zero"
else
    disc_type="negative"
fi

# Use case to handle different types of roots
case $disc_type in
    "positive")
        echo "Real and different roots"
        x1=$(echo "scale=2; (-$b - sqrt($d)) / (2 * $a)" | bc -l)
        x2=$(echo "scale=2; (-$b + sqrt($d)) / (2 * $a)" | bc -l)
        echo "x1 = $x1"
        echo "x2 = $x2"
        ;;
    "zero")
        echo "Real and same root"
        x=$(echo "scale=2; (-$b) / (2 * $a)" | bc -l)
        echo "x = $x"
        ;;
    "negative")
        echo "Imaginary roots"
        real_part=$(echo "scale=2; -$b / (2 * $a)" | bc -l)
        imaginary_part=$(echo "scale=2; sqrt(-$d) / (2 * $a)" | bc -l)
        echo "x1 = $real_part - ${imaginary_part}i"
        echo "x2 = $real_part + ${imaginary_part}i"
        ;;
esac

# 4. Find the factorial of a given number.
echo "Enter number"
read n
fact=1
for ((i=1; i<=n; i++)); do
	fact=$((fact * i))
done
echo "Factorial of the number is $fact"

#ADDITIONAL EXERCISE

# 1. Find whether the given string is palindrome.
echo "Enter string"
read str
revstr=$(echo "$str" | rev)
if [ "$str" = "$revstr" ]; then
	echo "Inputted string is a palindrome"
else 
	echo "Inputted string is not a palindrome"
fi

# 2. Find out the sum of the numbers given by user.
echo "Enter numbers separated by spaces:"
read -a numbers
sum=0
for num in "${numbers[@]}"; do
    sum=$((sum + num))
done
echo "The sum of the numbers is: $sum"
