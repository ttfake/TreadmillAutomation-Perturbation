#include "../include/InstrumentationPanel.h"

InstrumentationPanel::InstrumentationPanel(QWidget* parent, Qt::WindowFlags flags)
{
    instrumentationPanelLayout = new QVBoxLayout;
    instTabWidget = new QTabWidget;
    setLayout(instrumentationPanelLayout);
    instrumentationPanelLayout->addWidget(instTabWidget);
    setWindowFlags(Qt::Window);
    createInstrumentationEmgTab();
    addEMGQuadrant();
}

void InstrumentationPanel::createInstrumentationEmgTab()
{
    emgTab = new QWidget;
    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    emgTabGridLayout = new QGridLayout;
    emgTab->setLayout(emgTabGridLayout);
    setObjectName("EMG Display");
    instTabWidget->addTab(emgTab, "EMG");
}

void InstrumentationPanel::addEMGQuadrant()
{
    QPalette* pal = new QPalette;
    pal->setColor(QPalette::Background, Qt::black);
    emgGroupBox = new QGroupBox;
    emgGroupBoxCh1To3 = new QGroupBox;
    emgGroupBoxCh1To3->setStyleSheet("border:none");
    emgGroupBoxCh1To3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    emgGroupBoxCh1To3->setFixedSize(700,600);
    emgGroupBoxCh1To3->setAutoFillBackground(true);
    emgGroupBoxCh1To3->setPalette(*pal);
    emgGroupBoxCh1To3VLayout = new QVBoxLayout;
    emgGroupBoxCh1To3->setLayout(emgGroupBoxCh1To3VLayout);
    
    emgGroupBoxCh4To6 = new QGroupBox;
    emgGroupBoxCh4To6->setStyleSheet("border:none");
    emgGroupBoxCh4To6->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    emgGroupBoxCh4To6->setFixedSize(700,600);
    emgGroupBoxCh4To6VLayout = new QVBoxLayout;
    emgGroupBoxCh4To6->setLayout(emgGroupBoxCh4To6VLayout);
    
    emgGroupBoxCh7To8 = new QGroupBox;
    emgGroupBoxCh7To8->setStyleSheet("border:none");
    emgGroupBoxCh7To8->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    emgGroupBoxCh7To8->setFixedSize(700,600);
    emgGroupBoxCh7To8VLayout = new QVBoxLayout;
    emgGroupBoxCh7To8->setLayout(emgGroupBoxCh7To8VLayout);

       
    emgGroupBoxHLayout = new QHBoxLayout;
    emgGroupBox->setLayout(emgGroupBoxHLayout);
    emgGroupBoxHLayout->addWidget(emgGroupBoxCh1To3);
    emgGroupBoxHLayout->addWidget(emgGroupBoxCh4To6);
    emgGroupBoxHLayout->addWidget(emgGroupBoxCh7To8);
    emgTabGridLayout->addWidget(emgGroupBox);
    addEmgDataVisualization();
}

InstrumentationPanel::~InstrumentationPanel()
{
    qDebug() << "InstrumentationPanel destructor called";
}

void InstrumentationPanel::showInstPanel()
{
    show();
}

void InstrumentationPanel::closeWindow()
{
    close();
}

void InstrumentationPanel::addEmgDataVisualization()
{
    QQuickView* channel1QuickView = new QQuickView;
    ch1DataSource = new DataSource(channel1QuickView);
    chDataSourceVector.append(ch1DataSource);
    channel1 = new EmgChannel(0, 0, "Channel1.qml", "Channel 1", ch1DataSource, channel1QuickView);
    channel1->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel1->setFixedSize(600,200);
    emgGroupBoxCh1To3VLayout->addWidget(channel1);
    
    QQuickView* channel2QuickView = new QQuickView;
    ch2DataSource = new DataSource(channel2QuickView);
    chDataSourceVector.append(ch2DataSource);
    channel2 = new EmgChannel(0, 0, "Channel2.qml", "Channel 2", ch2DataSource, channel2QuickView);
    channel2->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel2->setFixedSize(600,200);
    emgGroupBoxCh1To3VLayout->addWidget(channel2);
    
    QQuickView* channel3QuickView = new QQuickView;
    ch3DataSource = new DataSource(channel3QuickView);
    chDataSourceVector.append(ch3DataSource);
    channel3 = new EmgChannel(0, 0, "Channel3.qml", "Channel 3", ch3DataSource, channel3QuickView);
    channel3->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel3->setFixedSize(600,200);
    emgGroupBoxCh1To3VLayout->addWidget(channel3);
    
    QQuickView* channel4QuickView = new QQuickView;
    ch4DataSource = new DataSource(channel4QuickView);
    chDataSourceVector.append(ch4DataSource);
    channel4 = new EmgChannel(0, 0, "Channel4.qml", "Channel 4", ch4DataSource, channel4QuickView);
    channel4->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel4->setFixedSize(600,200);
    emgGroupBoxCh4To6VLayout->addWidget(channel4);

    QQuickView* channel5QuickView = new QQuickView;
    ch5DataSource = new DataSource(channel5QuickView);
    chDataSourceVector.append(ch5DataSource);
    channel5 = new EmgChannel(0, 0, "Channel5.qml", "Channel 5", ch5DataSource, channel5QuickView);
    channel5->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel5->setFixedSize(600,200);
    emgGroupBoxCh4To6VLayout->addWidget(channel5);

    QQuickView* channel6QuickView = new QQuickView;
    ch6DataSource = new DataSource(channel6QuickView);
    chDataSourceVector.append(ch6DataSource);
    channel6 = new EmgChannel(0, 0, "Channel6.qml", "Channel 6", ch6DataSource, channel6QuickView);
    channel6->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel6->setFixedSize(600,200);
    emgGroupBoxCh4To6VLayout->addWidget(channel6);

    QQuickView* channel7QuickView = new QQuickView;
    ch7DataSource = new DataSource(channel7QuickView);
    chDataSourceVector.append(ch7DataSource);
    channel7 = new EmgChannel(0, 0, "Channel7.qml", "Channel 7", ch7DataSource, channel7QuickView);
    channel7->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel7->setFixedSize(700,200);
    emgGroupBoxCh7To8VLayout->addWidget(channel7);

    QQuickView* channel8QuickView = new QQuickView;
    ch8DataSource = new DataSource(channel8QuickView);
    chDataSourceVector.append(ch8DataSource);
    channel8 = new EmgChannel(0, 0, "Channel8.qml", "Channel 8", ch8DataSource, channel8QuickView);
    channel8->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
    channel8->setFixedSize(700,200);
    emgGroupBoxCh7To8VLayout->addWidget(channel8);
}

void InstrumentationPanel::setChannelDataPoints(QMap<int,QVector<double>> dataPoints)
{
    channel = 0;
    //qDebug() << "InstrumentationPanel::setChannelDataPoints triggered.";
    try
    {
        for(auto& ch : dataPoints)
        {
            chDataSourceVector[channel]->setDataPoints(dataPoints[channel]);
            channel++;
        }
    } 
    catch (...)
    {
        qDebug() << "InstrumentationPanel::setChannelDataPoints >> chDataSourceVector[channel]->setDataPoints error";
    }
}


#include "../include/moc_InstrumentationPanel.cpp"
