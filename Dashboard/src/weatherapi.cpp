#include "weatherapi.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

const QString API_KEY = "YOUR_OPENWEATHERMAP_API_KEY";
const QString BASE_URL = "https://api.openweathermap.org/data/2.5/weather?q=%1&appid=%2&units=metric";

WeatherAPI::WeatherAPI(QObject *parent) : QObject(parent) {}

void WeatherAPI::fetchWeather(const QString &city) {
    QString url = BASE_URL.arg(city, API_KEY);
    QNetworkRequest request(QUrl(url));
    QNetworkReply *reply = manager.get(request);
    connect(reply, &QNetworkReply::finished, this, &WeatherAPI::onReplyFinished);
}

void WeatherAPI::onReplyFinished(QNetworkReply *reply) {
    if (reply->error() == QNetworkReply::NoError) {
        QString response = reply->readAll();
        emit weatherDataReceived(response);
    }
    reply->deleteLater();
}
