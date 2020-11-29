import numpy as np
import cvxopt
import scipy.io as scio
from sklearn import preprocessing

data = preprocessing.MinMaxScaler().fit_transform(scio.loadmat('watermelon_3a.mat')['watermelon_3a']) * 2 - 1
X = data[1:16, 0:2]
y = data[1:16, 2, None]
bias = 0
C = 1.0
sigma = 1.0
support_vector_threhold=1e-5
kernel = lambda X, y: np.exp(-np.sqrt(np.linalg.norm(X-y) ** 2 / (2 * sigma ** 2)))

num, label = X.shape
k = np.zeros((num, num))
# 空间映射
for i, xi in enumerate(X):
    for j, xj in enumerate(X):
        k[i, j] = kernel(xi, xj)
    
# 二次规划
P = cvxopt.matrix(np.outer(y, y)*k)
q = cvxopt.matrix(-1 * np.ones(num))

G_std = cvxopt.matrix(np.diag(np.ones(num)*-1))
h_std = cvxopt.matrix(np.zeros(num))

# a_i \leq C
G_slack = cvxopt.matrix(np.diag(np.ones(num)))
h_slack = cvxopt.matrix(np.ones(num) * C)

G = cvxopt.matrix(np.vstack((G_std, G_slack)))
h = cvxopt.matrix(np.vstack((h_std, h_slack)))

#y = y.reshape((1, y.shape[0]))
A = cvxopt.matrix(y, (1, num))
b = cvxopt.matrix(0.0)

solution = cvxopt.solvers.qp(P, q, G, h, A, b)
    # lagr multiplier
lagr = np.ravel(solution['x'])

def predict(x):
    result = bias
    for z_i, x_i, y_i in zip(support_lagr, support_vectors, support_vector_tags):
        result += z_i * y_i * kernel(x_i, x)
    if result > 0:
        return 1
    else:
        return 0

support_vectors_id = lagr > support_vector_threhold
support_lagr = lagr[support_vectors_id]
support_vectors = X[support_vectors_id]
support_vector_tags = y[support_vectors_id]

bias = np.mean([y_k - predict(x_k) for (y_k, x_k) in zip(support_vector_tags, support_vectors)]) # 计算偏差

pred = predict(np.array([0.70998117, 1]).reshape(1, 2)) # [0, :] 结果及预测均为1
print(pred)
pred = predict(np.array([0.79284369, -0.70813397]).reshape(1, 2)) # [16, :] 结果及预测均为0
print(pred)