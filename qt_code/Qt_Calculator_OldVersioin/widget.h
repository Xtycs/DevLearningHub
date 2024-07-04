#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStack>
#include <QByteArray>
#include <string.h>
#include <cstring>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_oneButton_clicked();

    void on_cleanButton_clicked();

    void on_delButton_clicked();

    void on_theroButton_clicked();

    void on_rightButton_clicked();

    void on_leftButton_clicked();

    void on_threeButton_clicked();

    void on_fourButton_clicked();

    void on_fiveButton_clicked();

    void on_sixButton_clicked();

    void on_sevenButton_clicked();

    void on_eightButton_clicked();

    void on_nineButton_clicked();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_mulButton_clicked();

    void on_divButton_clicked();

    void on_equButton_clicked();

private:
    Ui::Widget *ui;
    QString expression;

    int Priority(char ch);
};
#endif // WIDGET_H
