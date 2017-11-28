def validate_frequency(frequency):
    if frequency.isalpha():
        return True
    elif int(frequency) > 60 or int(frequency) < 0:
        return True
    else:
        return False

def display(frequencyList,dataList):
    print("+"*40)
    print("Frequency Distribution")
    print("+"*40)
    print()

    for i in range(len(frequencyList)):
        print("{0:20}{1:60}".format(dataList[i],int(frequencyList[i])*"\u2588"))
        for k in range(4):
            print("{0:20}{1:60}".format("",int(frequencyList[i])*"\u2588"))
        print()
    print()
    

def main():
    frequencyList = []
    dataList = []
    count = 0
    datavalue = ""
    while datavalue != "ZZZ" and count <= 5:
        datavalue = input("Next X data value ... <ZZZ to END>: ")
        if datavalue == "ZZZ" and count > 0:
            display(frequencyList,dataList)
        elif datavalue == "ZZZ":
            return
        dataList.append(datavalue)
        invalid = True
        while invalid:
            frequency = input("Frequency...: ")
            invalid = validate_frequency(frequency)
        frequencyList.append(frequency)
        count += 1
    print()
    display(frequencyList,dataList)

main()
