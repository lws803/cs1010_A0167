def dict_intersect(dic1,dic2):
    dic = {}
    for key1 in dic1:
        for key2 in dic2:
            if key1 == key2:
                if dic1[key1] == dic2[key2]:
                    dic[key1] = dic1[key1]
    print(dic)

def hist(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput1 = input("Enter something: ")
    userInput2 = input("Enter another thing: ")
    dic1 = hist(userInput1)
    dic2 = hist(userInput2)
    dict_intersect(dic1,dic2)

main()
