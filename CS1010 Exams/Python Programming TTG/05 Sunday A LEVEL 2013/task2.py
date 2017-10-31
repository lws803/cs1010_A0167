def SearchItem(array1,array2,item,choice):
    i = 0
    highest = len(array1)
    found = False
    result = []
    while not found and i < highest:
        if item == array1[i] and choice == '2':
            found = True
        elif item == array1[i] and choice == '1':
            result.append(array2[i])
        i += 1
    if found and choice == '2':
        return array2[i]
    elif choice == '1':
        if len(item) == 0:
            print('Not found.')
        else:
            return result
    else:
        print("Not found.")
        return

def main():
    EmployeeCode = []
    Surname = []
    for i in range(33):
        EmployeeCode.append('')
        Surname.append('')

    EmployeeCode[1]="L001"
    Surname[1]="Pollard"
    EmployeeCode[2]="L002"
    Surname[2]="Wills"
    EmployeeCode[3]="L007"
    Surname[3]="Singh"
    EmployeeCode[4]="L008"
    Surname[4]="Yallop"
    EmployeeCode[5]="L009"
    Surname[5]="Adams"
    EmployeeCode[6]="L013"
    Surname[6]="Davies"
    EmployeeCode[7]="L014"
    Surname[7]="Patel"
    EmployeeCode[8]="L021"
    Surname[8]="Kelly"
    EmployeeCode[9]="S001"
    Surname[9]="Ong"
    EmployeeCode[10]="S002"
    Surname[10]="Goh"
    EmployeeCode[11]="S003"
    Surname[11]="Ong"
    EmployeeCode[12]="S004"
    Surname[12]="Ang"
    EmployeeCode[13]="S005"
    Surname[13]="Wong"
    EmployeeCode[14]="S006"
    Surname[14]="Teo"
    EmployeeCode[15]="S007"
    Surname[15]="Ho"
    EmployeeCode[16]="S008"
    Surname[16]="Chong"
    EmployeeCode[17]="S009"
    Surname[17]="Low"
    EmployeeCode[18]="S010"
    Surname[18]="Sim"
    EmployeeCode[19]="S011"
    Surname[19]="Tay"
    EmployeeCode[20]="S012"
    Surname[20]="Tay"
    EmployeeCode[21]="S013"
    Surname[21]="Chia"
    EmployeeCode[22]="S014"
    Surname[22]="Tan"
    EmployeeCode[23]="S015"
    Surname[23]="Yeo"
    EmployeeCode[24]="S016"
    Surname[24]="Lim"
    EmployeeCode[25]="S017"
    Surname[25]="Tan"
    EmployeeCode[26]="S018"
    Surname[26]="Ng"
    EmployeeCode[27]="S018"
    Surname[27]="Lim"
    EmployeeCode[28]="S019"
    Surname[28]="Toh"
    EmployeeCode[29]="N011"
    Surname[29]="Morris"
    EmployeeCode[30]="N013"
    Surname[30]="Williams"
    EmployeeCode[31]="N016"
    Surname[31]="Chua"
    EmployeeCode[32]="N023"
    Surname[32]="Wong"

    EmployeeCode.pop(0)
    Surname.pop(0)

    print("1) Search for employee ID using Surname:")
    print("2) Search for Surname using employeeID")
    response = input("Enter a choice: [1/2]")
    if response == '1':
        item = input("Enter the Surname: ")
        result = SearchItem(Surname,EmployeeCode,item,'1')
    elif response == '2':
        item = input("Enter an ID: ")
        result = SearchItem(EmployeeCode,Surname,item,'2')
    print(result)
main()

























    

        
