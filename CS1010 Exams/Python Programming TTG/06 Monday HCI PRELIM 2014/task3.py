def ConvertWord(SingleWord):
    infile = open("MORSE.txt","r")
    data = infile.readlines()
    infile.close()
##    cipher = []
##    alpha = []
    dictionary ={}
    for i in data:
        character,morse = i[:-1].split()
        dictionary[character] = morse
##        cipher.append(morse)
##        alpha.append(character)
    morsecode = []
    for i in SingleWord:
##        index = alpha.index(i)
##        subs = cipher[index]
        morsecode.append(dictionary[i])

    return ' '.join(morsecode)

##ConvertWord("COMPUTING")

def main():
    valid = False
    while not valid:
        sentence = input("Enter a sentence: ")
        words = sentence.split(' ')
        if len(words) > 5:
            valid = False
        else:
            valid = True
    translated = []
    for word in words:
        morse = ConvertWord(word)
        translated.append(morse)
    print('/'.join(translated))
##main()

def morse_to_word(morsecode):
    infile = open("MORSE.txt","r")
    data = infile.readlines()
    infile.close()
##    cipher = []
##    alpha = []
    dictionary ={}
    for i in data:
        character,morse = i[:-1].split()
        dictionary[morse] = character
##        cipher.append(morse)
##        alpha.append(character)

    characters = morsecode.split()
    print(characters)
    text = ''
    for i in characters:
        text += dictionary[i]
    return text
print(morse_to_word('... --- ...'))
