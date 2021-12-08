#ifndef DETECTED_H
#define DETECTED_H

#include <QWidget>

namespace Ui {
class detected;
}

class detected : public QWidget
{
    Q_OBJECT

public:
    explicit detected(QWidget *parent = nullptr);
    ~detected();

private:
    Ui::detected *ui;
};

#endif // DETECTED_H
