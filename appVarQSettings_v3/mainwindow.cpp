#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(APPLICATION_NAME);

    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    ui->trayCheckBox->setChecked(settings.value(SETTINGS_TRAY, false).toBool());
    ui->label_11->setText(ORGANIZATION_NAME);
    ui->label_12->setText(APPLICATION_NAME);
    ui->label_13->setText(ORGANIZATION_DOMAIN);

    if (ui->trayCheckBox->isChecked()) ui->label_14->setText("true");
    else ui->label_14->setText("false");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent * event)
{
}

void MainWindow::iconActivated(QSystemTrayIcon::ActivationReason reason)
{
}

//First way  in  on_saveButton_clicked()
////////////////////////////////////////
void MainWindow::on_saveButton_clicked()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    if(ui->trayCheckBox->isChecked()){
        settings.setValue(SETTINGS_TRAY, true);
    } else {
        settings.setValue(SETTINGS_TRAY, false);
    }

    if (ui->trayCheckBox->isChecked()) ui->label_14->setText("true");
    else ui->label_14->setText("false");

    settings.sync();

    QMessageBox::information(this,
                             "Сохранение настроек",
                             "Сохранение настроек выполнено успешно");
}

//Second ways in on_pushButton_clicked() on_pushButton_2_clicked() on_pushButton_3_clicked()
////////////////////////////////////////
void MainWindow::on_pushButton_clicked()
{
    QSettings settings("Chapy Soft", "newDocAll");

    settings.beginGroup("MainWindow");

    settings.setValue("fridge/color", 	QColor(Qt::white));
    settings.setValue("fridge/size", 	QSize(32, 96));
    settings.setValue("writeSettings 1",  ui->lineEdit->text());
    settings.setValue("writeSettings 2",  ui->lineEdit_2->text());
    settings.setValue("writeSettings 3",  ui->lineEdit_3->text());

    ui->label->setText(ui->lineEdit->text());
    ui->label_2->setText(ui->lineEdit_2->text());
    ui->label_3->setText(ui->lineEdit_3->text());

    settings.setValue("tv", false);

    settings.setValue("size", size());
    settings.setValue("pos", pos());

    ui->label_4->setText(QString("WINDOWS width: %1").arg(settings.value("size", QSize(400, 400)).toSize().width()));
    ui->label_5->setText(QString("WINDOWS hight: %1").arg(settings.value("size", QSize(400, 400)).toSize().height()));

    ui->label_6->setText(QString("pos WINDOWS width: %1").arg(settings.value("pos", QSize(400, 400)).toPoint().x()));
    ui->label_7->setText(QString("pos WINDOWS hight: %1").arg(settings.value("pos", QSize(400, 400)).toPoint().y()));

    settings.endGroup();

    qDebug() << "writeSettings();";
}

//Second ways in on_pushButton_clicked() on_pushButton_2_clicked() on_pushButton_3_clicked()
void MainWindow::on_pushButton_2_clicked()
{
    QSettings settings("Chapy Soft", "newDocAll");

    settings.beginGroup("MainWindow");
    resize(settings.value("size", QSize(400, 400)).toSize());
    move(settings.value("pos", QPoint(200, 200)).toPoint());
    ui->label->setText(settings.value("writeSettings 1").toString());
    ui->label_2->setText(settings.value("writeSettings 2").toString());
    ui->label_3->setText(settings.value("writeSettings 3").toString());
    ui->lineEdit->setText(settings.value("writeSettings 1").toString());
    ui->lineEdit_2->setText(settings.value("writeSettings 2").toString());
    ui->lineEdit_3->setText(settings.value("writeSettings 3").toString());
    ui->label_4->setText(QString("WINDOWS width: %1").arg(settings.value("size", QSize(400, 400)).toSize().width()));
    ui->label_5->setText(QString("WINDOWS hight: %1").arg(settings.value("size", QSize(400, 400)).toSize().height()));

    ui->label_6->setText(QString("pos WINDOWS width: %1").arg(settings.value("pos", QSize(400, 400)).toPoint().x()));
    ui->label_7->setText(QString("pos WINDOWS hight: %1").arg(settings.value("pos", QSize(400, 400)).toPoint().y()));

    settings.endGroup();

    qDebug() << "readSettings";
}

//Second ways in on_pushButton_clicked() on_pushButton_2_clicked() on_pushButton_3_clicked()
void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("reset1");
    ui->label_2->setText("reset2");
    ui->label_3->setText("reset3");

    ui->lineEdit->setText("writeSettings 1===>reset");
    ui->lineEdit_3->setText("writeSettings 3===>reset");
    ui->lineEdit_2->setText("writeSettings 2===>reset");

    qDebug() << "reset Settings();";
}

//     Therd ways
////////////////////////
void MainWindow::on_pushButton_4_clicked()
{
        //Initialisation examples of QSetting
        QSettings settings1(QSettings::SystemScope);
        QSettings settings2("thesettings.ini", QSettings::IniFormat);
        QSettings settings3(QSettings::NativeFormat, QSettings::UserScope, "ChapyLnadAll v3", "ChapyLnadAll v3 app QSettings");
        QSettings settings4("ChapyLnadAll v3", "QSettings v3 Example Application");

        //General Data
        settings2.setValue("author", "Dmytra Bob");
        settings2.setValue("web", "githab.com/dmytra");
        //Grouped data
        settings2.setValue("Lang/programming", "C++");
        settings2.setValue("Lang/framework", "Qt Framework");
        settings2.setValue("Lang/experience", "6");

        qDebug()  << "Author : " << settings2.value("author").toByteArray().constData() << "\n";
        qDebug()  << "Web : " << settings2.value("web").toByteArray().constData() << "\n";
        qDebug()  << "Programming Lang : " << settings2.value("Lang/programming").toByteArray().constData() << "\n";
        qDebug()  << "Framework : " << settings2.value("Lang/framework").toByteArray().constData() << "\n";
        qDebug()  << "Experience : " << settings2.value("Lang/experience").toByteArray().constData() << " years" << "\n";

        ui->label_15->setText(  settings2.value("author").toByteArray().constData());
        ui->label_16->setText(  settings2.value("web").toByteArray().constData());
        ui->label_17->setText(  settings2.value("Lang/programming").toByteArray().constData());
        ui->label_18->setText(  settings2.value("Lang/framework").toByteArray().constData());
        ui->label_19->setText(  settings2.value("Lang/experience").toByteArray().constData());
}

