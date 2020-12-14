import numpy as np
import math
def k_means(D, k, U_index):
    D=np.array(D)

    num_iterate=5;
    clusters_old=np.array([[],[],[]])#[[],[],[]]

    center=np.array([D[U_index[0]],D[U_index[1]],D[U_index[2]]]);
    should_continue=True
    sum=0.0
    for i in range(num_iterate):
        clusters_new=[[],[],[]]
        #print(i,center)
        for j in range(D.shape[0]):
            min=0
            min_index=0
            for k in range(3):
                temp_dis=(D[j][0]-center[k][0])**2+(D[j][1]-center[k][1])**2
                #print('dis: ',j,k,math.sqrt(temp_dis))
                if(k==0 or temp_dis<min):
                    min=temp_dis
                    min_index=k
            #print('cluster: ',min_index)
            clusters_new[min_index].append(j)
        #print('cluster old: ',clusters_old)
        #print('cluster new: ',clusters_new)
        if(i==0):
            clusters_old=clusters_new;
        else:
            for j in range(3):
                if(len(clusters_new[j])!=len(clusters_old[j])):
                    break
                else:
                    for k in range(len(clusters_new[j])):
                        if clusters_new[j][k]!=clusters_old[j][k]:
                            break
                        elif(k==len(clusters_new[j])-1 and j==2):
                            should_continue=False
        if should_continue==False:
            break
        clusters_old=clusters_new
        center=np.array([np.mean(D[clusters_new[0]],axis=0),np.mean(D[clusters_new[1]],axis=0),np.mean(D[clusters_new[2]],axis=0)])
    return clusters_new,center

            
            

    