#ifndef MAINBTNFORM_H
#define MAINBTNFORM_H

#include <QWidget>

namespace Ui {
class MainBtnForm;
}

class MainBtnForm : public QWidget
{
    Q_OBJECT

public:
    explicit MainBtnForm(QWidget *parent = nullptr);
    ~MainBtnForm();
    void setBtnType(const int p_type);
    void setFont(const QString p_font, const int p_size, const int p_width, const QString p_color);
    void setBtnText(const QString p_text);

signals:
    void sigPressed(const bool p_state);

protected:
    bool eventFilter(QObject *, QEvent *);

private:
    Ui::MainBtnForm *ui;
};

#endif // MAINBTNFORM_H
