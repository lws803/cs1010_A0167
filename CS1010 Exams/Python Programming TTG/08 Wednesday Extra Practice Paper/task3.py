def CheckDigits(IBAN):
    IBAN = IBAN[:2] + '00' + IBAN[4:]
##    print(IBAN)
    subs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    code = IBAN[0:4]
    IBAN = IBAN[4:] + code
    text = ''
    for element in IBAN:
        text += str(subs.index(element))
    result = int(text)
    temp = result % 97
    check_digit = 98 - temp
    check_digit = "{0}".format(str(check_digit).rjust(2,'0'))

    return(check_digit)

def validation(IBAN):
    subs = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    code = IBAN[0:4]
    temp = IBAN[4:] + code
    text = ''
    for element in temp:
        text += str(subs.index(element))
    result = int(text)
    temp2 = result % 97
    if temp2 != 1:
##        print(IBAN)
        checkdigit = CheckDigits(IBAN)
##        print(checkdigit)
        return IBAN[:2] + checkdigit + IBAN[4:]
    else:
        return "OK"

def ValidateCheckDigits():
    infile = open("TRANSACTIONS.txt","r")
    data = infile.readlines()
    changes = []
    for i in range(len(data)):
        changes.append('')
        result = validation(data[i][:-6])
        if result.isalpha():
            changes[i] = data[i][:-1]
            print(changes[i],"ok")
        else:
            print(data[i][:-1],"is invalid.")
            IBAN = result + data[i][-6:-1]
            print(IBAN)
            print("Expecting:",IBAN[2:4])
            changes[i] = IBAN

##    outfile = open("TRANSACTIONS.txt","w")
##    for i in changes:
##        print(i,file = outfile)
##    infile.close()
##    outfile.close()

def UpdateBalance():
    transactionFile = open("TRANSACTIONS.txt","r")
    transactions = transactionFile.readlines()
    accountsFile = open("ACCOUNTS.txt",'r')
    accounts = accountsFile.readlines()
    count = 0

    data = {}
    for i in accounts:
        iban = i[:22]
##        print(iban)
        name = i[22:37]
##        print(name)
        balance = i[37:]
##        print(balance)
        if iban in data.keys():
            data[iban].append([name.strip(),float(balance)])
        else:
            data[iban] = [[name.strip(),float(balance)]]
##    for i in sorted(data.keys()):
##        print(i,data[i])

    for i in transactions:
        trans_iban = i[:-6]
        action = i[-6:-5]
        amount = i[-5:]
        if trans_iban in data.keys():
            if len(data[trans_iban]) > 1:
                for j in data[trans_iban]:
                    count += 1
                    if action == 'W':
                        print("WITHDRAW")
                        j[1] -= float(amount)
                    else:
                        print("DEPOSIT")
                        j[1] += float(amount)
            else:
                count += 1
                if action == 'W':
                    print("WITHDRAW")
                    data[trans_iban][0][1] -= float(amount)
                else:
                    print("DEPOSIT")
                    data[trans_iban][0][1] += float(amount)

##    print()
##    for i in sorted(data.keys()):
##        print(i, data[i])
    print("{0} records updated.".format(count))      
            
        
def main():
    infile = open("IBANS.txt","r")
    data = infile.readlines()
    for i in data:
        CheckDigits(i[:-1])
    infile.close()
    
##main()
##ValidateCheckDigits()
UpdateBalance()
