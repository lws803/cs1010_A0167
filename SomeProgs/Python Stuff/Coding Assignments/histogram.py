# This program lists individual keys from a sentence

def histogram(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def print_hist(hist):
    key_list = []
    for key in hist:
        key_list.append(key)
    key_list.sort()
    print(key_list)

def main():
    userInput = input("Enter a word: ")
    user = histogram(userInput)
    print(user)
    print_hist(user)

main()
