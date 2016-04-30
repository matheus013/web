#pragma once

#include <QObject>
#include <QUrl>
#include <QJsonArray>
#include <QNetworkReply>

class WebManager : public QObject{
    Q_OBJECT
    QNetworkAccessManager * manager;
public:
    WebManager();
    QJsonArray getFoods();
    QJsonArray getUsers();
public slots:
    void replyFinished(QNetworkReply*reply);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
};
