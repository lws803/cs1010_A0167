def roman_numeral(number):
    tens = number // 10
    fives = (number%10) // 5
    units = (number%10) % 5

    if tens == 4:
        ten = 'XL'
    else:
        ten = 'X' * tens

    if units == 4 and fives == 1:
        unit = 'IX'
    elif units == 4 and fives == 0:
        unit = 'IV'
    else:
        unit = 'V'*fives + 'I'*units

    return(ten + unit)

def main():
    valid = False
    while not valid:
        number = eval(input("Enter a number: "))
        if number > 20 or number < 1:
            valid = False
        else:
            valid = True

    roman_numeral(number)

def addNumbers():
    dictionary = {}
    for i in range(41):
        if i == 0:
            pass
        else:
            dictionary[roman_numeral(i)] = i

    number1 = input("Enter roman numeral: ")
    number2 = input("Enter roman numeral: ")

    total = dictionary[number1.upper()] + dictionary[number2.upper()]
    print(roman_numeral(total))

##addNumbers()

def roman_to_number(roman):
    letters = list(roman)
    length = len(roman)
    dictionary = {'X':10,"V":5,"I":1}
    current = 0
    while current < length - 1:
        elements = []
        temp = ''
        if dictionary[letters[current]] == dictionary[letters[current+1]]:
            temp += letters[current]
            current += 1
        elif dictionary[letters[current]] > dictionary[letters[current+1]]:
            temp += letters[current]
            elements.append(temp)
            temp = ''
            current += 1
        
            
        
        length -= 1










    

