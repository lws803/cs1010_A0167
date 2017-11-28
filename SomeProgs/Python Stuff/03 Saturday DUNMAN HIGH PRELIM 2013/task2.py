def recursive_binary_search(array,item,highest,lowest):
    if lowest > highest:
        print("Unable to find the item.")
    else:
        mid = (highest+lowest) // 2
        if array[mid] == item:
            print("Found {0} in position {1}".format(item,mid))
            return
        elif array[mid] < item:
            recursive_binary_search(array,item,mid -1,lowest)
        else:
            recursive_binary_search(array,item,highest,mid+1)

def quicksort(array,left,right):
    low = left
    high = right
    seperator = array[(left + right) // 2]
    while low <= high:
        while array[low] < seperator:
            low += 1
        while array[high] > seperator:
            high -= 1

        if low <= high:
            array[low],array[high] = array[high],array[low]
            low += 1
            high -= 1
    if left <high:
        quicksort(array,left,high)
    if low < right:
        quicksort(array,low,right)
        
def main():
    X = []
    for i in range(20):
        X.append(0)
    X[0] = 999
    X[1] = 850
    X[2] = 812
    X[3] = 770
    X[4] = 733
    X[5] = 634
    X[6] = 511
    X[7] = 508
    X[8] = 500
    X[9] = 497
    X[10] = 413
    X[11] = 406
    X[12] = 389
    X[13] = 310
    X[14] = 292
    X[15] = 251
    X[16] = 107
    X[17] = 88
    X[18] = 53
    X[19] = 13

    recursive_binary_search(X,406,19,0)
    quicksort(X,0,19)
    print(X)
    
main()
