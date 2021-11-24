#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Qtcontroller.h"
#include <QString>

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

private:
    Ui::MainWindow *ui;
    Qtcontroller gamepad;
};
#endif // MAINWINDOW_H
