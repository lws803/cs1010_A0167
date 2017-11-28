def CreateKey(phrase):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    current = []
    extra = []
    for i in phrase:
        if i not in extra:
            extra.append(i)
            current.append(i)
        else:
            continue
    cipher = ''
    for i in current:
        cipher += i.upper()
    for i in alphabet:
        if i in current:
            continue
        else:
            cipher += i.upper()
    return cipher

##print(CreateKey("apple"))

def CreateKeyTest():
    infile = open("phrases.txt","r")
    data = infile.readlines()
    infile.close()
    for i in data:
        cipher = CreateKey(i[:-1])
        print("Phrase:",i[:-1])
        print("Key:",cipher)
        print()

CreateKeyTest()
    
def encode(message,phrase):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    punctuation = '<>?:"{}!@#$%^&*()_+1234567890-=[];\'./,~` '
    cipher = CreateKey(phrase)
    encoded_message = ''
    for i in message:
        if i in punctuation:
            encoded_message += i
        else:
            index = alphabet.index(i)
            substituted = cipher[index]
            encoded_message += substituted
    return encoded_message

def decode(message,phrase):
    alphabet = 'abcdefghijklmnopqrstuvwxyz'
    punctuation = '<>?:"{}!@#$%^&*()_+1234567890-=[];\'./,~` '
    cipher = CreateKey(phrase)
    decoded_message = ''
    for i in message:
        if i in punctuation:
            decoded_message += i
        else:
            index = cipher.index(i)
            substituted = alphabet[index]
            decoded_message += substituted
    return decoded_message

def decode_file():
    infile = open("cipher.txt","r")
    phrase = infile.readline()
    phrase = phrase[:-1]
    message = infile.readline()
    message = message[:-1]

    print("Phrase:",phrase)
    print("Key:",CreateKey(phrase))
    print("Decoded Message:",decode(message,phrase))

decode_file()
print()

def encode_file():
    cipher = CreateKey("skyhigh")
    print("Phrase: do not give up")
    print("Message:",encode("do not give up",'skyhigh'))

encode_file()










    
