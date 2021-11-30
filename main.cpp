#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("arduinogamepad");
    a.setOrganizationName("NWK");
    a.setOrganizationDomain("NWK.br");
    MainWindow w;
    w.show();
    return a.exec();
}
