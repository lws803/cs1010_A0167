letter = ['T']
numbers = [1,2,3,4,5,6,7]

for alphabet in letter:
    for digit in numbers:
        print((7 - digit) * ' ' + alphabet * digit)

print()

count = 0
n = 7

while n > 0:
    count = count + 1
    n = n - 1
    print((n) * ' ' + 'T' * count)
