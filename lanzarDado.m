N-100:
v=rand (1,N);
X-zeros (1,N);
p=1/6;
figure (1)
plot (v,'.')
figure (2)
histogram (v)
title ('hist')
for i=1:N
if v(i)<p
X(i)=1;
else if(p<=v(i) && v(i)<2*p)
X(i)=2;
else if(2*p<=v(i) && v(i)<3*p)
X(i)=3;
else if(3*p<=v(i) && v(i)<4*p)
X(i)=4;
else if(4*p<=v(i) && v(i)<5*p)
X(i)=5;
else if(5*p<=v(i) && v(i)<6*p)
X(i)=6;
end
end
end
end
end
end
end

figure(3)
subplot(1,2,1)
plot(X,'.')
title('lanzamientos')
subplot(1,2,2)
histogram(X,'binmethod','integers')
title('histograma')
uno=find(X==1);
dos=find(X==2);
tres=find(X==3);
cuatro=find(X==4);
cinco=find(X==5);
seis=find(X==6);
//probabilidades

f1=length(uno)/N;
f2=length(dos)/N;
f3=length(tres)/N;
f4=length(cuatro)/N;
f5=length(cinco)/N;
f6=length(seis)/N;

y=1:6;
figure(4)
bar(y,[f1 f2 f3 f4 f5 f6])


