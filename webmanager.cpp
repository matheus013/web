#include "webmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QEventLoop>
#include <QJsonDocument>
#include <QJsonObject>


WebManager::WebManager() {
    manager = new QNetworkAccessManager;
    QObject::connect(manager, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(replyFinished(QNetworkReply *)));
}

QJsonArray WebManager::getFoods() {
    QNetworkRequest request( QUrl("http://127.0.0.1:8080/get_foods") );

    QNetworkReply * reply = manager->get(request);
    connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));

    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)),
            this, SLOT(slotError(QNetworkReply::NetworkError)));

    connect(reply, SIGNAL(sslErrors(QList<QSslError>)),
            this, SLOT(slotSslErrors(QList<QSslError>)));
}

QJsonArray WebManager::getUsers() {

}

void WebManager::replyFinished(QNetworkReply * reply) {
    QString response = reply->readAll();
    response.replace("&quot;","\'");
    response.chop(1);
    qDebug() << qPrintable(response);
}

void WebManager::slotReadyRead() {qDebug() << "Ok";}

void WebManager::slotError(QNetworkReply::NetworkError) {qDebug() << "erro";}

void WebManager::slotSslErrors(QList<QSslError>) {qDebug() << "erro";}


