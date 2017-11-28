def ADD_STOCK():
    pass
def DELETE_STOCK():
    pass
def UPDATE_STOCK():
    pass
def REPORT_STOCK():
    pass

def main():
    run = True
    file = ''
    data = ''
    keys = ''
    
    dataDic = {}
    
    while run:
        choice = input("(A)dd/(D)elete stocks, (L)oad file, (U)pdate prices, (R)eport, or (Q)uit? ")
        if choice.upper() == 'A':
            if file == '':
                print("No file opened. Unable to compute.")
            else:
                ADD_STOCK()

        elif choice.upper() == "D":
            if file == '':
                print("No file opened. Unable to compute.")
            else:
                DELETE_STOCK()
                
        elif choice.upper() == "L":
            file = input("Load file: ")
            infile = open(file,"r")
            data = infile.readlines()
            for i in data:
                temp = i.split('|')
                dataDic[temp[1]] = temp

            keys = dataDic.keys()
            print(keys)
        
        elif choice.upper() == "U":
            if file == '':
                print("No file opened. Unable to compute.")
            else:
                UPDATE_STOCK()

        elif choice.upper() == "R":
            if file == '':
                print("No file opened. Unable to compute.")
            else:
                REPORT_STOCK()

        elif choice.upper() == "Q":
            run = False

main()
