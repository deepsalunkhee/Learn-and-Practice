
model small
.stack 100H
.data
arr db 2h,4h,5h,11h,10h 
len dw $-arr
smal db ? 
ends
.code
START: mov ax,@data 
mov ds,AX 
mov cx,len
lea si,arr 
mov al,[si] 
mov smal,al
Y: mov al,[si]
cmp al,smal 
jg X
mov smal,al
X: inc si
loop Y
mov AH,4CH 
int 21H
end start
end
