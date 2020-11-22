import numpy as np

def bp_create(X,T):  
    (e,f)=X.shape
    l=T.shape[1]
    h=6
    num_iterator=4000
    learning_rate=0.01
    v=np.random.random((f,h))
    theta=np.random.random((1,h))
    w=np.random.random((h,l))
    gamma=np.random.random((1,l))
    Error=np.zeros((num_iterator,1))
    for i in range(num_iterator):
        for k in range(e):
            x=np.zeros((1,f))
            x[0,:]=X[k]
            t=T[k,:]
            #print("training sample ",x)
            #print("label",t)
        
            hidden_output=sigmoid(np.dot(x,v)-theta)#e*h
            output=sigmoid(np.dot(hidden_output,w)-gamma)
            error=output-t

            g=np.multiply(output,1-output)
            g=np.multiply(g,t-output)#e*l

            dw=learning_rate*np.dot(hidden_output.T,g)
            w=w+dw;

            dgamma=-1*learning_rate*g
            gamma=gamma+dgamma
            E=np.multiply(hidden_output,1-hidden_output)*np.dot(g,w.T)#e*h
            dv=learning_rate*np.dot(x.T,E)
            v=v+dv;

            dtheta=-1*learning_rate*E
            theta=theta+dtheta

            
        Error[i]=np.array([error])

    
    #print(Error)
    net={"w":w,"theta":theta,"v":v,"gamma":gamma}
    return net,0,Error
    
        
        
        

def sigmoid(x):
    return 1/(1+np.exp(-1*x))

#x=np.array([[1,1],[0,0],[1,0],[0,1]])
#y=np.array([[1,1,0,0]]).T
#bp_create(x,y)
