# This program takes a dictionary as an arguement
# and returns values which appear more than 2 times.

def count_duplicates(dic):
    inv = {}
    for key in dic:
        value = dic[key]
        if value not in inv:
            inv[value] = [key]
        else:
            inv[value].append(key)

    key_list = []
    for key in inv:
        if len(inv[key]) >= 2:
            key_list.append(key)
    print(key_list)    

def hist(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput = input("Enter something: ")
    user = hist(userInput)
    count_duplicates(user)

main()
