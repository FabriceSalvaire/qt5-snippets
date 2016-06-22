// -*- mode: c++ -*-

/**************************************************************************************************/

#ifndef __SERVICE_APPLICATION_H__
#define __SERVICE_APPLICATION_H__

/**************************************************************************************************/

#include <QCoreApplication>
#include <QTimer>
#include <QtDebug>

/**************************************************************************************************/

class ServiceServer : public QObject
{
  Q_OBJECT

public:
  ServiceServer(QObject * parent = nullptr);
  ~ServiceServer();

  // static ServiceServer & instance() {
  //   // Thread-safe in C++11
  //   static ServiceServer m_instance;
  //   return m_instance;
  // }

  // Delete copy and move constructors and assign operators
  // ServiceServer(ServiceServer const &) = delete;             // Copy construct
  // ServiceServer & operator=(ServiceServer const &) = delete; // Copy assign
  // ServiceServer(ServiceServer &&) = delete;                  // Move construct
  // ServiceServer & operator=(ServiceServer &&) = delete;      // Move assign

public slots:
  void start_timer();
  void stop_timer();

private slots:
  void timer_slot();

private:
  QTimer m_timer;
};

/**************************************************************************************************/

class ServiceApplication : public QCoreApplication
{
  Q_OBJECT

public:
  static ServiceServer * service_server;

public:
  ServiceApplication(int & argc, char ** argv);

private:
  // ServiceServer * m_service_server;
};

/**************************************************************************************************/

#endif // __SERVICE_APPLICATION_H__

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
