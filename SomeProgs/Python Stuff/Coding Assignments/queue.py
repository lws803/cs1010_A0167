
def initialiseQueue(num):
    queue = []
    for i in range(num):
        queue.append('')
    size = 0
    front = 0
    rear = 0
    maximum = num
    return queue,size,front,rear,maximum

def insertQueue(queue,front,rear,size,maximum):
    newdata = input("Enter new data to be inserted: ")
    if rear == maximum:
        print("OVERFLOW")
        print()
        return queue,front,rear,size
    else:
        queue[rear] = newdata
        rear += 1
        size += 1
        print(queue)
        print("Front: {0}".format(front))
        print("Rear: {0}".format(rear))
        print()
        return queue,front,rear,size

def removeQueue(queue,front,rear,size):
    if rear == front:
        print("UNDERFLOW")
        print()
        return queue,front,rear,size
    else:
        queue[front] = ''
        front += 1
        size -= 1
        print(queue)
        print("Front: {0}".format(front))
        print("Rear: {0}".format(rear))
        print()
        return queue,front,rear,size

def main():
    num = eval(input("Enter number of items in queue: "))
    queue,size,front,rear,maximum = initialiseQueue(num)

    run = True
    while run:
        print("Choose : ")
        print("1) Insert an item")
        print("2) Remove an item")
        print("3) Print the list")
        print("4) Stop the program")
        choice = eval(input("Enter a choice: "))

        if choice == 1:
            queue,front,rear,size = insertQueue(queue,front,rear,size,maximum)
        elif choice == 2:
            queue,front,rear,size = removeQueue(queue,front,rear,size)
        elif choice == 3:
            print(queue)
            
            print("Front: {0}".format(front))
            print("Rear: {0}".format(rear))
            print("Size: {0}".format(size))
            print(maximum)
        elif choice == 4:
            run = False
        else:
            print("Not a valid input! \n")

main()
