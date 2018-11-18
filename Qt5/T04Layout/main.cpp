

/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>

#include <QLabel>

/* 按钮 */
#include <QPushButton>
#include <QLineEdit>

#include <QVBoxLayout>  //数值
#include <QHBoxLayout> //水平
#include <QGridLayout>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /* 构造一个窗口*/
    QWidget w;

    /* 按钮也是个窗口 */
    QPushButton button;
    button.setText("Button");
    /* 窗口对象的父子关系，影响显示位置 */
    /* 没有父窗口的窗口，我们称之为主窗口 */
	//button.setParent(&w); 有了layout不需要了
    button.show();

    QLineEdit edit;
    edit.setParent(&w);
	
#if 0
	//窗口里面有个layout(非窗口) layout里面有button和edit两个子窗口
    QHBoxLayout layout;
    layout.addStretch(1); 	//防止edit和button随窗口变化而变化
    layout.addWidget(&button, 1); //第二个参数类似addstretch
    layout.addSpacing(50);	//edit和button之间设置50像素间距
    layout.addWidget(&edit, 1);
    layout.addStretch(1);
#endif

#if 0
    QGridLayout layout;
    layout.setColumnStretch(3, 1);
    layout.setColumnStretch(0, 1); //第一列上比重是1
	layout.setRowStretch(4, 1);
    layout.setRowStretch(0, 1);	//第一行上控件比重是1

    layout.addWidget(&button, 1, 1);//button放置在第1行第2列
    layout.addWidget(&edit, 1, 2);
    layout.addWidget(new QPushButton("1, 0"), 2, 1);
    layout.addWidget(new QPushButton("1, 1"), 2, 2);

    layout.addWidget(new QPushButton("aaa"), 3, 1, 1, 2);
#endif

    QGridLayout layout;
    QLineEdit* password;
    layout.setColumnStretch(3, 1);
    layout.setRowStretch(4, 1);
    layout.setColumnStretch(0, 1);
    layout.setRowStretch(0, 1);

    layout.addWidget(new QLabel("Username:"), 1, 1); //提示文字用Qlabel不可更改只能显示
    layout.addWidget(new QLineEdit(), 1, 2);
    layout.addWidget(new QLabel("Password:"), 2, 1);
    layout.addWidget(password = new QLineEdit(), 2, 2);

	//使用layout而不是addwidget是为了界面美观
    QHBoxLayout* hBox;
    layout.addLayout(hBox = new QHBoxLayout, 3, 2);
    hBox->addStretch(1);
    hBox->addWidget(new QPushButton("Login"));

    //layout.addWidget(new QPushButton("登录"), 3, 2);
    password->setEchoMode(QLineEdit::Password);//以password格式输入


    /*显示窗口*/
    w.show();
    w.setLayout(&layout);

    w.setWindowTitle("Hello World");
    /*在exec中有一个消息循环*/
    return app.exec();
}

