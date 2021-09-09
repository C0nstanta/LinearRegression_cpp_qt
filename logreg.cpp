#include "logreg.h"

LogReg::LogReg(){};

QVector<double> LogReg::linear_regression(QVector<double>& X, QVector<double>& Y,
                                 QVector<double> start_weights, double alpha=0.01, int num_steps=10)
{
// Y = k * X + b;
    double b = start_weights[0];
    double k = start_weights[1];
    int n = X.size();


    // mse derivatve
    // int n = Y.size() - num cases
    // MSE = sum((Y_pre - Y)**2) / n


    for (int i = 0; i < num_steps; ++i)
    {
        QVector<double> diff(n);
        QVector<double> sub_diff;

        std::transform(X.begin(), X.end(), diff.begin(), [k , b](double x){
            return k * x + b;
        });
        std::transform(diff.begin(), diff.end(), Y.begin(), std::back_inserter(sub_diff),
                       std::minus<double>());
        diff.clear();

        //sum((k * X + b) - Y) / Y.size() - dy/db
        double db = std::accumulate(sub_diff.begin(), sub_diff.end(), 0.0) / n;

        std::transform(sub_diff.begin(), sub_diff.end(), X.begin(),
                       std::back_inserter(diff), std::multiplies<double>());

        //sum(((k * x + b) - Y) * X) / Y.size() - dy/dk
        double dk = std::accumulate(diff.begin(), diff.end(), 0.0) / n;


        k -= alpha * dk;
        b -= alpha * db;
    }



    return QVector<double>({b, k});
};
