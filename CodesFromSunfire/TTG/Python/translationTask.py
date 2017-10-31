size = input("Start from: ")
intSize = int(size)
myArray = [i for i in range(intSize,intSize+10)]
reversal = []

for num in myArray[::-1]:
    reversal.append(num)

print("Generated array of 10 elements")
print(myArray)
print(reversal)
