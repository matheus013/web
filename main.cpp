#include <QCoreApplication>
#include "webmanager.h"

int main(int argc, char *argv[]) {
    WebManager *web = new WebManager("http://127.0.0.1:8000/");
    web->getFoods();
}
