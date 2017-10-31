# Name: Tan Tze Guang
# Class: 13S28
# Date: 4 April 2013
# This program calculates retail prices using data from input file

def gatherData(file): # Receives data and creates the lists needed for output
    quantityList = []
    priceList = []
    discountList = []
    subtotalList = []
    total = 0

    for line in range(len(file)):
        temp_data = file[line].split()
        
        quantityList.append(temp_data[0]) # Compiles all quantities of items into a list
        priceList.append(temp_data[1]) # Compiles all prices of items into a list
        discountList.append(temp_data[2]) # Compiles all discounts of items into a list

        subtotal = (float(temp_data[1])*float(temp_data[0])* (1 - float(temp_data[2])/100))
        subtotalList.append(subtotal) # Compiles all subtotals of items into a list
        total = total + subtotal # Finds total of subtotals

    return(quantityList,priceList,discountList,subtotalList,total)

def checkMember(code): # Determine if customer is eligible to privilages of member
    if code[0] == "M" or code[0] == "m":
        member = "M"
        discount = 0.95 # 5% discount
        discountMem = "5%"
        return discount,member,discountMem

    elif code[0] == "S" or code[0] == "s":
        member = "S"
        discount = 0.85 # 15% discount
        discountMem = "15%"
        return discount,member,discountMem

    else:
        member = "N"
        discount = 1 # 0% discount
        discountMem = "0%"
        return discount,member,discountMem

def checkPayment(Type): # Determines if customer is eligible for prompt purchase discount
    if Type[0] == "C" or Type[0] == "c":
        paymentType = "Cash"
        discountPayment = 0.98 # 2% discount
        discountPercent = "2%"
        return discountPayment, paymentType, discountPercent 

    else:
        paymentType = "Bill"
        discountPayment = 1 # 0% discount
        discountPercent = "0%"
        return discountPayment, paymentType, discountPercent

def outputScreen(file,quantityList,priceList,discountList,subtotalList,memberDiscount,membership,paymentDiscount,paymentType,discountMem,discountPay,total):
    print("{0:<6}{1:^10}{2:^14}{3:^12}{4:^13}".format("Item","Quantity","Unit Price $","Discount %","Subtotal $"))
    for line in range(len(file)): # Runs through the available items and prints the respective info
        print("{0:<6}{1:>10}{2:>14}{3:>12}{4:>13.2f}".format(line+1,quantityList[line],priceList[line],discountList[line],subtotalList[line]))
    print("{0:<6}{1:>10}{2:>14}{3:>12}{4:>13.2f}".format(" ","Cust Type",membership,discountMem,total*memberDiscount))
    print("{0:<6}{1:<10}{2:<14}{3:>12}{4:>13.2f}".format(" ","Payment:",paymentType,discountPay,total*memberDiscount*paymentDiscount))
    print("{0:<6}{1:^10}{2:^14}{3:<12}{4:>13.2f}".format(" "," "," ","Total:",total*memberDiscount*paymentDiscount))
    
def outputFile(file,quantityList,priceList,discountList,subtotalList,memberDiscount,membership,paymentDiscount,paymentType,outfile,discountMem,discountPay,total):
    print("{0:<6}{1:^10}{2:^14}{3:^12}{4:^13}".format("Item","Quantity","Unit Price $","Discount %","Subtotal $"), file = outfile)
    for line in range(len(file)): # Runs through the items and output to outfile
        print("{0:<6}{1:>10}{2:>14}{3:>12}{4:>13.2f}".format(line+1,quantityList[line],priceList[line],discountList[line],subtotalList[line]),file = outfile)
    print("{0:<6}{1:>10}{2:>14}{3:>12}{4:>13.2f}".format("","Cust Type",membership,discountMem,subtotalList[len(subtotalList)-1]*memberDiscount), file = outfile)
    print("{0:<6}{1:<10}{2:<14}{3:>12}{4:>13.2f}".format("","Payment:",paymentType,discountPay,subtotalList[len(subtotalList)-1]*memberDiscount*paymentDiscount), file = outfile)
    print("{0:<6}{1:^10}{2:^14}{3:<12}{4:>13.2f}".format(" "," "," ","Total:",total*memberDiscount*paymentDiscount), file = outfile)
    
def main():
    print("This is a program which reads a customer transaction,")
    print("prints it on the screen and creates an output file.")
    print()

    infileName = input("Enter the name of the file you want to read from: ")
    infile = open(infileName,'r')
    infileData = infile.readlines()

    quantityList, priceList, discountList, subtotalList, total = gatherData(infileData)
    # Prepared all lists needed for the file
    print()

    member = input("Enter member type: (N/M/S) ")
    memberDiscount,membership,discountMem = checkMember(member)

    pay = input("Enter payment method: (Cash/Bill) ")
    paymentDiscount,paymentType,discountPercent = checkPayment(pay)

    print()
    
    outputScreen(infileData,quantityList,priceList,discountList,subtotalList,memberDiscount,membership,paymentDiscount,paymentType,discountMem,discountPercent,total)

    print()
    
    outfileName = input("Enter the name of the file you want to save to: ")
    outfile = open(outfileName,'w')
    outputFile(infileData,quantityList,priceList,discountList,subtotalList,memberDiscount,membership,paymentDiscount,paymentType,outfile,discountMem,discountPercent,total)

    outfile.close()
    infile.close()
main()
