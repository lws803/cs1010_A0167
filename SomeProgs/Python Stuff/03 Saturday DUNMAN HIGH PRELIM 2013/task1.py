def validate_temp(temp):
    if temp in range(-90,61):
        return False
    else:
        return True

def main():
    import datetime
    data = []
    no_data_input = 0
    more = True
    while no_data_input <= 3 and more:
        country = input("Enter the name of the country: ")
        wrong = True
        while wrong:
            highest_temp = eval(input("Enter the highest temperature of the country: "))
            wrong = validate_temp(highest_temp)
        wrong = True
        while wrong:
            lowest_temp = eval(input("Enter the lowest temperature of the country: "))
            wrong = validate_temp(lowest_temp)
        print()
        difference = highest_temp - lowest_temp
        if difference < 0:
            absolute_difference = -1 * difference
        else:
            absolute_difference = difference
        dataset = [country,highest_temp,lowest_temp,absolute_difference]
        data.append(dataset)
        no_data_input += 1
        response = input("Anymore data?: [y/n] ")
        if response.lower() == 'y':
            more = True
        else:
            more = False

    infile = open("WIDEST.txt","r")
    date = infile.readline()
    widest = infile.readline()
    current_greatest_diff = int(widest[:-1].split(',')[1])
    current_country_greatest = widest[:-1].split(',')[0]
    infile.close()

    greatest_diff = 0
    country_greatest = ''
    
    for i in data:
        if i[3] >= greatest_diff:
            greatest_diff = i[3]
            country_greatest = i[0]

    print("country:{0},temp:{1}".format(country_greatest,greatest_diff))

    if current_greatest_diff < greatest_diff:
        outfile = open("WIDEST.txt","w")
        today = str(datetime.datetime.today())[0:10]
        print(today,file = outfile)
        print("{0},{1}".format(country_greatest,greatest_diff),file = outfile)
        outfile.close()
    else:
        print("Current greatest difference still greater")
        
main()
    
    
