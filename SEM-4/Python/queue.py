class queue:
    def __init__(self):
        self.queue=[]
    def isempty(self):
        if(self.queue==[]):
            return True
        else:
            return False
    def push(self,element):
        self.queue.append(element)
    def pop(self):
        return self.queue.pop(0)
    def peek(self):
        n=len(self.queue)
        return self.queue[0]
    def search(self,element):
        if self.isempty():
            return -1
        else:
            try:
                n=self.queue.index(element)
                return n
            except valueError:
                return -2
    def display(self):
        return self.queue


s=queue()
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
        print('queue:',s.display())
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
            print('queue is empty')
        elif p==-2:
            print('element is not present')
        else :
            print('Element is present at:',p)
    else:
        break