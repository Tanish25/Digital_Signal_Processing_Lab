/*
 * main.c
 */

#include <stdio.h>
#include "usbstk5515.h"

#define IR_length 12
#define In_length 12
#define tmp_l IR_length+In_length-1

Int16 x[In_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 array[tmp_l];
Int16 t[tmp_l];
void linearbuff();
Int16 *inPtr;
Int16 *outPtr;
Int16 *coeff;
Int16 coefs[IR_length] = {1, 1, 1, 2, 2, 2, 3, 3, 3, 1, 1, 1};
Int16 input;
Int16 output;


void linearbuff(void)
{
	int i,j,n,k;
	long int accumulator=0;
	static Int16 buffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// write convolution code here;

 for(i=0;i<(tmp_l);i++)

        {

                array[i] = 0;

                t[i]=0;

                x[In_length+i]=0;

        }

       

        for(i=0,j=(IR_length-1);i<(IR_length);i++,j--)

                t[i] = coefs[j];

 

        for(n=0;n<(tmp_l);n++)

        {

                for(k=0;k<=n;k++)

                        array[n] = (array[n])+((x[k])*(t[n-k]));

        }
 //*/
   (*outPtr)=((Int16)accumulator);	
}




main(void)
{
int y=0;
int z=0;
coeff = &coefs[0]; 	//coefs is coefficient of impulse response defined in fdacoefs_int.h
inPtr = &input;		//inPtr is a globally declared pointer to a Int16
outPtr = &output;
//	SYS_EXBUSSEL = 0x6100;
//    USBSTK5515_init( );
//temp_length=IR_length+In_length-1;

//static Int16 inbuffer[In_length]={0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while(y<In_length) // loop 
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);

    	input=x[y];
    	//write your code for function call;

    	
      y=y+1;
    }
    linearbuff();
//
    while(z<tmp_l) // loop 
    {
        /*  Read input data using a probe-point connected to a host file. */
      //printf("x=%d\n",x[j]);

        
        //write your code for function call;

        output=array[z];
        printf("output=%d\n",array[z]);

      z=z+1;
    }
    return 0;
    
}

/*
 * FUNCTION:     Read input signal and write processed output signal
 *              using ProbePoints
 * PARAMETERS: none.
 * RETURN VALUE: none.
 */

/*
static void dataInput()
{
    do data I/O
    return;
}
*/


/*

for(i=0;i<(xn+hn-1);i++)

        {

                outval[i] = 0;

                t[i]=0;

                xval[xn+i]=0;

        }

       

        for(i=0,j=(hn-1);i<(hn);i++,j--)

                t[i] = xval[j];

 

        for(n=0;n<(xn+hn-1);n++)

        {

                for(k=0;k<=n;k++)

                        outval[n] = (outval[n])+((xval[k])*(t[n-k]));

        }
*/
