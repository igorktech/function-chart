
#include "datawindow.h"

#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

//! [0]
DataWindow::DataWindow(QWidget *parent,QVector<QPointF>* ptr)
    : QWidget(parent), m_pTableWidget(NULL)
{
    Vect = ptr;
    m_pTableWidget = new QTableWidget(this);
    m_pTableWidget->setRowCount(Vect->length());
    m_pTableWidget->setColumnCount(2);
    m_TableHeader<<"x"<<"y";
    m_pTableWidget->setHorizontalHeaderLabels(m_TableHeader);
    m_pTableWidget->setShowGrid(true);
    auto vBegin = Vect->begin();
    auto vEnd = Vect->end();
    for(int num = 0; vBegin != vEnd; ++vBegin,num++ ){
    m_pTableWidget->setItem(num, 0, new QTableWidgetItem(QString("%1").arg(vBegin->x())));
    m_pTableWidget->setItem(num, 1, new QTableWidgetItem(QString("%1").arg(vBegin->y())));
    }



    QWidget::setWindowFlags(Qt::Sheet);


    closeButton = new QPushButton("&Close");
    connect(closeButton, &QPushButton::clicked,
            this, &DataWindow::close);
    loadButton = new QPushButton("&Load");
    connect(loadButton, &QPushButton::clicked,
            this, &DataWindow::loadFromFile);
    saveButton = new QPushButton("&Save");
    connect(saveButton, &QPushButton::clicked,
            this, &DataWindow::saveToFile);
    QVBoxLayout *layoutV = new QVBoxLayout;
    QFrame* frame = createFrame();

    QHBoxLayout *layoutH = new QHBoxLayout();
    layoutV->addWidget(m_pTableWidget);
    layoutH->addWidget(closeButton);
    layoutH->addWidget(saveButton);
    layoutH->addWidget(loadButton);
    frame->setLayout(layoutH);
    layoutV->addWidget(frame);
    setLayout(layoutV);

    setWindowTitle("Data");
}
DataWindow::~DataWindow(){
    delete closeButton;
    delete loadButton;
    delete saveButton;
    delete m_pTableWidget;
}
QFrame* DataWindow::createFrame(){
    QFrame* frame =new QFrame(this);
    frame->setObjectName("Frame");

    return frame;
}

void DataWindow::loadFromFile(){
    QString str=QFileDialog::getOpenFileName(0,"Open Dialog", ".", "*.csv" );

    if (!str.isNull())
    {
        int lineindex = 0;
          QTextStream in(&str);

        while (!in.atEnd()) {

            QString fileLine = in.readLine();

            QStringList lineToken = fileLine.split(QRegularExpression(","), Qt::SkipEmptyParts);

            for (int j = 0; j < lineToken.size(); j++) {
                QString value = lineToken.at(j);
                QStandardItem *item = new QStandardItem(value);

            }

            lineindex++;
        }
    }
    else{

    }
}
void DataWindow::saveToFile(){
    QString fileName = QFileDialog::getSaveFileName(this,
        "Save chart data", "",
        "*.csv;;All Files (*)");


    if (fileName.isEmpty())
        return;
    else {
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly)) {
            QMessageBox::information(this, "Unable to open file",
                file.errorString());
            return;
        }


        QTextStream out(&file);

        int tmp_column = 0;

        for(int i = 0; i < m_pTableWidget->rowCount(); ++i){
            for (int j = 0; j < m_pTableWidget->columnCount(); ++j){
                if(m_pTableWidget->item(i, j) != 0)
                    out<<m_pTableWidget->item(i, j)->text();
                    out<<";";
                    tmp_column = j;
            }
            if(m_pTableWidget->item(i, tmp_column) != 0)
                out<<"\n";
        }

        out.flush();

    }



}
