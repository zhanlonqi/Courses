import numpy as np
def bp_create(x, t):
    num_hidden=10
    theta=np.random(t.shape).repeat(x.shape[0])
    gamma=np.random(num_hidden)
    v=np.random(x.shape[1],num_hidden);
    w=np.random(num_hidden,t.shape[1]);
    learning_rate=0.001;
    y_pred=np.zeros(t.shape)
    for i in range(1000):
        y_pred=w.T*(v.T*(x-theta)-gamma)


    return net, y, E  

def sigmoid(x):
    return 1/(1+math.exp(-1*x))

def sigmoid_derivative(x):
    return sigmoid(x)*(1-sigmoid(x));

def forward(x,t):
    return


