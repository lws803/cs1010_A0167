import time

def recursion_sort(array,n):
    if n > 0:
        recursion_sort(array,n-1)
        key = array[n]
        i = n-1
        while i > -1 and array[i] > key:
            array[i+1] = array[i]
            i = i - 1
        array[i+1] = key
    return array

def main():
    Animal = ["SNAKE", "CAT", "LION", "WOLF", "TIGER", "GIRAFFE", "HORSE", "ZEBRA", "LIZARD", "BEAR", "CROCODILE", "AARDVARK", "ALLIGATOR"]
    Sport = ["FOOTBALL", "HANDBALL", "HOCKEY", "CRICKET", "CYCLING", "JUDO", "SWIMMING", "BASKETBALL", "WATER POLO"]

    Animal = recursion_sort(Animal * 100,(len(Animal)-1)* 100)
    Sport = recursion_sort(Sport * 100, (len(Sport)-1)* 100)

time1 = time.time()
main()
time2 = time.time()
print(time2 - time1)
