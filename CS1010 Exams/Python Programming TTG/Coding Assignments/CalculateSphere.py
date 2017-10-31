#File: CalculateSphere.py
#A program to calculate volume, surface area of a sphere

import math
def main():
    print("This is a program to calculate the surface area and volume of a sphere")
    sphere_radius = eval(input("Radius: "))
    sphere_volume = 4/3 * math.pi * sphere_radius**3
    sphere_area = 4 * math.pi * sphere_radius**2

    print("The volume of the sphere is: ",sphere_volume)
    print("The surface area of the sphere is: ",sphere_area)

main()
