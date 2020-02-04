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

/*
 *  * Class:     Test
 *   * Method:    getArr
 *    * Signature: (II)[[F
 *     */
JNIEXPORT jobjectArray JNICALL Java_Test_getArr
  (JNIEnv *env, jobject object, jint numRows, jint numCols) {
    jclass floatClass = (*env)->FindClass(env, "[F");

    // Create the returnable 2D array
    jobjectArray jObjarray = (*env)->NewObjectArray(env, numRows, floatClass, NULL);

    // Go through the first dimension and add the second dimension arrays
    int n = 0;
    for (int row = 0; row < numRows; row++) {
        float cols[numCols];
        for (int col = 0; col < numCols; col++) {
            cols[col] = n++;
        }

        jfloatArray floatArray = (*env)->NewFloatArray(env, numCols);
        (*env)->SetFloatArrayRegion(env, floatArray, (jsize) 0, (jsize) numCols, (jfloat*) cols);
        (*env)->SetObjectArrayElement(env, jObjarray, (jsize) row, floatArray);
        (*env)->DeleteLocalRef(env, floatArray);
    }

    return jObjarray;
}
