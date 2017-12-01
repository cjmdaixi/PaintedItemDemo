#include "layerrenderer.h"
#include <QPainter>
#include <QBrush>
#include <QtDebug>

LayerRenderer::LayerRenderer(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
    setAcceptedMouseButtons(Qt::AllButtons);
}

void LayerRenderer::paint(QPainter *painter)
{
    painter->resetTransform();
    painter->translate(m_transOrigin -m_transOrigin * m_scale);
    painter->scale(m_scale, m_scale);
    drawMesh(painter);
    //painter->fillRect(10, 10, 100, 100, QBrush(Qt::red));
}

void LayerRenderer::mousePressEvent(QMouseEvent *event)
{

}

void LayerRenderer::mouseMoveEvent(QMouseEvent *event)
{

}

void LayerRenderer::mouseReleaseEvent(QMouseEvent *event)
{

}

void LayerRenderer::wheelEvent(QWheelEvent *event)
{
    if (event->orientation() == Qt::Vertical) {
        m_scale += (float(event->delta())/1200);
        m_transOrigin = event->pos();
        update();
    }
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
