function f2_1()
    x=-10:0.1:10;
    y1=x.^2;
    y2=cos(2*x);
    y3=y1.^y2;
    plot(x,y1, '-r');
    hold on;
    plot(x,y2,'-g');
    hold on;
    plot(x,y3,'-b');