# Mobile Computing Experiment 4 : CDMA



import random
def polar(key_a):
    for i in range(len(key_a)):


     if key_a[i] == 0 :


        key_a[i] = -1
    return key_a    
   
def check_ortho(key_a,key_b):
    for i in range(len(key_a)):


     if key_a[i] == 0 :


        key_a[i] = -1


     if key_b[i] == 0:


        key_b[i]= -1


#print(User_a,User_b)


    result = []


    for i,j in zip(key_a,key_b):


    # print(i*j)
     result.append(i*j)


    print("Resultant Code:",result)    


    result = sum(result)


    print(result)    


    if result ==0:


      print("It is orthogonal code")
      return True,key_a,key_b


    else:


      print("It's not an orthogonal code")
      return False
user_a_data = list(map(int,input("User1 data:")))
user_b_data = list(map(int,input("User2 data:")))
def random_chip():
    chippin = [(random.choice([0,1])) for i in range(0,8)]
    print(chippin)
    return chippin
chippin = random_chip()
while True:
 if check_ortho(chippin[chippi:],chippin[:chippi]):
    break
 else:
    chippin = random_chip()
chippi= len(chippin) //2    


def sender(user_data,chippin):
    result=[]
    l = len(user_data)
    parts = len(chippin) // l # Calculate the number of parts
    chippin_m= [chippin[i:i + parts] for i in range(0, len(chippin), parts)]
    for index,value in enumerate(chippin_m):
        res = []
        print(index,value)
        for j in range(0,len(value)):
            res.append(data[index]*value[j])
        result.append(res)  
    return result    




data = user_a_data + user_b_data
pol_chippin = polar(chippin)
pol_data = polar(data)
result = sender(pol_data,pol_chippin)
print("Encrypted_SIGNAL:",result)
#calculate cs
C=[]
for i in range(0,len(data),2):
    cc=[]
    result1 = result[i]
    result2= result[i+1]
    for a,b in zip(result1,result2):
        c=a+b
        cc.append(c)
    C.append(cc)  
print(C)        
#result = sender(data, chippin)
#print("RESULTING_SIGNAL:",result)


receiver= []
def receiver(key,c):
    result=[]
    for j in (c):
        res=[]
        for i in range(0,len(j)):
            res.append(key[i]*j[i])
        result.append(res)
    return result
def get_data(data):
 for i in data:
    if sum(i) >0:
        return 1
    else:
        return 0
ad=receiver(pol_chippin[chippi:],C)
bd =receiver(pol_chippin[:chippi],C)
ad=get_data(ad)    
bd=get_data(bd)
print(ad)
print(bd)
