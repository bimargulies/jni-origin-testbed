
package test;

public class TestNative {
    public static native void testNative();

    public static void main(String[] args) {
	if (args.length == 0) {
	    System.loadLibrary("jninoorigin");
	} else {
	    System.load(args[0]);
	}
	testNative();
    }
}