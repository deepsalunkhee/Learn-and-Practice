# # Readig from file
# f=open('dummy1.txt','r')
# #printing the entire file
# print(f.read())
# #print line n char
# print(f.read(5))
# #print a line
# print(f.readline())


# #counting the number of lines
# f=open('dummy1.txt','r')
# count=0
#
# for x in f:
#     print(x)
#     count=count+1
#
# print("The numbe of the lines is ",count)
# f.close()


# #Adding  the content inthe file
# f=open('dummy1.txt','a')
# f.write("jhdfskahgfksaj6")

# #creating  a new file
# f1=open('dummy2.txt','x')
# f1.close()


# #Deleting a existing file
# import os
# if os.path.exists('dummy2.txt'):
#     r=os.remove('dummy2.txt')
#     print("file removed")
# else:
#     print("file does not exist")

# #removing a folder
# import os
# os.rmdir('dummy')

# #displaying all the files
# import os
# print(os.listdir('.'))

# #finding number of char
# f=open('dummy1.txt','r')
# count=0
# for x in f:
#     count=count-1;
#     for y in x:
#         count=count+1
# print(count)

# #finding number of words
# f=open('dummy1.txt','r')
# count=0
# for x in f:
#    count=count+1
#    for y in x:
#         if(y==' '):
#             count=count+1
# print(count)


