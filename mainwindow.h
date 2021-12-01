#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Qtcontroller.h"
#include <QString>
#include <QSystemTrayIcon>
#include <QCloseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QStringList combooptions();
    char formatbuttons(QString button);

private slots:
    void on_apply_clicked();

    void on_joystic_mode_currentIndexChanged(const QString &arg1);

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_as_triggered();

    void saveFile(bool isSaveAs=false);

    std::string get_combo(bool serial);

    void writesettings();

    void readsettings();

    void closeEvent(QCloseEvent *event) override;

    void createActions();

    void createTrayIcon();

    void setIcon();

private:
    Ui::MainWindow *ui;
    Qtcontroller gamepad;
    QString currentFileName;
    QAction *minimizeAction;
    QAction *maximizeAction;
    QAction *restoreAction;
    QAction *quitAction;
    QMenu *trayIconMenu;
    QSystemTrayIcon *trayIcon;
};
#endif // MAINWINDOW_H
