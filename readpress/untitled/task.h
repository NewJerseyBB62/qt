#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QRunnable>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(const QString &p_str, QObject *parent = nullptr);
    void startTask(const QString &p_str);
    void stopTask();
signals:
    void SigTaskOver();

protected:
    void run() override;

private:
    bool m_Run;
     QString m_Sqlstr;
};

#endif // TASK_H
