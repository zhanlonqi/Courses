#-------------------------------------#
#       调用摄像头检测
#-------------------------------------#
from yolo import YOLO
from PIL import Image
import numpy as np
import cv2
import time
import tkinter
from PIL import Image,ImageTk
yolo = YOLO()
    # 调用摄像头
capture=cv2.VideoCapture(0)
def vid(top,img):
 # capture=cv2.VideoCapture("1.mp4")
    fps = 0.0
    for i in range(1):
        t1 = time.time()
        # 读取某一帧
        ref,frame=capture.read()
        # 格式转变，BGRtoRGB
        frame = cv2.cvtColor(frame,cv2.COLOR_BGR2RGB)
        # 转变成Image
        frame = Image.fromarray(np.uint8(frame))

        # 进行检测
        #frame = np.array(yolo.detect_image(frame))
        frame,c=yolo.detect_image(frame.resize((600,600)))
        # RGBtoBGR满足opencv显示格式
        #frame = cv2.cvtColor(frame,cv2.COLOR_RGB2BGR)

        #fps  = ( fps + (1./(time.time()-t1)) ) / 2
        #print("fps= %.2f"%(fps))
        #frame = cv2.putText(frame, "fps= %.2f"%(fps), (0, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)
        
        #cv2.imshow("video",frame)
        load_image=ImageTk.PhotoImage(frame)
        img=tkinter.Label(top,image=load_image)
        img.image=load_image
        img.place(x=800,y=100);
    return c

        

        #c= cv2.waitKey(1) & 0xff 
        #if c==27:
         #   capture.release()
          #  break
