#include "calculate.h"
#include <QDebug>
Calculate::Calculate()
{

}

void Calculate::setA(qreal num){
    A = num;
}
void Calculate::setB(qreal num){
    B = num;
}
void Calculate::setC(qreal num){
    C = num;
}
void Calculate::setFrom(qreal num){
    From = num;
}
void Calculate::setTo(qreal num){
    To = num;
}
void Calculate::setStep(qreal num){
    Step = num;
}
void Calculate::setStepVal(qreal num){
    StepVal = num;
}
void Calculate::setSwitchFunc(int num){
    SwitchFunc = num;
}
void Calculate::setLength(int num){
    Length = num;
}
int Calculate::switchFunc(){
    return SwitchFunc;
}
qreal Calculate::a(){
    return A;

}
qreal Calculate::b(){
    return B;
}
qreal Calculate::c(){
    return C;
}
qreal Calculate::from(){
    return From;
}
qreal Calculate::to(){
    return To;
}
qreal Calculate::step(){
    return Step;
}
qreal Calculate::stepVal(){
    return StepVal;
}
int Calculate::length(){
    return Length;
}

void Calculate::FuncCalculate(){
    qreal stepRes = 0;

        switch (SwitchFunc) {
            case 0:
                //f(x) = A*(x*x) + B*x + C
               stepRes = A*(StepVal*StepVal)+B*StepVal+C;
                break;
            case 1:
                //f(x) = A * sin(x) + B * cos( C*x )
                stepRes = A*qSin(StepVal)+B*qCos(C*StepVal);
                break;
            case 2:
                //f(x) = A*log( B*x )
            if(qSin(StepVal*StepVal)*B !=0){
                stepRes = A*(log10(StepVal)+log10(B));
            }
                break;
            case 3:
                //f(x) = A / ( sin(x*x) * B )
                if(qSin(StepVal*StepVal)*B !=0){
                stepRes = A/(qSin(StepVal*StepVal)*B);
                }
                break;
            default:
                stepRes = 0;
                break;
    }
        num_resVec.push_back(QPointF(StepVal,stepRes));
}

void Calculate::Reserve(){
    num_resVec.reserve(Length);
}
