# Name: Tan Tze Guang
# Class: 13S28

#Question 1:

def count_values(dic):
    vallist = []
    for key in dic:
        if dic[key] not in vallist:
            vallist.append(dic[key])
    print(vallist)
    print(len(vallist))
    
#Question 2:

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

#Question 3:

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

#Question 4

def dict_intersect(dic1,dic2):
    dic = {}
    for key1 in dic1:
        for key2 in dic2:
            if key1 == key2:
                if dic1[key1] == dic2[key2]:
                    dic[key1] = dic1[key1]
    print(dic)

#Question 5

def rotate_pair(wordList):
    dic = {}
    for word1 in wordList:
        rotated_word = word1[::-1]
        for word2 in wordList:
            if word2 == rotated_word:
                dic[word1] = rotated_word
    return dic

def main():
    dic1 = {'a':2,'s':3,'d':43,'w':65,'n':99}
    dic2 = {'a':2,'d':43,'w':64}
    wordlist = ['desserts','bat','ergo','ogre','tab','madness','stressed']
    #count_values(dic1)
    #count_duplicates(dic2)
    #fetch_and_set(dic1,'a',100)
    #dict_intersect(dic1,dic2)
    dic3 = rotate_pair(wordlist)
    print(dic3)
    
main()
