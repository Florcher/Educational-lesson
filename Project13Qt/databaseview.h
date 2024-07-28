#ifndef DATABASEVIEW_H
#define DATABASEVIEW_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "Vector2D.h"
#include "InputStatus.h"
class DataBaseView : public QGraphicsScene
{
public:
    explicit DataBaseView(QObject* parent = 0);
    ~DataBaseView() = default;

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    vector2D getPoint();

private:

    vector2D point;
    InputStatus _status;
};

#endif // DATABASEVIEW_H
