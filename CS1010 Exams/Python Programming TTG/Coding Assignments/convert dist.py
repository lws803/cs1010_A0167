#File: convert distance for km to miles

def main():
    print("This is a program to convert km to miles")
    dist_km = eval(input("What is the distance in km? : "))
    dist_miles = dist_km * .62
    print("The distance is",dist_miles,"miles")

main()
