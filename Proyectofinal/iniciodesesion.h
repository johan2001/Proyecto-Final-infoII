#ifndef INICIODESESION_H
#define INICIODESESION_H

#include <QWidget>

namespace Ui {
class Iniciodesesion;
}

class Iniciodesesion : public QWidget
{
    Q_OBJECT

public:
    explicit Iniciodesesion(QWidget *parent = nullptr);
    ~Iniciodesesion();

private:
    Ui::Iniciodesesion *ui;
};

#endif // INICIODESESION_H
