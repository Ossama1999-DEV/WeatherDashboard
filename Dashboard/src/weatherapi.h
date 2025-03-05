#ifndef WEATHERAPI_H
#define WEATHERAPI_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class WeatherAPI : public QObject {
    Q_OBJECT
public:
    explicit WeatherAPI(QObject *parent = nullptr);
    void fetchWeather(const QString &city);

signals:
    void weatherDataReceived(const QString &weatherJson);

private slots:
    void onReplyFinished(QNetworkReply *reply);

private:
    QNetworkAccessManager manager;
};

#endif // WEATHERAPI_H
