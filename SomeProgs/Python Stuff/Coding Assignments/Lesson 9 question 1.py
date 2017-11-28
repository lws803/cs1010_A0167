letter = ['T']
numbers = [1,2,3,4,5,6,7]

for i in letter:
    for number in numbers:
        print(i * number)

print("")
n = 7
count = 0
while n > 0:
    count = count + 1
    print(count * 'T')
    n = n - 1
