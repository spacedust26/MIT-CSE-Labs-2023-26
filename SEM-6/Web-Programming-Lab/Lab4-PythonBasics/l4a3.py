# Write a python program to multiply two matrices
X = [[2,4,6],
    [8,10,12],
    [14,16,18]]
Y = [[1,2,3,4],
    [5,6,7,8],
    [9,10,11,12]]
result = [[0,0,0,0],
         [0,0,0,0],
         [0,0,0,0]]

for i in range(len(X)):
   for j in range(len(Y[0])):
       for k in range(len(Y)):
           result[i][j] += X[i][k] * Y[k][j]

for r in result:
   print(r)
