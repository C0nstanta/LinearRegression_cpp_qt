#ifndef NORMALIZE_H
#define NORMALIZE_H
#include <QVector>


struct NormData
{
    QVector<double> v_norm;
    double v_mean;
    double v_std;
};


class Normalize
{
public:
    Normalize();

    NormData StandartScoreNorm(const QVector<double>&);
    QVector<double> StandartScoreDeonorm(NormData&);

    NormData MinMaxNorm(const QVector<double>&);
    QVector<double> MinMaxDenorm(NormData&);

    NormData DivMaxNorm(const QVector<double>&);
    QVector<double> DivMaxDenorm(NormData&);
};

#endif // NORMALIZE_H
