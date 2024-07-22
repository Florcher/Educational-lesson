#include "linecreator.h"

LineCreator::LineCreator(QObject* parent) : clicksCount(0) {
    line.setName("Line");
}

object::ptr LineCreator::getObject() const
{
    return std::make_shared<Line>("Line", start, end);
}

void LineCreator::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    point.x = event->pos().x();
    point.y = event->pos().y();
    clicksCount++;
}

void LineCreator::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if(clicksCount == 0){
        start = point;
    } else {
        end = point;
    }
}
