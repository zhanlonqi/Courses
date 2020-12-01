function   ans=f4()
    method=input('please input ');
    a=unidrnd(90)+10
    b=unidrnd(90)+10
    switch method
    case{'+'}
        ans=a+b;
    case{'-'}
        ans=a-b;
    case{'*'}
        ans=a*b;
    case{'/'}
        ans=a/b;
    otherwise
        ans='error';
    end;