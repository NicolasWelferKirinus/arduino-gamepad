#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextStream>
#include <QFileDialog>
#include <QFile>
#include <QSettings>
#include <QCoreApplication>
#include <QMessageBox>
#include <QCloseEvent>

QStringList MainWindow::combooptions(){

return QStringList() << "a" << "b" << "c" << "d" << "e"
                     << "f" << "g" << "h" << "i" << "j"
                     << "k" << "l" << "m" << "n" << "o"
                     << "p" << "q" << "r" << "s" << "t"
                     << "u" << "v" << "w" << "x" << "y"
                     << "z" << "space" << "ctrl" << "shift" << "alt"
                     << "1" << "2" << "3" << "4" << "5"
                     << "6" << "7" << "8" << "9" << "0"
                     << "mouse left click" << "mouse middle click" << "mouse right click"
                     << "move mouse up" << "move mouse left" << "move mouse right" << "move mouse down"
                     << "scroll up" << "scroll down"
                     << "arrow up" << "arrow left" << "arrow right" << "arrow down"
                     << "enter" << "backspace" << "tab" << "esc" << "insert" << "delete"
                     << "page up" << "page down" << "home" << "end" << "capslock"
                     << "F1" << "F2" << "F3" << "F4" << "F5" << "F6"
                     << "F7" << "F8" << "F9" << "F10" << "F11" << "F12"
                     << "Xinput y" << "Xinput x" << "Xinput b" << "Xinput a"
                     << "Xinput lt" << "Xinput rt" << "Xinput lb" << "Xinput rb"
                     << "Xinput d-pad up" << "Xinput d-pad left" << "Xinput d-pad right" << "Xinput d-pad down"
                     << "Xinput back" << "Xinput logo" << "Xinput start" << "Xinput l3" << "Xinput r3"
                     << "Xinput left joystick up" << "Xinput left joystick left" << "Xinput left joystick right" << "Xinput left joystick down"
                     << "Xinput right joystick up" << "Xinput right joystick left" << "Xinput right joystick right" << "Xinput right joystick down";
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , gamepad()
{
    ui->setupUi(this);
    currentFileName = "";
    ui->button_analogic->addItems(combooptions());
    ui->button_up->addItems(combooptions());
    ui->button_left->addItems(combooptions());
    ui->button_right->addItems(combooptions());
    ui->button_down->addItems(combooptions());
    ui->joystick_up->addItems(combooptions());
    ui->joystick_left->addItems(combooptions());
    ui->joystick_right->addItems(combooptions());
    ui->joystick_down->addItems(combooptions());
    readsettings();
    on_joystic_mode_currentIndexChanged(ui->joystic_mode->currentText());
    createActions();
    createTrayIcon();
    setIcon();
    trayIcon->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

constexpr unsigned int str2int(const char* str, int h = 0)
{
    return !str[h] ? 5381 : (str2int(str, h+1) * 33) ^ str[h];
}

char MainWindow::formatbuttons(QString button){
    std::string str =  button.toStdString();
    if (str == "enter")
        return 176;
    if (str == "mouse movement")
        return 65;
    if (str == "buttons")
        return 66;
    if (str == "Xinput left joystick")
        return 220;
    if (str == "Xinput right joystick")
        return 221;
    if (str == "Xinput l3")
        return 222;
    if (str == "Xinput r3")
        return 223;
    if (str == "Xinput left joystick up")
        return 224;
    if (str == "Xinput left joystick left")
        return 225;
    if (str == "Xinput left joystick right")
        return 226;
    if (str == "Xinput left joystick down")
        return 227;
    if (str == "Xinput right joystick up")
        return 228;
    if (str == "Xinput right joystick left")
        return 229;
    if (str == "Xinput right joystick right")
        return 230;
    if (str == "Xinput right joystick down")
        return 231;
    if (str == "mouse left click")
        return 67;
    if (str == "mouse middle click")
        return 68;
    if (str == "mouse right click")
        return 69;
    if (str == "move mouse up")
        return 70;
    if (str == "move mouse left")
        return 71;
    if (str == "move mouse right")
        return 72;
    if (str == "move mouse down")
        return 73;
    if (str == "scroll up")
        return 74;
    if (str == "scroll down")
        return 75;
    if (str == "Xinput y")
        return 76;
    if (str == "Xinput x")
        return 77;
    if (str == "Xinput b")
        return 78;
    if (str == "Xinput a")
        return 79;
    if (str == "Xinput lt")
        return 80;
    if (str == "Xinput rt")
        return 81;
    if (str == "Xinput lb")
        return 82;
    if (str == "Xinput rb")
        return 83;
    if (str == "Xinput d-pad up")
        return 84;
    if (str == "Xinput d-pad left")
        return 85;
    if (str == "Xinput d-pad right")
        return 86;
    if (str == "Xinput d-pad down")
        return 87;
    if (str == "Xinput back")
        return 88;
    if (str == "Xinput logo")
        return 89;
    if (str == "Xinput start")
        return 90;
    if (str == "ctrl")
        return 128;
    if (str == "shift")
        return 129;
    if (str == "alt")
        return 130;
    if (str == "arrow up")
        return 218;
    if (str == "arrow left")
        return 216;
    if (str == "arrow right")
        return 215;
    if (str == "arrow down")
        return 217;
    if (str == "backspace")
        return 178;
    if (str == "tab")
        return 179;
    if (str == "esc")
        return 177;
    if (str == "insert")
        return 209;
    if (str == "delete")
        return 212;
    if (str == "page up")
        return 211;
    if (str == "page down")
        return 214;
    if (str == "home")
        return 210;
    if (str == "end")
        return 213;
    if (str == "capslock")
        return 193;
    if (str == "F1")
        return 194;
    if (str == "F2")
        return 195;
    if (str == "F3")
        return 196;
    if (str == "F4")
        return 197;
    if (str == "F5")
        return 198;
    if (str == "F6")
        return 199;
    if (str == "F7")
        return 200;
    if (str == "F8")
        return 201;
    if (str == "F9")
        return 202;
    if (str == "F10")
        return 203;
    if (str == "F11")
        return 204;
    if (str == "F12")
        return 205;
    if (str == "space")
        return 32;
    return str[0];
}

std::string MainWindow::get_combo(bool serial){
    std::string str = "";
    if(serial){
    str += formatbuttons(ui->button_analogic->currentText());
    str += formatbuttons(ui->button_up->currentText());
    str += formatbuttons(ui->button_left->currentText());
    str += formatbuttons(ui->button_right->currentText());
    str += formatbuttons(ui->button_down->currentText());
    str += formatbuttons(ui->joystic_mode->currentText());
    str += formatbuttons(ui->joystick_up->currentText());
    str += formatbuttons(ui->joystick_left->currentText());
    str += formatbuttons(ui->joystick_right->currentText());
    str += formatbuttons(ui->joystick_down->currentText());
    }else{
        str += "arduinocontroller/";
        str += ui->button_analogic->currentText().toStdString() + '/';
        str += ui->button_up->currentText().toStdString() + '/';
        str += ui->button_left->currentText().toStdString() + '/';
        str += ui->button_right->currentText().toStdString() + '/';
        str += ui->button_down->currentText().toStdString() + '/';
        str += ui->joystic_mode->currentText().toStdString() + '/';
        str += ui->joystick_up->currentText().toStdString() + '/';
        str += ui->joystick_left->currentText().toStdString() + '/';
        str += ui->joystick_right->currentText().toStdString() + '/';
        str += ui->joystick_down->currentText().toStdString() + '/';
    }
    return str;
}

void MainWindow::on_apply_clicked()
{
    std::string str = get_combo(true);
    gamepad.apply(str);
    gamepad.send();
    writesettings();
}


void MainWindow::on_joystic_mode_currentIndexChanged(const QString &arg1)
{
    if(arg1 == "buttons"){
        ui->joystick_up->setDisabled(false);
        ui->joystick_left->setDisabled(false);
        ui->joystick_right->setDisabled(false);
        ui->joystick_down->setDisabled(false);
    }else{
        ui->joystick_up->setDisabled(true);
        ui->joystick_left->setDisabled(true);
        ui->joystick_right->setDisabled(true);
        ui->joystick_down->setDisabled(true);
    }
}

void MainWindow::saveFile(bool isSaveAs){
    if(isSaveAs || currentFileName.isEmpty()){
        QString fileName = QFileDialog::getSaveFileName();
        if(fileName.isEmpty()) return;
        currentFileName = fileName;

    }
    QFile file(currentFileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    textStream << QString::fromUtf8(get_combo(false).data());
    file.close();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    if(fileName.isEmpty()) return;

    currentFileName=fileName;
    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream textStream(&file);
    QString text = textStream.readAll();
    QStringList list1 = text.split('/');
    if(list1[0] == "arduinocontroller"){
    ui->button_analogic->setCurrentText(list1[1]);
    ui->button_up->setCurrentText(list1[2]);
    ui->button_left->setCurrentText(list1[3]);
    ui->button_right->setCurrentText(list1[4]);
    ui->button_down->setCurrentText(list1[5]);
    ui->joystic_mode->setCurrentText(list1[6]);
    ui->joystick_up->setCurrentText(list1[7]);
    ui->joystick_left->setCurrentText(list1[8]);
    ui->joystick_right->setCurrentText(list1[9]);
    ui->joystick_down->setCurrentText(list1[10]);
    }else{
        ui->statusbar->showMessage("invalid file", 2000);
    }
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
   saveFile();
}

void MainWindow::on_actionSave_as_triggered()
{
   saveFile(true);
}

void MainWindow::writesettings(){
   QSettings sett;
   sett.setValue("b_joy", ui->button_analogic->currentText());
   sett.setValue("b_up", ui->button_up->currentText());
   sett.setValue("b_left", ui->button_left->currentText());
   sett.setValue("b_right", ui->button_right->currentText());
   sett.setValue("b_down", ui->button_down->currentText());
   sett.setValue("joy_mode", ui->joystic_mode->currentText());
   sett.setValue("joy_up", ui->joystick_up->currentText());
   sett.setValue("joy_left", ui->joystick_left->currentText());
   sett.setValue("joy_right", ui->joystick_right->currentText());
   sett.setValue("joy_down", ui->joystick_down->currentText());
}

void MainWindow::readsettings(){
    QSettings sett;
    ui->button_analogic->setCurrentText(sett.value("b_joy", 'a').toString());
    ui->button_up->setCurrentText(sett.value("b_up", 'a').toString());
    ui->button_left->setCurrentText(sett.value("b_left", 'a').toString());
    ui->button_right->setCurrentText(sett.value("b_right", 'a').toString());
    ui->button_down->setCurrentText(sett.value("b_down", 'a').toString());
    ui->joystic_mode->setCurrentText(sett.value("joy_mode", "mouse movement").toString());
    ui->joystick_up->setCurrentText(sett.value("joy_up", 'a').toString());
    ui->joystick_left->setCurrentText(sett.value("joy_left", 'a').toString());
    ui->joystick_right->setCurrentText(sett.value("joy_right", 'a').toString());
    ui->joystick_down->setCurrentText(sett.value("joy_down", 'a').toString());
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (trayIcon->isVisible()) {
        QMessageBox::information(this, tr("Systray"),
                                 tr("The program will keep running in the "
                                    "system tray. To terminate the program, "
                                    "choose <b>Quit</b> in the context menu "
                                    "of the system tray entry."));
        hide();
        event->ignore();
    }
}

void MainWindow::createActions()
{
    minimizeAction = new QAction(tr("Mi&nimize"), this);
    connect(minimizeAction, &QAction::triggered, this, &QWidget::hide);

    maximizeAction = new QAction(tr("Ma&ximize"), this);
    connect(maximizeAction, &QAction::triggered, this, &QWidget::showMaximized);

    restoreAction = new QAction(tr("&Restore"), this);
    connect(restoreAction, &QAction::triggered, this, &QWidget::showNormal);

    quitAction = new QAction(tr("&Quit"), this);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
}

void MainWindow::createTrayIcon()
{
    trayIconMenu = new QMenu(this);
    trayIconMenu->addAction(minimizeAction);
    trayIconMenu->addAction(maximizeAction);
    trayIconMenu->addAction(restoreAction);
    trayIconMenu->addSeparator();
    trayIconMenu->addAction(quitAction);

    trayIcon = new QSystemTrayIcon(this);
    trayIcon->setContextMenu(trayIconMenu);
}

void MainWindow::setIcon()
{
    QIcon icon = QIcon(":/images/icon.jpg");
    trayIcon->setIcon(icon);
    setWindowIcon(icon);

    trayIcon->setToolTip("arduino gamepad");
}
