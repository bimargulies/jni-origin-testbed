all: libsl1.so libsl2.so driverdlo compilejava libjni.so libjninoorigin.so


libsl2.so: sl2.c
	gcc -fPIC -shared -o $@ sl2.c

# extra copy
libsl2.2.so: sl2.c
	gcc -fPIC -shared -o $@ sl2.c

libsl1.so: libsl2.so sl1.c
	gcc -fPIC -shared -L. -o $@ sl1.c -lsl2 -Wl,-rpath='$$ORIGIN'

libsl1noorigin.so: libsl2.2.so sl1.c
	gcc -fPIC -shared -L. -o $@ sl1.c -lsl2.2

driverdlo: libsl1.so libsl2.so maindlo.c libsl1noorigin.so
	gcc  -o driverdlo maindlo.c -ldl
	rm -rf testlib testbin
	mkdir testlib testbin
	cp $@ testbin
	cp *.so testlib

testjava:
	rm -rf jtestlib jtestbin
	mkdir jtestbin
	mkdir jtestlib
	cp libjni*.so jtestlib
	cp libsl2.so jtestlib
	(cd jtestbin;java -cp ../classes test/TestNative $(PWD)/jtestlib/libjni.so)
	(cd jtestbin;java -cp ../classes test/TestNative $(PWD)/jtestlib/libjninoorigin.so)


compilejava:
	-mkdir classes
	javac -d classes java/test/TestNative.java
	javah -classpath classes test.TestNative

#JAVA_HOME=/usr/lib/jvm/java-6-sun

libjni.so: jni.c libsl2.so
	gcc -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/linux -fPIC -shared -L. -o $@ jni.c -lsl2 -Wl,-rpath='$$ORIGIN'

libjninoorigin.so: jni.c libsl2.so
	gcc -I$(JAVA_HOME)/include  -I$(JAVA_HOME)/include/linux -fPIC -shared -L. -o $@ jni.c -lsl2

clean:
	rm -f driver libsl1.so libsl2.so