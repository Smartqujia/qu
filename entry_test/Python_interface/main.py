#!/usr/bin/python
# coding=UTF-8

from ctypes import *
import types
from Tkinter import *
import  tkMessageBox as messagebox

class StructDatalist(Structure):
    pass

StructDatalist._fields_ = [('figure', c_char*1000),('next', POINTER(StructDatalist))]

def CtypeInit(listlib, inputlib):    
    listlib.create_link.restype = POINTER(StructDatalist)
    listlib.insert_link.argtypes = [POINTER(StructDatalist), c_char_p]
    listlib.delete_link.argtypes = [POINTER(StructDatalist), c_char_p]
    listlib.traversal_link.argtypes = [POINTER(StructDatalist)]
    listlib.sort_link.argtypes = [POINTER(StructDatalist)]
    
    inputlib.syntax_check.argtypes = [c_char_p, POINTER(c_int), POINTER(c_int)]
    inputlib.syntax_check.restype = c_int
    inputlib.valid_data_copy.argtypes = [c_char_p, c_int, c_int]
    
    pass

class Application(Frame):
    def __init__(self, master=None):
        Frame.__init__(self, master)
        self.pack()
        self.createWidgets()

    def createWidgets(self):
        self.nameInput = Entry(self)
        self.nameInput.pack()
        self.alertButton = Button(self, text='insert', command=self.insert)
        self.alertButton.pack()
        self.alertButton = Button(self, text='delete', command=self.delete)
        self.alertButton.pack()

    def insert(self):
        name = self.nameInput.get()
        input_str = 'a ' + name
        ret = inputlib.syntax_check(input_str, byref(start_bit), byref(stop_bit))
        inputlib.valid_data_copy(input_str, start_bit, stop_bit)
        listlib.insert_link(p, input_str)
        self.nameInput.delete(0, END)
        
    def delete(self):
        name = self.nameInput.get()
        input_str = 'd ' + name
        ret = inputlib.syntax_check(input_str, byref(start_bit), byref(stop_bit))
        inputlib.valid_data_copy(input_str, start_bit, stop_bit)
        listlib.delete_link(p, input_str)
        self.nameInput.delete(0, END)


#def 

if __name__ == '__main__':
    
    listlib = cdll.LoadLibrary("../C_Background/libdatalist.so")
    inputlib = cdll.LoadLibrary("../C_Background/libinputhandle.so")
    CtypeInit(listlib, inputlib)

    start_bit = c_int()
    stop_bit = c_int()
    ret = c_int

    p = listlib.create_link()

    '''
    app = Application()

    app.master.title('Hello World')

    app.mainloop()
    '''
    while True:
        input_str = raw_input("(null)@(null) QUJIA CLI> ")

        ret = inputlib.syntax_check(input_str, byref(start_bit), byref(stop_bit))
        #print '%s  %s' % (start_bit, stop_bit)
        #print input_str[0]
        #print ret 
        if 0 == ret:
            if 'a' == input_str[0]:
                inputlib.valid_data_copy(input_str, start_bit, stop_bit)
                print input_str
                listlib.insert_link(p, input_str)
                #print input_str

            elif 'd' == input_str[0]:
                inputlib.valid_data_copy(input_str, start_bit, stop_bit)
                print input_str
                listlib.delete_link(p, input_str)

            elif 'p' == input_str[0]:
                listlib.sort_link(p)
                listlib.traversal_link(p)
                print "\n",
            else:
                print 'Not expect!'

