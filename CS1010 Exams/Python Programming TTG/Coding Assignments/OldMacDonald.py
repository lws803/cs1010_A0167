# Name: Tan Tze Guang
# Class: 13S28
# Date: 14 March 2013
# This program prints the Old MacDonald Song 5 times with 5 different Animals

def macdonald(animal,sound):
    print("Old MacDonald had a farm, Ee-igh,Ee-igh, Oh!")
    print("And on that farm he had a",animal,",Ee-igh,Ee-igh, Oh!")
    print("With a",sound,",",sound,"here and a",sound,sound,"there.")
    print("Here a",sound,",there a",sound,", everywhere a ",sound +",", sound)
    print("OldMacdonald had a farm,Ee-igh,Ee-igh, Oh!")
    print()
    
def main():
    print("This is a program to create a Old MacDonald song with 5 animals.")
    print("-----------------------------------------------------------------")

    macdonald("Cow","moo")
    macdonald("Duck","quack")
    macdonald("Chicken","chirp")
    macdonald("Dog","bark")
    macdonald("Cat","meow")

main()
