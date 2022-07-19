#!/bin/python3

import math
import os
import random
import re
import sys



#
# Complete the 'fizzBuzz' function below.
#
# The function accepts INTEGER n as parameter.
#

def fizzBuzz(n):
    if(n%3==0 and n%5!=0):
        print("Fizz")
    elif(n%5==0 and n%3!=0):
        print("Buzz")
    elif(n%3==0 and n%5==0):
        print("FizzBuzz")
    else:
        print(n)
            
    
    
    # Write your code here

if __name__ == '__main__':
    n = int(input().strip())
    
    for i in range(1 ,n+1):
        fizzBuzz(i)