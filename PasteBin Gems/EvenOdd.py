# Author: Ethan 
# Date Created: 10/10/17
# Lab 18.20
# Calculates amount of Even and Odd Integers entered, Total amount entered, Sum of all integers, and the Average.

numbers = []
print('This program separates numbers into odd/even and performs calculations ')  # make this better, am lazy
while True:
    print("Enter a positive integer, or enter 0 to perform calculations")
    try:
        new_number = int(raw_input())
    except ValueError:
        print('Please enter an integer!')
        pass
        continue

    if len(numbers) == 0 and new_number == 0:
        print('Cannot start with zero!')
        continue

    if new_number == 0:
        break

    else:
        numbers.append(new_number)

odd_numbers = []
even_numbers = []
sum_of_numbers = 0

for number in numbers:
    if number % 2 == 0:
        even_numbers.append(number)
    else:
        odd_numbers.append(number)

    sum_of_numbers += number

average_of_numbers = float(sum_of_numbers) / len(numbers)

print('There are %s even numbers: ' % len(even_numbers))
print('The even numbers follow:')
for even in even_numbers:
    print(even)
print('There are %s odd numbers: ' % len(odd_numbers))
print('The odd numbers follow:')
for odd in odd_numbers:
    print(odd)
print('The sum of the given numbers is %s: ' % sum_of_numbers)
print('The average of the given numbers is %s: ' % average_of_numbers)