#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <calculate.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Calculate objC;
    bool statement = false;
    bool statementPause = false;
    bool statementBreak = false;
    bool flag = false;
    int timer_id;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void valueChangedA(QString);
    void valueChangedB(QString);
    void valueChangedC(QString);
    void valueChangedFrom(QString);
    void valueChangedTo(QString);
    void valueChangedStep(QString);
    void valueChangedSwitchFunc(int);
    void slotEnabled();
    void slotPause();
    void slotBreak();
     void on_actionAbout_triggered();
protected:
    virtual void timerEvent(QTimerEvent *event) override;
signals:
    void sendPoint(QPointF);
    void sendPermit(bool);
    void sendNew(bool);
    void sendVectorPointer(QVector<QPointF>*);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
