#include "include/TreadmillAutomation.h"

TreadmillAutomation::TreadmillAutomation(QWidget *parent, Qt::WindowFlags flags):
    centralWidget(new QWidget)
{

    setCentralWidget(centralWidget);
    centralWidgetLayout = new QVBoxLayout;
    centralWidget->setLayout(centralWidgetLayout);

    perturbationTabWidget = new PerturbationTabWidget;
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
    saveVelocityDataAct = new QAction;
    menuFile->addAction(saveVelocityDataAct);
    saveVelocityDataAct->setText("Save Velocity Data");
    connect(saveVelocityDataAct, SIGNAL(triggered()), perturbationTabWidget, SLOT(saveVelocityData()));
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

    viewSubjectInterfaceAct = new QAction();
    menuView->addAction(viewSubjectInterfaceAct);
    viewSubjectInterfaceAct->setText("Subject Interface");
    connect(viewSubjectInterfaceAct, SIGNAL(triggered()), this, SLOT(showSubjectView()));

    daqViewAct = new QAction();
    daqViewAct->setCheckable(true);
    menuView->addAction(daqViewAct);
    daqViewAct->setText("Show DAQ Data View");
    connect(daqViewAct, SIGNAL(changed()), SLOT(showDaqDataBox()));

    /*    menuMouseScan = new QMenu(menuBar);
    menuMouseScan->setObjectName(QStringLiteral("menuMouseScan"));
    menuMouseScan->setTitle(QApplication::translate("TreadmillAutomation", "Mouse Interface", Q_NULLPTR));
    scanMouseAction = new QAction;
    menuMouseScan->addAction(scanMouseAction);
    scanMouseAction->setText("Scan");
    connect(scanMouseAction, SIGNAL(triggered()), mouseInterface, SLOT(scanForDevices()));
    getRawDataMouseAction = new QAction;
    menuMouseScan->addAction(getRawDataMouseAction);
    gtRawDataMouseAction->setText("Get Mouse Data");
    connect(getRawDataMouseAction, SIGNAL(triggered()), mouseInterface, SLOT(getRawInput()));
 */
   
    menuBar->addMenu(menuView);
//    menuBar->addMenu(menuMouseScan);
    centralWidgetLayout->setMenuBar(menuBar);
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

void TreadmillAutomation::showDaqDataBox()
{
    bool checked = false;
    if(daqViewAct->isChecked())
    {
        checked = true;
        perturbationTabWidget->showDaqDataBox(checked);
    }
    else
    {
        checked = false;
        perturbationTabWidget->showDaqDataBox(checked);
    }
}

void TreadmillAutomation::showSubjectView()
{
    sInterface = new SubjectInterface;
    sInterface->setAttribute(Qt::WA_DeleteOnClose);
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
    QAbstractSocket* socket = netWidget->getSocketInstance();
    QString host(netWidget->getHost());
    QString port(netWidget->getPort());
    perturbationTabWidget->setSocket(socket);
//    qDebug("From TreadmillAutomation: The host is %s ", qPrintable(host));
    perturbationTabWidget->setHost(host);
//    qDebug("From TreadmillAutomation: The port is %s ", qPrintable(port));
    perturbationTabWidget->setPort(port);

}

void TreadmillAutomation::setUseLibraryStatus()
{
    NetworkTabWidget* netWidget = NetworkTabWidget::getInstance();
    useLibraryCheckBox = netWidget->getUseLibraryIsCheckedStatus();
    perturbationTabWidget->setUseLibraryStatus(useLibraryCheckBox);
}

void TreadmillAutomation::errorString(QString s)
{
    qDebug() << s;
}


static void showWarning(QWidget * mparent, const QString & mtitle, const QString & mtext)
{
	Q_ASSERT(mparent);
	QMessageBox * box = new QMessageBox(QMessageBox::Warning, mtitle, mtext, QMessageBox::Ok, mparent);
	box->setWindowModality(Qt::WindowModal);
	box->setAttribute(Qt::WA_DeleteOnClose);
	box->show();
}

#include "../include/moc_TreadmillAutomation.cpp"
