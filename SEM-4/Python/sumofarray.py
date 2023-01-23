import array
a=array.array('i',[])
n=int(input("Enter the size of array"))
for i in range(0,n):
    a.append(int(input("entr the  element")))
sum=0
for i in a:
    sum=sum+i
for i in a:
    print(i)

print("The sum is",sum)
