# Name: Tan Tze Guang
# Class: 13S28
# Date: 28 March 2013
# This program calculates the wage of the baby sitter

def convertTime(time):
    hours = (time // 100) * 100
    minutes = (time % 100) * 100/60
    totalTime = (hours + minutes) / 100
    return totalTime

def main():
    print("This program calculates the wage of the baby sitter.")
    print("The hourly wage from 7am to 9 pm is $5.")
    print("The hourly wage any other time is $3.50.")
    print()

    startTime = input("What time did you start work(hhmm[24 hours clock]): ")
    startTime = int(startTime)

    endTime = input("What time did you end work(hhmm[24 hour clock]): ")
    endTime = int(endTime)

    if startTime >= 0000 and startTime < 700: # Start before 7 am

        startTime = convertTime(startTime)
        endTime = convertTime(endTime)
        
        if endTime <= 700: # End before 7am
            total_morning = endTime - startTime
            total_bill = total_morning * 3.50
            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        elif endTime <= 2100: # End before 9pm
            total_morning = 700 - startTime
            salary_morning = total_morning * 3.50

            total_afternoon = endTime - 700
            salary_afternoon = total_afternoon * 5
            
            total_bill = salary_morning + salary_afternoon
            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        elif endTime <= 2400: # End before 12am
            total_morning = 700 - startTime
            salary_morning = total_morning * 3.50

            total_night = endTime - 2100
            salary_afternoon_night = (total_night * 3.50) + (14 * 5)

            total_bill = salary_morning + salary_afternoon_night
            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        else: # If day is over...
            print("ERROR! INVALID INPUT!")

    elif startTime >= 700 and startTime <= 2100: # Start between 7am to 9pm

        startTime = convertTime(startTime)
        endTime = convertTime(endTime)
        
        if endTime <= 2100: # End before 9pm
            total_afternoon = endTime - startTime

            total_bill = total_afternoon * 5
            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        elif endTime <= 2400: # End before 12am
            total_afternoon = 2100 - startTime
            salary_afternoon = total_afternoon * 5

            total_night = endTime - 2100
            salary_night = total_night * 3.50

            total_bill = salary_afternoon + salary_night
            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        else: # If day is over...
            print("ERROR! INVALID INPUT!")

    elif startTime > 2100 and startTime <= 2400: # Start after 9 pm

        startTime = convertTime(startTime)
        endTime = convertTime(endTime)
        
        if endTime <= 2400: # End before 12 am
            total_night = endTime - startTime
            salary_night = total_night * 3.50

            print("Total babysitting bill is: ${0:0.2f}".format(total_bill))

        else: # If day is over...
            print("ERROR! INVALID INPUT!")

    else: # If startTime crosses over to other days
        print("ERROR! INVALID INPUT!")

main()
