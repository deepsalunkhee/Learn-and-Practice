from pydoc import plain
import random
def gameover(Player,Computer):
    if(Player==Computer):
        return None
    elif Computer=='s':
        if Player=='w':
            return False
        elif Player=='g':
            return True
    elif Computer=='w':
        if Player=='g':
            return False
        elif Player=='s':
            return True
    elif Computer=='g':
        if Player=='s':
            return False
        elif Player=='w':
            return True

print("Computer turn: Snake(s),Water(w) or Gun (g)?:")
randomNo=random.randint(1,3)
if randomNo==1:
    Computer='s'
elif randomNo==2:
    Computer='w'
elif randomNo==1:
    Computer='g'

Player=input("Your Turn: Snake(s),Water(w) or Gun (g)?:")

a=gameover(Computer,Player)

print("Computer chose",Computer)
print("You chose",Player)

if a==None:
    print("the game is tie")
elif a:
    print("You won the Mathch")
else:
     print("You loss the Mathch")


       
        
        
    
