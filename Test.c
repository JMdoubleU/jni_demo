#include "Test.h"
#include <stdio.h>

void testProto(int *intVal, float *floatVal, float *floatArr, int *floatArrLen) {
    printf("%d %.2f %d\n", *intVal, *floatVal, *floatArrLen);
    for (int i = 0; i < *floatArrLen; i++) {
        printf("%.2f ", *floatArr);
        *(floatArr++) = (float) i; //Test modifying stored value
    }
    printf("\n");
}

/*
 * Class:     Test
 * Method:    func
 * Signature: (IF[F)V
 */
JNIEXPORT void JNICALL Java_Test_func
  (JNIEnv *env, jobject object, jint intVal, jfloat floatVal, jfloatArray floatArr) {
    jfloat* floatArrC = (*env)->GetFloatArrayElements(env, floatArr, NULL);
    jint floatArrCLen = (*env)->GetArrayLength(env, floatArr);

    testProto(&intVal, &floatVal, floatArrC, &floatArrCLen);

    (*env)->ReleaseFloatArrayElements(env, floatArr, floatArrC, 0);
}
