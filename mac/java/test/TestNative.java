
package test;

public class TestNative {
    public static native void testNative();

    public static void main(String[] args) {
	System.load(args[0]);
	testNative();
    }
}