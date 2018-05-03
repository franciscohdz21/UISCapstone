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
    QQmlContext* coreLogicCtx = engine.rootContext();
    coreLogicCtx->setContextProperty("corelogic", &CoreLogic::Instance());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
