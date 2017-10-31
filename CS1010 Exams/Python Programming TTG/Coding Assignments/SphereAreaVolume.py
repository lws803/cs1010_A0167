import math

def SphereArea(radius):
    return 4 * math.pi * radius * radius

def SphereVolume(radius):
    return 4/3 * math.pi * radius**3

def main():
    print("This program returns the value of the area and volume of a sphere given the radius")
    radius = eval(input("What is the radius of the sphere: "))
    area = SphereArea(radius)
    print("The total surface area of the sphere is {0:0.2f}".format(area))
    volume = SphereVolume(radius)
    print("The volume of the sphere is {0:0.2f}".format(volume))
    
main()
    
