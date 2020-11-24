function f3()
    t=-10:0.01:10;
    x=(2+cos(t/2)).*cos(t);
    y=(2+cos(t/2)).*sin(t);
    z=sin(t/2);
    plot3(x,y,z);