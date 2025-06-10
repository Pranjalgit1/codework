# Program to determine quadrant of a point in XY coordinate system

# Get coordinates from user
x = float(input("Enter x coordinate: "))
y = float(input("Enter y coordinate: "))

# Determine quadrant
if x > 0 and y > 0:
    print("Point (", x, ",", y, ") lies in First Quadrant")
elif x < 0 and y > 0:
    print("Point (", x, ",", y, ") lies in Second Quadrant")
elif x < 0 and y < 0:
    print("Point (", x, ",", y, ") lies in Third Quadrant")
elif x > 0 and y < 0:
    print("Point (", x, ",", y, ") lies in Fourth Quadrant")
elif x == 0 and y == 0:
    print("Point (", x, ",", y, ") lies at the Origin")
elif x == 0:
    print("Point (", x, ",", y, ") lies on Y-axis")
elif y == 0:
    print("Point (", x, ",", y, ") lies on X-axis")     