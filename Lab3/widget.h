#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_plus_clicked();

    void on_minus_clicked();

    void on_count_clicked();

    void on_mnoz_clicked();

    void on_dele_clicked();

    void on_sqrt_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
