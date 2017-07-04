#include "include/TreadmillAutomation.h"

TreadmillAutomation::TreadmillAutomation(QWidget *parent, Qt::WindowFlags flags):
    centralWidget(new QWidget)
{

    setCentralWidget(centralWidget);
    centralWidgetLayout = new QVBoxLayout;
    centralWidget->setLayout(centralWidgetLayout);
    createFileMenu();
    createTabWidget();
    networkTabWidget = NetworkTabWidget::getInstance();
    centralTabWidget->addTab(networkTabWidget, "Network");
    connect(networkTabWidget->connectBtn, SIGNAL(clicked()), SLOT(setUseLibraryStatus()));
    connect(networkTabWidget->connectBtn, SIGNAL(clicked()), SLOT(setSocket()));
    perturbationTabWidget = PerturbationTabWidget::getInstance();
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
    centralWidgetLayout->setMenuBar(menuBar);
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
