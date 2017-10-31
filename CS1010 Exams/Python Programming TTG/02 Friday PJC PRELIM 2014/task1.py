def bubblesort(array):
    i = len(array)
    element_switched = True
    while element_switched and i > 0:
        j = 0
        element_switched = False
        while j < i-1:
            if float(array[j][3]) > float(array[j+1][3]):
                array[j],array[j+1] = array[j+1],array[j]
                element_switched = True
            j += 1
        i -= 1
            

def main():
    infile = open("RACE.csv","r")
    data = infile.readlines()
    records = []
    for i in data:
        item = i[:-1].split(',')
        records.append(item)
    more_11 = []
    number_more_11 = 0
    for j in records:
        if float(j[3]) > 11:
            more_11.append(j)
            number_more_11 += 1
    print("{0:^10}{1:^10}{2:^20}{3:^10}".format("Runner ID","Country","Name","RaceTime"))
    for k in more_11:
        print("{0:^10}{1:^10}{2:^20}{3:^10}".format(k[0],k[1],k[2],k[3]))
    print(number_more_11)
    bubblesort(records)
    
    print("{0:^10}{1:^10}{2:^20}{3:^10}".format("Runner ID","Country","Name","RaceTime"))
    for i in range(10):
        print("{0:^10}{1:^10}{2:^20}{3:^10}".format(records[i][0],records[i][1],records[i][2],records[i][3]))
    

main()
        

