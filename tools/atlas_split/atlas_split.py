# -*- coding: utf-8 -*-

# split atlas created by TexturePacker
# created by AdamWu(calvinmankor@gmail.com)

import os
import plistlib as plib
import cv2
import numpy as np

root = os.getcwd()
dst = root + "/result"
plist = "build_rubbish.plist"

def makedirs(dir):
	if os.path.exists(dir):
		return
	os.makedirs(dir)

def atlas_split(folder, filename, dst):
	data = plib.readPlist(os.path.join(folder,filename))
	n, e = os.path.splitext(filename)
	pngName = n + ".png" #对应的png名字
	print "Atlas", pngName
	colorImg = cv2.imread(os.path.join(folder, pngName), cv2.CV_LOAD_IMAGE_UNCHANGED)
	print colorImg.ndim
	print colorImg.shape

	#print data
	for k in data["frames"]:
		d, f = os.path.split(k)
		makedirs(os.path.join(dst, d))
		print "\n", k
		v = data["frames"][k]

		# source size
		sourceSize_v = v["sourceSize"]
		sourceSize = sourceSize_v[1:len(sourceSize_v)-1].split(',')
		width = int(sourceSize[0])
		height = int(sourceSize[1])
		print "size:", width, height

		# frame size
		frame = v["frame"]
		frame_list = frame[1:len(frame)].split(',')
		x = int(frame_list[0][1:len(frame_list[0])])
		y = int(frame_list[1][0:len(frame_list[1])-1])
		w = int(frame_list[2][1:len(frame_list[2])])
		h = int(frame_list[3][0:len(frame_list[3])-2])
		print "frame:", x, y, w, h

		# offset (trim mode:trim or crop)
		# just avaliable in mode crop
		offset = v["offset"]
		offset_list = offset[1:len(offset)-1].split(',')
		offset_x = int(offset_list[0])
		offset_y = int(offset_list[1])
		print "offset:", offset_x, offset_y

		# rotated
		rotated = v["rotated"]
		print "rotated:", rotated

		# source rect(can be calculated)
		source_rect = v["sourceColorRect"]
		source_rect_list = source_rect[1:len(source_rect)].split(',')
		source_x = int(source_rect_list[0][1:len(source_rect_list[0])])
		source_y = int(source_rect_list[1][0:len(source_rect_list[1])-1])

		# new img
		frameImg = np.zeros((height, width, 4), np.uint8)

		# calculate rect
		if rotated:
			ox = 0.5*(width - w) + offset_x
			oy = 0.5*(height - h) + offset_y
		else:
			ox = 0.5*(width - w) + offset_x
			oy = 0.5*(height - h) - offset_y

		for i in range(h):
			for j in range(w):
				if rotated:
					#frameImg[height-1-(source_y+i), source_x+j] = colorImg[y+j, x+i]
					frameImg[height-1-(oy+i), ox+j] = colorImg[y+j, x+i]
				else:
					#frameImg[source_y+i, source_x+j] = colorImg[y+i, x+j]
					frameImg[oy+i, ox+j] = colorImg[y+i, x+j]

		# write to file
		cv2.imwrite(os.path.join(dst, d, f), frameImg)

atlas_split(root, plist, dst)


