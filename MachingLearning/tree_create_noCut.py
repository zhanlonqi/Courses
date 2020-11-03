import numpy as np
def tree_create_noCut(D,A,classLabel):
    i=D.shape[0]
    myTree=f(D,A,classLabel,1)
    #print(myTree[0])
    return myTree


def f(D,A,classLabel,depth):
    D=D.tolist()
    num_data=np.shape(D)[0]
    if(num_data==0 or len(A)==0):
        label=classLabel['values'][1]
        if(decide(D)==0):
            label=classLabel['values'][0]
        return {'label':label,'class':'class','best':-1,'branch_num':0,'branchLabels':[],'branches':0}
    #首先决定这一层的特征
    A,feature=calculateGini(D,A,classLabel)
    share_same_feature=True
    last_data=D[0][feature['id']-1]
    for i in range(num_data):
        if(i==0):
            continue
        if(D[i][feature['id']-1]!=last_data):
            share_same_feature=False
    if(share_same_feature):
        label=classLabel['values'][1]
        if(decide(D)==0):
            label=classLabel['values'][0]
        return {'label':label,'class':'class','best':-1,'branch_num':0,'branchLabels':[],'branches':0}
    branch_num=feature['values'].size
    branches=[]
    for i in range(branch_num):
        temp=[]
        for ii in range(num_data):
            if D[ii][feature['id']-1]%10==i+1:
                temp.append(D[ii])
        temp=np.array(temp)
        branches.append(f(temp,A,classLabel,depth+1))
    return {'label':feature['name'],'class':'class','best':feature['id'],'branch_num':branch_num,'branchLabels':feature['values'],'branches':branches}


    
        
def decide(D):
    num=np.shape(D)[0]
    count=0
    for i in range(num):
        if D[i][6]==1:
            count+=1
    if(count>num/2):
        return 1
    else:
        return 0

            

def comp(e):
    return 1-e[0]

def GiniBase(D,classLabel):
    num_label=len(classLabel['values'])
    num_data=np.shape(D)[0]
    ans=1
    if(num_data==0):
        return 1
    for i in range(num_label):
        count=0
        for j in range(num_data):
            if D[j][6]==i:
                count+=1
        ans-=pow(count/num_data,2)
    return ans


def calculateGini(D,A,classLabel):
    print("")
    size=len(A)
    num_data=np.shape(D)[0]
    temp_D=[]
    Ginis=[]
    for i in range(size):
        num_att=A[i]['values'].size
        gini=0
        for j in range(num_att):
            count=0
            temp_D=[]
            for k in range(num_data):
                if D[k][i]%10==j+1:
                    count+=1
                    temp_D.append(D[k])
            gini+=count/num_data*GiniBase(temp_D,classLabel)
        Ginis.append((gini,i))
    Ginis.sort(key=comp)
    print(Ginis)
    next=Ginis.pop()[1]
    temp_A=A
    temp=temp_A.pop(next)
    return temp_A,temp
