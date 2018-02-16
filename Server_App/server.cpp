#include "server.h"
#include <QImage>

using namespace std;

Server::Server(QObject* parent): QObject(parent)
{
  connect(&server, SIGNAL(newConnection()),
    this, SLOT(acceptConnection()));

  server.listen(QHostAddress::Any, 8888);

 // pImage = new QImage();
}

void Server::setLabel(QLabel *label)
{
    pLabel = label;
}

Server::~Server()
{
  server.close();
  //delete pImage;
}

void Server::acceptConnection()
{
  client = server.nextPendingConnection();

  connect(client, SIGNAL(readyRead()),
    this, SLOT(startRead()));
}

void Server::startRead()
{
  //char buffer[1024] = {0};

  //qDebug() << client->read(buffer, client->bytesAvailable());

  QByteArray ba;
  ba = client->readAll();
  //qDebug() << ba.size();

  QBuffer buffer(&ba);
  buffer.open(QIODevice::ReadOnly);
  QImage myImage;
  myImage.load(&buffer, "PNG"); // read image into ba in PNG format



  QPixmap NewPixMap;
  NewPixMap.convertFromImage(myImage,Qt::ColorOnly);
  pLabel->setPixmap(NewPixMap);

/*
  QString fileName = "C:\\test.png";
  if ( myImage.save(fileName)){
    QPixmap img(fileName);
    pLabel->setPixmap(img);
  }
  else{
    pLabel->setText("Image load fail");
  }
*/
  client->close();
}
