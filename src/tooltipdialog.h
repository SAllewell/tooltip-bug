#ifndef __TOOLTIPDIALOG_H
#define __TOOLTIPDIALOG_H

#include "ui_tooltipdlg.h"

class tooltipdialog : public QDialog
{
    Q_OBJECT
    
public:
    tooltipdialog(QWidget *parent);
    ~tooltipdialog();

private:
    Ui::tooltipdlg ui;
};

#endif
