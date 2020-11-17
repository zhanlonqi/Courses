function grade=f2()
    a=input('please input grade ')
    if(a>=0&a<=100)
        switch a/10
            case {9,10}
                grade='A';
            case {8}
                grade='B';
            case {7}
                grade='C';
            case{6}
                grade='D';
            case{(0:5)}
                grade='E';        
        end
    
    else 
        grade='error';
    end

