# Name: Tan Tze Guang
# Class: 13S28
# Date: 20 May 2013
import datetime

def validateBooks(book):
    if not book.isnumeric():
        return False
    if int(book) >= 0:
        return True
    elif int(book) < 0 or book == "":
        return False
        
def validateCat(date,cat):
    if cat.isnumeric() and (date[6:] == cat[:4]) and len(cat) == 7:
        return True
    else:
        return False
    
def validateTitle(title):
    if len(title) > 30 or title == "":
        return False
    else:
        return True
    
def validateAuthor(author):
    if len(author) > 30 or author == "":
        return False
    else:
        return True
    
def validateFormat(form):
    if not form.isalpha():
        return False
    if form == "S":
        return True
    elif form == "L":
        return True
    elif form == "O":
        return True
    elif form == "P":
        return True
    else:
        return False

def CREATEBOOK():
    outfile = open("BOOK.dat",'w')
    
    date_today = str(datetime.date.today())
    year = date_today[0:4]
    month = date_today[5:7]
    day = date_today[8:10]
    date = day+"-"+month+"-"+year
    print("Today is",date+'.')

    noBooks = input("Enter number of book entries: ")
    while not(validateBooks(noBooks)):
        noBooks = input("Invalid Entry. Enter number of books: ")

    print(date + "|" + noBooks, file = outfile)

    entries = int(noBooks)
    entryNo = 1

    while entries != 0:
        print("Entry",entryNo)
        cat = input("\tEnter Catalogue number: ")
        while not(validateCat(date,cat)):
            cat = input("\tInvalid Entry. Enter Catalogue number: ")

        title = input("\tEnter Title of the book:(max 30 char) ")
        while not (validateTitle(title)):
            title = input("\tInvalid Entry. Enter Title of the book: (max 30 char) ")

        author = input("\tEnter Author of the book: (max 30 char) ")
        while not (validateAuthor(author)):
            author = input("\tInvalid Entry. Enter Author of the book: (max 30 char) ")

        form = input("\tEnter the format of the book: (S/L/O/P) ")
        while not (validateFormat(form)):
            form = input("\tInvalid Entry. Enter the format of the book: (S/L/O/P) ")

        print(cat+"|"+title+"|"+author+"|"+form, file = outfile)
        entries = entries - 1
        entryNo = entryNo + 1

def DISPLAYBOOK():
    infile = open("BOOK.dat","r")
    data = infile.readlines()

    for eachline in data:
        if eachline[-1] == "\n":
            eachline = eachline[:-1]
        print(eachline)

def main():
    #CREATEBOOK()
    DISPLAYBOOK()

main()
