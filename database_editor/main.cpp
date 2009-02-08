/******************************************************************************
 *                                    iTest                                   *
 * -------------------------------------------------------------------------- *
 * Version:      1.0.0                                                        *
 * Qt version:   4.2.2                                                        *
 * -------------------------------------------------------------------------- *
 * iTest is a Qt application consisting of a Database Editor and a Test       *
 * Writer designed for easy computerised examination.                         *
 * -------------------------------------------------------------------------- *
 * This program is distributed under the terms of the GPL v2.                 *
 * -------------------------------------------------------------------------- *
 * The program is provided AS IS with ABSOLUTELY NO WARRANTY OF ANY KIND,     *
 * INCLUDING THE WARRANTY OF DESIGN, MERCHANTIBILITY AND FITNESS FOR          *
 * A PARTICULAR PURPOSE.                                                      *
 ******************************************************************************/

#include <QApplication>

#include "main_window.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	QSettings settings("Michal Tomlein", "iTest");
	QString lang = settings.value("lang", "English").toString();
	if (lang != "English") {
		QTranslator * translator = new QTranslator;
		translator->load(QString(":/i18n/%1.qm").arg(lang));
		app.installTranslator(translator);
	}

	MainWindow * itest_window = new MainWindow;
	itest_window->show();
	return app.exec();
}

// ---------------------------- version changelog: -----------------------------
// version 1.0 - 