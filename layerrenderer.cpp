#include "layerrenderer.h"
#include <QPainter>
#include <QBrush>
#include <QtDebug>

LayerRenderer::LayerRenderer(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setAcceptHoverEvents(true);
    setAcceptedMouseButtons(Qt::AllButtons);
    m_prevPoint = QPoint(-1, -1);
}

void LayerRenderer::paint(QPainter *painter)
{
    painter->setTransform(m_transform);
    drawMesh(painter);
}

void LayerRenderer::mousePressEvent(QMouseEvent *event)
{
    m_prevPoint = event->pos();
}

void LayerRenderer::mouseMoveEvent(QMouseEvent *event)
{
    auto curPos =event->pos();
    auto offsetPos = curPos - m_prevPoint;
    auto tm = QTransform()
            .translate(offsetPos.x(), offsetPos.y());
    m_prevPoint = curPos;
    m_transform *= tm;
    update();
}

void LayerRenderer::mouseReleaseEvent(QMouseEvent *event)
{

}

void LayerRenderer::wheelEvent(QWheelEvent *event)
{
    if (event->orientation() == Qt::Vertical) {
        auto pos = event->pos();
        m_scale = 1 + (float(event->delta())/1200);
        auto tm = QTransform()
                .translate(pos.x(), pos.y())
                .scale(m_scale, m_scale)
                .translate(-pos.x(), -pos.y());
        m_transform *= tm;
        update();
    }
}

void LayerRenderer::hoverMoveEvent(QHoverEvent *event)
{
    QQuickPaintedItem::hoverMoveEvent(event);
}

void LayerRenderer::drawMesh(QPainter *painter)
{
    painter->drawLine(width() / 4, height() / 4,        width() / 4 * 3, height() / 4);
    painter->drawLine(width() / 4, height() / 4 * 2,    width() / 4 * 3, height() / 4 * 2);
    painter->drawLine(width() / 4, height() / 4 * 3,    width() / 4 * 3, height() / 4 * 3);

    painter->drawLine(width() / 4, height() / 4,        width() / 4, height() / 4 * 3);
    painter->drawLine(width() / 4 * 2, height() / 4,    width() / 4 * 2, height() / 4 * 3);
    painter->drawLine(width() / 4 * 3, height() / 4,    width() / 4 * 3, height() / 4 * 3);
}
