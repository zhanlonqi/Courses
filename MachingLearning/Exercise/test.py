import Tkinter 
from PIL import Image,ImageTk
import pyautogui as pau

img_chosen=-1
top=Tkinter.Tk()
source=[]
for i in range(20):
    s='coil-20-proc/obj'+str((i+1))+'__0.png'
    source.append(s)
def callback(event):
    global img_chosen
    global top
    x,y=pau.position()
    x=x-top.winfo_x()
    y=y-top.winfo_y()
    x=(x-50)/120
    y=(y-50)/120
    img_chosen=x+y*4
    if(img_chosen<0 or img_chosen>20):
        img_chosen=-1
    if img_chosen!=-1:
        image_jpg=Image.open(source[img_chosen])
        load_image=ImageTk.PhotoImage(image_jpg)
        img=Tkinter.Label(top,image=load_image)
        img.image=load_image
        img.place(x=800,y=100);


top.geometry('1200x800+10+10')
top.bind('<Button-1>',callback)

label_text=Tkinter.Label(top,text='Please choose the picture')




n=0
print(img_chosen)
for s in source:
    image_jpg=Image.open(s)
    load_image=ImageTk.PhotoImage(image_jpg)
    img=Tkinter.Label(top,image=load_image)
    img.image=load_image
    img.place(x=120*(n%4)+50,y=120*(n/4)+50)
    n=n+1;



label_text.pack()




top.mainloop()