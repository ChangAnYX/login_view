#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

protected:
    //拖拽窗口
    void mousePressEvent(QMouseEvent* event); //鼠标按下
    void mouseMoveEvent(QMouseEvent* event); //鼠标移动
    void mouseReleaseEvent(QMouseEvent* event); //鼠标释放

public:
    void setPointAndName(QPoint pot, QString name="");

private slots:
    void on_Button_mini_clicked();
    void on_Button_close_clicked();
    void on_Button_regist_clicked();
    void on_Button_login_clicked();
};
#endif // LOGINWINDOW_H
