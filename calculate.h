#ifndef CALCULATE_H
#define CALCULATE_H

#include <math.h>
#include <QtGlobal>
#include <QVector>
#include <QPoint>
#include <QString>
#include <QtMath>

class Calculate
{
    int SwitchFunc = 0;
    qreal From = 0;
    qreal To = 1;
    qreal Step = 0;
    qreal StepVal = 0;
    qreal A = 0, B = 0, C = 0;
    int Length = 0;
    QVector<QPointF> num_resVec{0};
public:
    Calculate();
void setA(qreal);
void setB(qreal);
void setC(qreal);
void setFrom(qreal);
void setTo(qreal);
void setStep(qreal);
void setStepVal(qreal);
void setSwitchFunc(int);
void setLength(int);
int switchFunc();
void FuncCalculate();
void Reserve();
qreal a();
qreal b();
qreal c();
qreal from();
qreal to();
qreal step();
qreal stepVal();
int length();
QVector<QPointF>& vect(){
    return num_resVec;
}
QVector<QPointF>* vectPtr(){
    return &num_resVec;
}


};

#endif // CALCULATE_H
