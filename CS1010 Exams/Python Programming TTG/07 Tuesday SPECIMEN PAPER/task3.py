def HashKey(ThisCountry):
    total = 0
    for i in ThisCountry:
        total += ord(i)
    address = int(total % 373 + 1)
    return int(address)

def CreateCountry():
    infile = open("COUNTRIES.txt","r")
    countries = infile.readlines()
    array = []
    for i in range(374):
        array.append('')
    for i in countries:
        address = HashKey(' '.join(i.split(' ')[:-1]))
        noSpace = address - 1
        if noSpace == -1:
            noSpace = 372
        while array[address] != '' and address != noSpace:
            address += 1
            if address == 372:
                address = 0
        array[address] = i
    outfile = open("NEWFILE.txt","w")
    for i in array:
        print(i[:-1],file = outfile)
    outfile.close()

def LookUpCountry():
    infile = open('NEWFILE.txt','r')
    data = infile.readlines()
    lookup = input("Enter the country name: ")
    address = HashKey(lookup)
    noSpace = address - 1
    if noSpace == -1:
        noSpace = 372
    countryName = ' '.join(data[address].split(' ')[:-1])
    while countryName != lookup and address != noSpace:
        address += 1
        if address == 372:
            address = 0
        countryName = ''.join(data[address].split()[:-1])
    
    if countryName == lookup:
        print(address,data[address][:-1])
    else:
        print("Cannot find the data.")
        
CreateCountry()
LookUpCountry()
