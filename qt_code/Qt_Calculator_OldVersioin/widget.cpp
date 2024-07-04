#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setMinimumSize(200,300);
    this->setMaximumSize(200,300);

    this->setWindowTitle("Calculator");

    QFont f("仿宋",14);  //改字体
    ui->mainLineEdit->setFont(f);

    //按钮上放图片
    QIcon con("D:/Lists/Qt/Qt_Calculator/pic.PNG");
    ui->delButton->setIcon(con);

    //改变按钮背景色
    ui->equButton->setStyleSheet("background:skyblue");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_oneButton_clicked()
{
    expression += "1";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_cleanButton_clicked()
{
    expression.clear();
    ui->mainLineEdit->clear();
}


void Widget::on_delButton_clicked()
{
    expression.chop(1);
    ui->mainLineEdit->setText(expression);
}


void Widget::on_theroButton_clicked()
{
    expression += "0";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_rightButton_clicked()
{
    expression += ")";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_leftButton_clicked()
{
    expression += "(";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_threeButton_clicked()
{
    expression += "3";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fourButton_clicked()
{
    expression += "4";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_fiveButton_clicked()
{
    expression += "5";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sixButton_clicked()
{
    expression += "6";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_sevenButton_clicked()
{
    expression += "7";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_eightButton_clicked()
{
    expression += "8";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_nineButton_clicked()
{
    expression += "9";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_plusButton_clicked()
{
    expression += "+";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_minusButton_clicked()
{
    expression += "-";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_mulButton_clicked()
{
    expression += "*";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_divButton_clicked()
{
    expression += "/";
    ui->mainLineEdit->setText(expression);
}


void Widget::on_equButton_clicked()
{
    QStack<int> s_num;
    QStack<char> s_opt;

    char opt[128] = {0};
    int i = 0, tmp = 0, num1,num2;


    QByteArray ba = expression.toUtf8(); //把QStringArray转换成QByteArray
    std::strcpy(opt, ba.constData()); //data可以把QByteArray转换为const char*

    while(opt[i] != '\0' || s_opt.empty() != true)
    {
        if(opt[i] >= '0' && opt[i] <= '9')
        {
            tmp = tmp * 10 + (opt[i] - '0');
            i++;
            if(opt[i] < '0' || opt[i] > '9')
            {
                s_num.push(tmp);
                tmp = 0;
            }
        }
        else
        {
            if(s_opt.empty() == true || Priority(opt[i]) > Priority(s_opt.top())
                || (s_opt.top() == '(' && opt[i] != ')'))
            {
                s_opt.push(opt[i]);
                i++;
                continue;
            }

            if(s_opt.top() == '(' && opt[i] == ')')
            {
                s_opt.pop();
                i++;
                continue;
            }

            if(Priority(opt[i]) <= Priority(s_opt.top()) || (opt[i] == ')' && s_opt.top() != '(')
                || (opt[i] == '\0' && s_opt.empty() != true))
            {
                char ch = s_opt.top();
                s_opt.pop();
                switch(ch)
                {
                case'+':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1+num2);
                    break;
                case'-':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1-num2);
                    break;
                case'*':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1*num2);
                    break;
                case'/':
                    num1 = s_num.top();
                    s_num.pop();
                    num2 = s_num.top();
                    s_num.pop();
                    s_num.push(num1/num2);
                    break;
                }
            }
        }
    }
    ui->mainLineEdit->setText(QString::number(s_num.top()));
    //ui->mainLineEdit->clear();
    expression.clear();
}

int Widget::Priority(char ch)
{
    switch(ch)
    {
        case'(':return 3;
        case'*':
        case'/':return 2;
        case'+':
        case'-':return 1;
        default:return 0;
    }
}
