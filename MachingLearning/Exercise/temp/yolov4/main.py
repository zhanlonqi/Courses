import tkinter 
from PIL import Image,ImageTk
import pyautogui as pau
import os
import predict
import time

path='img/'
file_dir=os.listdir(path)
file_dir.sort()
c=len(file_dir)-1
img_chosen=-1
top=tkinter.Tk()
source=[]
img=tkinter.Label(top)
c=-1
#for i in range(20):
#    s='coil-20-proc/obj'+str((i+1))+'__0.png'
for i in file_dir:
    temp1=path+i
    source.append(temp1)

    
def f(me):
    global c
    global img_chosen
    global top
    global img
    img.config(image='')
    x,y=pau.position()
    x=x-top.winfo_x()
    y=y-top.winfo_y()
    x=int((x-50)/125)
    y=int((y-50)/125)
    img_chosen=(x+y*4)
    if(img_chosen<0 or img_chosen>len(file_dir)):
        img_chosen=-1
    elif img_chosen!=-1:
        c=predict.pred(source[img_chosen])
        image_jpg=Image.open('img_res/result.jpg')
        load_image=ImageTk.PhotoImage(image_jpg)
        img=tkinter.Label(top,image=load_image)
        img.image=load_image
        img.place(x=800,y=100)
    
    
def temp():
    global c
    if c<0 or c>19:
        image2=Image.open('null.png').resize((100,100))
        c=19
    else:
        image2=Image.open('VOCdevkit/obj%d'%(c+1)+'__1.jpg')
    load_image2=ImageTk.PhotoImage(image2)
    img2=tkinter.Label(top,image='')
    img2=tkinter.Label(top,image=load_image2)
    img2.image=load_image2
    img2.place(x=1000,y=800)
    
    img.after(50,temp)

top.geometry('1600x1000+10+10')
top.bind(sequence='<Button-1>',func=f)

label_text=tkinter.Label(top,text='Please choose the picture')

img.after(50,temp)
top.update()
n=0
print(img_chosen)
for s in source:
    image_jpg=Image.open(s).resize((120,120))
    load_image=ImageTk.PhotoImage(image_jpg)
    img2=tkinter.Label(top,image=load_image)
    img2.image=load_image
    img2.place(x=125*int(n%4)+50,y=125*int(n/4)+50)

    n=n+1


label_text.pack()

top.mainloop()