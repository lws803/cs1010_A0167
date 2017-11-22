// Functions to try out different combinations of r element subsets 
// nCr 
void subset(int arr[], int data[], int start, int end, int index, int r)
{
    int j, i;
    if (index == r) {
        for (j = 0; j < r; j++)
            printf("%d ", data[j]);
        printf("\n");
        // Add any operations here to process data (subset)
        return;
    }
    for (i = start; i <= end && end - i + 1 >= r - index; i++)
    {
        data[index] = arr[i];
        subset(arr, data, i+1, end, index+1, r);
    }
}
 
void printsubset(int arr[], int n, int r)
{
    int data[r];
    subset(arr, data, 0, n - 1, 0, r);
}

// Permutation 

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int l, int r)
{
   int i;
   if (l == r)
     printf("%sn", a);
   else
   {
       for (i = l; i <= r; i++)
       {
          swap((a+l), (a+i));
          permute(a, l+1, r);
          swap((a+l), (a+i)); //backtrack
       }
   }
}

void print()
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1); 
    // Outputs: 
    /*
    ABC
    ACB
    BAC
    BCA
    CBA
    CAB
    */
}


