#include "webmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>


WebManager::WebManager() {
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply *)),
                     this, SLOT(replyFinished(QNetworkReply *)));
}

void WebManager::getFoods() {
    QNetworkRequest request( QUrl("http://localhost:8080/get_foods") );
    manager->get(request);
}

void WebManager::getUsers() {
    QNetworkRequest request( QUrl("http://localhost:8080/get_users") );
    manager->get(request);
}

void WebManager::replyFinished(QNetworkReply * reply) {
    if(reply->error() != QNetworkReply::NoError)
        qDebug() << reply->errorString();
    else{
        QString response = reply->readAll();
        response.replace("&quot;","\'");
        response.chop(1);
        requestQueue.push_back(response);
    }
}

