## Some tips to tracing
1. Check for loops such as for loops and while loops 
2. Get a rough idea of the total number of iterations to expect. (eg. 12*12) iterations 
3. Draw a table for each loop variable i.e i, j or k. 
4. Write down beside it everytime a variable or element changes. 

```c
for (i = 0; i < 5; i++){
	for (j = 0; j < 5; j++) {
		if (i + j < 4) {
			temp = arr[i][j];
			arr[i][j] = arr[4-j][4-i];
			arr[4-j][4-i] = temp;
		}
	}
}
```
![img_3326](https://user-images.githubusercontent.com/7874219/33268111-ea2e7d96-d3b6-11e7-9ae2-d06a668f0e14.png)


## Tracing recursion 
1. Trace the first few functions by spreading it out like a tree. 
2. Trace their return values when the function terminates and trace upwards the tree
3. Apply memoisation (if eg. f(2) is being called again, there's no need tot trace cause we already know what it is). 

```c
int f(int n) {
	if (n <= 3)
		return n;
	else 
		return 3*f(n-1) - 2*f(n-2);
}
```
![img_3327](https://user-images.githubusercontent.com/7874219/33268269-99e8d65a-d3b7-11e7-8682-afe734d7d269.png)
