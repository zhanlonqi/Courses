function f1_2()
    x=-5:0.01:5;
    length(x)
    y=(x+sqrt(pi))/exp(2).*(x<=0)+1/2*log(x+sqrt(1+x.^2)).*(x>0);
    plot(x,y);
end

