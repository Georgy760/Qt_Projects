#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
}

void MainWindow::on_ButtonRandom_clicked()
{
    int row_count = ui->tableWidget->rowCount();
    int col_count = ui->tableWidget->columnCount();

    for (int i=0;i<row_count;i++){
            for (int j=0;j<col_count;j++){
                if(ui->tableWidget->item(i,j)==nullptr){ //ячейчка не определена
                    QTableWidgetItem*ti;//завели указатель
                    ti = new QTableWidgetItem;//создали ячейку
                    ui->tableWidget->setItem(i,j,ti);//занесли созданную ячейку в таблицу
                }
                ui->tableWidget->item(i,j)->setText(QString::number(rand()%200-100));
            }
        }
}



void MainWindow::on_tableWidget_cellChanged(int row, int column)
{
    bool fl;
    ui->tableWidget->item(row,column)->text().toUInt(&fl);
    if(fl)
        ui->tableWidget->item(row,column)->setBackground(Qt::white);
}
