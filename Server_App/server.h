#pragma once
#include <QtNetwork>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QLabel>
#include <QImage>
#include <QPaintDevice>

class Server: public QObject
{
Q_OBJECT
public:
  Server(QObject * parent = 0);
  void setLabel(QLabel* label);
  ~Server();
public slots:
  void acceptConnection();
  void startRead();
private:
  QTcpServer server;
  QTcpSocket* client;
  QLabel* pLabel;

};
