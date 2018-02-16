#include "include/PerturbationTabWidget.h"


PerturbationTabWidget::PerturbationTabWidget(QWidget* parent, Qt::WindowFlags flags)
{
    tableFilled = false;
    sendSetpoints = SendSetpoints::getInstance();
    createTreadmillPerturbationTab();
    populateTreadmillPerturbationTab();
    trialRun = 1;
    prp = new ParseRunProfile;
    cellDoubleClicked = false;
    InstrumentationPanel* instPanel = new InstrumentationPanel;
    /* 
     * Signal connect below must be uncommented form stimulation to work.
     * connect(prp, SIGNAL(startStimulation()), SLOT(startStim()));
     */
    
/*	if (DS8Controller.ErrorCode != -1)
	{
		//DS8Controller.SetVariables(NULL,NULL,10,NULL,NULL,NULL,TRUE); //Set to Defaults
		DS8Controller.ToggleOutput(FALSE);
		DS8Controller.SetVariables(NULL,NULL,20,NULL,NULL,NULL,TRUE); //Set to Defaults
		//sprintf_s(str,"%d",e);
		//printf ("Error: %s\n",str);
		printf("No Errors \n");
		//DS8Controller.SetVariables(NULL,NULL,10,NULL,NULL,NULL,TRUE); //Set to Defaults
	}
*/
}

PerturbationTabWidget::~PerturbationTabWidget()
{
    //DS8Controller.CloseDS8();
}

void PerturbationTabWidget::createTreadmillPerturbationTab()
{
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    perturbationTabLayout = new QGridLayout;
    setObjectName("PerturbationTab");
    setLayout(perturbationTabLayout);
}

void PerturbationTabWidget::populateTreadmillPerturbationTab()
{
    addQuadrantOne();
    addQuadrantTwo();
    addQuadrantThree();
    addQuadrantFour();
}

void PerturbationTabWidget::addQuadrantOne()
{
    quadrantOneGroupBox = new QGroupBox;
    quadrantOneGroupBox->setFixedSize(975,450);
    quadrantOnePerturbationLayout = new QVBoxLayout;
    quadrantOneGroupBox->setLayout(quadrantOnePerturbationLayout);
    perturbationTabLayout->addWidget(quadrantOneGroupBox, 0,0);

    addRunGroupBox();
}

void PerturbationTabWidget::addQuadrantTwo()
{
    quadrantTwoGroupBox = new QGroupBox;
    quadrantTwoGroupBox->setFixedSize(850, 850);
    quadrantTwoPerturbationLayout = new QVBoxLayout;
    quadrantTwoGroupBox->setLayout(quadrantTwoPerturbationLayout);
    perturbationTabLayout->addWidget(quadrantTwoGroupBox, 0,1);
    addPersonStimGroupBox();
//    quadrantTwoGroupBox->hide();
    //addEmgDataVisualization();
}

void PerturbationTabWidget::addQuadrantThree()
{
    quadrantThreeGroupBox = new QGroupBox;
    quadrantThreePerturbationLayout = new QVBoxLayout;
    quadrantThreeGroupBox->setLayout(quadrantThreePerturbationLayout);
    perturbationTabLayout->addWidget(quadrantThreeGroupBox, 1,0);
    quadrantThreeGroupBox->setFixedSize(950,300);
    addFudgeFactorGroupBox();

    //addSpeedGroupBox();
    addAccelDecelGroupBox();
    addTimerGroupBox();
    addStartPertRunGroupBox();

}

void PerturbationTabWidget::addQuadrantFour()
{
    quadrantFourGroupBox = new QGroupBox;
    quadrantFourPerturbationLayout = new QVBoxLayout;
    quadrantFourGroupBox->setLayout(quadrantFourPerturbationLayout);
    perturbationTabLayout->addWidget(quadrantFourGroupBox, 1,1);
    quadrantFourGroupBox->hide();
}

void PerturbationTabWidget::addFudgeFactorGroupBox()
{
    fudgeFactorGroupBox = new QGroupBox;
    fudgeFactorGroupBoxHorizontalLayout = new QHBoxLayout;
    fudgeFactorGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    fudgeFactorGroupBox->setLayout(fudgeFactorGroupBoxHorizontalLayout);
    fudgeFactorLabel = new QLabel;
    fudgeFactorLabel->setFixedSize(180,180);
    fudgeFactorLabelFont.setFamily("Times");
    fudgeFactorLabelFont.setWeight(75);
    fudgeFactorLabelFont.setPointSize(12);
    fudgeFactorLabel->setFont(fudgeFactorLabelFont);
    fudgeFactorLabel->setText("Added Time: ");
    fudgeFactorGroupBoxHorizontalLayout->addWidget(fudgeFactorLabel);
    fudgeFactorDoubleSpinBox = new QDoubleSpinBox;
    fudgeFactorDoubleSpinBox->setRange(0.00, 100000000.00);
    fudgeFactorDoubleSpinBox->setFont(fudgeFactorLabelFont);
    fudgeFactorDoubleSpinBox->setSuffix(" ms");
    fudgeFactorDoubleSpinBox->setFixedSize(160, 40);
    fudgeFactorGroupBoxHorizontalLayout->addWidget(fudgeFactorDoubleSpinBox);

    quadrantThreePerturbationLayout->addWidget(fudgeFactorGroupBox);
    fudgeFactorGroupBox->hide();
}

void PerturbationTabWidget::addSpeedGroupBox()
{
    speedGroupBox = new QGroupBox;
    speedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedGroupBoxHorizontalLayout = new QHBoxLayout;
    speedGroupBox->setLayout(speedGroupBoxHorizontalLayout);

    speedLeftFrontLabel = new QLabel;
    speedLeftFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedLeftFrontLabel->setText("Left Acceleration Speed: ");
    speedLeftFrontLabel->setFixedSize(180,180);
    speedLeftFrontLabelFont.setFamily("Times");
    speedLeftFrontLabelFont.setWeight(75);
    speedLeftFrontLabelFont.setPointSize(12);
    speedLeftFrontLabel->setFont(speedLeftFrontLabelFont);
    speedGroupBoxHorizontalLayout->addWidget(speedLeftFrontLabel);
    leftFrontSpeedSetpoint = new QDoubleSpinBox;
    leftFrontSpeedSetpointFont.setFamily("Times");
    leftFrontSpeedSetpointFont.setWeight(75);
    leftFrontSpeedSetpointFont.setPointSize(12);
    leftFrontSpeedSetpoint->setFont(leftFrontSpeedSetpointFont);
    leftFrontSpeedSetpoint->setSuffix("  m/s");
    leftFrontSpeedSetpoint->setFixedSize(160,40);
    speedGroupBoxHorizontalLayout->addWidget(leftFrontSpeedSetpoint);

    speedRightFrontLabel = new QLabel;
    speedRightFrontLabel->setText("Right Acceleration Speed: ");
    speedRightFrontLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    speedRightFrontLabel->setFixedSize(180,180);
    speedRightFrontLabelFont.setFamily("Times");
    speedRightFrontLabelFont.setWeight(75);
    speedRightFrontLabelFont.setPointSize(12);
    speedRightFrontLabel->setFont(speedRightFrontLabelFont);
    speedGroupBoxHorizontalLayout->addWidget(speedRightFrontLabel);
    rightFrontSpeedSetpoint = new QDoubleSpinBox;
    rightFrontSpeedSetpointFont.setFamily("Times");
    rightFrontSpeedSetpointFont.setWeight(75);
    rightFrontSpeedSetpointFont.setPointSize(12);
    rightFrontSpeedSetpoint->setFont(rightFrontSpeedSetpointFont);
    rightFrontSpeedSetpoint->setSuffix("  m/s");
    rightFrontSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightFrontSpeedSetpoint->setFixedSize(160,40);
    speedGroupBoxHorizontalLayout->addWidget(rightFrontSpeedSetpoint);
    speedGroupBox->hide();

    quadrantThreePerturbationLayout->addWidget(speedGroupBox);
}

void PerturbationTabWidget::addDecelerationSpeedGroupBox()
{
    decelSpeedGroupBox = new QGroupBox;
    decelSpeedGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedGroupBoxHorizontalLayout = new QHBoxLayout;
    decelSpeedGroupBox->setLayout(decelSpeedGroupBoxHorizontalLayout);

    decelSpeedLeftLabel = new QLabel;
    decelSpeedLeftLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedLeftLabel->setText("Left Deceleration Speed: ");
    decelSpeedLeftLabel->setFixedSize(180,180);
    decelSpeedLeftLabelFont.setFamily("Times");
    decelSpeedLeftLabelFont.setWeight(75);
    decelSpeedLeftLabelFont.setPointSize(12);
    decelSpeedLeftLabel->setFont(decelSpeedLeftLabelFont);
    decelSpeedGroupBoxHorizontalLayout->addWidget(decelSpeedLeftLabel);
    leftDecelSpeedSetpoint = new QDoubleSpinBox;
    leftDecelSpeedSetpointFont.setFamily("Times");
    leftDecelSpeedSetpointFont.setWeight(75);
    leftDecelSpeedSetpointFont.setPointSize(12);
    leftDecelSpeedSetpoint->setFont(leftDecelSpeedSetpointFont);
    leftDecelSpeedSetpoint->setSuffix("  m/s");
    leftDecelSpeedSetpoint->setFixedSize(160,40);
    decelSpeedGroupBoxHorizontalLayout->addWidget(leftDecelSpeedSetpoint);

    decelSpeedRightLabel = new QLabel;
    decelSpeedRightLabel->setText("Right Deceleration Speed: ");
    decelSpeedRightLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelSpeedRightLabel->setFixedSize(180,180);
    decelSpeedRightLabelFont.setFamily("Times");
    decelSpeedRightLabelFont.setWeight(75);
    decelSpeedRightLabelFont.setPointSize(12);
    decelSpeedRightLabel->setFont(decelSpeedRightLabelFont);
    decelSpeedGroupBoxHorizontalLayout->addWidget(decelSpeedRightLabel);
    rightDecelSpeedSetpoint = new QDoubleSpinBox;
    rightDecelSpeedSetpointFont.setFamily("Times");
    rightDecelSpeedSetpointFont.setWeight(75);
    rightDecelSpeedSetpointFont.setPointSize(12);
    rightDecelSpeedSetpoint->setFont(rightDecelSpeedSetpointFont);
    rightDecelSpeedSetpoint->setSuffix("  m/s");
    rightDecelSpeedSetpoint->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    rightDecelSpeedSetpoint->setFixedSize(160,40);
    decelSpeedGroupBoxHorizontalLayout->addWidget(rightDecelSpeedSetpoint);

    quadrantThreePerturbationLayout->addWidget(decelSpeedGroupBox);
}

void PerturbationTabWidget::addPersonStimGroupBox()
{
    personStimGroupBox = new QGroupBox;
    personStimGroupBoxHBoxLayout = new QHBoxLayout;
    personStimGroupBox->setLayout(personStimGroupBoxHBoxLayout);
    personSessionGroupBox = new QGroupBox;
    personSessionVBoxLayout = new QVBoxLayout;
    personSessionGroupBox->setLayout(personSessionVBoxLayout);
    rightSoleusStimGroupBox = new QGroupBox;
    rightSoleusStimVerticalGroupBoxLayout = new QVBoxLayout;
    rightSoleusStimGroupBox->setLayout(rightSoleusStimVerticalGroupBoxLayout);
    leftSoleusStimGroupBox = new QGroupBox;
    leftSoleusStimVerticalGroupBoxLayout = new QVBoxLayout;
    leftSoleusStimGroupBox->setLayout(leftSoleusStimVerticalGroupBoxLayout);
    
    personSessionStimQuickView = new QQuickView;
    personSessionStimQuickViewContainer = QWidget::createWindowContainer(personSessionStimQuickView, this);
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    personSessionStimQuickView->engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                QString::fromLatin1("qml")));
    QObject::connect(personSessionStimQuickView->engine(), &QQmlEngine::quit, personSessionStimQuickView, &QWindow::close);

    personSessionStimQuickView->setTitle(QStringLiteral("Person / Session / Stimulation Panel"));
    personSessionStimQuickView->setSource(QUrl("PersonSessionStimData.qml"));
    personSessionStimQuickView->setResizeMode(QQuickView::SizeViewToRootObject);
    personSessionStimQuickViewContainer->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    personSessionStimQuickViewContainer->setFixedSize(750,750);
    
    personSessionStimQuickViewItem = personSessionStimQuickView->rootObject();

    quadrantTwoPerturbationLayout->addWidget(personSessionStimQuickViewContainer);
    
}

void PerturbationTabWidget::addRunGroupBox()
{
    runGroupBox = new QGroupBox;
    runTableWidget = new QTableWidget;
    
    importExportGroupBox = new QGroupBox;
    importExportGroupBoxVLayout = new QHBoxLayout;
    importExportGroupBox->setLayout(importExportGroupBoxVLayout);
    importExportButtonFont.setFamily("Times");
    importExportButtonFont.setWeight(75);
    importExportButtonFont.setPointSize(12);
    importButton = new QPushButton;
    importButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    importButton->setFont(importExportButtonFont);
    importButton->setFixedSize(200,40);
    importButton->setText("Load");
    exportButton = new QPushButton;
    exportButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    exportButton->setFont(importExportButtonFont);
    exportButton->setFixedSize(200,40);
    exportButton->setText("Export");
    importExportGroupBoxVLayout->addWidget(importButton);
    importExportGroupBoxVLayout->addWidget(exportButton);

    connect(importButton, SIGNAL(clicked()), SLOT(loadRunProfile()));
    connect(exportButton, SIGNAL(clicked()), SLOT(exportTable()));


    runTableWidget->setStyleSheet("selection-background-color : green");
    runTableWidget->setFixedSize(900,300);
    runTableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    runTableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //updateRunTableBtn = new QPushButton;
    //updateRunTableBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    //updateRunTableBtn->setText("Update Run Profile");
    //updateRunTableBtn->setFont(startPertRunBtnFont);
    //updateRunTableBtn->setFixedSize(200,40);
    connect(runTableWidget, SIGNAL(cellChanged(int, int)), SLOT(updateRun(int, int)));
    connect(runTableWidget, SIGNAL(cellDoubleClicked(int, int)), SLOT(setCellChangedTrue(int, int)));
    //connect(updateRunTableBtn, SIGNAL(clicked()), SLOT(updateRun()));
    runGroupBoxLayout = new QVBoxLayout;
    runTableHeaderFont.setFamily("Times");
    runTableHeaderFont.setWeight(75);
    runTableHeaderFont.setPointSize(12);
    runGroupBox->setLayout(runGroupBoxLayout);
    runGroupBoxLayout->addWidget(runTableWidget);
    runGroupBoxLayout->addWidget(importExportGroupBox);
//    runGroupBoxLayout->addWidget(updateRunTableBtn);
//    runGroupBox->setFixedSize(950,250);
    QStringList runHeader;
    runTableWidget->horizontalHeader()->setFont(runTableHeaderFont);
    runTableWidget->setColumnCount(8);
    runTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    runTableWidget->resizeColumnsToContents();
    runHeader << "Subject #" << "Session #" << "Run #" << "Type #" << "Level #"
        << "Stim Seq" << "Trial #" << "Status";
    runTableWidget->setHorizontalHeaderLabels(runHeader);
    runTableWidget->setColumnHidden(0, true);
    runTableWidget->setColumnHidden(1, true);
    runTableWidget->setColumnHidden(3, true);

//    quadrantThreePerturbationLayout->addWidget(runGroupBox);
    quadrantOnePerturbationLayout->addWidget(runGroupBox);
}

void PerturbationTabWidget::showRunTableCol(int colNumber, bool showBool)
{
    runTableWidget->setColumnHidden(colNumber, showBool);
}


void PerturbationTabWidget::addTimerGroupBox()
{
    timerGroupBox = new QGroupBox;
    timerGroupBoxVerticalLayout = new QVBoxLayout;
    timerGroupBox->setLayout(timerGroupBoxVerticalLayout);
    accelDecelTimerGroupBoxHorizontalLayout->addWidget(timerGroupBox);
    
    timeAccelLabel = new QLabel;
    timeAccelLabelFont.setFamily("Times");
    timeAccelLabelFont.setWeight(75);
    timeAccelLabelFont.setPointSize(12);
    timeAccelLabel->setText("Acceleration Time: ");
    timeAccelLabel->setFont(timeAccelLabelFont);
    timeAccelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeAccelLabel->setFixedSize(190,90);
    timerGroupBoxVerticalLayout->addWidget(timeAccelLabel);
    timeAccelSpinBox = new QDoubleSpinBox;
    timeAccelSpinBoxFont.setFamily("Times");
    timeAccelSpinBoxFont.setWeight(75);
    timeAccelSpinBoxFont.setPointSize(12);
    timeAccelSpinBox->setFont(timeAccelSpinBoxFont);
    timeAccelSpinBox->setFixedSize(160,40);
    timeAccelSpinBox->setSuffix("  ms");
    timeAccelSpinBox->setRange(0.00, 100000000.00);

    timeAccelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed); 
    timerGroupBoxVerticalLayout->addWidget(timeAccelSpinBox);
    
    timeDecelLabel = new QLabel;
    timeDecelLabelFont.setFamily("Times");
    timeDecelLabelFont.setWeight(75);
    timeDecelLabelFont.setPointSize(12);
    timeDecelLabel->setFont(timeDecelLabelFont);
    timeDecelLabel->setText("Deceleration Time: ");
    timeDecelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelLabel->setFixedSize(190,90);
    timerGroupBoxVerticalLayout->addWidget(timeDecelLabel);
    timeDecelSpinBox = new QDoubleSpinBox;
    timeDecelSpinBoxFont.setFamily("Times");
    timeDecelSpinBoxFont.setWeight(75);
    timeDecelSpinBoxFont.setPointSize(12);
    timeDecelSpinBox->setFont(timeDecelSpinBoxFont);
    timeDecelSpinBox->setSuffix("  ms");
    timeDecelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelSpinBox->setFixedSize(160,40);
    timeDecelSpinBox->setRange(0.00, 100000000.00);
    timeDecelSpinBox->setValue(600.00);
    timeDecelSpinBox->setEnabled(false);
    timerGroupBoxVerticalLayout->addWidget(timeDecelSpinBox);


/*    timeGroupBox = new QGroupBox;
    timeGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBoxLayout = new QHBoxLayout;
    timeGroupBox->setLayout(timeGroupBoxLayout);
    
    timeAccelLabel = new QLabel;
    timeAccelLabelFont.setFamily("Times");
    timeAccelLabelFont.setWeight(75);
    timeAccelLabelFont.setPointSize(12);
    timeAccelLabel->setText("Acceleration Time: ");
    timeAccelLabel->setFont(timeAccelLabelFont);
    timeAccelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeAccelLabel->setFixedSize(190,180);
    timeGroupBoxLayout->addWidget(timeAccelLabel);
    timeAccelSpinBox = new QDoubleSpinBox;
    timeAccelSpinBoxFont.setFamily("Times");
    timeAccelSpinBoxFont.setWeight(75);
    timeAccelSpinBoxFont.setPointSize(12);
    timeAccelSpinBox->setFont(timeAccelSpinBoxFont);
    timeAccelSpinBox->setFixedSize(160,40);
    timeAccelSpinBox->setSuffix("  ms");
    timeAccelSpinBox->setRange(0.00, 100000000.00);

    timeAccelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed); 
    timeGroupBoxLayout->addWidget(timeAccelSpinBox);
    
    timeDecelLabel = new QLabel;
    timeDecelLabelFont.setFamily("Times");
    timeDecelLabelFont.setWeight(75);
    timeDecelLabelFont.setPointSize(12);
    timeDecelLabel->setFont(timeDecelLabelFont);
    timeDecelLabel->setText("Deceleration Time: ");
    timeDecelLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelLabel->setFixedSize(190,180);
    timeGroupBoxLayout->addWidget(timeDecelLabel);
    timeDecelSpinBox = new QDoubleSpinBox;
    timeDecelSpinBoxFont.setFamily("Times");
    timeDecelSpinBoxFont.setWeight(75);
    timeDecelSpinBoxFont.setPointSize(12);
    timeDecelSpinBox->setFont(timeDecelSpinBoxFont);
    timeDecelSpinBox->setSuffix("  ms");
    timeDecelSpinBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    timeDecelSpinBox->setFixedSize(160,40);
    timeDecelSpinBox->setRange(0.00, 100000000.00);
    timeDecelSpinBox->setValue(600.00);
    timeDecelSpinBox->setEnabled(false);
    timeGroupBoxLayout->addWidget(timeDecelSpinBox);
    
    quadrantOnePerturbationLayout->addWidget(timeGroupBox);
    timeGroupBox->hide();
*/
}

void PerturbationTabWidget::addTrialRunName()
{

}

void PerturbationTabWidget::addAccelDecelGroupBox()
{
    accelDecelTimerGroupBox = new QGroupBox;
    accelDecelTimerGroupBoxHorizontalLayout = new QHBoxLayout;
    accelDecelTimerGroupBox->setLayout(accelDecelTimerGroupBoxHorizontalLayout);
    accelDecelGroupBox = new QGroupBox;
    accelDecelGroupBoxVerticalLayout = new QVBoxLayout;
    accelDecelGroupBox->setLayout(accelDecelGroupBoxVerticalLayout);
    accelDecelTimerGroupBoxHorizontalLayout->addWidget(accelDecelGroupBox);
    accelGroupBox = new QGroupBox;
    accelDecelGroupBoxVerticalLayout->addWidget(accelGroupBox);
    accelGroupBoxVerticalLayout = new QVBoxLayout;
    accelGroupBox->setLayout(accelGroupBoxVerticalLayout);
    decelGroupBox = new QGroupBox;
    decelGroupBoxVerticalLayout = new QVBoxLayout;
    decelGroupBox->setLayout(decelGroupBoxVerticalLayout);

    accelerationLabel = new QLabel;
    accelerationLabelFont.setFamily("Times");
    accelerationLabelFont.setWeight(75);
    accelerationLabelFont.setPointSize(12);
    accelerationLabel->setFont(accelerationLabelFont);
    accelerationLabel->setText("Acceleration: ");
    accelerationLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    accelerationLabel->setFixedSize(110,90);
    accelGroupBoxVerticalLayout->addWidget(accelerationLabel);
    accelDecelGroupBoxVerticalLayout->addWidget(accelGroupBox);
    accelDecelTimerGroupBoxHorizontalLayout->addWidget(accelDecelGroupBox);
    
    acceleration = new QDoubleSpinBox;
    accelerationSpinBoxFont.setFamily("Times");
    accelerationSpinBoxFont.setWeight(75);
    accelerationSpinBoxFont.setPointSize(12);
    acceleration->setSuffix("  m/s²");
    acceleration->setRange(-15.00, 15.00);
    acceleration->setFont(accelerationSpinBoxFont);
    acceleration->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    acceleration->setFixedSize(160,40);
    accelGroupBoxVerticalLayout->addWidget(acceleration);

    decelerationLabel = new QLabel;
    decelerationLabelFont.setFamily("Times");
    decelerationLabelFont.setWeight(75);
    decelerationLabelFont.setPointSize(12);
    decelerationLabel->setFont(decelerationLabelFont);
    decelerationLabel->setText("Deceleration: ");
    decelerationLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    decelerationLabel->setFixedSize(110,90);
    decelGroupBoxVerticalLayout->addWidget(decelerationLabel);
    deceleration = new QDoubleSpinBox;
    decelerationSpinBoxFont.setFamily("Times");
    decelerationSpinBoxFont.setWeight(75);
    decelerationSpinBoxFont.setPointSize(12);
    deceleration->setSuffix("  m/s²");
    deceleration->setRange(-15.00, 15.00);
    deceleration->setFont(decelerationLabelFont);
    deceleration->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    deceleration->setFixedSize(160,40);
    decelGroupBoxVerticalLayout->addWidget(deceleration);

    accelDecelGroupBoxVerticalLayout->addWidget(decelGroupBox);

    quadrantThreePerturbationLayout->addWidget(accelDecelTimerGroupBox);

}


void PerturbationTabWidget::addStartPertRunGroupBox()
{
//    prp = new ParseRunProfile();
    sInterface = new SubjectInterface;
    sInterface->setAttribute(Qt::WA_DeleteOnClose);
    startPertRunGroupBox = new QGroupBox;
    startPertRunGroupBox->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunGroupBoxLayout = new QVBoxLayout;
    startPertRunGroupBox->setLayout(startPertRunGroupBoxLayout);
    startPertRunBtn = new QPushButton;
    nextPertRunBtn = new QPushButton;
    nextPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    nextPertRunBtn->setFixedSize(200,40);
    nextPertRunBtn->setText("Next Trial");
    prevPertRunBtn = new QPushButton;
    prevPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    prevPertRunBtn->setFixedSize(200,40);
    prevPertRunBtn->setText("Previous Trial");
    startPertRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startPertRunBtn->setFixedSize(200,40);
    startPertRunBtn->setText("Start Perturbation");    
    
    startStimRunBtn = new QPushButton;
    startStimRunBtn->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    startStimRunBtn->setFixedSize(200,40);
    startStimRunBtn->setText("Start Stimulation");
    
    startPertRunGroupBoxLayout->addWidget(startPertRunBtn);
    startPertRunGroupBoxLayout->addWidget(prevPertRunBtn);
    startPertRunGroupBoxLayout->addWidget(nextPertRunBtn);
    startPertRunGroupBoxLayout->addWidget(startStimRunBtn);
    startPertRunBtnFont.setFamily("Times");
    startPertRunBtnFont.setWeight(75);
    startPertRunBtnFont.setPointSize(12);
    startPertRunBtn->setFont(startPertRunBtnFont);
    prevPertRunBtn->setFont(startPertRunBtnFont);
    nextPertRunBtn->setFont(startPertRunBtnFont);
    startStimRunBtn->setFont(startPertRunBtnFont);
    accelDecelTimerGroupBoxHorizontalLayout->addWidget(startPertRunGroupBox);
    //startPertRunGroupBox->hide();
    //recTreadmillStream = new RecordTreadmillStream;
    readTrialNameFile = new ReadTrialNameFile("config/TrialNames.txt");
    mouseInterface = new MouseInterface;
    mouseInterface->openPort();
//    mouseInterface->SetupDigitalOutput();
    mouseInterface->SetupEventTrigger();
    mouseInterface->SetupStimTrigger();
    // The following connect waits for a change in speed data from the treadmill 
    // and when the treadmillStarted signal is received (a change in the treadmill 
    // speed is detected), treadmillWait is activated. This connect will be changed
    // to reflect the new mouse sensor system.
//    connect(recTreadmillStream, SIGNAL(treadmillStarted(double)), 
//            this, SLOT(treadmillWait(double)));
    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(getTrialName()));
//    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(startTreadmill()));
    connect(startPertRunBtn, SIGNAL(clicked()), SLOT(randomDelay()));
    connect(startPertRunBtn, SIGNAL(clicked()), mouseInterface, SLOT(WriteEvent()));  // Trigger 1
    connect(mouseInterface, SIGNAL(movement()), SLOT(treadmillWait()));
    connect(mouseInterface, SIGNAL(movementStopped()), SLOT(slotTimeout()));
    connect(startPertRunBtn, SIGNAL(clicked()), mouseInterface, SLOT(setPerturbationActiveBoolTrue()));
    connect(nextPertRunBtn, SIGNAL(clicked()), SLOT(nextRun()));
    connect(prevPertRunBtn, SIGNAL(clicked()), SLOT(prevRun()));
    connect(startStimRunBtn, SIGNAL(clicked()), SLOT(startStim()));
}

void PerturbationTabWidget::addEmgDataVisualization()
{
    QQuickView* viewer = new QQuickView;
    QWidget *container = QWidget::createWindowContainer(viewer, this);
    container->setMinimumSize(700, 800);
    container->setMaximumSize(700, 800);
    viewer->setFormat(QtDataVisualization::qDefaultSurfaceFormat());
#ifdef Q_OS_WIN
    QString extraImportPath(QStringLiteral("%1/../../../../%2"));
#else
    QString extraImportPath(QStringLiteral("%1/../../../%2"));
#endif
    viewer->engine()->addImportPath(extraImportPath.arg(QGuiApplication::applicationDirPath(),
                QString::fromLatin1("qml")));
    QObject::connect(viewer->engine(), &QQmlEngine::quit, viewer, &QWindow::close);

    viewer->setTitle(QStringLiteral("Oscilloscope example"));

    DataSource* dataSource = new DataSource;
    viewer->rootContext()->setContextProperty("dataSource", dataSource);

    viewer->setSource(QUrl("main.qml"));
    viewer->setResizeMode(QQuickView::SizeRootObjectToView);
    /*    qmlRegisterType<QmlInterface>("io.qt.examples.backend", 1, 0, "QmlInterface");
          QQmlApplicationEngine engine;
          engine.load(QUrl(QStringLiteral("QmlInterface.qml")));
    */
//    quadrantTwoPerturbationLayout->addWidget(container);
}

/*void PerturbationTabWidget::addRecordDataStreamVelocityBox()
{
    recTreadmillStream->hide();

    quadrantThreePerturbationLayout->addWidget(recTreadmillStream);

}
*/
void PerturbationTabWidget::setAddToSpeed(double mAddToSpeed)
{
    addToSpeed = mAddToSpeed;
}

void PerturbationTabWidget::showTimer(bool state)
{
    if(state)
    {
        timerGroupBox->show();
        startPertRunGroupBox->show();
    }
    else
    {
        timerGroupBox->hide();
        startPertRunGroupBox->hide();
    }
}

void PerturbationTabWidget::showFudgeFactorGroupBox(bool state)
{
    if(state)
    {
        fudgeFactorGroupBox->show();
    }
    else
    {
       fudgeFactorGroupBox->hide();
    }
}

void PerturbationTabWidget::setAccelerationTimeValue(double maccelTimeValue)
{
    accelerationTimeValue = maccelTimeValue;

    std::cout << "Acceleration Time Set to: " << accelerationTimeValue << std::endl;
}

void PerturbationTabWidget::setDecelerationTimeValue(double mdecelTimeValue)
{
    decelerationTimeValue = mdecelTimeValue;

    std::cout << "Deceleration Time Set to: " << decelerationTimeValue << std::endl;
}

void PerturbationTabWidget::setAccelerationValue(double maccelValue)
{
    accelerationValue = fabs(maccelValue);
    sendSetpoints->setAccelerationValue(accelerationValue);
    std::cout << "Acceleration Value Set to: " << accelerationValue << std::endl;
}

void PerturbationTabWidget::setDecelerationValue(double mdecelValue)
{
    decelerationValue = fabs(mdecelValue);
    sendSetpoints->setDecelerationValue(decelerationValue);
    std::cout << "Deceleration Set to: " << decelerationValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValue(double mleftFrontSpeedValue)
{

    leftSpeedFrontValue = mleftFrontSpeedValue;
    sendSetpoints->setLeftFrontSpeedValue(leftSpeedFrontValue);
    std::cout << "Left Front Speed Set to: " << leftSpeedFrontValue << std::endl;
}

void PerturbationTabWidget::setLeftFrontSpeedValueFromIncoming(qint16 mleftFrontSpeedValue)
{
    leftSpeedFrontValue = static_cast<double>(mleftFrontSpeedValue);
}

void PerturbationTabWidget::setRightFrontSpeedValue(double mrightFrontSpeedValue)
{
    rightSpeedFrontValue = mrightFrontSpeedValue;  
    sendSetpoints->setRightFrontSpeedValue(rightSpeedFrontValue);
    std::cout << "Right Front Speed Set to: " << rightSpeedFrontValue << std::endl;

}

void PerturbationTabWidget::setRightFrontSpeedValueFromIncoming(qint16 mrightFrontSpeedValue)
{
  rightSpeedFrontValue = static_cast<double>(mrightFrontSpeedValue); 
}

double PerturbationTabWidget::getAccelerationTimeValue()
{
    return accelerationTimeValue;
}

double PerturbationTabWidget::getDecelerationTimeValue()
{
    return decelerationTimeValue;
}

double PerturbationTabWidget::getAccelerationValue()
{
    return accelerationValue;
}
double PerturbationTabWidget::getDecelerationValue()
{
    return decelerationValue;
}
double PerturbationTabWidget::getLeftFrontSpeedValue()
{
    return leftSpeedFrontValue;
}
double PerturbationTabWidget::getRightFrontSpeedValue()
{
    return rightSpeedFrontValue;
}

void PerturbationTabWidget::setUseLibraryStatus(bool useLibCheckBox)
{
    useLibraryCheckBoxStatus = useLibCheckBox;
}

void PerturbationTabWidget::randomDelay()
{
    sInterface->changeToCircle(true);
    startPertRunBtn->setDisabled(true);
    nextPertRunBtn->setDisabled(true);
    prevPertRunBtn->setDisabled(true);
    int randomTime = rand() % 2000 + 2000;
    qDebug("Random Time: %i", randomTime);
    QFile randomDelayLog(logPath + "/" + "randomDelayLog.log");
    randomDelayLog.open(QIODevice::Append);
    randomDelayLog.write(QString::number(randomTime).toUtf8() + "\n");
    randomDelayLog.close();
//    mouseInterface->WriteLine();
    QTimer::singleShot(randomTime, this, SLOT(startTreadmill()));
}

void PerturbationTabWidget::startTreadmill()
{
    QFile accelerationSignalSentLog(logPath + "/" + "accelerationSignalSentLog.log");
    accelerationSignalSentLog.open(QIODevice::Append);
/*    int low = 0;
    int hi  = 6;
    int millisecondsConversionFactor = 1000;
    int randomMilliseconds = qrand() % ((hi + 1) - low) + low;
    int millisecondsToSeconds = randomMilliseconds * millisecondsConversionFactor;
    QTimer timer;
    timer.setSingleShot(true);*/
//    recTreadmillStream->setRecord();
    setAccelerationValue(acceleration->value());
    setDecelerationValue(deceleration->value());
    setAccelerationTimeValue(timeAccelSpinBox->value());
    setDecelerationTimeValue(timeDecelSpinBox->value());
    setAddToSpeed(fudgeFactorDoubleSpinBox->value());
    qDebug() << addToSpeed;
    setLeftFrontSpeedValue(calculateSpeed());
    setRightFrontSpeedValue(calculateSpeed());
    //timer.start(millisecondsToSeconds);

    //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::setprecision(5);
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    accelerationSignalSentLog.write(uptimeString.toUtf8() + "\n");
    //-----------------------------------------------------------------------

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationSignalSentLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    accelerationSignalSentLog.close();
    mouseInterface->WriteEvent(); // Trigger 2
    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::ACCEL, SendSetpoints::NormalSetpoint);
    //    recTreadmillStream->setSharedSocket(pertSocket);
//    recTreadmillStream->startDataCollection();
}

void PerturbationTabWidget::treadmillWait()
{
    QFile accelerationTimerStartedLog(logPath + "/" + "accelerationTimerStartedLog.log");
    accelerationTimerStartedLog.open(QIODevice::Append);
    double retAccelValue;
    //double timeSinceStart = fabs((mvelocity / fabs(getAccelerationValue())) * 1000.00);
//    retAccelValue = fabs(( getAccelerationTimeValue() * fabs(getAccelerationValue())) / 1000);

    retAccelValue = getAccelerationTimeValue();
    qDebug("Deceleration Time Set To: %f", retAccelValue);

   //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

 
    mouseInterface->setMovementBool(true);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    accelerationTimerStartedLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    accelerationTimerStartedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerStartedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    accelerationTimerStartedLog.close();
    mouseInterface->WriteEvent(); // Trigger 4
    QTimer::singleShot(retAccelValue, this, SLOT(startDecelTimer()));
}

void PerturbationTabWidget::startDecelTimer()
{

    //-----------------------------------------------------------------------
    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

    QFile accelerationTimerEndedLog(logPath + "/" + "accelerationTimerEndedLog.log");
    QFile decelerationSignalSentLog(logPath + "/" + "decelerationSignalSentLog.log");
    QFile decelerationTimerStartedLog(logPath + "/" + "decelerationTimerStartedLog.log");
    accelerationTimerEndedLog.open(QIODevice::Append);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerEndedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    accelerationTimerEndedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------

    accelerationTimerEndedLog.close();
    decelerationSignalSentLog.open(QIODevice::Append);
    decelerationTimerStartedLog.open(QIODevice::Append);
    mouseInterface->setMovementBool(false);
    double retDecelTimeValue = getDecelerationTimeValue();
    setRightFrontSpeedValue(0);
    setLeftFrontSpeedValue(0);
//    qDebug("Sending Setpoints...");
 
    //-----------------------------------------------------------------------
    uptime = std::chrono::milliseconds(GetTickCount());
    out << std::chrono::milliseconds(uptime).count() << "ms";
    uptimeStdString = out.str();
    uptimeString = QString::fromStdString(uptimeStdString);
    decelerationSignalSentLog.write(uptimeString.toUtf8() + "\n");
    //-----------------------------------------------------------------------

    sendSetpoints->sendSetpoints(SendSetpoints::TreadmillProperty::DECEL, SendSetpoints::NormalSetpoint);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    decelerationSignalSentLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    decelerationSignalSentLog.close();
//    qDebug("Starting Timer...");
//    qDebug("Deceleration will commence for %f seconds", retDecelTimeValue/millisecondConversion);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    uptime = std::chrono::milliseconds(GetTickCount());
    
    out << std::chrono::milliseconds(uptime).count() << "ms";
    uptimeStdString = out.str();
    uptimeString = QString::fromStdString(uptimeStdString);
    decelerationTimerStartedLog.write(uptimeString.toUtf8() + "\n");

    //-----------------Current Unix Timestamp--------------------------------
    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    decelerationTimerStartedLog.write("Unix System Timestamp:" + QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    //-----------------------------------------------------------------------
    
    decelerationTimerStartedLog.close();
    mouseInterface->WriteEvent(); // Trigger 5
//    mouseInterface->setPerturbationActiveBoolFalse();
//    mouseInterface->setMovementDetectedBool(false);
   

    QTimer::singleShot(retDecelTimeValue, this, SLOT(slotTimeout()));
//    recTreadmillStream->setRecord();
//    emit recTreadmillStream->setEmitComplete();
}

void PerturbationTabWidget::slotTimeout()
{
    mouseInterface->setMovementDetectedBool(false);
    QString complete("Complete");
    columnIndex = 7;
    runTableWidget->setItem(currentRunRowIndex, columnIndex, 
            new QTableWidgetItem(tr("%1").arg(complete)));
    runTableWidget->item(currentRunRowIndex, columnIndex)->setFont(tableRowsFont);
    sInterface->setTrialComplete(true);
    mouseInterface->setPerturbationActiveBoolFalse();
    mouseInterface->setMovementDetectedBool(false);
    startPertRunBtn->setDisabled(false);
    nextPertRunBtn->setDisabled(false);
    prevPertRunBtn->setDisabled(false);
    //-----------------------------------------------------------------------
/*    auto uptime = std::chrono::milliseconds(GetTickCount());
    std::ostringstream out;
    out << std::chrono::milliseconds(uptime).count() << "ms";
    std::string uptimeStdString = out.str();
    QString uptimeString = QString::fromStdString(uptimeStdString);
    //-----------------------------------------------------------------------

    QFile decelerationTimerEndedLog(logPath + "/" + "decelerationTimerEndedLog.log");
    QFile zeroSignalSentLog(logPath + "/" + "zeroSignalSentLog.log");
    decelerationTimerEndedLog.open(QIODevice::Append);
    zeroSignalSentLog.open(QIODevice::Append);
//    qint64 currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
    decelerationTimerEndedLog.write(uptimeString.toUtf8() + "\n");

    mouseInterface->WriteLine();
    decelerationTimerEndedLog.close();
    sendSetpoints->sendSetpoints(SendSetpoints::ZERO, SendSetpoints::NormalSetpoint);
//    currentMsecsSinceEpoch = QDateTime::currentMSecsSinceEpoch();
//    zeroSignalSentLog.write(QString::number(currentMsecsSinceEpoch).toUtf8() + "\n");
    zeroSignalSentLog.write(uptimeString.toUtf8() + "\n");
    zeroSignalSentLog.close();
    std::cout << "Trial Ended" << std::endl;
    mouseInterface->setPerturbationActiveBoolFalse();
//    mouseInterface->StopTask();
    //recTreadmillStream->stopRecord();
*/
}



void PerturbationTabWidget::setSocket(QAbstractSocket* socket)
{
    pertSocket = socket;
    sendSetpoints->setSocket(socket);
}

double PerturbationTabWidget::calculateSpeed()
{
    //double addToSpeed = 100;    //Added to compensate for flat top
    return ((acceleration->value() * ((getAccelerationTimeValue()/millisecondConversion) + 
                    (addToSpeed / 1000)))); 
}



void PerturbationTabWidget::loadRunProfile()
{
    currentRunRowIndex = 0;

    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), \
            "C:\\Users\\User\\Desktop\\HReflex_Binaries-master\\RunProfiles", \
            tr("CSV (*.csv)"));
    if(fileName == "")
    {
        QMessageBox errLoadFile;
        errLoadFile.setText("Error Loading File");
        errLoadFile.exec();
    }
    else
    {
        runTableWidget->setRowCount(0);
        prp->setRunFile(fileName);
        tableFilled = false;
        prp->getRuns();
        prp->getRun(1);
        mouseInterface->SetupChannelSelection();
        setAccelerationValue(prp->getAccelLeft());
        acceleration->setValue(prp->getAccelLeft());
        setDecelerationValue(prp->getDecelLeft());
        deceleration->setValue(prp->getDecelLeft());
        timeAccelSpinBox->setValue(prp->getAccelTime());
        setAccelerationTimeValue(prp->getAccelTime());
        populateRunsTextBox();
        runTableWidget->selectRow(currentRunRowIndex);
        sInterface->startTrialRun(true);
        setPleaseStandQuietly();
        setStimChannel();
    }
}

void PerturbationTabWidget::setStimChannel()
{
    QString stimLevel(prp->getStimSeq());
    qDebug() << "Stim Level from PerturbationTabWidget: " << stimLevel.split(",");
    stimChannelA = stimLevel.split(",")[0].toInt();  
    stimChannelB = stimLevel.split(",")[1].toInt(); 
}

/*void PerturbationTabWidget::saveVelocityData()
{
    recTreadmillStream->setVelocityFileName();
}

void PerturbationTabWidget::setHost(QString mhost)
{
    host = mhost;
    recTreadmillStream->setHost(host);
    qDebug("From PerturbationTabWidget: The host is %s ", qPrintable(host));
    
}

void PerturbationTabWidget::setPort(QString mport)
{
    port = mport;
    recTreadmillStream->setPort(port);
    qDebug("From PerturbationTabWidget: The port is %s ", qPrintable(port));
}
*/

void PerturbationTabWidget::getTrialName()
{
    QString trialName(readTrialNameFile->getTrialName());
    setLoggingDirectory(trialName);
}

void PerturbationTabWidget::setLoggingDirectory(QString dirName)
{
    QString dataDir("data");
    if(!QDir(dataDir).exists())
    {
        QDir().mkdir(dataDir);
    }
    dirName = dirName.remove(QRegExp("[\\n\\t\\r]"));   
    dirName = dataDir + "/" + dirName;// + "_" + trialRun;
    qDebug() << dirName;

    if(!QDir(dirName).exists())
    {
        QDir().mkdir(dirName);
    }

    trialRun++;
    if(trialRun > 2)
    {
        trialRun = 1;
    }

    logPath = dirName;
    mouseInterface->setLogPath(logPath);
}

void PerturbationTabWidget::disableButton()
{
    startPertRunBtn->setEnabled(false);
}

void PerturbationTabWidget::enableButton()
{
    startPertRunBtn->setEnabled(true);
}

void PerturbationTabWidget::nextRun()
{
    int pleaseStandQuietly = 10000;
    //sInterface->setRunOver(true);
    sInterface->startTrialRun(true);
    QTimer::singleShot(pleaseStandQuietly, this, SLOT(setPleaseStandQuietly()));
    currentRunRowIndex++;
    prp->getRun(1);
    setAccelerationValue(prp->getAccelLeft());
    acceleration->setValue(prp->getAccelLeft());
    setDecelerationValue(prp->getDecelLeft());
    deceleration->setValue(prp->getDecelLeft());
    timeAccelSpinBox->setValue(prp->getAccelTime());
    setAccelerationTimeValue(prp->getAccelTime());
    runTableWidget->selectRow(currentRunRowIndex);
}

void PerturbationTabWidget::setPleaseStandQuietly()
{
    QString plsStandQuietly("Please Stand Quietly");
    sInterface->updateTextField(plsStandQuietly);
}

void PerturbationTabWidget::prevRun()
{
    sInterface->setRunOver(true);
    sInterface->startTrialRun(true);

    setCellChangedFalse();
    if(currentRunRowIndex > 0)
    {
        currentRunRowIndex--;
    }
    else 
    {
        currentRunRowIndex = 0;
    }
    prp->getRun(-2);
    QString empty("");
    runTableWidget->item(currentRunRowIndex, columnIndex)->setText(empty);
    runTableWidget->item(currentRunRowIndex, columnIndex)->setFont(tableRowsFont);
    setAccelerationValue(prp->getAccelLeft());
    acceleration->setValue(prp->getAccelLeft());
    setDecelerationValue(prp->getDecelLeft());
    deceleration->setValue(prp->getDecelLeft());
    timeAccelSpinBox->setValue(prp->getAccelTime());
    setAccelerationTimeValue(prp->getAccelTime());
    runTableWidget->selectRow(currentRunRowIndex);
}

void PerturbationTabWidget::setLeftStimCurrent()
{
    QVariant leftStimCurrent;
    int multFactor(10);
    int leftStimCrnt;
    if(!(QMetaObject::invokeMethod(personSessionStimQuickViewItem, "getLeftCurrent", Q_RETURN_ARG(QVariant, leftStimCurrent))))
    {
        qDebug("Method failed to invoke");
    }
    DS8Controller.ToggleOutput(TRUE);
    qDebug() << "Stim Current: " << leftStimCurrent.toInt();
    leftStimCrnt = leftStimCurrent.toInt();
    DS8Controller.SetVariables(0,0,leftStimCrnt,0,0,0,TRUE);
    DS8Controller.UpdateDS8();
}

void PerturbationTabWidget::setRightStimCurrent()
{
    QVariant rightStimCurrent;
    int multFactor(10);
    int rightStimCrnt;
    if(!(QMetaObject::invokeMethod(personSessionStimQuickViewItem, "getRightCurrent", Q_RETURN_ARG(QVariant, rightStimCurrent))))
    {
        qDebug("Method failed to invoke");
    }
    DS8Controller.ToggleOutput(TRUE);
    qDebug() << "Stim Current: " << rightStimCurrent.toInt();
    rightStimCrnt = rightStimCurrent.toInt();
    DS8Controller.SetVariables(0,0,rightStimCrnt,0,0,0,TRUE);
    DS8Controller.UpdateDS8();
}

void PerturbationTabWidget::startStim()
{
    if(stimChannelA == 1)
    {
        setLeftStimCurrent();
    }
    else if(stimChannelA == 2)
    {
        setRightStimCurrent();
    }

    mouseInterface->WriteChannel(stimChannelA);

    if(stimChannelB == 1)
    {
        setLeftStimCurrent();
    }
    else if(stimChannelB == 2)
    {
        setRightStimCurrent();
    }

        //randomDelay();
}

void PerturbationTabWidget::populateRunsTextBox()
{
    runTableWidget->setRowCount(0);
    QVector<QString> runs;
    QVector<QString> runHead;
    runs = prp->getRunsVector();
    runHead = prp->getRunProfileHead();
    runTableWidget->setRowCount(runs.size());
    int indexX = 0;
    int indexY = 0;
    int stopIndex = 2;
    int indexA = 0;
    int indexB = 3;
    int stopIndexC = 3;
    int indexRow = 0;
    int indexCol = 6;
    int statusCol = 7;
    QComboBox* levelComboBox;
    QStringList levelList;
    tableRowsFont.setFamily("Times");
    tableRowsFont.setWeight(75);
    tableRowsFont.setPointSize(18);

    for(const auto& runHeader : runHead)
    {
        QString runHdrTemp(runHeader.split('"')[1]);
        runTableWidget->setItem(indexX, indexY, 
                new QTableWidgetItem(tr("%1").arg(runHdrTemp)));
        runTableWidget->item(indexX, indexY)->setFont(tableRowsFont);
        indexY++;
        if(indexY > stopIndex)
        {
            indexY = 0;
            indexX++;
        }
    }

    for(const auto& run : runs)
    {
        runTableWidget->setItem(indexA, indexB, new QTableWidgetItem(tr("%1").arg(run.split(',')[0])));
        runTableWidget->item(indexA, indexB)->setFont(tableRowsFont);
        indexB++;
        runTableWidget->setItem(indexA, indexB, new QTableWidgetItem(tr("%1").arg(run.split(',')[1])));
        runTableWidget->item(indexA, indexB)->setFont(tableRowsFont);
        indexB++;
        runTableWidget->setItem(indexA, indexB, new QTableWidgetItem(tr("%1").arg(run.split(',')[2])));
        runTableWidget->item(indexA, indexB)->setFont(tableRowsFont);
        indexB++;
        runTableWidget->setItem(indexA, indexB, new QTableWidgetItem(tr("%1").arg(run.split(',')[3])));
        runTableWidget->item(indexA, indexB)->setFont(tableRowsFont);
        indexB++;
        runTableWidget->setItem(indexA, statusCol, new QTableWidgetItem(tr("%1").arg("")));

        if(indexB > stopIndexC)
        {
            indexB = 3;
            indexA++;
        }
    }

    tableFilled = true;

}

void PerturbationTabWidget::updateRun(int cellRow, int cellCol)
{
    int participantIdCol = 0;
    int sessionIdCol = 1;
    int runNoCol = 2;
    int typeCol = 3;
    int levelCol = 4;
    int stimCol = 5;
    int trialNoCol = 6;
    int statusCol = 7;
    QString tableName("currentRunProfile");
    QString runProfileTable("runProfile");



    if(cellCol == trialNoCol && tableFilled && cellDoubleClicked)
    {
        QTableWidgetItem* trialNumberItem = runTableWidget->item(cellRow, trialNoCol);
        QString trialNo(trialNumberItem->text());

        cellRow += 1;

        while(cellRow < runTableWidget->rowCount())
        {
            runTableWidget->item(cellRow, trialNoCol)->setText(tr("%1").arg(returnTrialNum(trialNo)));

            trialNo = returnTrialNum(trialNo);

            QTableWidgetItem* participantItem = runTableWidget->item(cellRow, participantIdCol);
            QString participant(participantItem->text());
            QTableWidgetItem* sessionItem = runTableWidget->item(cellRow, sessionIdCol);
            QString session(sessionItem->text());
            QTableWidgetItem* runNoItem = runTableWidget->item(cellRow, runNoCol);
            QString runNo(runNoItem->text());
            QTableWidgetItem* typeNoItem = runTableWidget->item(cellRow, typeCol);
            QString typeNo(typeNoItem->text());
            QTableWidgetItem* levelNoItem = runTableWidget->item(cellRow, levelCol);
            QString levelNo(levelNoItem->text());
            QTableWidgetItem* stimSeqNoItem = runTableWidget->item(cellRow, stimCol);
            QString stimOrderNo(stimSeqNoItem->text());
            
            
            cellRow++;
        }

        cellRow = 0;
        
        while(cellRow < runTableWidget->rowCount())
        {
            qDebug() << "Cell Row: " << QString::number(cellRow);
            trialNumberItem = runTableWidget->item(cellRow, trialNoCol);
            trialNo = trialNumberItem->text();

            QString setString("trial = " );
            setString += "\"" + trialNo + "\"";
            QString whereString("ROWID = ");
            whereString += "\"" + QString::number(cellRow + 1);
            whereString += "\""; 

            prp->updateRunTable(tableName, setString, whereString);
            cellRow++;
        }

        prp->clearRunResultsVector();
        prp->getRuns();
        
    }
    else if(cellCol == levelCol && tableFilled && cellDoubleClicked)
    {
        int participantColCoord = 0;
        int sessionIdColCoord = 1;
        int runNumberColCoord = 2;
        int typeNumberColCoord = 3;
        int levelNumberColCoord = 4;
        int stimSeqNumberColCoord = 5;
        int trialNumberColCoord = 6;
        QRegularExpression numbers("^(.)([0-9]+)$|^(.)([A-Z])([0-9]+$)");
        QTableWidgetItem* participantIdItem = runTableWidget->item(cellRow, participantColCoord);
        QString participantId(participantIdItem->text());
        QTableWidgetItem* sessionIdItem = runTableWidget->item(cellRow, sessionIdColCoord);
        QString sessionNo(sessionIdItem->text());
        QTableWidgetItem* runNumberItem = runTableWidget->item(cellRow, runNumberColCoord);
        QString runNo(runNumberItem->text());
        QTableWidgetItem* typeNumberItem = runTableWidget->item(cellRow, typeNumberColCoord);
        QString type(typeNumberItem->text());
        QTableWidgetItem* levelNumberItem = runTableWidget->item(cellRow, levelNumberColCoord);
        QString level(levelNumberItem->text());
        QTableWidgetItem* stimSeqNumberItem = runTableWidget->item(cellRow, stimSeqNumberColCoord);
        QString stimOrder(stimSeqNumberItem->text());
        QTableWidgetItem* trialNumberItem = runTableWidget->item(cellRow, trialNumberColCoord);
        QString trialNo(trialNumberItem->text());
        
        int cellRowBckup = cellRow;

        while(cellRow < runTableWidget->rowCount())
        {
            QString setString("level = " );
            setString += "\"" + level + "\"";
            QString whereString("ROWID = ");
            whereString += "\"" + QString::number(cellRow + 1);
            whereString += "\""; 

            prp->updateRunTable(tableName, setString, whereString);
            cellRow++;
        }

        cellRow = cellRowBckup;
        
        prp->clearRunResultsVector();
        prp->getRuns();

        QRegularExpressionMatchIterator numIter = numbers.globalMatch(type);
        QString typeNum;
        QString levelNum;

        while(numIter.hasNext())
        {
            QRegularExpressionMatch match = numIter.next();
            typeNum = match.captured(2);
            qDebug() << typeNum;
        }

        numIter = numbers.globalMatch(level);

        while(numIter.hasNext())
        {
            QRegularExpressionMatch match = numIter.next();
            levelNum = match.captured(2);
            qDebug() << levelNum;
        }

        QMessageBox::StandardButton reply;
        
        if(prp->getDirectionFromDb(typeNum,levelNum) == 0)
        {
            setAccelerationValue(-(prp->getAccelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\"")));
            acceleration->setValue(-(prp->getAccelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\"")));
            setDecelerationValue(-(prp->getDecelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\"")));
            deceleration->setValue(-(prp->getDecelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\"")));
            timeAccelSpinBox->setValue(prp->getAccelTimeDb("\"" + typeNum + "\""));
            setAccelerationTimeValue(prp->getAccelTimeDb("\"" + typeNum + "\""));
        }

        else
        {
            setAccelerationValue(prp->getAccelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\""));
            acceleration->setValue(prp->getAccelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\""));
            setDecelerationValue(prp->getDecelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\""));
            deceleration->setValue(prp->getDecelLeftDb("\"" + typeNum + "\"", "\"" + levelNum + "\""));
            timeAccelSpinBox->setValue(prp->getAccelTimeDb("\"" + typeNum + "\""));
            setAccelerationTimeValue(prp->getAccelTimeDb("\"" + typeNum + "\""));
        }

        QVector<QString> runs;
        runs = prp->getRunsVector();
        qDebug() << "updateRuns: " << runs;
        qDebug() << "New Runs: " << runs[0].split(',')[0];

        while(cellRow < runTableWidget->rowCount())
        {
            if(cellCol == participantIdCol)
            {
            runTableWidget->item(cellRow, participantColCoord)->setText(tr("%1").arg
                    (participantId));    
            }
            else if(cellCol == sessionIdCol)
            {
                runTableWidget->item(cellRow, sessionIdColCoord)->setText(tr("%1").arg
                    (sessionNo));    
            }
            else if(cellCol == runNoCol)
            {
                runTableWidget->item(cellRow, runNumberColCoord)->setText(tr("%1").arg
                    (runNo));    
            }
            else if(cellCol == typeCol)
            {
                runTableWidget->item(cellRow, typeNumberColCoord)->setText(tr("%1").arg
                    (type));    
            }
            else if(cellCol == levelCol)
            {
                runTableWidget->item(cellRow, levelNumberColCoord)->setText(tr("%1").arg
                    (level));    
            }
            else if(cellCol == stimCol)
            {
                runTableWidget->item(cellRow, stimSeqNumberColCoord)->setText(tr("%1").arg
                    (stimOrder));    
            }
            
            cellRow++;
        }
    }
    
    else if(cellCol == runNoCol && tableFilled && cellDoubleClicked)
    {
        qDebug() << "Welcome to the Run Column";
        int runNumberColCoord = 2;
        QTableWidgetItem* runNumberItem = runTableWidget->item(cellRow, runNumberColCoord);
        QString runNo(runNumberItem->text());
        
        int cellRowBckup = cellRow;

        while(cellRow < runTableWidget->rowCount())
        {
            QString setString("runNo = " );
            setString += "\"" + runNo + "\"";
            QString whereString("ROWID = ");
            whereString += "\"" + QString::number(cellRow + 1);
            whereString += "\""; 

            prp->updateRunTable(tableName, setString, whereString);
            cellRow++;
        }
        cellRow = cellRowBckup;
        
        while(cellRow < runTableWidget->rowCount())
        {
            runTableWidget->item(cellRow, runNumberColCoord)->setText(tr("%1").arg
                    (runNo));   
            cellRow++;
        }

    }
}

QString PerturbationTabWidget::returnTrialNum(QString trialString)
{
    QString newTrialNum;
    QRegularExpression numbers("^(.)([A-Z])([0-9]+$)");
    QRegularExpressionMatchIterator numIter = numbers.globalMatch(trialString);
    QString trial;
    QString tr = "TR";
    int width = 4;
    int trialNum;

    qDebug() << "Trial String: " << trialString;

    while(numIter.hasNext())
    {
        QRegularExpressionMatch match = numIter.next();
        trial = match.captured(3);
        trialNum = trial.toInt() + 1;
    }

    if(QString::number(trialNum).size() < width) 
    {
        newTrialNum = QString(width - QString::number(trialNum).size(), '0') + QString::number(trialNum);
    }
//    qDebug() << "Trial Number: " << tr + newTrialNum;

    return tr + newTrialNum;
}

void PerturbationTabWidget::exportTable()
{
    qDebug() << "Hello from exportTable()";
    QVector<QString> rowVec;
    QString rowString;
    saveFile();
    for(int row = 0; row < runTableWidget->rowCount(); row++)
    {
        for(int col = 0; col < runTableWidget->columnCount(); col++)
        {
            QTableWidgetItem* item = runTableWidget->item(row,col);
            if(!item || !(item->text().isEmpty()))
            {
                rowVec.append(item->text());
            }
            rowVec.append("_");
        }
        for(auto& item : rowVec)
        {
            rowString += item;
        }
        int pos = rowString.lastIndexOf(QChar('_'));
        qDebug() << rowString.left(pos-1);
        saveProfile->open(QIODevice::ReadWrite);
        *saveProfileStream << rowString.left(pos-1) << "\n";

        rowString = "";
        rowVec.clear();
    }

    saveProfile->close();
}

void PerturbationTabWidget::saveFile()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Profile"), \
            "C:\\Users\\User\\Desktop\\HReflex_Binaries-master\\RunProfiles", \
            tr("CSV (*.csv)"));
    if(fileName == "")
    {
        QMessageBox errLoadFile;
        errLoadFile.setText("Error Loading File");
        errLoadFile.exec();
    }
    saveProfile = new QFile(fileName);
    saveProfileStream = new QTextStream(saveProfile);
}

void PerturbationTabWidget::setCellChangedTrue(int mCellRow, int mCellCol)
{
    cellDoubleClicked = true;
}

void PerturbationTabWidget::setCellChangedFalse()
{
    cellDoubleClicked = false;
}

void PerturbationTabWidget::showSubjectView()
{
}

void PerturbationTabWidget::setStimTimer(double time)
{
    stimTimer = time;
}

#include "../include/moc_PerturbationTabWidget.cpp"
