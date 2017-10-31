# This program looks up the [key] from a value and dictionary input.

def reverse_lookup(dic,value):
    key_list = []
    for key in dic:
        if dic[key] == value:
            key_list.append(key)
    return key_list

def dic(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput = input("Enter something: ")
    user = dic(userInput)
    value = eval(input("Enter a number: "))
    key = reverse_lookup(user,value)
    print(key)
    
main()
