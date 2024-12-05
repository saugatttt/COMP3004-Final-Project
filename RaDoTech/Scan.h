#ifndef SCAN_H
#define SCAN_H

#include <QString>
#include <QDate>

class Scan {

private:
    QDate date;

    // store 24 measurements in the following order:
    // H1(left), H1(right), H2(left), H2(right), [...], F5(left), F5(right), F6(left), F6(right)
    QList<int> scanResults;

public:
    Scan(QDate &date);

    QDate getDate() const;
    QList<int> getScanResults();

};

#endif
