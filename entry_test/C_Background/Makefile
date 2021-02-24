objects = main.o data_list.o input_handle.o
cc = gcc -g

main:$(objects)
	$(cc) -o main $(objects)

libdatalist.so:data_list.c data_list.h
	$(cc) -fPIC -shared -o libdatalist.so data_list.c

libinputhandle.so:input_handle.c input_handle.h
	$(cc) -fPIC -shared -o libinputhandle.so input_handle.c

main.o:main.c data_list.h input_handle.h
	$(cc) -c main.c
data_list.o:data_list.c data_list.h
	$(cc) -c data_list.c
input_handle.o:input_handle.c input_handle.h
	$(cc) -c input_handle.c


.PHONY:clean
clean:
	rm -rf *.o main
	rm -rf *.so

