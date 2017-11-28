infile = open("EMPLOYEEDATA.txt","r")

data = infile.read()
templist = data.split(" : ")
newtemp =[]
for i in templist:
    newtemp.append(i.strip())
print(templist)
