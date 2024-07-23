#include "drawclickscene.h"

DrawClickScene::DrawClickScene(QObject* parent) : clickcount(0) {}

void DrawClickScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton)
        points.clear();

    vector2D point{event->scenePos().x(), event->scenePos().y()};
    points.push_back(point);
}

object::ptr DrawClickScene::getObject(int typeId)
{
    if(typeId == Line::Type()){
        if(points.size() > 1)
        {
        vector2D start = points[points.size() - 2];
        vector2D end = points[points.size() - 1];
        points.clear();
        return std::make_shared<Line>("Line", start, end);
        }
        throw std::exception();
    }

    if(typeId == Circle::Type()){
        if(points.size() > 1)
        {
        vector2D start = points[points.size() - 2];
        vector2D end = points[points.size() - 1];
        points.clear();
        double dir = sqrt((end.x - start.x) *(end.x - start.x) + (end.y - start.y) *(end.y - start.y));
        return std::make_shared<Circle>("Circle", start, dir);
        }
        throw std::exception();
    }

    if(typeId == Polyline::Type()){
        if(points.size() > 1)
        {
         std::vector<vector2D> data = points;
         points.clear();
         return std::make_shared<Polyline>("PolyLine", data);
        }
        throw std::exception();
    }
}

