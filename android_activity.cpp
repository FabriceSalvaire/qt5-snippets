/**************************************************************************************************/

#include "android_activity.h"

#include <QtAndroidExtras/QAndroidJniObject>
#include <QtAndroid>
#include <QtDebug>

/**************************************************************************************************/

AndroidActivity::AndroidActivity(QObject * parent)
  : QObject(parent)
{
}

AndroidActivity::~AndroidActivity()
{
}

void
AndroidActivity::start_service()
{
  qInfo() << "Call Java start_service";
  QtAndroid::androidActivity().callMethod<void>("start_service", "()V");
}

void
AndroidActivity::stop_service()
{
  qInfo() << "Call Java stop_service";
  QtAndroid::androidActivity().callMethod<void>("stop_service", "()V");
}

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
