#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "layerrenderer.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<LayerRenderer>("LayerRenderer", 1, 0, "LayerRenderer");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
