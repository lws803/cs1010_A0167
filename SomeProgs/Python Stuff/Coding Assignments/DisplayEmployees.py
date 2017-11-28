# Name: Tan Tze Guang
# Class: 13S28
# Date: 22 April 2013

def DISPLAYEMPLOYEES():
    import os.path
    fname = input("Enter filename containing employee records: ")
    if os.path.isfile(fname):
        infile = open(fname,"r")
        print("File " + fname + " exists. Proceeding to read employee records...\n")
    else:
        print("File " + fname + " does not exist. Exiting the program.")
        return

    dept = infile.readline() # read first line into dept
    dept = dept[:-1] # remove newline character
    num_employee = infile.readline() # read second line into num_employee
    num_employee = num_employee[:-1] # remove newline character

    num_employee = int(num_employee)
    data = [] # declare data as list to contain all employee data

    for eachLine in infile:
        record = eachLine.split("\t")   # read each employee record into record
        if record[3].endswith("\n"):
            record[3] = record[3][:-1]
        data.append(record)
    infile.close()
        
    print("Department name: {0}".format(dept))
    print("#Employees: {0}\n".format(num_employee))
    print("{0:15}{1:20}{2:15}{3:20}".format("Employee ID","Name","Tel No","Type of Employee"))

    for i in range(len(data)): # loop through length of data
        for j in range(len(record)): # loop through length of record
            if j == 0: # ID column
                print("{0:15}".format(data[i][j]),end="")
            elif j == 1: # Name column
                print("{0:20}".format(data[i][j]), end="")
            elif j == 3: # type column
                print("{0:20}".format(data[i][j]))
            else:
                print("{0:15}".format(data[i][j]), end="")
        
def main():
    DISPLAYEMPLOYEES()

main()
