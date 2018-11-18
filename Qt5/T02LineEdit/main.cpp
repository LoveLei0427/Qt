
/* 应用程序抽象类 */
#include <QApplication>

/*窗口类*/
#include <QWidget>
#include <QCompleter>
#include <QLineEdit>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    /* 构造一个窗口*/
    QWidget w;

    QLineEdit edit;
    edit.show();  //此时主窗口有一个输入框
    edit.setParent(&w);

    /* 以密码样式输入 */
	edit.setEchoMode(QLineEdit::Password);
	edit.text();  //获取输入结果
	edit.setPlaceholderText("Please input text:");//输入提示

    //自动补全 提示
    QCompleter completer(QStringList() << "aab" << "123" << "998");
    completer.setFilterMode(Qt::MatchContains); //匹配模式
    edit.setCompleter(&completer);

    /*显示窗口*/
    w.show();

    w.setWindowTitle("Hello World");

    /*在exec中有一个消息循环*/
    return app.exec();
}
