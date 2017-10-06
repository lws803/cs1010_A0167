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


// To detect size of an unknown array 

int size (int arr[]) {
    int i = 0;
    while (arr[i] != '\0') {
        i++
    }
    
    return i;
}


