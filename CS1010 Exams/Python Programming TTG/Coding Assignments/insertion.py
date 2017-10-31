import time

def insertion_sort(animal):
    num_elements = len(animal) 
    i = 0
    while i <= (num_elements - 2): # while there are still 2 or more elements
        if animal[i] > animal[i+1]:# compare the 2 elements
            temp = animal[i+1]  # if the first elements is larger then the next
            j = i # copy the next element
            while j >= 0 and animal[j] > temp: # find the spot where j < element
                animal[j+1] = animal[j] # shifts the other elements forward
                j = j - 1
            animal[j+1] = temp # once found, copy the temp into the spot
        i = i + 1
    return animal

def main():
    Animal = ["SNAKE", "CAT", "LION", "WOLF", "TIGER", "GIRAFFE", "HORSE", "ZEBRA", "LIZARD", "BEAR", "CROCODILE", "AARDVARK", "ALLIGATOR"]
    Sport = ["FOOTBALL", "HANDBALL", "HOCKEY", "CRICKET", "CYCLING", "JUDO", "SWIMMING", "BASKETBALL", "WATER POLO"]

    Sport = insertion_sort(Sport)
    print(Sport)

time1 = time.time()
main()
time2 = time.time()
print(time2 - time1)
