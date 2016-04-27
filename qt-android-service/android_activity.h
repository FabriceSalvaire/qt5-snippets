// -*- mode: c++ -*-

/**************************************************************************************************/

#ifndef ANDROID_ACTIVITY_H
#define ANDROID_ACTIVITY_H

#include <QObject>

/**************************************************************************************************/

class AndroidActivity : public QObject
{
  Q_OBJECT

public:
  explicit AndroidActivity(QObject * parent = 0);
  ~AndroidActivity();

  Q_INVOKABLE void start_service(); // static const
  Q_INVOKABLE void stop_service(); // static const
};

/**************************************************************************************************/

#endif // ANDROID_ACTIVITY_H

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
