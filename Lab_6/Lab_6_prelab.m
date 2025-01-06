A=5;
B=3;
C=1;
f=3;
ff=25;
fff=120;
t=0:0.001:1;
x1=A*sin(2*pi*f*t);
x2=B*sin(2*pi*ff*t);
x3=C*sin(2*pi*fff*t);

plot(t,x1);
title('Multitone Plots ')
hold on;
plot(t,x2);
plot(t,x3);
hold off;
legend('x1','x2','x3');
xlabel('Time');
ylabel('Signals');
y=x1+x2+x3;
plot(t,y);
xlabel('Time');
ylabel('Net Signal');
title('Multitone signal');