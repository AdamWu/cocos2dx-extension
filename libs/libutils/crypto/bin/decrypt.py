# -*- coding: utf-8 -*-
import os

# aes 128 ecb
key = "adamwuadamwuadam"

root = os.getcwd()

resFolder = root + "/result_encrypt"
dstFolder = root + "/result_decrypt"
cmdexe = root + "/decrypt.exe "

def decryptFolder(src, dst):
    print "Decrypt folder : " + src
    if not os.path.exists(dst):
        os.mkdir(dst)

    for d in os.listdir(src):
        if os.path.isdir(os.path.join(src, d)):
        	# deep decrypt
            decryptFolder(os.path.join(src, d), os.path.join(dst, d))
        else:
            cmd = "%s %s %s %s" % (cmdexe, os.path.join(src, d), os.path.join(dst, d), key)
            os.system(cmd)

decryptFolder(resFolder, dstFolder)


