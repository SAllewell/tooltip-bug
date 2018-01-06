#ifndef TOOLTIP_H
#define TOOLTIP_H

#include <QMainWindow>

namespace Ui {
class tooltip;
}

class tooltip : public QMainWindow
{
    Q_OBJECT

public:
    explicit tooltip(QWidget *parent = 0);
    ~tooltip();
    
public slots:
    void openDialog();

private:
    Ui::tooltip *ui;
};

#endif // TOOLTIP_H
