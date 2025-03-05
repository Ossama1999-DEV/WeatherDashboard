#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "weatherapi.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    WeatherAPI weatherAPI;
    engine.rootContext()->setContextProperty("weatherAPI", &weatherAPI);

    engine.load(QUrl(QStringLiteral("qrc:/qml/Main.qml")));
    return app.exec();
}
