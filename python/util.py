import openslide
from openslide import ImageSlide, open_slide
from openslide.deepzoom import DeepZoomGenerator
from io import BytesIO
import base64
import sys

class PILBytesIO(BytesIO):
    def fileno(self):
        '''Classic PIL doesn't understand io.UnsupportedOperation.'''
        raise AttributeError('Not supported')

def getmetadata(file):
    slide = DeepZoomGenerator(open_slide(file))
    return slide.get_dzi('jpeg')

def getmppx(file):
    slide = open_slide(file)
    return slide.properties[openslide.PROPERTY_NAME_MPP_X]

def getmppy(file):
    slide = open_slide(file)
    return slide.properties[openslide.PROPERTY_NAME_MPP_Y]

def getTile(file,level,col,row):
    format = 'jpeg'
    slide = DeepZoomGenerator(open_slide(file))
    tile = slide.get_tile(level, (col, row))
    buf = PILBytesIO()
    tile.save(buf, format, quality=app.config['DEEPZOOM_TILE_QUALITY'])
    return base64.b64encode(buf.getvalue())

def runThis():
    if (len(sys.argv)<=1):
        print('err - no file')
    elif(len(sys.argv)==2):
        print(getmetadata(sys.argv[1]))
    elif(sys.argv[2] == "mpp-x"):
        print(getmppx(sys.argv[1]))
    elif(sys.argv[2] == "mpp-y"):
        print(getmppy(sys.argv[1]))
    elif(sys.argv[2] == "tile"):
        file = sys.argv[1]
        level = sys.argv[3] or 1
        col = sys.argv[4] or 1
        row = sys.argv[5] or 1
        print(getTile(file,level,col,row))
    else:
        print('err - bad command')

print (sys.argv)
runThis()
