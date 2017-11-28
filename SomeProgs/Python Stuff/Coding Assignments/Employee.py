# Name: Tan Tze Guang
# Class: 13S28
# Date: 6 April 2013
# This program saves the data of employees working salary

def check_ID(ID, invalid): # Checks ID in correct format, loops otherwise
    if ID[0].isalpha() and ID[1:6].isdigit():
        invalid = False
        return ID,invalid
    else:
        invalid = True
        print("Error, invalid ID")
        return ID, invalid

def check_name(name,invalid): # Checks Name of Employee is within 20 characters long, loops otherwise
    if len(name) <= 20:
        invalid = False
        return name,invalid
    else:
        invalid = True
        print("Error, Name must be shorter than 20 characters")
        return name, invalid

def check_type(Type,invalid): # Checks Type of payment is hourly or salary, loops otherwise
    if Type == "S" or Type == "s":
        invalid = False
        return Type,invalid
    elif Type == "H" or Type == "h":
        invalid = False
        return Type,invalid
    else:
        invalid = True
        print("Error, invalid employee type")
        return Type,invalid

def check_salary(salary,invalid): # Checks Salary is in range of $600 to $5000, loops otherwise
    if salary >= 600.00 and salary <= 5000.00:
        invalid = False
        return salary,invalid
    else:
        invalid = True
        print("Error, salary out of range")
        return salary,invalid

def check_rate(rate,invalid): # Checks hourly rate is in range $5 to $120,loops otherwise
    if rate >= 5.00 and rate <= 120.00:
        invalid = False
        return rate,invalid
    else:
        invalid = True
        print("Error, Rate out of range")
        return rate,invalid


def check_hours(hours,invalid): # Checks hours worked is in range 5 to 40 hours,loops otherwise
    if hours >= 5.00 and hours <= 40.00:
        invalid = False
        return hours,invalid
    else:
        invalid = True
        print("Error, hours out of range")
        return hours,invalid

def check_repeat(repeat,invalid): # Checks if there are any more entries to be input
    if repeat[0] == "N" or repeat[0] == "n":
        invalid = False
        return repeat,invalid
    else:
        invalid = True
        return repeat,invalid
    

def output(ID,Name,Type,Salary,Rate,Hours,outfile): # Writes the data to file in the following format
    print("ID:",ID, file = outfile)
    print("Name:",Name, file = outfile)
    print("Type:",Type, file = outfile)
    print("Salary:",Salary, file = outfile)
    print("Hourly Rate:",Rate, file = outfile)
    print("Hours Worked:",Hours, file = outfile)
    print("",file = outfile)

def main():
    print("This program writes the employees working salary into a different file.")
    outfileName = input("Enter the file to save the data to: ")
    outfile = open(outfileName,"w") # Prepares the file to receive data
    
    repeat = True # Forces the program to repeat if left unchanged
    while repeat:
        invalid_ID = True
        while invalid_ID: # Constantly asks for an input until ID is valid 
            EmployeeID = input("Enter your ID: ")
            EmployeeID, invalid_ID = check_ID(EmployeeID, invalid_ID)

        invalid_name = True
        while invalid_name: # Asks for name lesser than 20 characters
            Name = input("Enter your name: ")
            Name,invalid_name = check_name(Name,invalid_name)

        invalid_Type = True
        while invalid_Type: # Asks for payment mode. If not valid, it will ask again
            EmployeeType = input("Enter the form of payment: ")
            EmployeeType,invalid_Type = check_type(EmployeeType,invalid_Type)

        if EmployeeType == "S" or EmployeeType == "s":
            invalid_salary = True
            while invalid_salary: # Ask for monthly salary and checks if it is in range
                Salary = eval(input("Enter your monthly salary: (between $600 to $5000) "))
                Salary,invalid_salary = check_salary(Salary,invalid_salary)

            output(EmployeeID,Name,EmployeeType,Salary,"NIL","NIL",outfile) # Calls function to write to file

        elif EmployeeType == "H" or EmployeeType == "h":
            invalid_rate = True
            while invalid_rate: # Ask for hourly wage and check if it is in range
                HourlyRate = eval(input("Enter the your hourly pay: (between $5 to $120) "))
                HourlyRate, invalid_rate = check_rate(HourlyRate,invalid_rate)

            invalid_hour = True
            while invalid_hour: # Ask for hours worked and check if it is in range
                HoursWorked = eval(input("Enter hours worked: (between 5 hours to 40 hours) "))
                HoursWorked , invalid_hour = check_hours(HoursWorked, invalid_hour)

            output(EmployeeID,Name,EmployeeType,"NIL",HourlyRate,HoursWorked,outfile) # Calls function to write to file

        redo = input("Any more entries: (Y/N)")
        redo,repeat = check_repeat(redo,repeat) # Checks if there is any more data to process

    outfile.close()
    
main()
