#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->error->setVisible(false);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_plus_clicked() //Переключение на сложение
{
    ui->operlabel1->setText("Слагаемое 1");
    ui->operlable2->setText("Слагаемое 2");
    ui->count->setText("Сумма");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

void Widget::on_minus_clicked() //Переключение на вычитание
{
    ui->operlabel1->setText("Вычетаемое 1");
    ui->operlable2->setText("Вычетатель 2");
    ui->count->setText("Разность");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

void Widget::on_count_clicked() //Кнопка вычисления
{
    int op1, op2;
    int res;
    bool ok1, ok2;
    QString str;
    ui->error->setVisible(false);
    if (ui->plus->isChecked()){ //Сложение

    str = ui->oper1->text();
    op1 = str.toInt(&ok1);

    if (ok1){
        str = ui->oper2->text();
        op2 = str.toInt(&ok2);

        if (ok2){
            res = op1+op2;
            ui->error->setVisible(0);
            ui->error->setText(" ");
            ui->resultlable->setNum(res);
        } else {
            ui->error->setText("Ошибка во втором операнде");
            ui->error->setVisible(1);
        }
    } else {
        ui->error->setText("Ошибка в первом операнде");
        ui->error->setVisible(1);
    }
    }
    if (ui->minus->isChecked()){ //Вычитание

        str = ui->oper1->text();
        op1 = str.toInt(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toInt(&ok2);

            if (ok2){
                res = op1-op2;
                ui->error->setVisible(0);
                ui->error->setText(" ");
                ui->resultlable->setNum(res);
            } else {
                ui->error->setText("Ошибка во втором операнде");
                ui->error->setVisible(1);
            }
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
        }
    }
    if (ui->mnoz->isChecked()){ //Умножение

        str = ui->oper1->text();
        op1 = str.toInt(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toInt(&ok2);

            if (ok2){
                res = op1*op2;
                ui->error->setVisible(0);
                ui->error->setText(" ");
                ui->resultlable->setNum(res);
            } else {
                ui->error->setText("Ошибка во втором операнде");
                ui->error->setVisible(1);
            }
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
        }
    }
    if (ui->dele->isChecked()){ //Деление

        str = ui->oper1->text();
        op1 = str.toInt(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toInt(&ok2);
            if (op2 != 0){
                if (ok2){
                    res = op1/op2;
                    ui->error->setVisible(0);
                    ui->error->setText(" ");
                    ui->resultlable->setNum(res);
                } else {
                    ui->error->setText("Ошибка во втором операнде");
                    ui->error->setVisible(1);
                }
            } else ui->resultlable->setText("Не дели на 0!");
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
        }
    }
}

void Widget::on_mnoz_clicked() //Переключение на умножение
{
    ui->operlabel1->setText("Множитель 1");
    ui->operlable2->setText("Множитель 2");
    ui->count->setText("Произведение");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

void Widget::on_dele_clicked() //Переключение на деление
{
    ui->operlabel1->setText("Делимое 1");
    ui->operlable2->setText("Делитель 2");
    ui->count->setText("Отношение");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

