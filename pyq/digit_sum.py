# Program to find sum of digits in an alphanumeric string

# Get input string
string = input("Enter an alphanumeric string: ")

# Initialize sum
digit_sum = 0

# Iterate through each character
for char in string:
    # Check if character is a digit
    if char.isdigit():
        # Convert to integer and add to sum
        digit_sum += int(char)

# Print result
print(f"\nInput string: {string}")
print(f"Sum of digits: {digit_sum}") 