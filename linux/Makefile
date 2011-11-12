
all: libsl1.so libsl2.so driver


libsl2.so: sl2.c
	gcc -fPIC -shared -o $@ sl2.c

libsl1.so: libsl2.so sl1.c
	gcc -fPIC -shared -L. -o $@ sl1.c -lsl2

driver: libsl1.so libsl2.so
	gcc -L. -o driver main.c -lsl1 -Wl,-rpath-link=.

clean:
	rm -f driver libsl1.so libsl2.so