#include "include/TreadmillAutomation.h"
#include <QtWidgets/QApplication>
#include <QScopedPointer>

int main(int argc, char *argv[])
{

    QScopedPointer<QApplication> app(new QApplication(argc, argv));
    QScopedPointer<TreadmillAutomation> panel(new TreadmillAutomation);

	panel->show();
	return app->exec();
}
