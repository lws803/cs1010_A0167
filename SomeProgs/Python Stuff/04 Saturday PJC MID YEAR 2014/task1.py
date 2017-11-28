def main():

    infile = open("MERS.txt","r")
    data = infile.readlines()
    infile.close()
    
    countrylist = []
    detectlist = []
    deathlist = []
    proportionlist = []
    highest = ''
    highestdetect = 0
    country_proportion = ''
    highestproportion = 0

    second_country = ''
    seconddetect = 0
    third_country = ''
    thirddetect = 0
    
    for i in data:
        country, detect,death = i.split(',')
        proportion = int(death) / int(detect)
        countrylist.append(country)
        detectlist.append(detect)
        deathlist.append(death)
        proportionlist.append(proportion)

    for i in range(len(detectlist)):
        if int(proportionlist[i]) > int(highestproportion):
            highestproportion = proportionlist[i]
            country_proportion = countrylist[i]
            
        if int(detectlist[i]) > int(highestdetect):
            highestdetect = detectlist[i]
            highest = countrylist[i]
        elif int(detectlist[i]) > int(seconddetect) and int(detectlist[i]) < int(highestdetect):
            seconddetect = detectlist[i]
            second_country = countrylist[i]
        elif int(detectlist[i]) > int(thirddetect)and int(detectlist[i]) < int(seconddetect):
            thirddetect = detectlist[i]
            third_country = countrylist[i]
        

    print(highest)
    print(highestdetect)
    print(second_country)
    print(seconddetect)
    print(third_country)
    print(thirddetect)

    print(country_proportion)
    print(highestproportion)

main()

#task 1.2

def find_n_position(detectlist,n):
    for slot in range(len(detectlist)-1,0,-1):
        positionOfMax = 0
        for position in range(1,slot+1):
            if int(detectlist[position]) >= int(detectlist[positionOfMax]):
                positionOfMax = position

        temp1 = detectlist[slot]
        temp2 = countrylist[slot]
        detectlist[slot] = detectlist[positionOfMax]
        countrylist[slot] = countrylist[positionOfMax]
        detectlist[positionOfMax] = temp1
        countrylist[positionOfMax] = temp2

        if slot == len(detectlist)-n:
            return countrylist[slot],detectlist[slot]

print("2nd largest:",find_n_position(detectlist,2))
print("3rd largest:",find_n_position(detectlist,3))
