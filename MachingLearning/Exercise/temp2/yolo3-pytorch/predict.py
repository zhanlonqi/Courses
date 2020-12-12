#-------------------------------------#
#       对单张图片进行预测
#-------------------------------------#
from yolo import YOLO
from PIL import Image
import sys
yolo = YOLO()

def pred(img):
    try:
        image = Image.open(img).resize((600,600))
    except:
        print('Open Error! Try again! ')
        return
    else:
        r_image,c = yolo.detect_image(image)
        #r_image.show()
        r_image.save(sys.path[0]+'/img_res/result.jpg')
    return c
        
