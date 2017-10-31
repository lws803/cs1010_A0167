# Name: Tan Tze Guang
# Class: 13S28
# Date: 11 March 2013
# Batch convert a series of dates into a different format in a output file

def main():
    month_list = ("January","February","March","April","May","June","July","August","September","October","November","December")
    infile = open("date.txt","r")
    outfile = open("file.txt","w")

    for line in infile:
        day = line[0:2]
        month = line[3:5]
        year = line[6:10]

        new_date = (day,month_list[int(month)-1],year)
        print(new_date,file = outfile)

    infile.close()
    outfile.close()

main()  
