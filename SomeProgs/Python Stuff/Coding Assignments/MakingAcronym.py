# This is a program which creates Acronyms from input

def main():
    print("This is a program which creates Acronyms from input.")
    print("Input: ")
    phrase = input()

    new_phrase = phrase.split()
    # Stores seperated strings into new_phrase
    
    for acronym in new_phrase:  # Takes each string in new_phrase
        print(acronym[0].upper(),end = "")
        # Take 1st char in each string, combine them together & capitalise them
        
main()
