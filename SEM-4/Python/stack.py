class stack:
    def __init__(self):
        self.stack=[]
    def isempty(self):
        if(self.stack==[]):
            return True
        else:
            return False
    def push(self,element):
        self.stack.append(element)
    def pop(self):
        self.stack.pop()
    def peek(self):
        n=len(self.stack)
        return self.stack[n-1]
    def search(self,element):
        if self.isempty():
            return -1
        else:
            try:
                n=self.stack.index(element)
                return n
            except valueError:
                return -2
    def display(self):
        return self.stack


s=stack()
choice=0

while choice<5:
    print('1-Push Element')
    print('2-Pop Element')
    print('3-Peek Element')
    print('4-Search Element')
    print('5-Exit')

    choice=int(input("Enter the choice"))
    if(choice==1):
        element=int(input('Enter element'))
        s.push(element)
        print('Stack:',s.display())
    elif choice==2:
        element=s.pop()
        if(element==-1):
            print('ELEMENT IS EMPTY')
        else :
            print('Popped element is :',element)
    elif choice==3:
        element=s.peek()
        print('element at top:',element)
    elif choice==4:
        element=int(input('Enter element to be searched'))
        p=s.search(element)
        if p==-1:
            print('stack is empty')
        elif p==-2:
            print('element is not present')
        else :
            print('Element is present at:',p)
    else:
        break