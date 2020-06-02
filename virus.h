#ifndef VIRUS_H
#define VIRUS_H

#include <QObject>

class virus : public QObject
{
    Q_OBJECT
public:
    explicit virus(QObject *parent = nullptr);

signals:

public slots:
};

#endif // VIRUS_H