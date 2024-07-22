#ifndef DRAWCLICKSCENE_H
#define DRAWCLICKSCENE_H
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class DrawClickScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DrawClickScene(QObject* parent = 0);
    ~DrawClickScene() = default;

private:

};

#endif // DRAWCLICKSCENE_H
