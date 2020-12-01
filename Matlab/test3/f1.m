function ans=f1()
    a=input('please input the number ');
    numbers=[fix(a/1000),fix(mod(a/100,10)),fix(mod(a/10,10)),fix(mod(a,10))];
    numbers=numbers+7;
    numbers=mod(numbers,10);
    temp=numbers(1);
    numbers(1)=numbers(3);
    numbers(3)=temp;
    temp=numbers(2);
    numbers(2)=numbers(4);
    numbers(4)=temp;
    disp(numbers)