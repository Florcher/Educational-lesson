#include "databaseview.h"
#include "QCoreApplication"
DataBaseView::DataBaseView(QObject* parent) {}

void DataBaseView::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::RightButton){
        _status = InputStatus::Canceled;
    }
    else{
        _status = InputStatus::Completed;
    }

    point.x = event->scenePos().x();
    point.y = event->scenePos().y();
}

vector2D DataBaseView::getPoint()
{
    _status = InputStatus::Inprogress;

    while(_status == InputStatus::Inprogress)
        QCoreApplication::processEvents();

    if(_status == InputStatus::Canceled)
        throw std::exception();

    return point;
}
