#ifndef POSTTHREAD_H
#define POSTTHREAD_H

#include <QObject>
#include <QThread>
#include <QtNetwork/QNetworkReply>
#include "QtNetwork/QNetworkAccessManager"
#include "QtNetwork/QNetworkRequest"
#include <QTimer>

class PostThread : public QThread
{
    Q_OBJECT
public:
    explicit PostThread();
    void initPost();

public slots:
    void slotOver();
    void slotTimeout();

protected:
    void run() override;

signals:

private:
    QNetworkReply *m_Reply;
    QNetworkAccessManager m_manager;
    QNetworkRequest *m_request;
    QTimer *m_Timer;
};

#endif // POSTTHREAD_H
