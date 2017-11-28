def validateID(ID,year):
    if len(ID) == 6 and ID[0:4] == year and ID.isnumeric():
        return True
    else:
        return False

def validateName(name):
    if len(name) > 40:
        return False
    else:
        return True

def validateType(sType):
    if sType == 'S' or sType == 'D':
        return True
    else:
        return False

def validateSkill(skill):
    if skill[0] == "I" or skill[0] == 'i':
        return True,"IT"
    if skill[0] == "B" or skill[0] == 'b':
        return True,"Business"
    if skill[0] == "A" or skill[0] == 'a':
        return True,"Accountancy"
    if skill[0] == "R" or skill[0] == 'r':
        return True,"Retail"
    else:
        print("Invalid Entry.")
        return False,skill

def validateResultS(result):
    if result == "D" or result == "M" or result == "P" or result == "F":
        return True
    else:
        return False

def validateResultD(result):
    if result == "A" or result == "B" or result == "C" or result == "D" or result == "E" or result == "F":
        return True
    else:
        return False

def validateMore(more):
    if more[0] == "y" or more[0] == "Y":
        return True
    else:
        return False

def ADDNEW(data,year):
    new_student = True
    while new_student:
        StudentID = input("Enter Student ID: ")
        while not validateID(StudentID,year):
            StudentID = input("Invalid Entry. Enter Student ID: ")
        Name = input("Enter Student Name: ")
        while not validateName(Name):
            Name = input("Invalid Entry. Enter Student Name: ")

        TypeValid = True
        while TypeValid:
            StudentType = input("Enter Student Type: ")
            while not validateType(StudentType):
                StudentType = input("Invalid Entry. Enter Student Type: ")

            if StudentType == "S":
                TypeValid = False

                invalidSkill = False
                while not invalidSkill:
                    SkillArea = input("Enter Skill Area(IT/Business/Accountancy/Retail): ")
                    invalidSkill,SkillArea = validateSkill(SkillArea)                
                
                Result_s = input("Enter Result(D/M/P/F): ")
                while not validateResultS(Result_s):
                    Result_s = input("Invalid Entry. Enter Result(D/M/P/F): ")
                student = StudentID+"|"+Name+"|"+StudentType+"|"+SkillArea+"|"+"0"+"|"+Result_s
                print(student,file = data)

            if StudentType == "D":
                NoOfSubjects = eval(input("Number of Subjects taken(min 5, max 10): "))
                if not str(NoOfSubjects).isnumeric():
                    return False
                if NoOfSubjects < 5:
                    print("Not Enough Subjects. Returning to choosing Type.")
                    TypeValid = True
                elif NoOfSubjects > 10:
                    print("Too Many Subjects. Returning to choosing Type.")
                    TypeValid = True
                else:
                    TypeValid = False
                    Result_d = input("Enter Result (A-F): ")
                    while not validateResultD(Result_d):
                        Result_d = input("Invalid Entry. Enter Result (A-F): ")
                    student = StudentID+"|"+Name+"|"+StudentType+"|"+"Diploma"+"|"+str(NoOfSubjects)+"|"+Result_d
                    print(student,file = data)

        more = input("Anymore entries (Yes/No): ")
        new_student = validateMore(more)
        print()

def main():
    import datetime
    import os.path
    
    date_today = str(datetime.date.today())
    year = date_today[0:4]
    month = date_today[5:7]
    day = date_today[8:10]
    date = day+"-"+month+"-"+year
    print(date)
    
    fileName = 'STUDENT.dat'
    if os.path.isfile(fileName):
        outfile = open(fileName,'a')
    else:
        outfile = open(fileName,'w')
        print(date,file = outfile)
    
    ADDNEW(outfile,year)

    outfile.close()

main()









