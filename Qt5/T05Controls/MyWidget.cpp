#include "MyWidget.h"
#include <QApplication>

#include <QLabel>     // disply static text, or image
#include <QPushButton>
#include <QLineEdit> // single line

#include <QComboBox>
#include <QCheckBox>
#include <QRadioButton>
#include <QTextEdit> // multi lines, rich text
#include <QTextBrowser> // readonly textedit
#include <QGroupBox>  //
#include <QSlider>    // 模拟方式显示数值
#include <QSpinBox>  // 数字
#include <QDateEdit>
#include <QTimeEdit>
#include <QDateTimeEdit>
#include <QTabWidget> // 不介绍,不算控件
#include <QCompleter>
#include <QHBoxLayout>
#include <QDebug>
#include <QPixmap>
#include  <QVBoxLayout>
#include <QLCDNumber>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout* lay = new QVBoxLayout(this);
    QLabel* label;
    QComboBox* combo;   //下拉框
    QPushButton* button;
    QRadioButton* radio;
    QTextEdit* edit;
    QGroupBox* group;

    lay->addWidget(label = new QLabel("<a href=www.baidu.com>baidu</a>"));
    label->setPixmap(QPixmap("../aaa.png"));

    connect(label, &QLabel::linkActivated, [](QString str){
        qDebug() << str;
    });

    lay->addWidget(button = new QPushButton("Button"));
    button->setStyleSheet("QPushButton {font:bold 16px; color:red; padding:5px}");

    lay->addWidget(radio = new QRadioButton("Radio"));
    radio->setStyleSheet("QRadioButton {font:bold 16px; color:red; padding:5px}");
    connect(radio, &QRadioButton::clicked, [](bool v){
        qDebug() << v;
    });

    lay->addWidget(new QCheckBox("check box"));


    lay->addWidget(combo = new QComboBox());
    combo->addItem("Select item1");
    combo->addItem("Select item2");
    combo->setEditable(true);
    connect(combo, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotComboBoxIndexChanged(QString)));

    combo->setCompleter(new QCompleter(combo->model()));

    lay->addWidget(edit = new QTextEdit);
    edit->setText("<table border=1><tr><th>head1</th><th>head2</th></tr>"
                  "<tr><td>value1</td><td>value2</td></tr>"
                  "<tr><td>value3</td><td>value4</td></tr>"
                  "</table><br>"
                  "<img src=../aaa.png></img>");
    _edit = edit;
    connect(edit, &QTextEdit::textChanged, [&](){
      QTextEdit* edit = (QTextEdit*)this->sender();
        qDebug() << _edit->toPlainText();
    });
    edit->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    edit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    lay->addWidget(group = new QGroupBox("Some items"));
    QHBoxLayout* hBoxLay;
    group->setLayout(hBoxLay = new QHBoxLayout);
    hBoxLay->addWidget(new QPushButton("aaaa"));
    hBoxLay->addWidget(new QPushButton("aaaa"));

    //
    QSlider* slider;  //滑块
    QSpinBox* spinBox;

    lay->addWidget(slider = new QSlider(Qt::Horizontal));
    slider->setMaximum(100);
    slider->setMinimum(0);

    lay->addWidget(spinBox = new QSpinBox);
    spinBox->setMaximum(100);
    spinBox->setMinimum(0);

    connect(slider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
    connect(spinBox, SIGNAL(valueChanged(int)), slider, SLOT(setValue(int)));

    lay->addWidget(new QDateTimeEdit);

    //QLCDNumber控件用于显示一个LCD数字
    QLCDNumber* lcd;
    lay->addWidget(lcd = new QLCDNumber(10));
    lcd->display(12345);
    lcd->setMode(QLCDNumber::Hex); //设置格式 十六进制
    lcd->setSegmentStyle(QLCDNumber::Outline);//设置外观 平的
}


void MyWidget::slotComboBoxIndexChanged(const QString &str)
{
    qDebug() << "slotComboBoxIndexChanged" << str;
}


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MyWidget w;
    w.show();

    return app.exec();
}
