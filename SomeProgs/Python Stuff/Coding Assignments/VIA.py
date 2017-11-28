def main():
    ## GETTING DATA ##
    infile = open("VIA.DAT","r")
    data = infile.readlines()

    via_list = []
    name_list = []
    for i in range(len(data)):
        if i % 2 == 0:
            name_list.append(data[i])
        else:
            tempList = data[i].split(":")
            totalHours = int(tempList[0]) + int(tempList[1]) + int(tempList[2])
            via_list.append(totalHours)
    infile.close()

    database = []
    for i in range(len(via_list)):
        student_data = "{0}:{1}".format(via_list[i],name_list[i][:-1])
        database.append(student_data)

    ## Finding minimum VIA hours ##
    count = 0
    people_index = []
    invalid = True
    while invalid:
        x = input("Enter minimum number of hours of VIA: ")
        if x.isdigit():
            invalid = False
        else:
            invalid = True

    ## Finding people who did not meet minimum VIA hours ##
    for i in range(len(via_list)):
        if int(via_list[i]) < int(x):
            count += 1
            people_index.append(database[i])

    ## Sorting the names in ascending order of number of VIA hours ##
    length = len(people_index)
    while length > 0:
        j = 0
        while j < length - 1:
            first = people_index[j].split(":")
            second = people_index[j+1].split(":")
            if int(first[0]) > int(second[0]):
                temp = people_index[j]
                people_index[j] = people_index[j+1]
                people_index[j+1] = temp

            j += 1
        length -= 1

    ## PRINTING ##
    print("Names of students who did not do",x,"VIA hours.")
    print("{0:<20}{1:<5}".format("Name","Hours"))
    for i in people_index:
        items = i.split(":")
        print("{0:<20}{1:<5}".format(items[1],items[0]))
    print("There are",count,"students who did not meet the required VIA hours.")
    if count == 0:
        print("Care. Serve. Lead!")
    elif count >= len(name_list)//2:
        print("You are not the centre of the universe.")
        
main()
