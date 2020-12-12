import PIL
import os
import sys
from PIL import Image
file_dir=os.listdir(sys.path[0]+'/img')
for i in file_dir:
    im=Image.open(sys.path[0]+'/img/'+i)
    im.thumbnail((100,100))
    im.save(sys.path[0]+'/img_thumbnail/'+i)