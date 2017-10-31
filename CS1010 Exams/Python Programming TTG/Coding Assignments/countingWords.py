# Name: Tan Tze Guang
# Class: 13S28
# Date: 7 March 2013
# This program counts the number of word in a sentence

def main():
    print("This program counts number of words in a sentence")
    print("Type in a Sentence: ")
    sentence = input()

    words = sentence.split() # create substring from input sentence
    number = len(words) # counts number of substring

    print("There are", number,"words in this sentence.")
    
main()
