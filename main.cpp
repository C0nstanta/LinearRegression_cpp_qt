#include <QCoreApplication>
#include <QDebug>
#include <QVector>
#include "logreg.h"
#include <normalize.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Hello World";


    QVector<double> weights {1.3, 3.2};



    qDebug() << weights;

    QVector<double> X{70.0, 42.0, 92.0, 94.0, 89.0, 36.0, 28.0, 75.0,
                      63.0, 46.0, 57.0, 59.4, 28.0, 50.0, 58.0};

    QVector<double> Y{70.0, 57.98, 67.86, 110.0, 103.5, 130.0, 52.0,
                      51.0, 74.0, 82.5, 86.0, 68.0, 73.5, 50.0, 67.0};

    NormData x_norm_data;
    QVector<double> X1;
    QVector<double> X2;
    QVector<double> X3;

    Normalize norm;

    x_norm_data = norm.StandartScoreNorm(X);
    X1 = norm.StandartScoreDeonorm(x_norm_data);

    qDebug() << x_norm_data.v_mean << x_norm_data.v_std;
    qDebug() << x_norm_data.v_norm;

    qDebug() << X1;

    qDebug() << "===========================================";


    NormData x_min_max_norm;

    x_min_max_norm = norm.MinMaxNorm(X);
    X2 = norm.StandartScoreDeonorm(x_norm_data);

    qDebug() << x_min_max_norm.v_mean << x_min_max_norm.v_std;
    qDebug() << x_min_max_norm.v_norm;

    qDebug() << X2;
    qDebug() << "===========================================";
    NormData x_max_norm;

    x_max_norm = norm.DivMaxNorm(X);
    X3 = norm.DivMaxDenorm(x_max_norm);

    qDebug() << x_max_norm.v_std;
    qDebug() << x_max_norm.v_norm;

    qDebug() << X3;
    qDebug() << "===========================================";



    LogReg logreg;
    QVector<double> new_wages =  logreg.linear_regression(X, Y, {2, 3}, 0.02, 10);
    qDebug() << new_wages;

    return a.exec();
}
