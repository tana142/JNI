#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_applicationdemojni_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jlong JNICALL
Java_com_example_applicationdemojni_MainActivity_sum2IntegerJNI(JNIEnv *env, jobject thiz, jint a, jint b) {
    jlong result;
    result = a + b;
    return result;
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_applicationdemojni_MainActivity_stringFJ2C(JNIEnv *env, jobject thiz,
                                                            jstring message) {
    const char *cString = env->GetStringUTFChars(message, NULL);
    if (NULL == cString) {
        return NULL;
    }

    env->ReleaseStringUTFChars(message, cString);

    return env->NewStringUTF(cString);
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_applicationdemojni_MainActivity_personObjectFJ2C(JNIEnv *env, jobject thiz,
                                                                  jobject person) {
    //Get class of the object
    jclass personObjClass = env->GetObjectClass(person);

    //Get data field ids object of the object
    jfieldID personId = env->GetFieldID(personObjClass, "id", "Ljava/lang/String;");
    jfieldID personAge = env->GetFieldID(personObjClass, "age", "I");
    jfieldID personName = env->GetFieldID(personObjClass, "name", "Ljava/lang/String;");


    jstring id = static_cast<jstring>(env->GetObjectField(person, personId));
    const char *nativeString = env->GetStringUTFChars(id, 0);

    const char* personIdData = env->GetStringUTFChars(static_cast<jstring>(env->GetObjectField(person, personId)), 0);
    const char* personNameData = env->GetStringUTFChars(static_cast<jstring>(env->GetObjectField(person, personName)), 0);

    jint personAgeData = env->GetIntField(person,personAge);

    const std::string  result = std::string(personIdData) + std::string(personNameData) + std::to_string(personAgeData);


    return env->NewStringUTF(result.c_str());
}