#include "virus.h"
#include "utility.h"
#include "sceneone.h"
#include <QDebug>
//construct function
const QSize virus::fixedsize(30,41);//mayberevised

virus::virus(WayPoint *startPoint,Sceneone *game,const QPixmap &fig) : QObject(0),position(startPoint->pos()),
    figure(fig),game(game),goalpoint(startPoint->nextwaypoint())//??QObject(0)?
{
    Hplife=300.0;//*canberevised
    Hpnow=300.0;//*canberevised
    speed=5;//*canberevised
    rotation=0.0;//?????
//    qDebug()<<"construct virus";

    //active?
}
//draw the viurs and healthbar
void virus::draw(QPainter *painter)
{
    //qDebug()<<"draw";
    if(!active)
        return;
    //healthbar
    static const int  healthbarWidth=40;
    painter->save();
    QPoint huansuan1(-healthbarWidth/2,-fixedsize.height()/2-3);//tiaozheng!!
    QPoint healthbarPos=position+huansuan1;
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::red);
    QRect healthbarBackrect(healthbarPos,QSize(healthbarWidth,2));
    painter->drawRect(healthbarBackrect);
    painter->setBrush(Qt::green);
    QRect healthbarRect(healthbarPos,QSize(Hpnow/Hplife,2));
    painter->drawRect(healthbarRect);
    //virus
    static const QPoint huansuan2(-fixedsize.width()/2,-fixedsize.height()/2);
    painter->translate(position);
    painter->rotate(rotation);
    painter->drawPixmap(huansuan2,figure);
    painter->restore();

}
//move
void virus::move()
{
   //qDebug()<<"move";
    if(!active)
    {
        return;
        qDebug()<<"not actice";
    }
    //at a waypoint
    if(collisionWithTurnpoint(position,1,goalpoint->pos(),1))
    {
        //qDebug()<<"^collided";
        //not reached final base
        if(goalpoint->nextwaypoint())
        {
            position=goalpoint->pos();
            this->goalpoint=goalpoint->nextwaypoint();
        }
        //reached final base
        else
        {
            game->getCampHurt(0);//deteriorate the camp
            game->removeVirus(this);//??????
        }
    }
    //on the way to waypoint
    QPoint targetpoint=goalpoint->pos();
    //未来修改这个可以添加移动状态，加减速等等
    double movespeed=speed;
    QVector2D normalized(targetpoint-position);
    normalized.normalize();
    position=position+normalized.toPoint() * movespeed;
    rotation=qRadiansToDegrees(qAtan2(normalized.y(),normalized.x()))+90;
    //后面几行？？？？？
}
//destruct function
virus::~virus()
{

}

//activate the virus
void virus::activate()
{
    active = true;
}
