function ans=f5()
    mat=input('Please input a 5*6 matrix :');
    n=input('please input n : ');
    if(n>0&n<=6)
        ans=mat(n,:);
    elseif(n>5)
        ans=mat(5,:);
    else
        ans='error';
    end

        