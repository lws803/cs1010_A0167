import time

def bubble_sort(animal):
    #noElements = len(animal) - 1
    #elementsSwitched = True
    #while elementsSwitched and noElements >= 2:
        #j= 0
        #elementsSwitched = False
        #while j <= noElements - 1:
            #if animal[j] > animal[j+1]:
                #temp = animal[j]
                #animal[j] = animal[j+1]
                #animal[j+1] = temp
                #elementsSwitched = True
            #j= j + 1
        #noElements = noElements - 1
    #print(animal)

    for a in range(len(animal)-1):
        for b in range(len(animal)-1):
            if animal[b] > animal[b+1]:
                temp = animal[b]
                animal[b] = animal[b+1]
                animal[b+1] = temp

def main():
    Animal = ["SNAKE", "CAT", "LION", "WOLF", "TIGER", "GIRAFFE", "HORSE", "ZEBRA", "LIZARD", "BEAR", "CROCODILE", "AARDVARK", "ALLIGATOR"]
    Sport = ["FOOTBALL", "HANDBALL", "HOCKEY", "CRICKET", "CYCLING", "JUDO", "SWIMMING", "BASKETBALL", "WATER POLO"]
    
    bubble_sort(Animal * 10)
    bubble_sort(Sport * 10)
    
time1 = time.time()
main()
time2 = time.time()
print(time2 - time1)
