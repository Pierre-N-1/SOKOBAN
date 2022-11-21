#ifndef AIDEWINDOW_H
#define AIDEWINDOW_H

#include <QDialog>
#include <QPainter>
#include <QMovie>
#include <QLabel>

namespace Ui {
class AideWindow;
}

class AideWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AideWindow(QWidget *parent = nullptr);
    ~AideWindow();

private slots:
    void on_bRetour_clicked();
    void paintEvent(QPaintEvent* e);

private:
    Ui::AideWindow *ui;
};

#endif // AIDEWINDOW_H
