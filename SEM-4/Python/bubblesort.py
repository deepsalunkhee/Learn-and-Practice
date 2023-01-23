
import array
n=int(input("entr the size of array"))
a=array.array("i",[])
for i in range(0,n):
    a.append(int(input("Entr the element" )))

for i in range(0,n):
    for j in range(0,n-1) :
        if(a[j]>a[j+1]):
            b=a[j]
            a[j]=a[j+1]
            a[j+1]=b

for i in a:
    print(i)




