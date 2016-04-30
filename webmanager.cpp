#include "webmanager.h"
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>


WebManager::WebManager(QString path) {
    setPath(path);
}

QString WebManager::path() const {
    return m_path;
}

QJsonArray WebManager::getFoods() {
    QString url = path() + "get_foods";
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)),
            this, SLOT(replyFinished(QNetworkReply*)));

    manager->get(QNetworkRequest(QUrl("http://127.0.0.1:8000/get_foods")));

}

QJsonArray WebManager::getUsers() {

}

void WebManager::setPath(const QString &path) {
    m_path = path;
}

