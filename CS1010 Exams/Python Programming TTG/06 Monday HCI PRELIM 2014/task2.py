Sport = []
Name = []
Team = []
for i in range(13):
    if i in range(0,11):
        Sport.append('')
        Team.append('')
    Name.append('')
    
Sport[1] = "BASKETBALL"
Sport[2] = "CRICKET"
Sport[3] = "CYCLING"
Sport[4] = "FOOTBALL"
Sport[5] = "HANDBALL"
Sport[6] = "HOCKEY"
Sport[7] = "JUDO"
Sport[8] = "SWIMMING"
Sport[9] = "TENNIS"
Sport[10] = "WATER POLO"

Name[1] = "ALI"
Name[2] = "BEN"
Name[3] = "CHARLIE"
Name[4] = "DON"
Name[5] = "ELICE"
Name[6] = "FENN"
Name[7] = "GLENN"
Name[8] = "HELEN"
Name[9] = "IAN"
Name[10] = "JULIE"
Name[11] = "KEN"
Name[12] = "LINNA"

Team[1] = "Lovepool"
Team[2] = "Arsenic"
Team[3] = "Totoham"
Team[4] = "MadCity"
Team[5] = "MadUnited"
Team[6] = "Chelsand"
Team[7] = "Stroke"
Team[8] = "Newcast"
Team[9] = "Everlong"
Team[10] = "WestBeef"

Sport.pop(0)
Name.pop(0)
Team.pop(0)

def quicksort(array):
    if len(array) <= 1:
        return array
    else:
        low = 0
        high = len(array) - 1
        mid = (low+high) // 2
        pivot = [array.pop(mid)]

        less = []
        great = []
        for item in array:
            if item < pivot[0]:
                less.append(item)
            elif item > pivot[0]:
                great.append(item)
            elif item == pivot[0]:
                pivot.append(item)
        
        return quicksort(less) + pivot + quicksort(great)
print(quicksort(Team))

def binary_search(array):
    searchitem = input("Enter value to search for: ")
    low = 0
    high = len(array) - 1
    found = False
    while not found and low <= high:
        mid = (low+high) // 2
        if array[mid] == searchitem:
            found = True
        elif array[mid] < searchitem:
            low = mid + 1
        else:
            high = mid -1
    if found:
        print("Found {0} in position {1}".format(searchitem,mid))
    else:
        print("Unable to find {0}".format(searchitem))
binary_search(Name)
