#include <stdio.h>
#include <math.h>

double calcDistance(float,float,float,float);
void incentre(float,float,float,float,float,float,float*,float*);

int main(void){
	float Ax,Ay,Bx,By,Cx,Cy,newX,newY;
	
	printf("Coordinates of 1st vertex: ");
	scanf("%f %f",&Ax,&Ay);	
	printf("Coordinates of 2nd vertex: ");
	scanf("%f %f",&Bx,&By);	
	printf("Coordinates of 3rd vertex: ");
	scanf("%f %f",&Cx,&Cy);
	
	incentre(Ax,Ay,Bx,By,Cx,Cy,&newX,&newY);
	
	printf("Coordinates of incentre: (%0.2f, %0.2f)\n",newX,newY);
}

double calcDistance(float x1,float y1,float x2,float y2) {
	double len1,len2,hyp;
	
	len1 = x2 - x1;
	len2 = y2 - y1;
	hyp = sqrt(len1*len1 + len2*len2);
	return hyp;
}

void incentre(float Ax,float Ay,float Bx,float By,float Cx,float Cy,float *x,float *y){
	float oppC,oppA,oppB;	
		
	oppC = calcDistance(Ax,Ay,Bx,By);
	oppA = calcDistance(Bx,By,Cx,Cy);
	oppB = calcDistance(Cx,Cy,Ax,Ay);

	*x = (oppA*Ax+oppB*Bx+oppC*Cx)/(oppC+oppA+oppB);
	*y = (oppA*Ay+oppB*By+oppC*Cy)/(oppC+oppA+oppB);
}