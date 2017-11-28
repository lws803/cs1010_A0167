# File: FormatDates.py
# This is a program to convert date formats from 'dd/mm/yyyy' to 'day month year'

def main():
    print("This is a program to convert date formats to \'day month year\'")
    print("Input date in \'dd/mm/year\' format: ")
    date = input()
    
    day = date[0:2]
    month = date[3:5]
    year = date[6:10]
    
    # Selection of 'new_month' from number from 'month'
    if month == "01":
        new_month = "Jan"
    elif month == "02":
        new_month = "Feb"
    elif month == "03":
        new_month = "Mar"
    elif month == "04":
        new_month = "Apr"
    elif month == "05":
        new_month = "May"
    elif month == "06":
        new_month = "Jun"
    elif month == "07":
        new_month = "Jul"
    elif month == "08":
        new_month = "Aug"
    elif month == "09":
        new_month = "Sep"
    elif month == "10":
        new_month = "Oct"
    elif month == "11":
        new_month = "Nov"
    elif month == "12":
        new_month = "Dec"
    else:
        new_month = month

    print("Old format: %s" % date)
    print("New format: %s %s %s" % (day,new_month,year))

main()
