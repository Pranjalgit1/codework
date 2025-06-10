# Program to demonstrate Python indexing

# List example
numbers = [10, 20, 30, 40, 50]
print("List:", numbers)
print("First element (index 0):", numbers[0])
print("Last element (index -1):", numbers[-1])
print("Second element (index 1):", numbers[1])
print("Second last element (index -2):", numbers[-2])

# String example
text = "Python"
print("\nString:", text)
print("First character (index 0):", text[0])
print("Last character (index -1):", text[-1])
print("Second character (index 1):", text[1])
print("Second last character (index -2):", text[-2])

# Slicing example
print("\nSlicing examples:")
print("First three elements:", numbers[0:3])
print("Last three elements:", numbers[-3:])
print("Every second element:", numbers[::2])
print("Reverse list:", numbers[::-1])

# Tuple example
coordinates = (5, 10, 15)
print("\nTuple:", coordinates)
print("First coordinate (index 0):", coordinates[0])
print("Last coordinate (index -1):", coordinates[-1])

# Dictionary example
student = {"name": "John", "age": 20, "grade": "A"}
print("\nDictionary:", student)
print("Accessing by key 'name':", student["name"])
print("Accessing by key 'age':", student["age"]) 