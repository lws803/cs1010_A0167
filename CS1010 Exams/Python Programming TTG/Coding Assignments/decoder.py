def decoder(textstream):
    upper = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    lower = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    punctuation = ['!','?',',','.',' ',';','\"','\'']
    numberlist = textstream.split(',')

    text = ''
    mode = 0
    for num in numberlist:
        if mode == 0:
            index = int(num) % 27
            print(index)
            if index == 0:
                mode = 1
                continue
            text += upper[index-1]
            
        elif mode == 1:
            index = int(num) % 27
            print(index)
            if index == 0:
                mode = 2
                continue
            text += lower[index-1]

        elif mode == 2:
            index = int(num) % 9
            print(index)
            if index == 0:
                mode = 0
                continue
            text += punctuation[index-1]

    print(text)

##decoder()

def encoder():
    import random
    upper = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z']
    lower = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    punctuation = ['!','?',',','.',' ',';','\"','\'']

    invalid = True
    while invalid:
        userinput = input("Enter a sentence: ")
        if userinput[0] in upper:
            invalid = False
    inputstream = list(userinput)
    outputstream = []
    length = len(outputstream)
    print(inputstream)
    currentMode = 0

    if inputstream[0].isupper():
        currentMode = 0
    else:
        currentMode = 1
    
    for item in inputstream:
        
        if item in upper:
            number = upper.index(item) + 1 + random.randint(1,10)*27
            if currentMode == 1:
                outputstream.append(str(0))
                outputstream.append(str(0))
            elif currentMode == 2:
                outputstream.append(str(0))
            outputstream.append(str(number))
            currentMode = 0
            
        elif item in lower:
            number = lower.index(item) + 1 + random.randint(1,10)*27
            if currentMode == 2:
                outputstream.append(str(0))
                outputstream.append(str(0))
            elif currentMode == 0:
                outputstream.append(str(0))
            outputstream.append(str(number))
            currentMode = 1
            
        elif item in punctuation:
            number = punctuation.index(item) + 1 + random.randint(1,10)*9
            if currentMode == 0:
                outputstream.append(str(0))
                outputstream.append(str(0))
            elif currentMode == 1:
                outputstream.append(str(0))
            outputstream.append(str(number))
            currentMode = 2

    outputtext = ','.join(outputstream)
    print(outputtext)

    decoder(outputtext)

##encoder()

def main():
    
    infile = open("textstream.txt",'r')
    data = infile.readline()
    textstream = str(data)
    infile.close()

##    decoder(textstream)
    encoder()
main()
