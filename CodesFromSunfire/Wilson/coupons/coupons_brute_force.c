#include "stdio.h"

typedef struct {
	int quantity;
	int price;
}coupon_t;


int minimumCost (coupon_t [], int , int ); 
int header (coupon_t [], int , int );

int main(int argc, char const *argv[])
{
	coupon_t coupons [4] = {{3, 10}, {2, 4}, {2, 4}, {1, 3}};


	// Min 8 
	printf("%d\n", header(coupons, 4, 4));


	return 0;
}

int header (coupon_t coupons[], int numCoupons, int units) {
	int i, price = 0;
	for (i = numCoupons-1; i >= 1; i--) {
		int internal = coupons[i].price;
		if (minimumCost(coupons, i-1, units - coupons[i].quantity != -1)) {
			internal += minimumCost(coupons, i-1, units - coupons[i].quantity); // If the next step is valid
		}
		// Compile the total price including the initial tries and then return the smallest one that is not equal to zero 
		if (price == 0 || price < internal) {
			price = internal;
		}
	}
	return price;
}

int minimumCost(coupon_t coupons[], int index, int units) {
	int i;
	// numcoupons = index 
	int unitsLeft = units - coupons[index].quantity; // Minus off the current quantity first 
	if (unitsLeft < 0) {
		return -1;
	}

	if (unitsLeft == 0) {
		return coupons[index].price;
	}
	int price = 0;
	// Else we will continue trying from the one below or the one after etc....
	for (i = index-1; i >= 0; i--) {
		if (minimumCost(coupons, i, unitsLeft) != -1) // If the next step is valid 
			// Add on to the price 
			price += minimumCost(coupons, i, unitsLeft);
	}
	return price;
}


