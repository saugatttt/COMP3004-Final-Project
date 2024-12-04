#ifndef SCAN_H
#define SCAN_H

#include <QString>
#include <QDate>

class Scan {

private:
    QDate date;

public:
    Scan(QDate &date);

    QDate getDate() const;
    // some data structure(s) that stores the scan data?

};

#endif
