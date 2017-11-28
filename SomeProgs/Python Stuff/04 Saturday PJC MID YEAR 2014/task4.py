#task 4.1

def checkParity(dataset):
    errorRow = []
    errorColumn = []

    for bitRow in range(len(dataset)):
        total = 0
        for bit in dataset[bitRow]:
            total += int(bit)
        if total % 2 != 0:
            errorRow.append(bitRow)

    for bitColumn in range(len(dataset[0])):
        total = 0
        for row in range(len(dataset)):
            total += int(dataset[row][bitColumn])
        if total % 2 != 0:
            errorColumn.append(bitColumn)

    errors = len(errorRow) + len(errorColumn)
    if errors == 0:
        print("No Error Detected")
    else:
        print("Error at ({0},{1})".format(errorRow[0],errorColumn[0]))
        error = dataset[errorRow[0]][errorColumn[0]]
        if error == "0":
            dataset[errorRow[0]][errorColumn[0]] = '1'
        else:
            dataset[errorRow[0]][errorColumn[0]] = '0'
        text = ''
        for i in range(len(dataset)-1):
            newtext = ''
            for k in range(len(dataset[i])):
                newtext += dataset[i][k]
            text = text + newtext + ' '
        print(text)
            

def check():
    infile = open("DATA41.txt","r")

    data = infile.readlines()
    data1 = data[0:5]
    data2 = data[5:]
    newdata1 = []
    newdata2 = []
    infile.close()

    for i in data1:
        i = i[:-1]
        item = list(i)
        newdata1.append(item)

    for i in data2:
        i = i[:-1]
        item = list(i)
        newdata2.append(item)

    checkParity(newdata1)
    checkParity(newdata2)    
    
check()

#task 4.2

def efficiency():
    infile = open("DATA42B.txt",'r')
    data = infile.readlines()
    infile.close()
    m = len(data[0])
    n = len(data)

    totalBits = m * n
    totalTransmit = (m+1) * (n+1)

    efficient = totalBits/totalTransmit
    temp = "{0:0.2f}".format(efficient)
    efficient = float(temp)

    print("Efficiency =",efficient)

efficiency()

#task 4.3

def CreateParity(dataset):
    # create even parity bit
    newdata = []
    text = ''
    
    for bitrow in range(len(dataset)):
        total = 0
        for bit in dataset[bitrow]:
            total += int(bit)
        if total % 2 == 0:
            databits = dataset[bitrow] + '0'
        else:
            databits = dataset[bitrow] + '1'
        newdata.append(databits)
        text += databits + '\n'
            
    parityRow = ''
    for bitColumn in range(len(newdata[0])):
        total = 0
        for row in range(len(newdata)):
            total += int(newdata[row][bitColumn])
        if total % 2 == 0:
            parityRow += '0'
        else:
            parityRow += '1'
    parityRow += '\n'
    text += parityRow
    text += '*'

    print(text)
        

def parity():
    infile = open("DATA43.txt","r")
    numbers = infile.readline()
    numbers = numbers[:-1]
    number = int(numbers)
    data = []
    while number > 0:
        bits = ''
        tempdataset = []
        while bits != '*\n':
            bits = str(infile.readline())
            item = bits[:-1]
            tempdataset.append(item)
        tempdataset = tempdataset[:-1]
        data.append(tempdataset)
        number -= 1

    infile.close()
    
    print(numbers)
    for i in data:
        CreateParity(i)
    
parity()
