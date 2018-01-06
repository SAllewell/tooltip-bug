#include "tooltiptest.h"
#include <QMouseEvent>
#include <QPainter>
#include <QStyleOptionRubberBand>
#include <QToolTip>

tooltiptest::tooltiptest(QWidget *parent) :
    QWidget(parent)
{
    setMouseTracking(true);
}

tooltiptest::~tooltiptest()
{
}

void tooltiptest::mousePressEvent(QMouseEvent* event)
{
    if (event->buttons() & Qt::LeftButton) {
        m_start = m_end = event->pos();
        m_rubberband = QRect();
        update();
    }
}

void tooltiptest::mouseReleaseEvent(QMouseEvent* event)
{
    m_end = event->pos();
    m_rubberband = QRect(m_start, m_end).normalized();
    update();
}

void tooltiptest::mouseMoveEvent(QMouseEvent* event)
{
    QPoint pos = event->pos();
    
    if (event->buttons() & Qt::LeftButton) {
        m_end = pos;
        m_rubberband = QRect(m_start, m_end).normalized();
        update();
        QToolTip::showText(mapToGlobal(pos), QString("%1 x %2").arg(m_rubberband.width()).arg(m_rubberband.height()));
    } else {
        QToolTip::showText(mapToGlobal(pos), QString("%1, %2").arg(pos.x()).arg(pos.y()));
    }
}

void tooltiptest::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    
    painter.fillRect(event->rect(), Qt::white);
    
    if (m_rubberband.isValid()) {
        QStyleOptionRubberBand opt;
        opt.initFrom(this);
        opt.shape = QRubberBand::Rectangle;
        opt.opaque = false;
        opt.rect = m_rubberband.adjusted(0, 0, 1, 1);

        style()->drawControl(QStyle::CE_RubberBand, &opt, &painter);
    }
}
