Animal = []
Sport = []

for i in range(13):
    if i in range(9):
        Sport.append('')
    Animal.append('')

Animal[0] = "SNAKE"
Animal[1] = "CAT"
Animal[2] = "LION"
Animal[3] = "WOLF"
Animal[4] = "TIGER"
Animal[5] = "GIRAFFE"
Animal[6] = "HORSE"
Animal[7] = "ZEBRA"
Animal[8] = "LIZARD"
Animal[9] = "BEAR"
Animal[10] = "CROCODILE"
Animal[11] = "AARDVARK"
Animal[12] = "ALLIGATOR"
Sport[0]="FOOTBALL"
Sport[1]="HANDBALL"
Sport[2]="HOCKEY"
Sport[3]="CRICKET"
Sport[4]="CYCLING"
Sport[5]="WATER POLO"
Sport[6]="JUDO"
Sport[7]="SWIMMING"
Sport[8]="BASKETBALL"

def BubbleSort(array):
    i = len(array)
    element_switched = True
    while i > 0 and element_switched:
        for j in range(0,i-1,1):
            element_switched = False
            if array[j] > array[j+1]:
                array[j],array[j+1] = array[j+1],array[j]
                element_switched = True
        i -= 1

def main():
    global Animal,Sport
    BubbleSort(Animal)
    BubbleSort(Sport)
    print(Animal)
    print(Sport)

main()










        
