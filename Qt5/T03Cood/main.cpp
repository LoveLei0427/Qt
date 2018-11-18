
/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>

/* 按钮 */
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
    button.setParent(&w);
    button.show();
	
	//包含了位置和大小信息 x,y,宽度和高度
    button.setGeometry(30, 30, 100, 30);

    

    w.setWindowTitle("Hello World");

    /*在exec中有一个消息循环*/
    return app.exec();
}

