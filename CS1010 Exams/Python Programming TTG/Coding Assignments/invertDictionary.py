# This program inverts the key with the value in a dictionary

def invert_dic(dic):
    inv = {}
    for key in dic:
        value = dic[key]
        if value not in inv:
            inv[value] = [key]
        else:
            inv[value].append(key)
    return inv

def dic(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput = input("Enter something: ")
    user = dic(userInput)
    inverted_dictionary = invert_dic(user)
    print(inverted_dictionary)
    
main()
