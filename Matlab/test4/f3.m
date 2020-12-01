function salary=f3(a)
if a<60
    salary=a*84-700;
    if(salary<0)
        salary=0;
        disp('杨白劳？');
elseif a>120
    salary=a*84+(a-120)*(84*0.15);
else
    salary=84*a;
end
end

