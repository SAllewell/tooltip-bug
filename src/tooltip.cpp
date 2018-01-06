#include "tooltip.h"
#include "ui_tooltip.h"
#include "tooltipdialog.h"

tooltip::tooltip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::tooltip)
{
    ui->setupUi(this);
    
    connect(ui->actionDialog, SIGNAL(triggered()), this, SLOT(openDialog()));
}

tooltip::~tooltip()
{
    delete ui;
}

void tooltip::openDialog()
{
    tooltipdialog *dlg = new tooltipdialog(this);
    dlg->exec();
    delete dlg;
}
