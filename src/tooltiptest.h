#ifndef TOOLTIPTEST_H
#define TOOLTIPTEST_H

#include <QWidget>

class tooltiptest : public QWidget
{
public:
    tooltiptest(QWidget *parent);
    virtual ~tooltiptest() override;
    
protected:
    virtual void mousePressEvent(QMouseEvent* event) override;
    virtual void mouseReleaseEvent(QMouseEvent* event) override;
    virtual void mouseMoveEvent(QMouseEvent* event) override;
    virtual void paintEvent(QPaintEvent* event) override;

public:
    QRect m_rubberband;
    QPoint m_end;
    QPoint m_start;
};

#endif // TOOLTIPTEST_H
