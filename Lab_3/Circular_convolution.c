/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/*
 * main.c
 */

#include <stdio.h>
#include "usbstk5515.h"

#define IR_length 12
#define In_length IR_length
#define tmp_l In_length

Int16 x[In_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 a[In_length];
Int16 x2[In_length];
Int16 array[tmp_l];
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;
Int16 coefs[IR_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 input;
Int16 output;


void linearbuff(void)
{
	int i,j,k;
	long int accumulator=0;
	static Int16 buffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
array[0]=0;
    a[0]=coefs[0];
    for(j=1;j<In_length;j++)                            //folding h(n) to h(-n)/
        a[j]=coefs[In_length-j];                        //Circular convolution/
    for(i=0;i<In_length;i++)
        array[0]+=x[i]*a[i];
    for(k=1;k<In_length;k++)
    {
        array[k]=0;                         //circular shift/
        for(j=1;j<In_length;j++)
            x2[j]=a[j-1];
        x2[0]=a[n-1];
        for(i=0;i<n;i++)
        {
            a[i]=x2[i];
            array[k]+=x[i]*x2[i];
        }
    }
    
 //*/
   (*outPtr)=((Int16)accumulator);	
}




main(void)
{
int j=0;
int u=0;
coeff = &coefs[0]; 	//coefs is coefficient of impulse response defined in fdacoefs_int.h
inPtr = &input;		//inPtr is a globally declared pointer to a Int16
outPtr = &output;
//	SYS_EXBUSSEL = 0x6100;
//    USBSTK5515_init( );
//temp_length=IR_length+In_length-1;

//static Int16 inbuffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(j<In_length) // loop 
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);

    	input=x[j];
    	//write your code for function call;

    	
      j=j+1;
    }
    linearbuff();
    
    while(u<tmp_l) // loop 
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);

        
        //write your code for function call;

        array[u]=output;
        printf("output=%d\n",array[u]);

      u=u+1;
    }
    return 0;
    
}

/*
 * FUNCTION:     Read input signal and write processed output signal
 *              using ProbePoints
 * PARAMETERS: none.
 * RETURN VALUE: none.
 */
/*static void dataInput()
{
    do data I/O
    return;
}*/