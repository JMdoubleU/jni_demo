public class Test {

    public static void main(String[] args) {
        System.loadLibrary("Test");
        float[] data = new float[] { 0.1f, 0.2f, 0.99f, 5.5f, 4f };
        
        new Test().func(5, 4.5f, data);
        for (int i = 0; i < data.length; i++) {
            System.out.print(data[i] + " ");
        }
        System.out.println();
    }

    public native void func(int intVal, float floarVal, float[] floatArr);

}
