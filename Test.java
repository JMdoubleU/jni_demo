public class Test {

    public static void main(String[] args) {
        System.loadLibrary("Test");
        new Test().func(5, 4.5f, new float[] { 0.1f, 0.2f, 0.99f, 5.5f, 4f } );
    }

    public native void func(int intVal, float floarVal, float[] floatArr);

}
