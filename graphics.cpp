#include "graphics.h"
Graphics::Graphics(QWidget *parent) : QWidget(parent),
    m_isTouching(false)
{

    series = new QLineSeries();

    chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->createDefaultAxes();
    chart->axes(Qt::Vertical).first()->setRange(0, 10);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    gLay = new QGridLayout;
    gLay->addWidget(chartView, 1, 1);
    setLayout(gLay);



}

void Graphics::addPoint(QPointF point){
    hide();
    if(m_isNewCalculate){
        numPoint = 0;
         yHighV = 10;
         yLowV = 0;
         xHighV = 1;
         xLowV = 0;

     series->clear();

     m_isNewCalculate = false;
    }


       series->append(point);
    if((series->at(numPoint)).y()> yHighV){
        yHighV = series->at(numPoint).y();
    }
    if(series->at(numPoint).y()< yLowV){
        yLowV = series->at(numPoint).y();
    }
    if((series->at(numPoint)).x()> xHighV){
        xHighV = series->at(numPoint).x();
    }
    if(series->at(numPoint).x()< xLowV){
        xLowV = series->at(numPoint).x();
    }
    chart->axes(Qt::Horizontal).last()->setRange(xLowV, xHighV);
    chart->axes(Qt::Vertical).last()->setRange(yLowV, yHighV);
    numPoint++;

   show();
}

void Graphics::mousePressEvent(QMouseEvent *event)
{
if(m_isTouching){
    if(dataWindow){
    DataWindow* tmp = dataWindow;
    delete tmp;
    }
dataWindow = new DataWindow(this, VecData);
dataWindow->show();
}
}


void Graphics::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus)
        chart->zoomIn();
    if (event->key() == Qt::Key_Minus)
        chart->zoomOut();
    if (event->key() == Qt::Key_D)
        chart->scroll(-10, 0);
    if (event->key() == Qt::Key_A)
        chart->scroll(10, 0);
    if (event->key() == Qt::Key_W)
        chart->scroll(0, 10);
    if (event->key() == Qt::Key_S)
        chart->scroll(0, -10);

}
void Graphics::SetPointer(QVector<QPointF>* ptr){
    VecData = ptr;
}
void Graphics::setPermit(bool b){
    m_isTouching = b;
}

Graphics::~Graphics(){
    if(dataWindow){

    delete dataWindow;
    }
    delete series;
    delete chart;
    delete gLay;
}
void Graphics::setNew(bool b){
    m_isNewCalculate = b;
}

