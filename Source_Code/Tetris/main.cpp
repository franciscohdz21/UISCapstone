#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "corelogic.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    //Context Properties
    //Important - this connects QML front-end with C++ back-end
    QQmlContext* coreLogicCtx = engine.rootContext();
    coreLogicCtx->setContextProperty("corelogic", &CoreLogic::Instance());

    //Load QML file
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
