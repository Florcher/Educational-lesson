#ifndef DRAWCLICKSCENE_H
#define DRAWCLICKSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "Vector2D.h"
#include "Objects.h"
#include <vector>

class DrawClickScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DrawClickScene(QObject* parent = 0);
    ~DrawClickScene() = default;
public:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    object::ptr getObject(int typeId);

private:
    std::vector<vector2D> points;
    int clickcount;
};

#endif // DRAWCLICKSCENE_H
