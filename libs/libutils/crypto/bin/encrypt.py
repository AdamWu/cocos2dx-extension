# -*- coding: utf-8 -*-
import os

# aes 128 ecb
key = "adamwuadamwuadam"

root = os.getcwd()

resFolder = root + "/test"
dstFolder = root + "/result_encrypt"
cmdexe = root + "/encrypt.exe "

def encryptFolder(src, dst):
    print "Encrypt folder : " + src
    if not os.path.exists(dst):
        os.mkdir(dst)

    for d in os.listdir(src):
        if os.path.isdir(os.path.join(src, d)):
        	# deep encrypt
            encryptFolder(os.path.join(src, d), os.path.join(dst, d))
        else:
        	cmd = "%s %s %s %s" % (cmdexe, os.path.join(src, d), os.path.join(dst, d), key)
        	os.system(cmd)

encryptFolder(resFolder, dstFolder)


