import numpy as np
def bp_pred(net ,x):
    x=x.T
    w=net["w"]
    v=net["v"]
    theta=net["theta"]
    gamma=net["gamma"]
    hidden_output=sigmoid(np.dot(x,v)-theta)#e*h
    output=sigmoid(np.dot(hidden_output,w)-gamma)
    return output.T 

def sigmoid(x):
    return 1/(1+np.exp(-1*x))
