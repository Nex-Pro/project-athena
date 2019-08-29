#include "Launcher.h"

#include <QResource>
#include <QFileInfo>
#include <QQmlContext>

#include "LauncherWindow.h"
#include "LauncherState.h"

Launcher::Launcher(int& argc, char**argv) : QGuiApplication(argc, argv) {
    QString resourceBinaryLocation =  QGuiApplication::applicationDirPath() + "/resources.rcc";
    QResource::registerResource(resourceBinaryLocation);
    _launcherState = std::make_shared<LauncherState>();
    _launcherState->setUIState(LauncherState::DOWNLOAD_SCREEN);
    _launcherWindow = std::make_unique<LauncherWindow>();
    _launcherWindow->rootContext()->setContextProperty("LauncherState", _launcherState.get());
    _launcherWindow->setFlags(Qt::FramelessWindowHint);
    LauncherState::declareQML();
    _launcherWindow->setSource(QUrl("qrc:/qml/root.qml"));
    _launcherWindow->setResizeMode(QQuickView::SizeRootObjectToView);
    _launcherWindow->show();
}

Launcher::~Launcher() {
}
