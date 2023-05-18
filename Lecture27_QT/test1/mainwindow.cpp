#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    model = new QStringListModel(this);

    // Populate our model


    // Glue model and view together
    ui->listView->setModel(model);
    ui->comboBox->setModel(model);

    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slotTimerAlarm()));
    timer->start(1000); // И запустим таймер
}

MainWindow::~MainWindow()
{
    delete timer;
    delete ui;
}


void MainWindow::on_btStart_clicked()
{
    std::string name = ui->line->text().toStdString();
    if(name.empty())
    {
        qDebug() << "Пустая строка";
    }
    else
    {
        qDebug() << ui->line->text();
        // Make data
        List << ui->line->text();
        model->setStringList(List);
    }
}

void MainWindow::slotTimerAlarm()
{
    qDebug() << "timeout";
    m_velocity++;
    ui->lcd->display(m_velocity);
}

