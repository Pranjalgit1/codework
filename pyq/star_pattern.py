# Program to print right-angled triangle pattern

# Get number of rows from user
n = int(input("Enter number of rows: "))

# Print pattern
for i in range(1, n + 1):
    # Print spaces
   # print(" " * (n - i), end="")
    # Print stars
    print("* " * i) 