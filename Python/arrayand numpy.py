import numpy
r, c = map(int, input().split())
i = numpy.array([input().split() for _ in range(r)], int)
print (numpy.transpose(i))
print (i.flatten())
