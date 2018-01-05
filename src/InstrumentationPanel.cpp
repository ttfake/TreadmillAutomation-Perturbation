#include "../include/InstrumentationPanel.h"

InstrumentationPanel::InstrumentationPanel(QWidget* parent, Qt::WindowFlags flags)
{
    instrumentationPanelQuickView = new QQuickView;
    instrumentationPanelQuickViewContainer = QWidget::createWindowContainer(instrumentationPanelQuickView, this);
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    instrumentationPanelQuickView->engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                QString::fromLatin1("qml")));
    QObject::connect(instrumentationPanelQuickView->engine(), &QQmlEngine::quit, instrumentationPanelQuickView, &QWindow::close);

    instrumentationPanelQuickView->setTitle(QStringLiteral("Instrumentation Panel"));
    instrumentationPanelQuickView->setSource(QUrl("MainInstrumentationPanel.qml"));
    instrumentationPanelQuickView->setResizeMode(QQuickView::SizeViewToRootObject);
    instrumentationPanelQuickViewContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    instrumentationPanelQuickViewContainer->setFixedSize(1950,900);

    instrumentationPanelItem = instrumentationPanelQuickView->rootObject();

    setWindowFlags(Qt::Window);
    show();
}

InstrumentationPanel::~InstrumentationPanel()
{
}
#include "../include/moc_InstrumentationPanel.cpp"
