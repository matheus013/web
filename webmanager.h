#pragma once

#include <QObject>
#include <QUrl>
#include <QJsonArray>
#include <QNetworkReply>
#include <QQueue>

class WebManager : public QObject{
    Q_OBJECT
public:
    WebManager();
    void getFoods();
    void getUsers();
    void load();
private:
    QJsonArray convert(QString str);

    QNetworkAccessManager * manager;
    QQueue<QString> requestQueue;
public slots:
    void replyFinished(QNetworkReply*reply);
};
