function f1_2()
    y=0;
    n=input(' n = ');
    i=1:n
    y=1./(2*i-1)./3.^(2*i-1);
    y=sum(y);
    disp(y);