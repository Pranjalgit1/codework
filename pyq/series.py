# Program to calculate series: 1 + 2*1 + 3*2*1 + ... + n*(n-1)*(n-2)*...*1

# Get the value of n from user
n = int(input("Enter the value of n: "))

# Initialize sum and factorial
sum = 0
fact = 1

# Calculate each term and add to sum
for i in range(1, n+1):
    # Calculate factorial for current term
    fact = i * fact
    
    # Add current term to sum
    sum = sum + fact
    
    # Print current term
    if i == 1:
        print("1", end="")
    else:
        print(" + ", end="")
        for k in range(i, 0, -1):
            print(k, end="")
            if k > 1:
                print("*", end="")
    
    # Print = sum after each term
    print(" =", sum)

# Print final sum
print("\nFinal sum of the series is:", sum)