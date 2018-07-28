#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QVariantList>
#include <QVariantMap>
#include <QQmlContext>
#include <QtPositioning/QGeoCoordinate>

int main(int argc, char *argv[])
{
    QVariantList va;
    for (int i =0; i< 3; i++) {
        QVariantMap m;
        QGeoCoordinate crd(10.0 + i, 10.0 + i);
        m.insert("crd", QVariant::fromValue(crd));
        m.insert("rds", 100 * 1000);
        m.insert("clr", "pink");
        m.insert("dataType", "circle");
        va.append(m);
    }

    for (int i =0; i< 3; i++) {
        QVariantMap m;
        m.insert("tl", QVariant::fromValue(QGeoCoordinate(15.0 + 2*i+1, 15.0 + 2*i)));
        m.insert("br", QVariant::fromValue(QGeoCoordinate(15.0 + 2*i, 15.0 + 2*i+1)));
        m.insert("clr", "green");
        m.insert("dataType", "rect");
        va.append(m);
    }

    QVariantMap m;
    m.insert("dataType", "model");
    QVariantList vaa;
    for (int i =0; i< 3; i++) {
        QVariantMap m;
        QGeoCoordinate crd(20.0 + i, 20.0 + i);
        m.insert("crd", QVariant::fromValue(crd));
        m.insert("rds", 100 * 1000);
        m.insert("clr", "fuchsia");
        m.insert("dataType", "circle");
        vaa.append(m);
    }

    for (int i =0; i< 3; i++) {
        QVariantMap m;
        m.insert("tl", QVariant::fromValue(QGeoCoordinate(25.0 + 2*i+1, 25.0 + 2*i)));
        m.insert("br", QVariant::fromValue(QGeoCoordinate(25.0 + 2*i, 25.0 + 2*i+1)));
        m.insert("clr", "blue");
        m.insert("dataType", "rect");
        vaa.append(m);
    }

    QVariantMap mm;
    mm.insert("dataType", "model");
    QVariantList vaaa;
    for (int i =0; i< 3; i++) {
        QVariantMap m;
        QGeoCoordinate crd(30.0 + i, 20.0 + i);
        m.insert("crd", QVariant::fromValue(crd));
        m.insert("rds", 100 * 1000);
        m.insert("clr", "fuchsia");
        m.insert("dataType", "circle");
        vaaa.append(m);
    }

    for (int i =0; i< 3; i++) {
        QVariantMap m;
        m.insert("tl", QVariant::fromValue(QGeoCoordinate(35.0 + 2*i+1, 25.0 + 2*i)));
        m.insert("br", QVariant::fromValue(QGeoCoordinate(35.0 + 2*i, 25.0 + 2*i+1)));
        m.insert("clr", "blue");
        m.insert("dataType", "rect");
        vaaa.append(m);
    }
    mm.insert("list", vaaa);
    vaa.append(mm);
    m.insert("list", vaa);
    va.append(m);

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("cppModel", va);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
