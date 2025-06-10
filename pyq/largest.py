# Program to find largest number among 5 numbers

# Initialize empty list to store numbers
numbers = []

# Input 5 numbers
print("Enter 5 numbers:")
for i in range(5):
    print("Enter number",i+1,":")
    num = int(input())
    numbers.append(num)

# Find largest number
largest = numbers[0]  # Assume first number is largest
for num in numbers:
    if num > largest:
        largest = num

# Print all numbers and the largest
print("\nNumbers entered:", numbers)
print("Largest number is:", largest) 