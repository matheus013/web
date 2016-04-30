#include <QCoreApplication>
#include "webmanager.h"

int main(int argc, char *argv[]) {
    QCoreApplication app(argc, argv);
    WebManager *web = new WebManager();
    web->getFoods();
    web->getUsers();

    return app.exec();
}
