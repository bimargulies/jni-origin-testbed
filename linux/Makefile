all: libsl1.so libsl2.so driver driverdlo


libsl2.so: sl2.c
	gcc -fPIC -shared -o $@ sl2.c

# extra copy
libsl2.2.so: sl2.c
	gcc -fPIC -shared -o $@ sl2.c

libsl1.so: libsl2.so sl1.c
	gcc -fPIC -shared -L. -o $@ sl1.c -lsl2 -Wl,-rpath='$$ORIGIN'

libsl1noorigin.so: libsl2.2.so sl1.c
	gcc -fPIC -shared -L. -o $@ sl1.c -lsl2.2

driver: libsl1.so libsl2.so main.c
	gcc -L. -o driver main.c -lsl1 -Wl,-rpath-link=.  -Wl,-rpath='$$ORIGIN'

driverdlo: libsl1.so libsl2.so maindlo.c libsl1noorigin.so
	gcc  -o driverdlo maindlo.c -ldl
	rm -rf testlib testbin
	mkdir testlib testbin
	cp $@ testbin
	cp *.so testlib

clean:
	rm -f driver libsl1.so libsl2.so