function f4()
    x=linspace(-5, 5,21);
    y=linspace(0,10,31);
    [x,y]=meshgrid(x,y);
    z=cos(x).*cos(y).*exp(-1*sqrt(x.^2+y.^2)/4);
    subplot(2, 1, 1);
    surf(x,y,z);
    subplot(2,1,2);
    surfc(x,y,z);