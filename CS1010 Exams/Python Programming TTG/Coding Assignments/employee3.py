# Name: Tan Tze Guang
# Class: 13S28
# file: DISPLAYEMPLOYEE / UPDATEEMPLOYEE

import os.path

def validateSalary(salary):
    if salary >= 600.00 and salary <= 5000.00:
        return False
    else:
        print("Salary is out of range")
        return True

def validateRate(rate):
    if rate >= 5.00 and rate <= 120.00:
        return False
    else:
        print("Pay per hour is out of range")
        return True

def validateHours(hour):
    if hour >= 5.00 and hour <= 40.00:
        return False
    else:
        print("Hours out of range.")
        return True

def display(record):
    print("Employee ID:",record[0])
    print("Name:",record[1])
    print("Tel No:",record[2])
    print("Type of Employee:",record[3])
    print()

def output(deptName, noEmployees, data,record):
    print("Department Name:",deptName)
    print("#Employees:",noEmployees)
    print("{0:15}{1:20}{2:10}{3:16}".format("Employee ID","Name","Tel No","Type of Employee"))
    for i in range(len(data)):
        for j in range(len(record)):
            if j == 0:
                print("{0:15}".format(data[i][j]),end = "")
            if j == 1: 
                print("{0:20}".format(data[i][j]),end = "")
            if j == 2: 
                print("{0:10}".format(data[i][j]),end = "")
            if j == 3: 
                print("{0:16}".format(data[i][j]))

def DISPLAYEMPLOYEES():
    infileName = input("Enter the name of the file to read: ")
    if os.path.isfile(infileName):
        infile = open(infileName,'r') # open file
        print("File",infileName,"exists. Proceeding to read employee records.\n")
    else:
        print("File",infileName,"does not exist. Exit the program.")
        return

    deptName = infile.readline()
    deptName = deptName[:-1]

    noEmployees = infile.readline()
    noEmployees = noEmployees[:-1]
    data = []

    for i in infile:
        record = i.split("\t")
        if record[3][-1] == "\n":
            record[3] = record[3][:-1]
        data.append(record)

    output(deptName,noEmployees,data,record)  
        
def UPDATEEMPLOYEES():
    infileName = input("Enter the name of the file to read: ")
    if os.path.isfile(infileName):
        infile = open(infileName,'r')
    else:
        print("File",infileName,"does not exist. Exit the program")
        return

    outfileName = input("Enter name of file to write into: ")
    outfile = open(outfileName,'w')

    deptName = infile.readline()
    deptName = deptName[:-1]

    noEmployees = infile.readline()
    noEmployees = noEmployees[:-1]
    data = []

    print("Department Name:",deptName)
    print("#Employee",noEmployees)

    for i in infile:
        record = i.split("\t")
        if record[3][-1] == "\n":
            record[3] = record[3][:-1]

        display(record)
        if record[3] == "S":
            invalidSalary = True
            while invalidSalary:
                Salary = eval(input("Enter employee salary:($600 to $5000) $"))
                invalidSalary = validateSalary(Salary)
            record.append(Salary)
            record.append("NIL")
            record.append("NIL")
            print()
            
        if record[3] == "H":
            invalidRate = True
            while invalidRate:
                HourlyRate = eval(input("Enter employee hourly pay:($5 to $120) $"))
                invalidRate = validateRate(HourlyRate)

            invalidHours = True
            while invalidHours:
                HoursWorked = eval(input("Enter number of hours worked:(5 hours to 40 hours) "))
                invalidHours = validateHours(HoursWorked)

            record.append("NIL")
            record.append(HourlyRate)
            record.append(HoursWorked)
            print()
            
        data.append(record)

    print("Department Name:",deptName, file = outfile)
    print("#Employees:",noEmployees, file = outfile)
    print("{0:15}{1:20}{2:10}{3:20}{4:8}{5:15}{6:20}".format("Employee ID","Name","Tel No","Type of Employee","Salary","Hourly Rate","Hours Worked"),file = outfile)
    for i in range(len(data)):
        for j in range(len(record)):
            if j == 0:
                print("{0:<15}".format(data[i][j]),end = "", file = outfile)
            if j == 1: 
                print("{0:<20}".format(data[i][j]),end = "", file = outfile)
            if j == 2: 
                print("{0:<10}".format(data[i][j]),end = "", file = outfile)
            if j == 3: 
                print("{0:<20}".format(data[i][j]),end = "", file = outfile)
            if j == 4: 
                print("{0:<8}".format(data[i][j]),end = "", file = outfile)
            if j == 5: 
                print("{0:<15}".format(data[i][j]),end = "", file = outfile)
            if j == 6: 
                print("{0:<20}".format(data[i][j]), file = outfile)

    print("Data has been stored in",outfileName)
    
def main():
    print("DISPLAYEMPLOYEES\n")
    DISPLAYEMPLOYEES()
    print("\nUPDATEEMPLOYEES\n")
    UPDATEEMPLOYEES()

main()
