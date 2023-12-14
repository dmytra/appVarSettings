#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    //First way   https://thecodeprogram.com/explanation-of-qsettings-and-how-to-use-in-qt-c--

    QSettings settings_withAppInfo("ChapyLnadAll v1", "ChapyLnadAll v1 app QSettings");

//////////////////////////

    //Second ways  https://thecodeprogram.com/explanation-of-qsettings-and-how-to-use-in-qt-c--

 // define from file #include "mainwindow.h"
 // #define ORGANIZATION_NAME "ChapyLnadAll v2"
 // #define ORGANIZATION_DOMAIN "githab.com/dmytra""
 // #define APPLICATION_NAME "ChapyLnadAll v2 app QSettings"

    QCoreApplication::setOrganizationName(ORGANIZATION_NAME);
    QCoreApplication::setOrganizationDomain(ORGANIZATION_DOMAIN);
    QCoreApplication::setApplicationName(APPLICATION_NAME);

        // and
//    Initialisation examples of QSetting
//    QSettings settings1(QSettings::SystemScope);
//    QSettings settings2("thesettings.ini", QSettings::IniFormat);
//    QSettings settings3(QSettings::NativeFormat, QSettings::UserScope, "ChapyLnadAll v3", "ChapyLnadAll v3 app QSettings");
//    QSettings settings4("ChapyLnadAll v3", "QSettings v3 Example Application");


    //Therd ways    https://thecodeprogram.com/explanation-of-qsettings-and-how-to-use-in-qt-c--
//    //General Data
//    settings2.setValue("author", "Dmytra Bob");
//    settings2.setValue("web", "githab.com/dmytra");
//    //Grouped data
//    settings2.setValue("Lang/programming", "C++");
//    settings2.setValue("Lang/framework", "Qt Framework");
//    settings2.setValue("Lang/experience", "6");

//    qDebug()  << "Author : " << settings2.value("author").toByteArray().constData() << "\n";
//    qDebug()  << "Web : " << settings2.value("web").toByteArray().constData() << "\n";
//    qDebug()  << "Programming Lang : " << settings2.value("Lang/programming").toByteArray().constData() << "\n";
//    qDebug()  << "Framework : " << settings2.value("Lang/framework").toByteArray().constData() << "\n";
//    qDebug()  << "Experience : " << settings2.value("Lang/experience").toByteArray().constData() << " years" << "\n";

//    //General Data
//    settings2.setValue("author", "Dmytra Bob");
//    settings2.setValue("web", "githab.com/dmytra");
//    //Grouped data
//    settings2.setValue("Lang/programming", "C++");
//    settings2.setValue("Lang/framework", "Qt Framework");
//    settings2.setValue("Lang/experience", "6");

//    qDebug()  << "Author : " << settings2.value("author").toByteArray().constData() << "\n";
//    qDebug()  << "Web : " << settings2.value("web").toByteArray().constData() << "\n";
//    qDebug()  << "Programming Lang : " << settings2.value("Lang/programming").toByteArray().constData() << "\n";
//    qDebug()  << "Framework : " << settings2.value("Lang/framework").toByteArray().constData() << "\n";
//    qDebug()  << "Experience : " << settings2.value("Lang/experience").toByteArray().constData() << " years" << "\n";

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
