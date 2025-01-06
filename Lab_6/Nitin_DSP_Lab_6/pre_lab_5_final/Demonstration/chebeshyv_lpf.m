clc;
clf;
 
b = [0.347136126715185677760189264517975971103                                                        
0.25351149148747326167452342815522570163                                                         
0.142852598338356534535265041085949633271                                                        
0.062278739307890795817712614734773524106                                                        
0.996061648029559543182642755709821358323                                                        
                                      ]'
%t = linspace(-pi,pi,100);
t=0:0.01:2.5;
rng default  %initialize random number generator
x = square(10*t) + sin(1000*t) 


y = filter(b,1,x);
fig1 = figure(1);
plot(t,x)
hold on
plot(t,y)
legend('Input Data','Filtered Data')