#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtMath"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_numOfColumns_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toInt(&ok);
    if (ok){
        ui->numOfColumns->setPalette(defPal);
        ui->mainTable->clear();
        while(ui->mainTable->columnCount()){
            ui->mainTable->removeColumn(0);
        }
        for (int i=0; i<arg1.toInt()%201; ++i){
            ui->mainTable->insertColumn(0);
        }
    }
    else{
        ui->numOfColumns->setPalette(redPal);
    }
    ui->textOut->clear();
}

void MainWindow::on_numOfRows_textChanged(const QString &arg1)
{
    bool ok;
    arg1.toInt(&ok);
    if (ok){
        ui->numOfRows->setPalette(defPal);
        ui->mainTable->clear();
        while(ui->mainTable->rowCount()){
            ui->mainTable->removeRow(0);
        }
        for (int i=0; i<arg1.toInt()%201; ++i){
            ui->mainTable->insertRow(0);
        }
    }
    else{
        ui->numOfRows->setPalette(redPal);
    }
    ui->textOut->clear();
}

void MainWindow::on_randomFill_clicked()
{
    bool ok1,ok2;
    ui->minInt->text().toInt(&ok1);
    ui->maxInt->text().toInt(&ok2);

    if (ok1){
        minRand = ui->minInt->text().toInt();
        ui->minInt->setPalette(defPal);
    }
    else{
        ui->minInt->setPalette(redPal);
        minRand = 0;
    }

    if (ok2){
        maxRand = ui->maxInt->text().toInt();
        ui->maxInt->setPalette(defPal);
    }
    else{
        maxRand = 200;
        ui->maxInt->setPalette(redPal);
    }

    for (int i = 0; i< ui->mainTable->rowCount(); ++i){
        for (int j=0; j< ui->mainTable->columnCount(); ++j){
            ui->mainTable->setItem(i,j, new QTableWidgetItem(QString::number(rand()%(maxRand - minRand + 1) + minRand)));
        }
    }
}

void MainWindow::on_getMinButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        float min = ui->mainTable->item(0,0)->text().toFloat();
        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                if (ui->mainTable->item(i,j)->text().toFloat() < min){
                    min = ui->mainTable->item(i,j)->text().toFloat();
                }
            }
        }
        ui->textOut->setText("Минимум = " + QString::number(min));
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

void MainWindow::on_getMaxButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        float max = ui->mainTable->item(0,0)->text().toFloat();
        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                if (ui->mainTable->item(i,j)->text().toFloat() > max){
                    max = ui->mainTable->item(i,j)->text().toFloat();
                }
            }
        }
        ui->textOut->setText("Максимум = " + QString::number(max));
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

void MainWindow::on_getAvrButton_clicked()
{
    tableIsOk = isTableOK();
    if (tableIsOk){
        sum = 0;
        for (int i = 0; i< ui->mainTable->rowCount(); ++i){
            for (int j=0; j< ui->mainTable->columnCount(); ++j){
                sum+=ui->mainTable->item(i,j)->text().toFloat();
            }
        }
        ui->textOut->setText("Среднее значение = " + QString::number(sum/(ui->mainTable->rowCount() *
                                                                          ui->mainTable->columnCount())));
    }
    else{
        ui->textOut->setText("Сначала корректно заполните таблицу");
    }
}

void MainWindow::on_sortButton_clicked()
{
    tableIsOk = isTableOK();
        if (tableIsOk){
            isSortingNow = true;
            int type = ui->typeOfSorting->currentIndex();
            ui->textOut->clear();
            ui->textOut->setText("Начата сортировка: " + ui->typeOfSorting->currentText());
            this->update();
            ui->textOut->update();
            switch (type) {
            case 0:
                bubbleSort();
                break;
            case 1:
                fastSort();
                break;
            case 2:
                combSort();
                break;
            case 3:
                gnomeSort();
                break;
            case 4:
                monkeySort();
                break;
            default:
                qDebug()<<"sort type error"<<Qt::endl;
            }
        }
        else{
            ui->textOut->setText("Сначала корректно заполните таблицу");
        }
}

bool MainWindow::isTableOK()
{
    bool ans=true;
    for (int i = 0; i< ui->mainTable->rowCount(); ++i){
        for (int j=0; j< ui->mainTable->columnCount(); ++j){
            bool castIsOk;
            if (ui->mainTable->item(i,j) != nullptr){
                ui->mainTable->item(i,j)->text().toFloat(&castIsOk);
                if (!castIsOk){
                    ans = false;
                    ui->mainTable->scrollToItem(ui->mainTable->item(i,j));
                    ui->mainTable->editItem(ui->mainTable->item(i,j));
                    break;
                }
            }
            else{
                ui->mainTable->scrollToItem(ui->mainTable->item(i,j));
                ui->mainTable->editItem(ui->mainTable->item(i,j));
                ans = false;
                break;
            }

        }
    }
    if (ui->mainTable->rowCount() + ui->mainTable->columnCount() == 0){
        ans = false;
    }
    return ans;
}



void MainWindow::on_mainTable_itemChanged(QTableWidgetItem *item)
{
    if (item != nullptr){
            bool ok;
            item->text().toFloat(&ok);
            if (!ok){
                item->setBackground(Qt::red);
            }
            else{
                if (!isSortingNow)
                    item->setBackground(Qt::white);
            }
        }
}


void MainWindow::bubbleSort()
{
        int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
        float arr[size];
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j+1]);
                }
            }
        }

        for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
            for(int j = 0; j < ui->mainTable->columnCount(); ++j)
                ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));
        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
}

void qsortRecursive(float *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;

    //Центральный элемент массива
    float mid = mas[size / 2];

    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            std::swap(mas[i],mas[j]);

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        qsortRecursive(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        qsortRecursive(&mas[i], size - i);
    }
}

void MainWindow::fastSort()
{
        int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
        float arr[size];
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        qsortRecursive(arr, size);
        for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
            for(int j = 0; j < ui->mainTable->columnCount(); ++j)
                ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));
        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
}

void MainWindow::combSort()
{
        int size = ui->mainTable->rowCount() * ui->mainTable->columnCount();
        float arr[size];
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        float factor = 1.2473309; // фактор уменьшения
        float step = size - 1; // шаг сортировки

        while (step >= 1)
        {
            for (int i = 0; i + step < size; i++)
            {
                if (arr[i] > arr[int(i + step)])
                {
                    std::swap(arr[i], arr[int(i + step)]);
                }
            }
            step /= factor;
        }

        for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
            for(int j = 0; j < ui->mainTable->columnCount(); ++j)
                ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));
        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
}

void MainWindow::gnomeSort()
{
        int n = ui->mainTable->rowCount() * ui->mainTable->columnCount();
        float arr[n];
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        int index = 0;

        while (index < n) {
            if (index == 0)
                index++;
            if (arr[index] >= arr[index - 1])
                index++;
            else {
                std::swap(arr[index], arr[index - 1]);
                index--;
            }
        }

        for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
            for(int j = 0; j < ui->mainTable->columnCount(); ++j)
                ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));
        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
}

bool correct(float *arr, int size) {
    while (size-- > 0)
        if (arr[size - 1] > arr[size])
            return false;
    return true;
}

void shuffle(float *arr, int size) {
    for (int i = 0; i < size; ++i){
        srand((unsigned int)clock());
        std::swap(arr[i], arr[(rand() % size)]);
    }
}

void bogoSort(float *arr, int size) {
    while (!correct(arr, size))
        shuffle(arr, size);
}

void MainWindow::monkeySort()
{
        int n = ui->mainTable->rowCount() * ui->mainTable->columnCount();
        float arr[n];
        for (int i = 0; i < ui->mainTable->rowCount(); ++ i) {
            for (int j=0; j < ui->mainTable->columnCount() ; ++j)
                arr[i*ui->mainTable->columnCount() +j] = ui->mainTable->item(i,j)->text().toFloat();
        }

        bogoSort(arr, n);

        for(int i = 0, k = 0; i < ui->mainTable->rowCount(); ++i)
            for(int j = 0; j < ui->mainTable->columnCount(); ++j)
                ui->mainTable->item(i,j)->setText(QString::number(arr[k++]));

        ui->textOut->setText(ui->textOut->toPlainText() + "\n" + "Сортировка завершена");
}
