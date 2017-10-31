#Task 3.1

def CheckDigits(IBAN):
    Alphabet_Map = [None for i in range(0,10)]
    Alphabet_Map.extend(['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'])

    IBAN = IBAN.replace(IBAN[2:4],'00')

    IBAN = IBAN[4:] + IBAN[:4]

    Total = 0

    for element in IBAN:
        if element.isalpha():
            IBAN = IBAN.replace(element,str(Alphabet_Map.index(element)))

    remainder = int(IBAN)%97

    remainder = 98 - remainder

    if len(str(remainder)) == 1:
        remainder = '0' + str(remainder)
        return remainder
    else:
        return remainder

    

print(CheckDigits('GB00WEST12345698765432'))
print(CheckDigits('GB00NWBK60161331926819'))
print(CheckDigits('GB00LOYD30952013145983'))

#Task 3.2

def ValidateCheckDigits():
    infile = open("TRANSACTIONS.txt","r")
    l_output = list()
    
    for line in infile:
        IBAN = line[4:22] + line[0:4]

        Alphabet_Map = [None for i in range(0,10)]
        Alphabet_Map.extend(['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'])

        for element in IBAN:
            if element.isalpha():
                IBAN = IBAN.replace(element,str(Alphabet_Map.index(element)))
        
        
        remainder = int(IBAN) % 97

        

        if remainder == 1:
            print("{0} OK".format(line[0:22]))
            l_output.append(line)
            
        else:
            Expected_Digit = str(CheckDigits(line[0:22]))
            print("{0} invalid. Expected check digits: {1}".format(line[0:22],Expected_Digit))
            line = line.replace(line[2:4],Expected_Digit)
            l_output.append(line)

    infile.close()
            
            
            
    outfile = open("TRANSACTIONS.txt","w")
    outfile.seek(0)
    output = ""
    for item in l_output:
        output += item
    outfile.write(output)
        
        
ValidateCheckDigits()
        
#Task 3.3

def UpdateBalance():
    #1)Initiate lists l_IBAN_NAME_Master and l_Balance_Master
    #2)Read each line of data in ACCOUNTS.txt. Append IBAN+Name and Balance into the respective lists.
    #3)Initiate lists l_IBAN_Trans, l_Activity_Trans (withdraw or deposit) and l_Amount_Trans. Read each line of data in TRANSACTIONS.txt into respective lists.
    #4)Initiate Count to store the integer value of the number of records updated
    #5)Iterate over l_IBAN_NAME_Master. For each element, search for whether this same element exists in l_IBAN_Name_Trans.
    # a)If no match, go to next item in l_IBAN_NAME_master
    # b)If match, obtain IBAN,NAME,Activity,Amount by obtaining the index of the element in l_IBAN_Trans. If Activity is W, subtract Amount from Balance.
    #   If Activity is D, add Amount to Balance.
    #6)Write to ACCOUNTS.txt

    l_IBAN_NAME_Master = list()
    l_Balance_Master = list()
    
    infile_Master = open("ACCOUNTS.txt","r")

    for line in infile_Master:
        line=line.rstrip()
        l_IBAN_NAME_Master.append(line[0:35])
        l_Balance_Master.append(float(line[36:]))

    print(l_IBAN_NAME_Master)
    print(l_Balance_Master)
            
    infile_Master.close()

    l_IBAN_Trans = list()
    l_Activity_Trans = list()
    l_Amount_Trans = list()

    infile_Trans = open("TRANSACTIONS.txt","r")

    for line in  infile_Trans:
        IBAN,Activity,Amount = line[0:22],line[22],line[23:]
        l_IBAN_Trans.append(IBAN)
        l_Activity_Trans.append(Activity)
        l_Amount_Trans.append(float(Amount))

    infile_Trans.close()
   

    for element in l_IBAN_NAME_Master:
        if element[0:22] in l_IBAN_Trans:
            i = l_IBAN_Trans.index(element[0:22])
            if l_Activity_Trans[i] == 'W':
                l_Balance_Master[l_IBAN_NAME_Master.index(element)] = str(l_Balance_Master[l_IBAN_NAME_Master.index(element)]-l_Amount_Trans[i])

            elif l_Activity_Trans[i] == 'D':
                l_Balance_Master[l_IBAN_NAME_Master.index(element)] = str(l_Balance_Master[l_IBAN_NAME_Master.index(element)]+l_Amount_Trans[i])
    output = ""

    for i in range(len(l_IBAN_NAME_Master)):
        temp = "{0}{1:>10}".format(l_IBAN_NAME_Master[i],str(l_Balance_Master[i]))
        output = output + temp + "\n"

    outfile = open("ACCOUNTS.txt","w")

    outfile.write(output)
            
    
    
    Count = len(set(l_IBAN_Trans))
    print(set(l_IBAN_Trans))

    print("{0} records updated.".format(Count))
UpdateBalance()

#Task 3.4

def QueryBalance(IBAN):
    pass
