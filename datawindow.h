
#ifndef DATAWINDOW_H
#define DATAWINDOW_H
#include <QtWidgets>
#include <QWidget>
#include <QPushButton>
QT_BEGIN_NAMESPACE
class QPushButton;

QT_END_NAMESPACE


class DataWindow : public QWidget
{
    Q_OBJECT

public:
    DataWindow(QWidget *parent = nullptr, QVector<QPointF>* ptr = nullptr);
    ~DataWindow();
    void setWindowFlags(Qt::WindowFlags flags);

private:
    QFrame* createFrame();
    QStringList m_TableHeader;
    QPushButton *closeButton;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QTableWidget* m_pTableWidget;
    QVector<QPointF>* Vect;
public slots:
    void loadFromFile();
    void saveToFile();

};


#endif
