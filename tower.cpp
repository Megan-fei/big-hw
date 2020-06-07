#include "tower.h"
#include <QPainter>
#include <QPixmap>
#include <QPoint>
#include <QPaintEvent>
#include <QDebug>
#include "sceneone.h"

const QSize tower::fixedsize(49,64);//????????????revise!!!
//construct function
tower::tower(QPoint pos,Sceneone *game, const QPixmap &fig)
{
    position=pos;
    figure=fig;
    attackrange=100;//@@@@@need to be set
    damage=10;//@@@@@need to be set
    firerate=1000;//@@@@@@need to be set
}
//drawing function
void tower::draw(QPainter *painter)
{
    painter->save();
    painter->setPen(Qt::white);
    //draw attack circle
    painter->drawEllipse(position,attackrange,attackrange);
    //draw the picture of the tower
    static const QPoint huansuan(-fixedsize.width()/2,-fixedsize.height()/2);//huansuan zuobiao
//    painter.drawPixmap(huansuan+position,figure);
    painter->translate(position);
    painter->drawPixmap(huansuan,figure);
    painter->restore();
}
//
