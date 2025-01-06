Extra Code:(Convolution part)
#define IR_length 11 //Length of filter coeffs
#define In_length 51//length of input signal
#define tmp_l IR_length+In_length-1

Int16 x[In_length]={};
Int16 coefs[IR_length]={};
Int16 coefs_rev[IR_length]={};
Int16 array[tmp_l]={0};
Int16 buffer[IR_length]={0};
Int16 buffer_temp[IR_length]={0};
int i=0,j=0,k=0,n=0;
Int16 temp=0;
Int16 output=0;
Int16 m=0;
/*Include in main
	for(k=0;k<IR_length;k++)
	{
		buffer[k]=0;
	}
	*/
Int16 convolution(Int16 input)
{

/*Reversal function- include in main
	for(i=0;i<IR_length;i++)
	{
		coefs_rev[i]=coefs[IR_length-1-i];
	}
*/
		buffer_temp[0]=0;
		for(n=1;n<IR_length1;n++)
		{
			buffer_temp[n]=buffer[n-1];
		}
		for(n=0;n<IR_length;n++)
		{
			
			buffer[n]=buffer_temp[n];
		}
		buffer[0]=input;
		for(n=0;n<IR_length;n++)
		{ 
			temp+= buffer[n]*coefs[n];
		}
		m=temp;
		temp=0;
		return m;
	
}

/*loop to give inputs
for(i=0;i<tmp_l;i++)
{
	if(i<In_length)
	{
			output=convolution(x[i]);
	}
	else
	{
			output=convolution(0);
	}
	
	array[i]=output;

}



Simplified C Code:
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define IR_length 4 //Length of filter coeffs
#define In_length 4//length of input signal
#define tmp_l IR_length+In_length-1
int x[In_length]={1,2,2,1};
int coefs[IR_length]={1,2,3,4};
//Int16 coefs_rev[IR_length]={0};
int array[tmp_l]={0};
int buffer[IR_length]={0};
int buffer_temp[IR_length]={0};
int i=0,j=0,k=0,n=0;
int temp=0;
int output=0;
int m=0;

int convolution(int input)
{

/*Reversal function- include in main
	for(i=0;i<IR_length;i++)
	{
		coefs_rev[i]=coefs[IR_length-1-i];
	}
*/
	//for(j=0; j<tmp_l ;j++)
	//{	
	    buffer_temp[0]=0;
		for(n=1;n<IR_length;n++)
		{
			
			buffer_temp[n]=buffer[n-1];
		}
		for(n=0;n<IR_length;n++)
		{
			
			buffer[n]=buffer_temp[n];
		}
		
		for(n=0;n<IR_length;n++)
		{
			printf("buffer array=%d\t",buffer[n]);
			
		}
		printf("\n");
		{
			buffer[0]=input;
		}
	
		printf("buffer[0]= %d\n",buffer[0]);
		for(n=0;n<IR_length;n++)
		{ 
			temp+= buffer[n]*coefs[n];
		}
		m=temp;
		temp=0;
		return m;
		
		//printf("array[j]= %d\n",array[j]);
	//}
}

int main()
{
	for(k=0;k<IR_length;k++)
	{
		buffer[k]=0;
	}

/*Include in main
	for(k=0;k<IR_length;k++)
	{
		buffer[k]=0;
	}
	*/

//loop to give inputs
for(i=0;i<tmp_l;i++)
{
	if(i<In_length)
	{
			output=convolution(x[i]);
	}
	else
	{
			output=convolution(0);
	}
	
	array[i]=output;
	printf("output= %d\n",output);

}

    return 0;
}
