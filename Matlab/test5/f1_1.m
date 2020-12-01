function f1_1()
    y=0;
    n=input('n :  ');
    for i=1:n
        y=y+1/(2*i-1)/3^(2*i-1);
    end
    disp(y)