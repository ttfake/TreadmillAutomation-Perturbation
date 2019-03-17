#include "include/EmgChannel.h"


Q_DECLARE_METATYPE(DataSource *);

EmgChannel::EmgChannel(QWidget* parent, Qt::WindowFlags flags, QString qmlFile, QString channelNo, 
        DataSource* dSource, QQuickView* channelQuickView)
{
    qRegisterMetaType<DataSource *>();
    
    mChannelNo = channelNo;

    channelQuickViewContainer = QWidget::createWindowContainer(channelQuickView, this);
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    channelQuickView->engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                QString::fromLatin1("qml")));
    QObject::connect(channelQuickView->engine(), &QQmlEngine::quit, channelQuickView, &QWindow::close);

    channelQuickView->setTitle(channelNo);
    channelQuickView->setSource(QUrl(qmlFile));
    channelQuickView->setResizeMode(QQuickView::SizeViewToRootObject);
    channelQuickViewContainer->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    channelQuickViewContainer->setFixedSize(600,250);

    channelQuickViewItem = channelQuickView->rootObject();

    channelQuickView->rootContext()->setContextProperty("dataSource", QVariant::fromValue(dSource));
}

EmgChannel::~EmgChannel()
{
}

#include "include/moc_EmgChannel.cpp"
