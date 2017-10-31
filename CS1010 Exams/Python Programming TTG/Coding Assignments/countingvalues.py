# Name: Tan Tze Guang
# Class: 13S28
# Date: 9 May 2013
# program: countvalues.py

def count_values(dic):
    vallist = []
    for key in dic:
        if dic[key] not in vallist:
            vallist.append(dic[key])
    print(vallist)
    print(len(vallist))

def count_duplicates(dic):
    inv = {}
    for key in dic:
        val = dic[key]
        if val not in inv:
            inv[val] = [key]
        else:
            inv[val].append(key)

    count = 0
    for key in inv:
        val = inv[key]
        if len(val)>=2:
            count += 1
            print(key,val)
    print(count,"values appear 2 or more times")

def main():
    dic = {'43':21,'32':21,'65':43,'54':43,'64':43}
    count_values(dic)
    count_duplicates(dic)

main()
