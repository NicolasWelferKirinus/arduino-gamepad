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
                     << "\\" << "/" << ";" << "[" << "]"
                     << "'" << "-" << "=" << "*" << "+" << "," << "."
                     << "mouse left click" << "mouse middle click" << "mouse right click"
                     << "move mouse up" << "move mouse left" << "move mouse right" << "move mouse down"
                     << "scroll up" << "scroll down"
                     << "arrow up" << "arrow left" << "arrow right" << "arrow down"
                     << "backspace" << "tab" << "esc" << "insert" << "delete"
                     << "page up" << "page down" << "home" << "end" << "capslock"
                     << "F1" << "F2" << "F3" << "F4" << "F5" << "F6"
                     << "F7" << "F8" << "F9" << "F10" << "F11" << "F12";
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
    if (str == "mouse movement")
        return 101;
    if (str == "buttons")
        return 102;
    if (str == "mouse left click")
        return 104;
    if (str == "mouse middle click")
        return 105;
    if (str == "mouse right click")
        return 106;
    if (str == "move mouse up")
        return 107;
    if (str == "move mouse left")
        return 108;
    if (str == "move mouse right")
        return 109;
    if (str == "move mouse down")
        return 110;
    if (str == "scroll up")
        return 111;
    if (str == "scroll down")
        return 112;
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
    if (str == "F11")
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
    if(arg1 == "mouse movement"){
        ui->joystick_up->setDisabled(true);
        ui->joystick_left->setDisabled(true);
        ui->joystick_right->setDisabled(true);
        ui->joystick_down->setDisabled(true);
    }else{
        ui->joystick_up->setDisabled(false);
        ui->joystick_left->setDisabled(false);
        ui->joystick_right->setDisabled(false);
        ui->joystick_down->setDisabled(false);
    }
}
