model small
.stack 100H
.data
arr db 2h,4h,5h,11h,10h 
len dw $-arr
larg db ? 
ends
.code
START: mov ax,@data 
mov ds,AX 
mov cx,len
lea si,arr 
mov al,[si] 
mov larg,al
Y: mov al,[si]
cmp al,larg 
jng X
mov larg,al
X: inc si
loop Y
mov AH,4CH 
int 21H
end start
end
