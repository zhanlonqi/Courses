import numpy as np
def bp_create(x,t):
    (e,f)=x.shape
    l=t.shape[1]
    h=6
    learning_rate=0.01
    v=np.random.random((f,h))
    theta=np.random.random((1,h))
    w=np.random.random((h,l))
    gamma=np.random.random((l,1))
    
    for i in range(10):
        print("iteratoring : ",i)
        hidden_output=sigmoid(np.dot(x,v)-np.repeat(theta,e,axis=0))#e*h
        output=sigmoid(np.dot(hidden_output,w)-np.repeat(gamma,l,axis=0))
        error=output-t

        g=np.multiply(output,1-output)
        g=np.multiply(g,t-output)#e*l
        
        dw=learning_rate*np.dot(hidden_output.T,g)
        w=w+dw;

        E=np.multiply(hidden_output,1-hidden_output)*np.dot(g,w.T)#e*h
        dv=learning_rate*np.dot(x.T,E)
        v=v+dv;
        
        dgamma=-1*learning_rate*np.sum(g,axis=0)
        gamma=gamma-dgamma

        dtheta=-1*learning_rate*E
        theta=theta-np.sum(dtheta,axis=0)
        
        
        print(error)



        
        
        

def sigmoid(x):
    return 1/(1+np.exp(-1*x))

a=np.array([[1,2,3],[4,5,6]])
print(a[:,:-1])

