function f3()
    a=input('Please input 3 float numbers : ');
    ans=mean(a);
    ans=vpa(ans,ans/10+2)
    disp(ans)
    