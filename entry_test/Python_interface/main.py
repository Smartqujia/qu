
# coding=UTF-8

from ctypes import *
import types

class StructDatalist(Structure):
    pass

StructDatalist._fields_ = [('figure', c_char*1000),('next', POINTER(StructDatalist))]


if __name__ == '__main__':
    listlib = cdll.LoadLibrary("../C_Background/libdatalist.so")
    inputhandle = cdll.LoadLibrary("../C_Background/libinputhandle.so")

    listlib.create_link.restype = POINTER(StructDatalist)
    p = listlib.create_link()