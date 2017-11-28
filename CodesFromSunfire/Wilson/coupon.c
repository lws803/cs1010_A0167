#include "stdio.h"

typedef struct {
	int quantity;
	int price;
}coupon_t;


int minimumCost (coupon_t [], int , int ); 

int main(int argc, char const *argv[])
{
	coupon_t coupons [4] = {{3, 10}, {2, 4}, {2, 4}, {1, 3}};


	// Min 8 
	printf("%d\n", minimumCost(coupons, 4, 4));


	return 0;
}



// Find minimum cost 
// This function has to act as the head + compare values + terminate only when units == 0 
int minimumCost(coupon_t coupons[], int numCoupons, int units)
{
	int i, value_i, j=0;
	coupon_t newcoup[20];
	float record = 0, value;
	
	if (units == 0)							//while there are still units to be bought
		return 0;
	
	for(i = 0; i < numCoupons; i++)			//find the coupon with the best value
		value = (float)coupons[i].quantity/ coupons[i].price;
		if(value > record && coupons[i].quantity <= units)
		{
			value_i = i;
			record = value;
		}
	}
	
	for(i = 0; i < numCoupons; i ++)		//make a new list without the current coupon.
		if (i != value_i)
			newcoup[j++] = coupons[i];
		
	if (record == 0)						//cannot find a coupon with the required quantity.
		return -1;
	
	if (minimumCost(newcoup, numCoupons -1, units - coupons[value_i].quantity) == -1)
		return minimumCost(newcoup, numCoupons -1, units) ;		//UNable to find a suitable coupon redo the current number of units
	else
		return minimumCost(newcoup, numCoupons -1, units - coupons[value_i].quantity) + coupons[value_i].price ;
	}
