/**************************************************************************************************/

#include "android_activity.h"
#include "service_application.h"

#include <QCoreApplication>
#include <QGuiApplication>
#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QString>
#include <QtAndroid>
#include <QtAndroidExtras/QAndroidJniObject>
#include <QtDebug>

/**************************************************************************************************/

int main(int argc, char *argv[])
{
  qInfo() << "Main argc" << argc;
  for(int i = 0; i < argc; i++)
    qInfo() << "argv" << i << argv[i];

  if (QString(argv[1]) == QLatin1Literal("-service")) {
    ServiceApplication app(argc, argv);
    return app.exec();
  } else {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QQmlContext * root_context = engine.rootContext();
    AndroidActivity * android_activity = new AndroidActivity(); // parent ?
    root_context->setContextProperty(QLatin1String("android_activity"), android_activity);
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
  }
}

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
