MAXSIZE = 57
currency_dic = {}
currentfile = open("CURRENCIES.txt","r")
readdata = currentfile.readlines()
for i in readdata:
    countryname = i[:-1].split(',')[0]
    value = i[:-1].split(',')[1]
    currency_dic[countryname] = float(value)
updatefile = open("UPDATED.txt","r")
readdata2 = updatefile.readlines()
for j in readdata2:
    countryname = i[:-1].split(',')[0]
    value = float(i[:-1].split(',')[1])
    if countryname in currency_dic.keys():
        if currency_dic[countryname] < value:
            currency_dic[countryname] = value
    else:
        currency_dic[countryname] = value
for i in sorted(currency_dic.keys()):
    print(i,currency_dic[i])

def HashKey(Country):
    total = 0
    global MAXSIZE
    for i in Country:
        total += ord(i)
    key = total % MAXSIZE
    return key + 1
        
def CreateCurrency():
    global currency_dic
    global MAXSIZE
    hashedKeys = []
    for i in range(MAXSIZE):
        hashedKeys.append('')
    for i in sorted(currency_dic.keys()):
        address = HashKey(i)
        if hashedKeys[address] == '':
            hashedKeys[address] = [i,currency_dic[i]]
        else:
            noMore = address - 1
            while hashedKeys[address] != '':
                address += 1
                if address == MAXSIZE:
                    address = 0
                if address == noMore:
                    print("No more space.")
                    return
            if hashedKeys[address] == '':
                hashedKeys[address] = [i,currency_dic[i]]
    outfile = open("DIRECTCURRENCIES.txt","w")
    for item in hashedKeys:
        if item != '':
            print('{0},{1}'.format(item[0],item[1]),file = outfile)
        else:
            print(item,file = outfile)
    outfile.close()
    
def LookupCurrency():
    infile = open("DIRECTCURRENCIES.txt","r")
    data = infile.readlines()
    infile.close()
    print(data)
    look = input("Enter country currency to look up: ")
    address = HashKey(look)
    if data[address].split(',')[0] == look:
        print(data[address].split(',')[1])
    else:
        noMore = address - 1
        while data[address].split(',')[0] != look:
            print(data[address].split(',')[0])
            address += 1
            if address == MAXSIZE:
                address = 0
            if address == noMore:
                print("No more space.")
                return
        if data[address].split(',')[0] == look:
            print(data[address].split(',')[1])

def FindCollisions():
    global currency_dic
    list_countries = sorted(currency_dic.keys())
    affected = []
    infile = open("DIRECTCURRENCIES.txt","r")
    data = infile.readlines()
    for i in list_countries:
        address = HashKey(i)
        if data[address].split(',')[0] != i:
            affected.append(i)
    infile.close()
    print(affected)
    
##CreateCurrency()
##LookupCurrency()
FindCollisions()
