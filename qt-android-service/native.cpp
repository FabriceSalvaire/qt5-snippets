/**************************************************************************************************/

#include <jni.h>

#include <QtAndroidExtras>
#include <QMetaObject>
#include <QtDebug>

#include "service_application.h"

/**************************************************************************************************/

// Define our native static functions
// these are the functions that Java part will call directly from Android UI thread
static void
ServiceServerStartTimer(JNIEnv * /*env*/, jobject /*obj*/)
{
  qInfo() << "invoke ServiceServerStartTimer";
  // call ServiceServer::notify from Qt thread
  QMetaObject::invokeMethod(ServiceApplication::service_server, // &ServiceServer::instance(),
                            "start_timer",
                            Qt::QueuedConnection // Qt::BlockingQueuedConnection
                            );
  // we wait until the called function finishes
  // in this function the application should close all its opened files, otherwise it will be killed
}

static void
ServiceServerStopTimer(JNIEnv * /*env*/, jobject /*obj*/)
{
  qInfo() << "invoke ServiceServerStopTimer";
  QMetaObject::invokeMethod(ServiceApplication::service_server,
                            "stop_timer",
                            Qt::QueuedConnection
                            );
}

/**************************************************************************************************/

// Create a vector with all our JNINativeMethod(s)
static JNINativeMethod methods[] = {
    {"ServiceServerStartTimer", "()V", (void *) ServiceServerStartTimer},
    {"ServiceServerStopTimer", "()V", (void *) ServiceServerStopTimer},
};

// this method is called automatically by Java after the .so file is loaded
JNIEXPORT jint
JNI_OnLoad(JavaVM * vm, void * /*reserved*/)
{
    JNIEnv * env;
    // get the JNIEnv pointer.
    if (vm->GetEnv(reinterpret_cast<void **>(&env), JNI_VERSION_1_6) != JNI_OK)
      return JNI_ERR;

    // search for Java class which declares the native methods
    jclass javaClass = env->FindClass("org/qtproject/example/NativeFunctions");
    if (!javaClass)
      return JNI_ERR;

    // register our native methods
    if (env->RegisterNatives(javaClass, methods, sizeof(methods) / sizeof(methods[0])) < 0)
      return JNI_ERR;

    return JNI_VERSION_1_6;
}

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
