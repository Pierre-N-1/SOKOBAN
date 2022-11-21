#ifndef OPTIONSWINDOW_H
#define OPTIONSWINDOW_H

#include <QDialog>
#include "configuration.h"
#include <QMessageBox>
#include <QPainter>

namespace Ui {
class OptionsWindow;
}

class OptionsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit OptionsWindow(QWidget *parent = nullptr);
    Configuration *config;
    QMessageBox msgBox;
    bool codeFaux;
    ~OptionsWindow();
    int trouve(QString code);

private slots:
    void on_bRetour_clicked();
    void on_bValider_clicked();
    void paintEvent(QPaintEvent* e);

private:
    Ui::OptionsWindow *ui;
};

#endif // OPTIONSWINDOWS_H
