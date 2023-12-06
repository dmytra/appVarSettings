#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle(APPLICATION_NAME);

    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);
    ui->trayCheckBox->setChecked(settings.value(SETTINGS_TRAY, false).toBool());
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

void MainWindow::writeSettings()
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
}

void MainWindow::readSettings()
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
}

void MainWindow::on_saveButton_clicked()
{
    QSettings settings(ORGANIZATION_NAME, APPLICATION_NAME);

    if(ui->trayCheckBox->isChecked()){
        settings.setValue(SETTINGS_TRAY, true);
    } else {
        settings.setValue(SETTINGS_TRAY, false);
    }
    settings.sync();

    QMessageBox::information(this,
                             "Сохранение настроек",
                             "Сохранение настроек выполнено успешно");
}

void MainWindow::on_pushButton_2_clicked()
{
    readSettings();
    qDebug() << "1";
}


void MainWindow::on_pushButton_clicked()
{
    writeSettings();
    qDebug() << "2";
}


void MainWindow::on_pushButton_3_clicked()
{
    ui->label->setText("reset1");
    ui->label_2->setText("reset2");
    ui->label_3->setText("reset3");

    ui->lineEdit->setText("writeSettings 1===>reset");
    ui->lineEdit_3->setText("writeSettings 3===>reset");
    ui->lineEdit_2->setText("writeSettings 2===>reset");
}

