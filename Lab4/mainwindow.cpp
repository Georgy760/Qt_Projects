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

void MainWindow::on_comboBox_OP1_currentIndexChanged(int index)
{
    QPalette pal;
      pal=ui->centralWidget->palette();
      switch (index)
      {
      case 0:
          if ((ui->comboBox_LOG->currentIndex() == 0) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ // 1 & 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
              } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 1) && ((ui->comboBox_OP1->currentIndex() == 0) || (ui->comboBox_OP2->currentIndex() == 0))){ // 1 || 0 = 1, 0 || 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 2) && ((ui->comboBox_OP1->currentIndex() == 1))){ // !0 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //1 -> 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 1) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 0 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 4) && (ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) { // A == B = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 5) && ((ui->comboBox_OP1->currentIndex() == 0) || ((ui->comboBox_OP2->currentIndex() == 0))) ){ // 1 || 0 = 1, 0 || 1 = 1, 1 == 1 = 0
              pal.setColor(QPalette::Window,Qt::green); //green
          } if ((ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) pal.setColor(QPalette::Window,Qt::red); //red

          break;

      case 1:
          if ((ui->comboBox_LOG->currentIndex() == 0) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ // 1 & 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
              } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 1) && ((ui->comboBox_OP1->currentIndex() == 0) || (ui->comboBox_OP2->currentIndex() == 0))){ // 1 || 0 = 1, 0 || 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 2) && ((ui->comboBox_OP1->currentIndex() == 1))){ // !0 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //1 -> 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 1) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 1 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 0 = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 4) && (ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) { // A == B = 1
              pal.setColor(QPalette::Window,Qt::green); //green
          } else pal.setColor(QPalette::Window,Qt::red); //red

          if ((ui->comboBox_LOG->currentIndex() == 5) && ((ui->comboBox_OP1->currentIndex() == 0) || ((ui->comboBox_OP2->currentIndex() == 0))) ){ // 1 || 0 = 1, 0 || 1 = 1, 1 == 1 = 0
              pal.setColor(QPalette::Window,Qt::green); //green
          } if ((ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) pal.setColor(QPalette::Window,Qt::red); //red
          break;
      }
      ui->centralWidget->setAutoFillBackground(true);
      ui->centralWidget->setPalette(pal);

}

void MainWindow::on_comboBox_LOG_currentIndexChanged(int index)
{
    QPalette pal;
    pal=ui->centralWidget->palette();

    switch (index)
    {
    case 0: ui->comboBox_OP2->setVisible(1);
        if ((ui->comboBox_LOG->currentIndex() == 0) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ // 1 & 1 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else pal.setColor(QPalette::Window,Qt::red); //red
        break;

    case 1: ui->comboBox_OP2->setVisible(1);
        if ((ui->comboBox_LOG->currentIndex() == 1) && ((ui->comboBox_OP1->currentIndex() == 0) || (ui->comboBox_OP2->currentIndex() == 0))){ // 1 || 0 = 1, 0 || 1 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else pal.setColor(QPalette::Window,Qt::red); //red
        break;

    case 2: ui->comboBox_OP2->setVisible(0);
        if ((ui->comboBox_LOG->currentIndex() == 2) && ((ui->comboBox_OP1->currentIndex() == 1))){ // !0 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else pal.setColor(QPalette::Window,Qt::red); //red
        break;

    case 3: ui->comboBox_OP2->setVisible(1);
        if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //1 -> 1 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 1) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 1 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else if ((ui->comboBox_LOG->currentIndex() == 3) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //0 -> 0 = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else pal.setColor(QPalette::Window,Qt::red); //red
        break;

    case 4: ui->comboBox_OP2->setVisible(1);
        if ((ui->comboBox_LOG->currentIndex() == 4) && (ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) { // A == B = 1
            pal.setColor(QPalette::Window,Qt::green); //green
        } else pal.setColor(QPalette::Window,Qt::red); //red
        break;

    case 5: ui->comboBox_OP2->setVisible(1);
        if ((ui->comboBox_LOG->currentIndex() == 5) && ((ui->comboBox_OP1->currentIndex() == 0) || ((ui->comboBox_OP2->currentIndex() == 0))) ){ // 1 || 0 = 1, 0 || 1 = 1, 1 == 1 = 0
            pal.setColor(QPalette::Window,Qt::green); //green
        } if ((ui->comboBox_OP1->currentIndex() == ui->comboBox_OP2->currentIndex())) pal.setColor(QPalette::Window,Qt::red); //red
        break;
    }

    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(pal);
}

void MainWindow::on_comboBox_OP2_currentIndexChanged(int index)
{
  /*QPalette pal;
    pal=ui->centralWidget->palette();
    switch (index)
    {
    case 0: if ((ui->comboBox_LOG->currentIndex() == 0) && ((ui->comboBox_OP1->currentIndex() == 0) && (ui->comboBox_OP2->currentIndex() == 0))){ //comboBox_LOG = 0
            pal.setColor(QPalette::Window,Qt::green); //green

        }

        break;
    case 1: //pal.setColor(QPalette::Window,Qt::red);
        break;
    }
    ui->centralWidget->setAutoFillBackground(true);
    ui->centralWidget->setPalette(pal);
    */
}
