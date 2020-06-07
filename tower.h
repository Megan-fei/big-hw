#ifndef TOWER_H
#define TOWER_H

#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QPaintEvent>
#include "sceneone.h"
class Sceneone;
class tower
{
public:
    tower(QPoint pos,Sceneone *scene, const QPixmap &fig=QPixmap(":/nurseone.jpg"));
    void draw(QPainter *painter);
private:
    QPoint position;//center position
    int attackrange;
    int damage;
    int firerate;
    QPixmap figure;

    static const QSize fixedsize;//the size of the tower
};

#endif // TOWER_H
