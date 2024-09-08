#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QRegularExpression>
#include <QStyle>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->run_button_, SIGNAL(clicked()), this, SLOT(run()));
    QObject::connect(ui->clear_button_, SIGNAL(clicked()), this, SLOT(clear()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clear()
{
    ui->text_lineedit_->clear();
    ui->expression_lineedit_->clear();
    ui->text_lineedit_->setPalette(this->style()->standardPalette());
}

void MainWindow::run()
{
    ui->text_lineedit_->setPalette(this->style()->standardPalette());

    const QString pattern = ui->expression_lineedit_->text();
    const QString text = ui->text_lineedit_->text();
    if(pattern.isEmpty())
    {
        return;
    }

    QRegularExpression reg_exp(pattern);
    QRegularExpressionMatch match = reg_exp.match(text);

    QPalette palette;
    palette.setColor(QPalette::Base, (match.hasMatch() ? Qt::green : Qt::red) );
    ui->text_lineedit_->setPalette(palette);
}
