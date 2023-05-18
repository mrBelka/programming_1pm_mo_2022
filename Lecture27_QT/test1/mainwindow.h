#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QStringListModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btStart_clicked();
    void slotTimerAlarm();

private:
    Ui::MainWindow *ui;
    int m_velocity = 0;
    QTimer *timer;
    QStringListModel *model;
    QStringList List;
};
#endif // MAINWINDOW_H
