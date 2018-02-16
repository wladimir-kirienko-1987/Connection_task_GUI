#include "client.h"
#include <QHostAddress>

Client::Client(QObject* parent): QObject(parent)
{
  connect(&client, SIGNAL(connected()),
    this, SLOT(startTransfer()));

  pba = 0;
}

Client::~Client()
{
  client.close();
}

void Client::start(QString address, quint16 port)
{
  QHostAddress addr(address);
  client.connectToHost(addr, port);
}

void Client::SetImageData(QByteArray* pba_)
{
    pba = pba_;
}


void Client::startTransfer()
{
  //client.write("Hello, world", 13);
  //if (pImageData) client.write(pImageData, ImageDatalen);
  if (pba) qDebug() << client.write(*pba);
}
