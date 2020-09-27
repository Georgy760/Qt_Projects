#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
//Kolokutin Georgy G "Georgy760"
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_OP1_currentIndexChanged(int index);

    void on_comboBox_LOG_currentIndexChanged(int index);

    void on_comboBox_OP2_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
    void my_func(void);
};

#endif // MAINWINDOW_H
