
/*应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>

/*按钮类*/
#include <QPushButton>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /* 构造一个窗口*/
    QWidget w;

    /*显示窗口*/
    w.show();

    /* 按钮也是个窗口 */
    QPushButton button;
    button.setText("Button");
    /* 窗口对象的父子关系，影响显示位置   把button放入窗口之中*/
    /* 没有父窗口的窗口，我们称之为主窗口 */
    button.setParent(&w);  
    button.show();//若无此句 并把上面三句放在w.show()之前 则button是不会显示的

    /* QT对C++的拓展 */
    // 类似于std::bind和std::function    调用信号函数导致槽函数被调用
    QObject::connect(&button, SIGNAL(clicked()), &w, SLOT(close()));

    w.setWindowTitle("Hello World");

    /*在exec中有一个消息循环*/
    return app.exec();
}
