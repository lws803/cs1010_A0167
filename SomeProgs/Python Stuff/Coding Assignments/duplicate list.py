def count_duplicates(dic):
    Dlist = []
    for key in dic:
        if dic[key] >=2:
            Dlist.append(key)
    print(Dlist)
    print(len(Dlist))        
    
def main():
    dic = {'red':2,'green':2,"yellow":3,"blue":1}
    count_duplicates(dic)

main()
