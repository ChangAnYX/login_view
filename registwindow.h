#ifndef REGISTWINDOW_H
#define REGISTWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

namespace Ui {
class RegistWindow;
}

class RegistWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RegistWindow(QWidget *parent = nullptr);
    ~RegistWindow();

private:
    Ui::RegistWindow *ui;
    bool        m_bDrag;
    QPoint      mouseStartPoint;
    QPoint      windowTopLeftPoint;

protected:
    //拖拽窗口
    void mousePressEvent(QMouseEvent* event); //鼠标按下
    void mouseMoveEvent(QMouseEvent* event); //鼠标移动
    void mouseReleaseEvent(QMouseEvent* event); //鼠标释放

public:
    void setpoint(QPoint pot);

private slots:
    void on_Button_close_clicked();
    void on_Button_mini_clicked();
    void on_Button_return_clicked();
    void on_Button_login_clicked();
};

#endif // REGISTWINDOW_H
