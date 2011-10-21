#ifndef MAP_H
#define MAP_H

#include <QMainWindow>
#include "svgview.h"

namespace Ui {
    class map;
}

class map : public QMainWindow
{
    Q_OBJECT

public:
    explicit map(QWidget *parent = 0);
    ~map();

private:
    Ui::map *ui;
    SvgView *m_view;
private slots:
    void openFile();
};

#endif // MAP_H
