#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->tableWidget->setColumnWidth(0, ui->tableWidget->width()/2);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_calculateSButton_clicked()
{
    polygon.clear();
    isEverythingOk = true;
    numOfPoints = ui->tableWidget->rowCount();
    for (int i=0; i<numOfPoints; ++i){
        bool ok1 = false, ok2 = false;
        float x,y;
        if (ui->tableWidget->item(i,0) != nullptr && ui->tableWidget->item(i,1) != nullptr){
            ok1= true; ok2=true;
            x = ui->tableWidget->item(i,0)->text().toFloat(&ok1);
            y = ui->tableWidget->item(i,1)->text().toFloat(&ok2);
        }

        if (!(ok1 && ok2))
            isEverythingOk = false;
        else{
            polygon.push_back(std::pair<float, float>(x, y));
        }
    }
    if (isEverythingOk){
        answer = QString::number(getS());
    }
    else {
        answer="Некорректный ввод";
    }
    QMessageBox::information(nullptr, "Площадь", answer);
}

void Widget::on_calculatePButton_clicked()
{

    QMessageBox::information(nullptr, "Периметр", answer);
}

void Widget::on_plusRowButton_clicked()
{
    ui->tableWidget->insertRow(ui->tableWidget->rowCount());
}

void Widget::on_minusRowButton_clicked()
{
    ui->tableWidget->removeRow(ui->tableWidget->currentRow());
}

float Widget::getS()
{
    float localAns=0;
    for(size_t i = 0; i < polygon.size(); ++i)
    {
        if(i != polygon.size() - 1)
            localAns += (polygon[i].first * polygon[i + 1].second - polygon[i].second * polygon[i + 1].first);
        else
            localAns += (polygon[i].first * polygon[0].second - polygon[i].second * polygon[0].first);
    }

    return abs(localAns)/2;
}

