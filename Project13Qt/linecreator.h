#ifndef LINECREATOR_H
#define LINECREATOR_H
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <Objects.h>

class LineCreator : public QObject
{
    Q_OBJECT

public:
    explicit LineCreator(QObject * parent = 0);
    virtual ~LineCreator() = default;

    object::ptr getObject() const;
private:

    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

    Line line;
    vector2D start, end, point;

    int clicksCount;
};

#endif // LINECREATOR_H
