function f5()
    s=linspace(0, pi/2,100);
    t=linspace(0,1.5*pi,100);
    [s,t]=meshgrid(s,t);
    x=cos(s).*cos(t);
    y=cos(s).*sin(t);
    z=sin(s);

    subplot(2,2,1)
    mesh(x,y,z);
    title('origin version')


    subplot(2,2,2)
    surf(x,y,z);shading flat;
    title('flat version');

    subplot(2, 2, 3);
    surf(x,y,z);shading interp;
    title('interp version');