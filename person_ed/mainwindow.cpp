#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_clear->click();// очищает значения
    ui->lineEdit_Points->setReadOnly(true);//запрещает менять текст
    ui->radioButton_Sex_M->click();
    ui->lineEdit_Name->setMaxLength(20);
    ui->lineEdit_str->setMaxLength(2);
    ui->lineEdit_int->setMaxLength(2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clear_clicked()
{
    {   //очищаем места вывода результатов и класса
        ui->label_hp_value->clear();
        ui->label_mp_value->clear();
        ui->label_atk_value->clear();
        ui->label_def_value->clear();
        ui->label_class_value->clear();
    }
    {   //очищаем ввод результатов и класса
        ui->lineEdit_Points->setText("20");
        ui->lineEdit_dex->setText("0");
        ui->lineEdit_int->setText("0");
        ui->lineEdit_luck->setText("0");
        ui->lineEdit_str->setText("0");
        /*ui->radioButton_Sex_M->setAutoExclusive(false);
        ui->radioButton_Sex_M->setChecked(false);
        ui->radioButton_Sex_W->setAutoExclusive(false);
        ui->radioButton_Sex_W->setChecked(false);*/
        calc_and_color_points();

    }
    ui->lineEdit_str->setVisible(true);
    points = 20;//максимум очков
    ui->lineEdit_Points->setText(QString::number(points));//преобразуем число в текст и записываем его в lineEdit
}

void MainWindow::on_pushButton_create_clicked()
{
    QString name;//имя
    int leng;//длина имени
    bool flag;//признак успешности генерации
    int str,dex,intel,luck;//параметры

    name.clear();
    name = ui->lineEdit_Name->text();
    leng = name.length();
    if ((leng < 3) ||(leng >20))
    {
        flag = false;
        QMessageBox::warning(this, "Ошибка", "Длина имени должа быть от 3 до 20 симоволов.");
    }
    else
    {
        flag = true;
    }
    if (flag)
    {
        if ((!ui->radioButton_Sex_M->isChecked())&&(!ui->radioButton_Sex_W->isChecked()))
        {
            flag = false;
            QMessageBox::warning(this, "Ошибка", "Пол не выбран.");
        }
        else
        {
            flag = true;
        }
    }
    if (flag) //сила
    {
        str = ui->lineEdit_str->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Сила.");
        }
        else
        {
            if ((str <1)|| (str > 10))
            {
                flag = false;
                QMessageBox::warning(this, "Ошибка", "Cила должна быть от 1 до 10 включительно.");
            }
        }
    }
    //Самим релизнуть
    if (flag) //ловкость
    {
        dex = ui->lineEdit_dex->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Ловкость.");
        }
        else
        {
            if ((dex <1)|| (dex > 10))
            {
                flag = false;
                QMessageBox::warning(this, "Ошибка", "Ловкость должна быть от 1 до 10 включительно.");
            }
        }
    }
    if (flag) //интеллект
    {
        intel = ui->lineEdit_int->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Интеллект.");
        }
        else
        {
            if ((intel <1)|| (intel > 10))
            {
                flag = false;
                QMessageBox::warning(this, "Ошибка", "Интеллект должна быть от 1 до 10 включительно.");
            }
        }
    }
    if (flag) //удача
    {
        luck = ui->lineEdit_luck->text().toInt(&flag);
        if (!flag)
        {
            QMessageBox::warning(this, "Ошибка", "Не верное значение параметра Удача.");
        }
        else
        {
            if ((dex <1)|| (dex > 10))
            {
                flag = false;
                QMessageBox::warning(this, "Ошибка", "Удача должна быть от 1 до 10 включительно.");
            }
        }
    }

    if (flag)// проверка суммы очков
    {
        int sum= points - (str+dex+intel+luck);
        ui->lineEdit_Points->setText(QString::number(sum));
        if (sum!=0)
        {
            flag = false;//false
            if (sum > 0)
            {
                QMessageBox::warning(this, "Ошибка", "Нужно потратить все очки.");
            }
            else
            {
                QMessageBox::warning(this, "Ошибка", "Нельзя больше чем "+QString::number(points)+" очков." );
            }
        }
    }

    if (flag)// вывод результата
    {
        int hp,mp,atk,def;
        hp = 8*str+2*dex;
        mp = 8*intel+dex+luck;
        atk = 6*str+2*dex+2*luck;
        def = 7*dex+3*luck;

        class_person(hp,mp,atk,def);

        ui->label_hp_value->setNum(hp);
        ui->label_mp_value->setNum(mp);
        ui->label_atk_value->setNum(atk);
        ui->label_def_value->setNum(def);
    }
    else
    {
        ui->label_hp_value->clear();
        ui->label_mp_value->clear();
        ui->label_atk_value->clear();
        ui->label_def_value->clear();
        ui->label_class_value->clear();
    }
}

void MainWindow::on_pushButton_rand_clicked()
{
    ui->label_class_value->clear();
    QString name;//имя
    int leng;//длина имени
    bool flag, random;
    random = false;
    ui->lineEdit_Points->setText("20");
    int str,dex,intel,luck;//параметры
    str = 0; dex = 0; intel = 0; luck = 0;
    srand(time(NULL));

    name.clear();

    ui->radioButton_Sex_M->setChecked(false);
    ui->radioButton_Sex_W->setChecked(false);

    if (!random)
    {
        flag = rand() % 2;
        if (flag == 0) {
            ui->radioButton_Sex_M->click();
            //ui->radioButton_Sex_W->setAutoExclusive(true);
            ui->radioButton_Sex_M->setChecked(true);
            sex=true;
        }
        else {
            ui->radioButton_Sex_W->click();
            //ui->radioButton_Sex_M->setAutoExclusive(true);
            ui->radioButton_Sex_W->setChecked(true);
            sex=false;
        }
    }

    QString male_names[10] = {"Угоу","Талваноп","Баглис","Могтулад","Иманил","Лионнеш","Елмон","Сулмутт","Мериаль","Стетьилс"};
    QString female_names[10] = {"Китамура","Нисида","Харука","Нисимура","Каору","Мацумото","Хаякава","Чиеко","Кикути","Киносита"};
    if (ui->radioButton_Sex_M->isChecked()){
        ui->lineEdit_Name->setText(name = male_names[rand()% 9]);
        ui->lineEdit_Name->text();
    }
    else// (ui->radioButton_Sex_W->isChecked()){
    {
        ui->lineEdit_Name->setText(name = female_names[rand()% 9]);
        ui->lineEdit_Name->text();
    }



    leng = name.length();
    if ((leng < 3) ||(leng >20))
    {
        flag = false;
        QMessageBox::warning(this, "Ошибка", "Длина имени должа быть от 3 до 20 симоволов.");
    }
    else
    {
        flag = true;
        while (!random)
        {
            if (((str + dex + intel + luck) > points) || ((str + dex + intel + luck) < points))
            {
                str = rand() % 9 + 2;
                dex = rand() % 9 + 2;
                intel = rand() % 9 + 2;
                luck = rand() % 9 + 2;
                random = false;
            }
            else
            {
                random = true;
                ui->lineEdit_str->setText(QString::number(str));
                ui->lineEdit_dex->setText(QString::number(dex));
                ui->lineEdit_int->setText(QString::number(intel));
                ui->lineEdit_luck->setText(QString::number(luck));
            }
        }




        if (random)// вывод результата
        {
            int hp,mp,atk,def;
            hp = 8*str+2*dex;
            mp = 8*intel+dex+luck;
            atk = 6*str+2*dex+2*luck;
            def = 7*dex+3*luck;

            class_person(hp,mp,atk,def);

            ui->label_hp_value->setNum(hp);
            ui->label_mp_value->setNum(mp);
            ui->label_atk_value->setNum(atk);
            ui->label_def_value->setNum(def);
        }
        else
        {
            ui->label_hp_value->clear();
            ui->label_mp_value->clear();
            ui->label_atk_value->clear();
            ui->label_def_value->clear();
            ui->label_class_value->clear();
        }
    }
}

void MainWindow::class_person(int str,int dex, int intel,int luck) // class_person(hp,mp,atk,def);
{

    ui->label_class_value->setText("!!!!!!!!!!!!!!");
//    if (ui->radioButton_Sex_M->isChecked()) //|| ui->radioButton_Sex_M->isChecked())
        if (sex)
    {
        if (str >= 5 && intel >= 5)
        {
            ui->label_class_value->setText("Паладин");
        }
        if (str >= 5 && luck >= dex )
        {
            ui->label_class_value->setText("Воин");
        }
        if (intel >= 5 && luck >= str)
        {
            ui->label_class_value->setText("Маг");
        }
        if (intel >= 5 && dex >= str)
        {
            ui->label_class_value->setText("Жрец");
        }
        if (luck >= 5 && dex >= str)
        {
            ui->label_class_value->setText("Разбойник");
        }
    }
    else
    //if (ui->radioButton_Sex_W->isChecked())
    {
        if (str >= 5 && intel >= 5)
        {
            ui->label_class_value->setText("Паладинша");
        }
        if (str >= 5 && luck >= dex )
        {
            ui->label_class_value->setText("Воительница");
        }
        if (intel >= 5 && luck >= str)
        {
            ui->label_class_value->setText("Волшебница");
        }
        if (intel >= 5 && dex >= str)
        {
            ui->label_class_value->setText("Жрица");
        }
        if (luck >= 5 && dex >= str)
        {
            ui->label_class_value->setText("Разбойница");
        }
    }
}

void MainWindow::on_lineEdit_Name_textChanged(const QString &arg1)
{
    QString str = arg1;
    str=str.remove(" "); //убираем пробелы
    int dlina_str=arg1.length();
    QPalette pal=ui->lineEdit_Name->palette();
    if(dlina_str<3){ //проверка длины
        pal.setColor(QPalette::Text,Qt::red);
    } else {
        pal.setColor(QPalette::Text,Qt::green);
    }
    ui->lineEdit_Name->setPalette(pal);
    ui->lineEdit_Name->setText(str);
}

void MainWindow::on_lineEdit_luck_textChanged(const QString &arg1) //проверка силы
{
    bool flag;
    int value=arg1.toInt(&flag);
    QPalette pal=ui->lineEdit_luck->palette();
    if (flag&(value<11)&&(value>0))
    {
        pal.setColor(QPalette::Text,Qt::green);
    } else {

        pal.setColor(QPalette::Text,Qt::red);
    }
    ui->lineEdit_luck->setPalette(pal);
    calc_and_color_points();
}

void MainWindow::calc_and_color_points(){ //расчет и расскарска остатка очков
    int ostatok;
    ostatok=points-ui->lineEdit_str->text().toInt()-ui->lineEdit_dex->text().toInt()-ui->lineEdit_int->text().toInt()-ui->lineEdit_luck->text().toInt();
    QPalette pal=ui->lineEdit_Points->palette();
    if(ostatok==0)
    {
        pal.setColor(QPalette::Text,Qt::green);
    } else {
        pal.setColor(QPalette::Text,Qt::red);
    }
    ui->lineEdit_Points->setPalette(pal);
    ui->lineEdit_Points->setText(QString::number(ostatok));
}

void MainWindow::on_lineEdit_str_textChanged(const QString &arg1)
{
    bool flag;
    int value=arg1.toInt(&flag);
    QPalette pal=ui->lineEdit_str->palette();
    if (flag&(value<11)&&(value>0))
    {
        pal.setColor(QPalette::Text,Qt::green);
    } else {

        pal.setColor(QPalette::Text,Qt::red);
    }
    ui->lineEdit_str->setPalette(pal);
    calc_and_color_points();
}

void MainWindow::on_lineEdit_dex_textChanged(const QString &arg1)
{
    bool flag;
    int value=arg1.toInt(&flag);
    QPalette pal=ui->lineEdit_dex->palette();
    if (flag&(value<11)&&(value>0))
    {
        pal.setColor(QPalette::Text,Qt::green);
    } else {

        pal.setColor(QPalette::Text,Qt::red);
    }
    ui->lineEdit_dex->setPalette(pal);
    calc_and_color_points();
}

void MainWindow::on_lineEdit_int_textChanged(const QString &arg1)
{
    bool flag;
    int value=arg1.toInt(&flag);
    QPalette pal=ui->lineEdit_int->palette();
    if (flag&(value<11)&&(value>0))
    {
        pal.setColor(QPalette::Text,Qt::green);
    } else {

        pal.setColor(QPalette::Text,Qt::red);
    }
    ui->lineEdit_int->setPalette(pal);
    calc_and_color_points();
}
