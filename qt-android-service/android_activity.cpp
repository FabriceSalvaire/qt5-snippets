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

// http://code.qt.io/cgit/qt/qtbase.git/commit/?h=5.7&id=efcf1dec4992bf7aab5bf1f0f4c0ee8c54030465
// http://code.qt.io/cgit/qt/qtandroidextras.git/commit/?h=5.7&id=e057ce322bae9fba6b9ac6864162aba48b8e7407
// QtAndroid::androidService()

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
