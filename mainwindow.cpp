#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QTextStream>

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
    ui->button_analogic->addItems(combooptions());
    ui->button_up->addItems(combooptions());
    ui->button_left->addItems(combooptions());
    ui->button_right->addItems(combooptions());
    ui->button_down->addItems(combooptions());
    ui->joystick_up->addItems(combooptions());
    ui->joystick_left->addItems(combooptions());
    ui->joystick_right->addItems(combooptions());
    ui->joystick_down->addItems(combooptions());
    on_joystic_mode_currentIndexChanged(ui->joystic_mode->currentText());
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

void MainWindow::on_apply_clicked()
{
    std::string str = "";
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
    gamepad.apply(str);
    gamepad.send();
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
