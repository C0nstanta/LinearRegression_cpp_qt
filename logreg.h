#ifndef LOGREG_H
#define LOGREG_H
#include <QVector>
#include <QDebug>

class LogReg
{
public:
    LogReg();

    QVector<double> linear_regression(QVector<double>& X, QVector<double>& Y,
                             QVector<double> start_weights, double alpha, int num_steps);

//    double x_;
//    QVector<double> weights_;

};

#endif // LOGREG_H
