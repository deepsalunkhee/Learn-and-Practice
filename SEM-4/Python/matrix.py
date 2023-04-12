import numpy as np
m=np.matrix('1 2 3;3 4 5;4 5 6')
print(np.diagonal(m))
m1=np.matrix('1 2 3; 9 8 7;1 2 3')
m2=np.matrix('2 4 5; 8 2 1;2 4 3')
m3=m1+m2
print(m3)
m4=m1*m2
print(m4)

print(m)