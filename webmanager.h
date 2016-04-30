#pragma once

#include <QObject>
#include <QUrl>
#include <QJsonArray>

class WebManager : public QObject{
    Q_OBJECT
    QString m_path;
public:
    WebManager(QString path);
    QString path() const;
    QJsonArray getFoods();
    QJsonArray getUsers();
private:
    void setPath(const QString &path);
};