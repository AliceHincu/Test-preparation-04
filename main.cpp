#include <iostream>
#include "GUI.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    Repository repo;
    Service service(repo);
    GUI gui(service);
    gui.show();

    return app.exec();
}
