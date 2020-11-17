function grade=f2()
    a=input('please input grade : ');
    if a>100|a<0
        grade='error';
    elseif a>=90
        grade='A'
    elseif a>=80
        grade='B'
    elseif a>=70
        grade='C'
    elseif a>=60
        grade='D'
    else
        grade='E'
end
