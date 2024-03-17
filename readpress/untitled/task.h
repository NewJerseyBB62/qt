#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QRunnable>
#include <QSqlDatabase>

class Task : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit Task(QObject *parent = nullptr);
    void setSql(const QString &p_str);
    void startTask(const QString &p_str);
    void stopTask();
signals:
    void SigTaskOver();

protected:
    void run() override;

private:
    bool m_Run;
     QString m_Sqlstr;
     QSqlDatabase m_SqlObj;
};

#endif // TASK_H
