//Я разделили взаимодействие между данными и графической оболочкой. Создал класс для вычислений Calculate
// Остальные классы отвечают за визуализацию данных, причем класс  MainWindow существует независимо от класса Graphics и взаимодействует с ним с помощью сигналов/слотов
//(Graphics выводит график, также в нем содержится класс DataWindow, который отвечает за вывод посчитанных точек в виде таблицы на экран и в файл с расширением .csv.
//Вывод из файла корректно мне не удалось реализовать)
//
//
//
//
//
//
//
//
//
//


#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow window;

    window.show();
    return a.exec();
}
