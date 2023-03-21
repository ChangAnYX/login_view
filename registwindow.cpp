#include "registwindow.h"
#include "ui_registwindow.h"
#include "loginwindow.h"

RegistWindow::RegistWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RegistWindow)
{
    ui->setupUi(this);
    m_bDrag = false;
    this->setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);  // 隐藏窗口标题栏
    setFixedSize(this->width(), this->height());  // 固定窗口尺寸
}

RegistWindow::~RegistWindow()
{
    delete ui;
}

// 鼠标按下操作
void RegistWindow::mousePressEvent(QMouseEvent* event)
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
void RegistWindow::mouseMoveEvent(QMouseEvent* event)
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
void RegistWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_bDrag = false;
    }
}

void RegistWindow::setpoint(QPoint pot)
{
    this->move(pot);
}

void RegistWindow::on_Button_close_clicked()
{
    this->close();
}

void RegistWindow::on_Button_mini_clicked()
{
    this->setWindowState(Qt::WindowMinimized);
}


void RegistWindow::on_Button_return_clicked()
{
    LoginWindow* loginview = new LoginWindow;
    loginview->setPointAndName(this->frameGeometry().topLeft());
    loginview->show();
    this->close();
}


void RegistWindow::on_Button_login_clicked()
{
    LoginWindow* loginview = new LoginWindow;
    loginview->setPointAndName(this->frameGeometry().topLeft(), ui->Edit_name->text());
    loginview->show();
    this->close();
}

