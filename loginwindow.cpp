#include "loginwindow.h"
#include "./ui_loginwindow.h"
#include "./registwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    m_bDrag = false;
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);  // 隐藏窗口标题栏
    setFixedSize(this->width(), this->height());  // 固定窗口尺寸
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

// 鼠标按下操作
void LoginWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = true;
        //获得鼠标的初始位置
        mouseStartPoint = event->globalPosition().toPoint();
        //获得窗口的初始位置
        windowTopLeftPoint = this->frameGeometry().topLeft();
    }
}

// 鼠标移动操作
void LoginWindow::mouseMoveEvent(QMouseEvent* event)
{
    if (m_bDrag)
    {
        //获得鼠标移动的距离
        QPoint distance = (event->globalPosition() - mouseStartPoint).toPoint();
        //QPoint distance = event->pos() - mouseStartPoint;
        //改变窗口的位置
        this->move(windowTopLeftPoint + distance);
    }
}

// 鼠标释放
void LoginWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

void LoginWindow::on_Button_mini_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}

void LoginWindow::on_Button_close_clicked()
{
    this->close();
}

void LoginWindow::on_Button_regist_clicked()
{
    RegistWindow* registview = new RegistWindow;
    registview->setpoint(this->frameGeometry().topLeft());
    registview->show();
    this->close();
}

void LoginWindow::setPointAndName(QPoint pot, QString name)
{
    this->move(pot);
    if (name!="")
    {
        ui->Edit_name->setText(name);
    }
}

void LoginWindow::on_Button_login_clicked()
{
    QString name = ui->Edit_name->text();
    QString pswd = ui->Edit_pswd->text();

}

