function f2_3()
    x=-10:0.1:10;
    y1=x.^2;
    y2=cos(2*x);
    y3=y1.^y2;
    subplot(2, 2, 1)
    bar(x,y1,'b');
    hold on
    bar(x,y2,'g');
    hold on
    bar(x,y3,'r');

    subplot(2,2,2)
    stairs(x,y1,'r');
    hold on
    stairs(x,y2,'g');
    hold on
    stairs(x,y3,'b');

    subplot(2,2,3)
    fill(x,y1,'r');
    hold on
    fill(x,y2,'g');
    hold on
    fill(x,y3,'b');
