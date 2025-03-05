import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    title: "5-Day Forecast"

    ListView {
        anchors.fill: parent
        model: weatherData.forecast

        delegate: Item {
            width: parent.width
            height: 60

            Row {
                spacing: 10
                anchors.centerIn: parent

                Text {
                    text: modelData.date
                    font.pixelSize: 16
                }

                Image {
                    source: "https://openweathermap.org/img/w/" + modelData.icon + ".png"
                    width: 40
                    height: 40
                }

                Text {
                    text: modelData.temperature + "°C"
                    font.pixelSize: 16
                }
            }
        }
    }
}
