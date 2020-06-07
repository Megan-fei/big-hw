#ifndef SCENEONE_H
#define SCENEONE_H

#include <QMainWindow>
#include <QPaintEvent>
#include <QPainter>
#include "seat.h"
#include "tower.h"
#include "waypoint.h"
#include "virus.h"

class tower;
class virus;
class Sceneone : public QMainWindow
{
    Q_OBJECT
public:
    explicit Sceneone(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event);
    //related to seats
    void loadseats();
    //related to towers
    bool canbuytower()const;
    void mousePressEvent(QMouseEvent *event);
    //related to virus and waves
    void getCampHurt(int damage);
    void removeVirus(virus *viru);
    bool loadwave();

signals:

public slots:
        void updatemap();

private:
    //related to seats
    QList<seat> seats;
    //related to towers
    QList<tower *> towerslist;
    //related to waypoints
    QList<WayPoint *> waypoints;
    void loadwaypoints();
    //related to enemies and waves
    QList<virus *> viruses;
    int wavenow =0;
    //
    bool whetherwin = false;
};

#endif // SCENEONE_H
