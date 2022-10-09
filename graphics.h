#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <QWidget>
#include <QtWidgets/QRubberBand>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QTableView>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QSplineSeries>
#include <QtCharts/QVXYModelMapper>
#include <QtWidgets/QHeaderView>
#include <QPainter>
#include <QtCharts>
#include <QPushButton>
#include <datawindow.h>
class Graphics : public QWidget
{
    Q_OBJECT
QLineSeries *series;
QChart *chart;
QGridLayout* gLay;
DataWindow *dataWindow;
QVector<QPointF>* VecData;
public:
     ~Graphics();
    explicit Graphics(QWidget *parent = nullptr);
public slots:
void addPoint(QPointF);
void SetPointer(QVector<QPointF>*);
void setPermit(bool);
void setNew(bool);
signals:
protected:

    void mousePressEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

private:

    bool m_isTouching = false;
    bool m_isNewCalculate = false;
    int numPoint = 0;
    qreal yHighV = 10;
    qreal yLowV = 0;
    qreal xHighV = 1;
    qreal xLowV = 0;

};

#endif // GRAPHICS_H
