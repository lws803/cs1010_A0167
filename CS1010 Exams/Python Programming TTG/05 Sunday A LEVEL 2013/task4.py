def main():
    more = True
    frequencyList = []
    itemList = []
    need_scale = False
    highest = 0
    while more:
        response = input("Next X value: ... <ZZZ to end> ")
        if response == "ZZZ":
            more = False
            break
        else:
            freq = eval(input("Frequency... "))
            if freq > 70:
                need_scale = True
            if freq > highest:
                highest = freq
            itemList.append(response)
            frequencyList.append(freq)

    print("{0}".format('+'*40))
    print("{0}".format("Frequency distribution"))
    print("{0}".format('+'*40))
    for i in range(len(frequencyList)):
        if not need_scale:
            print("{0:10}{1:70}".format(itemList[i],frequencyList[i]*'|'))
            print("{0:10}{1:70}".format('',frequencyList[i]*'|'))
        else:
            small_unit = highest / 70
            no_bar = frequencyList[i] / small_unit
            print("{0:10}{1:70}".format(itemList[i],int(no_bar)*'|'))
            print("{0:10}{1:70}".format('',int(no_bar)*'|'))
            scales = []
            for i in range(5):
                scales.append(small_unit * 70/5 * i)
            scales.append(highest)
    if need_scale:
        print("{0:10}{1:14}{2:14}{3:14}{4:14}{5:14}{6:14}".format('',str(scales[0]).ljust(14,'-'),str(scales[1]).ljust(14,'-'),str(scales[2]).ljust(14,'-'),str(scales[3]).ljust(14,'-'),str(scales[4]).ljust(14,'-'),str(scales[5])))
main()
            
