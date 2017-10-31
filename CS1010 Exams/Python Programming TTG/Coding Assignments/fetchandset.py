def fetch_and_set(dic,newKey,newValue):
    if (dic.get(newKey)) != None:
        x = dic.get(newKey)
        dic[newKey] = newValue
        print(dic[newKey])
    else:
        raise KeyError("Unable to replace value for non-existant key")
    return x

    #found = False
    #for key in dic:
        #if key == newKey:
            #dic_new = {key:newValue}
            #print(key,"is found")
            #print(dic[key],'replaced by',newValue)
            #dic.update(dic_new)
            #found = True
    #if not found:
        #raise KeyError("Unable to replace value for non-existant key")
    #return dic

def hist(word):
    dic = {}
    for key in word:
        dic[key] = dic.get(key,0) + 1
    return dic

def main():
    userInput = input("Enter something: ")
    user = hist(userInput)
    newKey = input("Enter an alphabet: ")
    newValue = eval(input("Enter a replacement value: "))
    newDic = fetch_and_set(user,newKey,newValue)
    print(newDic)

main()
