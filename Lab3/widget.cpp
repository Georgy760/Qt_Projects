#include "widget.h"
#include "ui_widget.h"
#include <QtMath>

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
    ui->oper2->setVisible(1);
    ui->operlabel1->setText("Слагаемое 1");
    ui->operlable2->setText("Слагаемое 2");
    ui->count->setText("Сумма");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

void Widget::on_minus_clicked() //Переключение на вычитание
{
    ui->oper2->setVisible(1);
    ui->operlabel1->setText("Вычитаемое 1");
    ui->operlable2->setText("Вычитатель 2");
    ui->count->setText("Разность");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}

void Widget::on_count_clicked() //Кнопка вычисления
{
    ui->resultlable->setText(" ");
    double op1, op2;
    double res;
    bool ok1, ok2;
    QString str;
    ui->error->setVisible(false);
    if (ui->plus->isChecked()){ //Сложение

    str = ui->oper1->text();
    op1 = str.toDouble(&ok1);

    if (ok1){
        str = ui->oper2->text();
        op2 = str.toDouble(&ok2);

        if (ok2){
            res = op1+op2;
            if(qIsInf(res)){
                ui->resultlable->setText("Бесконечность");
            } else {
            ui->error->setVisible(0);
            ui->error->setText(" ");
            ui->resultlable->setNum(res);
            }
        } else {
            ui->error->setText("Ошибка во втором операнде");
            ui->error->setVisible(1);
            ui->error->setPalette(Qt::red);
        }
    } else {
        ui->error->setText("Ошибка в первом операнде");
        ui->error->setVisible(1);
        ui->error->setPalette(Qt::red);
    }
    }
    if (ui->minus->isChecked()){ //Вычитание

        str = ui->oper1->text();
        op1 = str.toDouble(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toDouble(&ok2);

            if (ok2){
                res = op1-op2;
                if(qIsInf(res)){
                    ui->resultlable->setText("Бесконечность");
                } else {
                ui->error->setVisible(0);
                ui->error->setText(" ");
                ui->resultlable->setNum(res);
                }
            } else {
                ui->error->setText("Ошибка во втором операнде");
                ui->error->setVisible(1);
                ui->error->setPalette(Qt::red);
            }
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
            ui->error->setPalette(Qt::red);
        }
    }
    if (ui->mnoz->isChecked()){ //Умножение

        str = ui->oper1->text();
        op1 = str.toDouble(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toDouble(&ok2);

            if (ok2){
                res = op1*op2;
                if (qIsInf(res)){
                    ui->resultlable->setText("Бесконечность");
                } else{
                ui->error->setVisible(0);
                ui->error->setText(" ");
                ui->resultlable->setNum(res);
                }
            } else {
                ui->error->setText("Ошибка во втором операнде");
                ui->error->setVisible(1);
                ui->error->setPalette(Qt::red);
            }
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
            ui->error->setPalette(Qt::red);
        }
    }
    if (ui->dele->isChecked()){ //Деление

        str = ui->oper1->text();
        op1 = str.toDouble(&ok1);

        if (ok1){
            str = ui->oper2->text();
            op2 = str.toDouble(&ok2);
            if ((op2 > 0.0) || ( op2 < 0.0)){
                if (ok2){
                    res = op1/op2;
                    if (qIsInf(res)){
                        ui->resultlable->setText("Бесконечность");
                    } else {
                    ui->error->setVisible(0);
                    ui->error->setText(" ");
                    ui->resultlable->setNum(res);
                    }
                } else {
                    ui->error->setText("Ошибка во втором операнде");
                    ui->error->setVisible(1);
                    ui->error->setPalette(Qt::red);
                }
            } else ui->resultlable->setText("Не дели на 0!");
        } else {
            ui->error->setText("Ошибка в первом операнде");
            ui->error->setVisible(1);
            ui->error->setPalette(Qt::red);
        }
    }
    if (ui->sqrt->isChecked()){ //Корень
        str = ui->oper1->text();
        op1 = str.toDouble(&ok1);
        if (op1>=0.0){
           res = sqrt(op1);
           if (qIsInf(res)){
               ui->resultlable->setText("Бесконечность");
           }else{
           ui->error->setVisible(0);
           ui->error->setText(" ");
           ui->resultlable->setNum(res);
           }
        } else {
            ui->error->setVisible(1);
         //   QLabel RedPalette;
         //   ui->error->QLabel.setColor(QPalette::WindowText, Qt::red);
            //ui->error->setPalette(QPalette::WindowText, Qt::white);
            ui->error->setText("Ошибка в операнде");


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
    ui->oper2->setVisible(1);
}

void Widget::on_dele_clicked() //Переключение на деление
{
    ui->oper2->setVisible(1);
    ui->operlabel1->setText("Делимое 1");
    ui->operlable2->setText("Делитель 2");
    ui->count->setText("Отношение");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
}


void Widget::on_sqrt_clicked() //Переключение на корень
{
    ui->operlabel1->setText("Значение под корнем");
    ui->operlable2->setText(" ");
    ui->count->setText("Корень из операнда");
    ui->error->setText(" ");
    ui->resultlable->setText(" ");
    ui->oper2->setVisible(0);
}
