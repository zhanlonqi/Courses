function f2_2()
    x=-10:0.1:10;
    y1=x.^2;
    y2=cos(2*x);
    y3=y1.^y2;
    subplot(2,2,1);
    plot(x,y1, '-r');
    subplot(2,2,2);
    plot(x,y2,'-g');
    subplot(2,2,3)
    plot(x,y3,'-b');