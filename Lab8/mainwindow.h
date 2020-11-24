#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox> // библиотека с окошками сообщений
#include <QDebug>
#include <QTableWidgetItem>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
   explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_numOfColumns_textChanged(const QString &arg1);

    void on_numOfRows_textChanged(const QString &arg1);

    void on_randomFill_clicked();

    void on_getMinButton_clicked();

    void on_getAvrButton_clicked();

    void on_getMaxButton_clicked();

    void on_sortButton_clicked();

    void on_mainTable_itemChanged(QTableWidgetItem *item);

private:
    Ui::MainWindow *ui;
    void bubbleSort();
    void fastSort();
    void combSort();
    void gnomeSort();
    void monkeySort();
    bool isSortingNow=false;
    bool tableIsOk = true;
    bool isTableOK();
    float sum = 0;
    int numOfElements = 0;
    int minRand = 0;
    int maxRand = 200;
    QPalette defPal = QPalette();
    QPalette redPal;
};
#endif // MAINWINDOW_H
