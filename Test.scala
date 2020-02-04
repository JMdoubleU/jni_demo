object TestRunner {
    def main(args: Array[String]): Unit = {
        System.loadLibrary("Test");
        val data: Array[Float] = Array(0.1f, 0.2f, 0.99f, 5.5f, 4f);
        new Test().func(5, 4.5f, data);
        for (floatVal <- data) {
            print(floatVal + " ");
        }
        println();
    }
}

class Test {
    @native def func(intVal: Int, floatVal: Float, floatArr: Array[Float]) {}
}
