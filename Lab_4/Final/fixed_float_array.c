
/*
 _____ _____     ______  ___________   _       _      
|_   _|_   _|    |  _  \/  ___| ___ \ | |     | |     
  | |   | |______| | | |\ `--.| |_/ / | | __ _| |__   
  | |   | |______| | | | `--. \  __/  | |/ _` | '_ \  
  | |  _| |_     | |/ / /\__/ / |     | | (_| | |_) | 
  \_/  \___/     |___/  \____/\_|     |_|\__,_|_.__/  
*/




//Own wxample:
#include "stdio.h"
#include "usbstk5515.h"
#include "intrindefs.h"

//floating point implemetation variables
float x_floating[100]; //input array
float y_floating[100]; //result array

void compute_floating(float A, float B)
{
	int i;
//	float A = 4.3;
//	float B = 5.5;
	for (i=2000;i<2100;i++) 
	x_floating[i-2000]=i;
	
	for (i=0;i<100;i++)
	y_floating[i]=A*x_floating[i] + B;
	return;
}

//fixed point implemetation variables
short int x[100]; 
short int y[100]; 
long int temp1; 
short int temp2; 
short int xf[100];

void compute_fixed(void)
{
	int i;
	short int AF = 17613;
	/* 
	Integer Word length of A is 3 hence AF is computed as 
	A * 2 ^ (15-3) i.e. A * 4096
	i.e. 17613 is the best representation of 4.3 in 16-bit word 
	*/
	short int BF = 22528;
	/* 
	Integer Wordlength of B is 2 hence BF is computed as 	
	B * 2 ^ (15-3) i.e. B * 4096 
	*/ 
	
	for (i=2000;i<2100;i++) 
	{
		x[i-2000]=i;
		xf[i-2000]=x[i-2000] <<3; /* IWL of x is 12 so shifted left by 3 bits to normalize*/ 
	}
	/*General remark: an IWL of "M" can represent a max mag value of (2^M - 1)*/ 
	/*The 16-bit word is divided as: 1 sign bit + M IWL bits + remaining frac. bits 
 	i.e. the max magnitude M=15 number is 32767 = > we represent +/- 32767  
	(in 2's complement, one more number e.g. -32768).*/ 
	for(i=0;i<100;i++)
	{
		temp1 = _lsmpy(AF,xf[i]);
		//Multiply AF and xf[i] to return 32 bit integer 
		/* _lsmpy multiplies given two operands and shift the result left by 1. 
		 * Produces saturated 32 bit result.*/
		temp2 = (extract_h(temp1));
		/*extract upper 16 bits of the result. The IWL of temp2 will be IWL(A) + IWL(x) i.e. 13 */
		y[i] = ((temp2<<1) + (BF>>12))>>1; //final expression
		/*yf[i] = (temp2<<1) + (BF>>12) --- (1)
		y[i] = yf[i] >> 1;*/
	}
	return;
}



main(void)
{
	float A = 4.3;
	float B = 5.5;
	USBSTK5515_init( );
	compute_floating(A,B);
	compute_fixed();
	return 0;
} 
long int _lsmpy(short int a, short int b)
{
return (a*b)>>1;
}
short int extract_h(long int v)
{
return v<<16;
}
