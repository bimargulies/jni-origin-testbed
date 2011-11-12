This material demonstrates how to use JNI to access a shared library
that has, in turn, dependent shared libraries, WITHOUT the need to set
LD_LIBRARY_PATH on Linux and DYLD_LIBRARY_PATH on MacOSX.

The requirement is that the dependent libs reside in some known
relative location to the JNI library that uses them. This example
demonstrates the simplest case, in which they are sitting in the same
directory. 

If you create an 'ordinary' JNI shared objects (with gcc or g++ -shared), and
it references some other shared library, then, at runtime, you will
get an UnsatisfiedLinkError unless you include the location of the
other libraries in LD_LIBRARY_PATH/DYLD_LIBRARY_PATH.

To avoid this annoying requirement, follow the instructions below.

For Linux, when linking the JNI library, add:

   -Wl,-rpath='$$ORIGIN' 

to the link command line. Note that the above is the appropriate
syntax for a Makefile, where $$ maps to a single $. The overall goal
of this is to see "$ORIGIN" in the output of readelf -d.

For Mac OSX, there is no corresponding simple option for the link
command line. Instead, you have to run an additional command to patch
the pathname. Here is an example:

	install_name_tool -change libsl2.dynlib "@loader_path/libsl2.dynlib" libjni.jnilib

In the example, the jni library is 'libjni.jnilib", while the library
it links to is "libsl2.dynlib".

The correct form of this command depends on the 'install name' of
libsl2.dynlib. You can use otool -L on the JNI lib to see the string
as it comes out of the linker. The '-change' option finds the string
you specify and replaces it with the string you supply. 





