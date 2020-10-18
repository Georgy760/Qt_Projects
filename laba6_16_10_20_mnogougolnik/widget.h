#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMessageBox>
#include <vector>

using namespace std;

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

    void on_calculateSButton_clicked();

    void on_calculatePButton_clicked();

    void on_plusRowButton_clicked();

    void on_minusRowButton_clicked();

private:
    bool isEverythingOk;
    int numOfPoints;
    float s;
    float p;
    Ui::Widget *ui;
    QString answer;
    std::vector<std::pair<float, float>> polygon;
    float getS();

};
#endif // WIDGET_H
