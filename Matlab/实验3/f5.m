function f5()
    a=input('please input : ');
    temp=mod(fix(a/10),10);
    a=a-temp*10;
    disp(a);