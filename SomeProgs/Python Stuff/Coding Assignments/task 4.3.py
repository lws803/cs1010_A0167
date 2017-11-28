def validate_frequency(frequency):
    if frequency.isalpha():
        return True
    elif int(frequency) > 60 or int(frequency) < 0:
        return True
    else:
        return False

def display(frequencyList,dataList,maximum):
    print("+"*40)
    print("Frequency Distribution")
    print("+"*40)
    print()
    
    highestscale = 0
    while maximum > 0:
        maximum -= 10
        highestscale += 1
    highestscale += 1
    highestscale = highestscale * 10

    scales = []
    
    for number in range(6):
        scaleNo = (highestscale // 7) * (number + 1)
        scales.append(scaleNo)

    print("{0:10}{1:70}".format('',70*"-"))
    outputScale = ''
    line = ''
    for item in scales:
        line = '{0}'.format('-') + line
        outputScale += "{0:<10}".format(item)

    print("{0:10}{1:70}".format('',line))
    print("{0:10}{1:70}".format('',outputScale))
    for i in range(len(frequencyList)):
        print("{0:10}{1:70}".format(dataList[i],((int(frequencyList[i])//highestscale) * 70)*"@"))
        for k in range(5):
            print("{0:10}{1:70}".format("",(int(frequencyList[i])//highestscale * 70)*"@"))
    print()
    

def main():
    frequencyList = []
    dataList = []
    count = 0
    maximum = 0
    datavalue = ""
    while datavalue != "ZZZ" and count <= 5:
        datavalue = input("Next X data value ... <ZZZ to END>: ")
        if datavalue == "ZZZ" and count > 0:
            display(frequencyList,dataList)
        elif datavalue == "ZZZ":
            return
        dataList.append(datavalue)
        frequency = input("Frequency...: ")
        frequencyList.append(frequency)
        if int(frequency) > maximum:
            maximum = int(frequency)
        count += 1
    print()
    display(frequencyList,dataList,maximum)

main()
