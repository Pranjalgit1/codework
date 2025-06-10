# Program to demonstrate why we use n+1 in range for factorial

# Example 1: Using n (incorrect)
print("Example 1: Using n (incorrect)")
n = 5
fact = 1
for i in range(1, n):  # This will only go up to n-1
    fact = fact * i
    print(f"i = {i}, fact = {fact}")
print(f"Final factorial with n: {fact}")  # This will be wrong!

# Example 2: Using n+1 (correct)
print("\nExample 2: Using n+1 (correct)")
n = 5
fact = 1
for i in range(1, n+1):  # This will go up to n
    fact = fact * i
    print(f"i = {i}, fact = {fact}")
print(f"Final factorial with n+1: {fact}")  # This will be correct!

# Explanation
print("\nExplanation:")
print("1. For n = 5, we want to calculate 5!")
print("2. 5! = 5 * 4 * 3 * 2 * 1")
print("3. Using range(1, n) would only give: 4 * 3 * 2 * 1")
print("4. Using range(1, n+1) gives: 5 * 4 * 3 * 2 * 1")
print("5. That's why we need n+1 to include the number n itself") 