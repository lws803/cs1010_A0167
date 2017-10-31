def binarySearch(city,item):
    element_found = False
    low = 0
    high = len(city)-1
    while not element_found and low <= high:
        mid = (low+high) // 2
        if city[mid][0] == item:
            element_found = True
        else:
            if item < city[mid][0]:
                high = mid - 1
            else:
                low = mid + 1
    if element_found:
        print("Found {0} at {1}".format(city[mid][0],mid))
        print("City: {0}\nCountry: {1}\nPopulation: {2}".format(city[mid][0],city[mid][1],city[mid][2]))
    else:
        print("ERROR: Unable to find city")

def recursive_binary(array,item,low,high):
    mid = (low + high)//2
    if array[mid][0] == item:
        print("Found {0} at {1}".format(array[mid][0],mid))
        print("array: {0}\nCountry: {1}\nPopulation: {2}".format(array[mid][0],array[mid][1],array[mid][2]))
    else:
        if item < array[mid][0]:
            recursive_binary(array,item,low,mid-1)
        else:
            recursive_binary(array,item,mid + 1,high)

def main():
    infile = open("CITY.csv","r")
    header = infile.readline()
    data = infile.readlines()
    infile.close()
    cities = []
    for i in data:
        record = i[:-1].split(",")
        cities.append(record)
    response = input("Enter a city to search for: ")
    recursive_binary(cities,response,0,len(cities)-1)

main()
