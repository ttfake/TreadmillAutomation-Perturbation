#include "../include/SubjectInterface.h"

SubjectInterface::SubjectInterface(QWidget* parent, Qt::WindowFlags flags)
{
    subjectQuickView = new QQuickView;
    subjectQuickViewContainer = QWidget::createWindowContainer(subjectQuickView, this);
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    subjectQuickView->engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                QString::fromLatin1("qml")));
    QObject::connect(subjectQuickView->engine(), &QQmlEngine::quit, subjectQuickView, &QWindow::close);

    subjectQuickView->setTitle(QStringLiteral("Subject Interface"));
    subjectQuickView->setSource(QUrl("MainSubjectInterface.qml"));
    subjectQuickView->setResizeMode(QQuickView::SizeViewToRootObject);
    subjectQuickViewContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    subjectQuickViewContainer->setFixedSize(1920,1080);

    subjectIfaceItem = subjectQuickView->rootObject();
    setWindowFlags(Qt::Window);
    show();
}

SubjectInterface::~SubjectInterface()
{
}

void SubjectInterface::startTrialRun(bool runStartedBool)
{
    QMetaObject::invokeMethod(subjectIfaceItem, "hideSmileyFace");
//    QMetaObject::invokeMethod(subjectIfaceItem, "updateTextField", Q_ARG(QVariant, "Reposition Feet"));
}

void SubjectInterface::changeToCircle()
{
    QMetaObject::invokeMethod(subjectIfaceItem, "showGreenCircle");
    QMetaObject::invokeMethod(subjectIfaceItem, "updateTextField", Q_ARG(QVariant, ""));
}

void SubjectInterface::changeCircleColor(QColor circleColor)
{
    //QMetaObject::invokeMethod(subjectIfaceItem, "updateCircleColor", Q_ARG(QVariant, "black"));
}

void SubjectInterface::setTrialComplete(bool mTrialComplete)
{
    QMetaObject::invokeMethod(subjectIfaceItem, "hideGreenCircle");
    //QMetaObject::invokeMethod(subjectIfaceItem, "showSmileyFace");
    QMetaObject::invokeMethod(subjectIfaceItem, "showRedCircle");
}

void SubjectInterface::hideRedCircle()
{
    QMetaObject::invokeMethod(subjectIfaceItem, "hideRedCircle");
}

void SubjectInterface::hideGreenCircle()
{
    QMetaObject::invokeMethod(subjectIfaceItem, "hideGreenCircle");
}

void SubjectInterface::updateTextField(QString newText)
{
    QMetaObject::invokeMethod(subjectIfaceItem, "updateTextField", Q_ARG(QVariant, newText));
}

void SubjectInterface::updateTextColor(QString color)
{
    QMetaObject::invokeMethod(subjectIfaceItem, "setTextColor", Q_ARG(QVariant, color));
}

void SubjectInterface::setRunOver(bool mRunOver)
{
    QMetaObject::invokeMethod(subjectIfaceItem, "hideGreenCircle");
    QMetaObject::invokeMethod(subjectIfaceItem, "hideSmileyFace");
}

#include "../include/moc_SubjectInterface.cpp"

