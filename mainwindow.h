#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QSystemTrayIcon>
#include <QAction>
#include <QSettings>
#include <QMessageBox>

#define ORGANIZATION_NAME "ChapyAll"
#define ORGANIZATION_DOMAIN "www."
#define APPLICATION_NAME "app QSettings"

#define SETTINGS_TRAY "settings/tray"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent * event);

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);

    void on_saveButton_clicked();
    void writeSettings();
    void readSettings();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow          * ui;
    QSystemTrayIcon         * trayIcon;
};

#endif // MAINWINDOW_H
