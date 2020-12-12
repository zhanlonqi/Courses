# -*- mode: python ; coding: utf-8 -*-

block_cipher = None

SETUP_DIR='/home/zhan/work/Courses/MachingLearning/Exercise/temp2/yolo3-pytorch'

a = Analysis(['main.py',
		'yolo.py',
		'predict.py',
		'video.py'],
             pathex=['/home/zhan/work/Courses/MachingLearning/Exercise/temp2/yolo3-pytorch'],
             binaries=[],
             datas=[(SETUP_DIR+'//img','img'),(SETUP_DIR+'//img_res','img_res'),(SETUP_DIR+'//model_data','model_data'),
             (SETUP_DIR+'//VOCdevkit','VOCdevkit')],
             hiddenimports=['tkinter','PIL','pyautogui','os','time','numpy','cv2','torch'],
             hookspath=[],
             runtime_hooks=[],
             excludes=[],
             win_no_prefer_redirects=False,
             win_private_assemblies=False,
             cipher=block_cipher,
             noarchive=False)
pyz = PYZ(a.pure, a.zipped_data,
             cipher=block_cipher)
exe = EXE(pyz,
          a.scripts,
          [],
          exclude_binaries=True,
          name='main',
          debug=False,
          bootloader_ignore_signals=False,
          strip=False,
          upx=True,
          console=False )
coll = COLLECT(exe,
               a.binaries,
               a.zipfiles,
               a.datas,
               strip=False,
               upx=True,
               upx_exclude=[],
               name='main')
