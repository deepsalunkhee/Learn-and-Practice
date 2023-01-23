import array
a=array.array("i",[])
n=int(input("Enter the size of array"))
for i in range(0,n):
    a.append(int(input("enter the the arrat element")))

for i in  range(0,int(n/2)):
    b=a[i]
    a[i]=a[n-i-1]
    a[n - i - 1]=b

for i in a:
    print(i)



