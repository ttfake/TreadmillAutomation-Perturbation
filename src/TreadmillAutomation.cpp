#include "include/TreadmillAutomation.h"

TreadmillAutomation::TreadmillAutomation(QWidget *parent, Qt::WindowFlags flags):
    centralWidget(new QWidget)
{

    setCentralWidget(centralWidget);
    centralWidgetLayout = new QVBoxLayout;
    centralWidget->setLayout(centralWidgetLayout);
    perturbationTabWidget = PerturbationTabWidget::getInstance();
    sendSetpointObject = SendSetpoints::getInstance();
    createFileMenu();
    createTabWidget();
    networkTabWidget = NetworkTabWidget::getInstance();
    centralTabWidget->addTab(networkTabWidget, "Network");
    connect(networkTabWidget->connectBtn, SIGNAL(clicked()), SLOT(setUseLibraryStatus()));
    connect(networkTabWidget->connectBtn, SIGNAL(clicked()), SLOT(setSocket()));

    centralTabWidget->addTab(perturbationTabWidget, "Perturbation");
}

TreadmillAutomation::~TreadmillAutomation()
{

}

void TreadmillAutomation::createFileMenu()
{
    menuBar = new QMenuBar;
    menuFile = new QMenu(menuBar);
    menuFile->setObjectName(QStringLiteral("menuFile"));
    menuFile->setTitle(QApplication::translate("TreadmillAutomation", "File", Q_NULLPTR));
    exitAct = new QAction();
    menuFile->addAction(exitAct);
    exitAct->setText("Exit");
    menuBar->addMenu(menuFile);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));

    menuView = new QMenu(menuBar);
    menuView->setObjectName(QStringLiteral("menuView"));
    menuView->setTitle(QApplication::translate("TreadmillAutomation", "View", Q_NULLPTR));
    timerViewAct = new QAction();
    timerViewAct->setCheckable(true);
    menuView->addAction(timerViewAct);
    timerViewAct->setText("Show Timer");
    connect(timerViewAct, SIGNAL(changed()), SLOT(showTimer()));
    
    maxSpeedViewAct = new QAction();
    maxSpeedViewAct->setCheckable(true);
    menuView->addAction(maxSpeedViewAct);
    maxSpeedViewAct->setText("Show Max Speed Settings");
    connect(maxSpeedViewAct, SIGNAL(changed()), SLOT(showMaxSpeedBox()));

    menuBar->addMenu(menuView);
    centralWidgetLayout->setMenuBar(menuBar);
}

void TreadmillAutomation::showMaxSpeedBox()
{
    bool checked = false;
    if(maxSpeedViewAct->isChecked())
    {
        checked = true;
        perturbationTabWidget->showMaxSpeedBox(checked);
        sendSetpointObject->setUseMaxSpeed(checked);
    }
    else
    {
        checked = false;
        perturbationTabWidget->showMaxSpeedBox(checked);
        sendSetpointObject->setUseMaxSpeed(checked);
    }

}

void TreadmillAutomation::showTimer()
{
    bool checked = false;
    if(timerViewAct->isChecked())
    {
        checked = true;
        perturbationTabWidget->showTimer(checked);
    }
    else
    {
        checked = false;
        perturbationTabWidget->showTimer(checked);
    }
}

void TreadmillAutomation::createTabWidget()
{
    centralTabWidget = new QTabWidget;
    centralWidgetLayout->addWidget(centralTabWidget);
    centralGridLayout = new QGridLayout;
    centralTabWidget->setLayout(centralGridLayout);
}

void TreadmillAutomation::setSocket()
{
    NetworkTabWidget* netWidget = NetworkTabWidget::getInstance();
    PerturbationTabWidget* pertWidget = PerturbationTabWidget::getInstance();
    QAbstractSocket* socket = netWidget->getSocketInstance();
    pertWidget->setSocket(socket);

}

void TreadmillAutomation::setUseLibraryStatus()
{
    NetworkTabWidget* netWidget = NetworkTabWidget::getInstance();
    PerturbationTabWidget* pertWidget = PerturbationTabWidget::getInstance();

    useLibraryCheckBox = netWidget->getUseLibraryIsCheckedStatus();
    pertWidget->setUseLibraryStatus(useLibraryCheckBox);
}

template<typename T, typename U> void TreadmillAutomation::addWidgetToLayout(T* widget, U* layout)
{
    layout->addWidget(widget);

};

static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}

#include "../include/moc_TreadmillAutomation.cpp"
