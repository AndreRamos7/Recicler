// Write C++ code here.
//
// Do not forget to dynamically load the C++ library into your application.
//
// For instance,
//
// In MainActivity.java:
//    static {
//       System.loadLibrary("recicler");
//    }
//
// Or, in MainActivity.kt:
//    companion object {
//      init {
//         System.loadLibrary("recicler")
//      }
//    }

#include <jni.h>
#include <string>
#include <iostream>

extern "C" JNIEXPORT jstring JNICALL
Java_com_recicler_MainActivity_process(
        JNIEnv* env,
        jobject mainActivityInstance) {

    const jclass mainActivityCls = env->GetObjectClass(mainActivityInstance);
    const jmethodID jmethodId = env->GetMethodID(mainActivityCls,
                                                 "processInJava",
                                                 "()Ljava/lang/String;");
    if(jmethodId == nullptr){
        return env->NewStringUTF("");
    }
    const jobject result = env->CallObjectMethod(mainActivityInstance, jmethodId);
    const std::string java_msg = env->GetStringUTFChars((jstring) result, JNI_FALSE);
    const std::string c_msg = "Result from Java => ";
    const std::string msg = c_msg + java_msg;
    return env->NewStringUTF((msg.c_str()));
}