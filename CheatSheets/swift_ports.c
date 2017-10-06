/*
All arrays are used for integers in this example
*/

// To detect if an array contains an element

int contains(int arr[], int size, int element) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == element) {
            return 1;
        }
    }
    return 0;
}


// To detect size of an unknown sized array 

int size (int arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        i++;
    }
    
    return i;
}


// To insert a new element into a theoretically infinite array (size) 

int insert (int arr[], int element, int atIndex, int size) {
    int i;
    for (i = size-1, i >= atIndex, i--) {
        arr[i+1] = arr[i];
    }
    arr[atIndex] = element;
    size++;
    return size;
}

// To remove an element from a specified index

int remove (int arr[], int atIndex, int size) {
    int i;
    for (i = atIndex; i < size; i++) {
        arr[i] = arr[i+1];
    }
    size--;
    return size;
}
