#include <QApplication>
#include <QQmlApplicationEngine>

#include <backend.h>
#include <config.h>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    
    initDictionaries();
    qmlRegisterType<Backend>("backend", 1, 0, "Backend");
    
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    
    return app.exec();
}