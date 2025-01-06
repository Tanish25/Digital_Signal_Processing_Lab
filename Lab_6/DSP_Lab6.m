
%convolution using step by step input

clc;
clear all;
close all;

IR_length = 4;
In_length = 4;
tmp_l = IR_length + In_length - 1;
x = [1,2,2,1];
coefs=[1,2,3,4];
coefs_rev = zeros(1,IR_length);
array = zeros(1,tmp_l);
buffer = zeros(1,IR_length);
buffer_temp = zeros(1,IR_length);
i=0; j=0; k=0; n=0;
temp =0;
output=0;
m=0;


for k=1:1:IR_length
      buffer(k)=0;
end

for i=1:1:tmp_l+1
   
    if i<In_length
        input=x(i);
        output = convolution(input,IR_length,In_length,tmp_l,x,coefs,coefs_rev,array,buffer,buffer_temp,i,j,k,n,temp,output,m);
    else
        input=0;
        output = convolution(input,IR_length,In_length,tmp_l,x,coefs,coefs_rev,array,buffer,buffer_temp,i,j,k,n,temp,output,m);
    end
    array(i)=output;
    disp("output")
    disp(output)
end

function [m] = convolution(input,IR_length,In_length,tmp_l,x,coefs,coefs_rev,array,buffer,buffer_temp,i,j,k,n,temp,output,m)

 
    for i=1:1:IR_length
        coefs_rev(i)=coefs(IR_length+2 - 1 -i);
    end
    buffer_temp(1)=0;
    for n=2:1:IR_length
         buffer_temp(n)=buffer(n-1);
    end
    for n=1:1:IR_length
         buffer_temp(n)=buffer(n+1-1);
    end
    for n=1:1:IR_length
        disp("buffer array = ")
        disp(buffer(n))
    end
    buffer(1)=input;
    disp("buffer[0]= ")
    disp(buffer(1))
    
    for n=1:1:IR_length
        temp= temp + buffer(n)*coefs(n);
    end
    m=temp;
    temp=0;
    %return m;
    end

  

  %loop to give inputs
            