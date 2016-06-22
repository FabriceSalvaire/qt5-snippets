/**************************************************************************************************/

#include "service_application.h"

#include <QtDebug>

/**************************************************************************************************/

ServiceServer::ServiceServer(QObject * parent)
  : QObject(parent),
    m_timer(this)
{
  qInfo() << "ServiceServer::ServiceServer";

  // connect(&m_timer, SIGNAL(timeout()), this, SLOT(timer_slot()));
  connect(&m_timer, &QTimer::timeout, this, &ServiceServer::timer_slot);
  m_timer.setInterval(1000);
}

ServiceServer::~ServiceServer()
{
  qInfo() << "ServiceServer::ServiceServer";
}

void
ServiceServer::timer_slot()
{
  qInfo() << "ServiceServer::timer_slot";
}

void
ServiceServer::start_timer()
{
  qInfo() << "ServiceServer::start_timer";
  m_timer.start();
}

void
ServiceServer::stop_timer()
{
  qInfo() << "ServiceServer::stop_timer";
  m_timer.stop();
}

/**************************************************************************************************/

ServiceServer * ServiceApplication::service_server = nullptr;

ServiceApplication::ServiceApplication(int & argc, char ** argv)
  : QCoreApplication(argc, argv)
    // m_service_server(&ServiceServer::instance())
{
  qInfo() << "ServiceApplication::ServiceApplication";

  if (!service_server)
    service_server = new ServiceServer();
}

/***************************************************************************************************
 *
 * End
 *
 **************************************************************************************************/
