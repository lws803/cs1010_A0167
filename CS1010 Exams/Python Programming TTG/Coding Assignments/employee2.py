# Name: Tan Tze Guang
# Class: 13S28
# Date: 11 April 2013
# This program to store the employee data.

def validate_dept(dept):
    if len(dept) > 6:
        print("Department name is only 6 characters long.")
        return True
    return False

def validate_ID(ID,List):
    if not len(ID) == 6:
        print("ID should only have 6 characters")
        return True
    if not(ID[0].isalpha() and ID[0].isupper()):
        print("ID first character is supposed to be upper case.")
        return True
    if not(ID[1:6].isdigit()):
        print("ID is supposed to have 5 digits after 1st character.")
        return True
    List.append(ID)
    return False

def validate_Name(name,List):
    if len(name) > 20:
        print("Name is only 20 characters long")
        return True
    List.append(name)
    return False

def validate_No(number,List):
    if len(number) == 7 and number.isdigit():
        List.append(number)
        return False
    else:
        print("Telephone number is 7 digits long")
        return True

def validateType(Type,List):
    if Type == "S" or Type == "s":
        List.append(Type)
        return False
    elif Type == "H" or Type == "h":
        List.append(Type)
        return False
    else:
        print("Invalid payment type.")
        return True

def check_new(new,number):
    if new == "Y" or new == "y":
        number += 1
        return True,number
    else:
        return False,number

def output(deptName,employee_number,IDlist,NameList,PhoneList,TypeList,outfile):
    print("{0} Number of employees: {1}".format(deptName,employee_number),file = outfile)
    for i in range(len(IDlist)):
        print("{0} {1} {2} {3}".format(IDlist[i],NameList[i],PhoneList[i],TypeList[i]),file = outfile)

def CREATEEMPLOYEE():
    outfileName = input("Enter the file you want to save this into: ")
    outfile = open(outfileName,"w")

    invalid_dept = True
    while invalid_dept:
        deptName = input("Enter the department name: ")
        invalid_dept = validate_dept(deptName)

    employee_number = 1
    IDlist = []
    NameList = []
    PhoneList = []
    TypeList = []
    
    new_employee = True
    while new_employee:

        invalidID = True
        while invalidID:
            EmployeeID = input("Enter Employee ID: ")
            invalidID = validate_ID(EmployeeID,IDlist)

        invalidName = True
        while invalidName:
            Name = input("Enter Employee Name: ")
            invalidName = validate_Name(Name,NameList)

        invalidNo = True
        while invalidNo:
            TelephoneNumber = input("Enter Employee phone number: ")
            invalidNo = validate_No(TelephoneNumber,PhoneList)

        invalidType = True
        while invalidType:
            EmployeeType = input("Enter Payment mode of employee (S/H): ")
            invalidType = validateType(EmployeeType,TypeList)

        more_employee = input("Any more Employees? (Y/N)")
        new_employee,employee_number = check_new(more_employee,employee_number)

    output(deptName,employee_number,IDlist,NameList,PhoneList,TypeList,outfile)
    outfile.close()
    
def main():
    CREATEEMPLOYEE()

main()
