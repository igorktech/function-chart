#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this,SIGNAL(sendVectorPointer(QVector<QPointF>*)),ui->widget,SLOT(SetPointer(QVector<QPointF>*)));

    //QDoubleValidator* valid = new QDoubleValidator(-10000,10000,6);
    //ui->aEditFill->QLineEdit::setValidator(valid);
    //ui->bEditFill->QLineEdit::setValidator(valid);
    //ui->cEditFill->QLineEdit::setValidator(valid);
    //ui->fromEditFill->QLineEdit::setValidator(valid);
    //ui->toEditFill->QLineEdit::setValidator(valid);
    //ui->stepEditFill->QLineEdit::setValidator(valid);


    dumpObjectTree();
}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::valueChangedA(QString str){
    bool ok;
    objC.setA(str.toDouble(&ok));
}
void MainWindow::valueChangedB(QString str){
    bool ok;
    objC.setB(str.toDouble(&ok));
}
void MainWindow::valueChangedC(QString str){
    bool ok;
    objC.setC(str.toDouble(&ok));
}
void MainWindow::valueChangedFrom(QString str){
    bool ok;
    objC.setFrom(str.toDouble(&ok));
}
void MainWindow::valueChangedTo(QString str){
    bool ok;
    objC.setTo(str.toDouble(&ok));
}
void MainWindow::valueChangedStep(QString str){
    bool ok;
    objC.setStep(str.toDouble(&ok));
}
void MainWindow::valueChangedSwitchFunc(int num){
    objC.setSwitchFunc(num);
}
void MainWindow::slotEnabled(){
   if(!flag){
    if(statement){
        if(statementBreak){
            objC.vect().clear();
            emit sendNew(true);
        }
        statementBreak = false;
        ui->frameEdit->setEnabled(statement);
        ui->startB->setText("Start");
        statement = false;
        flag = false;

    }
    else{

        ui->frameEdit->setEnabled(statement);
        objC.setStepVal(objC.from());
        objC.setLength((qAbs(objC.to()-objC.from()))/objC.step());
        objC.Reserve();
        emit sendVectorPointer(objC.vectPtr());
        flag = true;
        ui->widget->setFocus();
        timer_id = startTimer(15);


    }
   }
}

void MainWindow::timerEvent(QTimerEvent *event){
if(flag){
if(!statementPause){
    int progress = 0;
    if(objC.stepVal()<= objC.to()){
    objC.FuncCalculate();
    emit sendPoint(objC.vect().last());
    progress = qAbs(objC.stepVal()-objC.from())/(objC.to()-objC.from())*100;
    ui->startB->setText(QString("Progress %1% ").arg(progress));
    objC.setStepVal(objC.stepVal()+objC.step());
}
    else{
      killTimer(timer_id);
      ui->startB->setText(QString("Progress 100%"));
      emit sendPermit(true);
    }
    }
}
}
void MainWindow::slotPause(){

    if(flag){
    statementPause = !statementPause;

    if(statementPause){
        ui->pauseB->setText("Continue");
        killTimer(timer_id);
        emit sendPermit(true);
    }
    else{
        ui->pauseB->setText("Pause");
        emit sendPermit(false);
        timer_id = startTimer(15);
    }
    }
}
void MainWindow::slotBreak(){


    statementBreak = true;
    statement = true;
    if(flag&&statementPause){
    killTimer(timer_id);
    }
    flag = false;

    statementPause = false;
    ui->pauseB->setText("Pause");
    emit sendPermit(false);
    ui->startB->setText("New");
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this, "Inform", "Hello,It's a small calculation programm", QMessageBox::Close, Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);

}
