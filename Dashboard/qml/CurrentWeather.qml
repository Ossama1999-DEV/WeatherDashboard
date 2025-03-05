import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    Column {
        spacing: 10
        anchors.centerIn: parent

        Text {
            id: cityName
            text: "City: "
            font.pixelSize: 18
        }

        Text {
            id: temperature
            text: "Temperature: "
            font.pixelSize: 18
        }

        Image {
            id: weatherIcon
            width: 50
            height: 50
        }

        Button {
            text: "View 5-day Forecast"
            onClicked: stackView.push("Forecast.qml")
        }
    }
}
