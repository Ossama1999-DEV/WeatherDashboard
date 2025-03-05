import QtQuick 2.15
import QtQuick.Controls 2.15

Page {
    Column {
        spacing: 10
        anchors.centerIn: parent

        TextField {
            id: cityInput
            placeholderText: "Enter city name"
        }

        Button {
            text: "Get Weather"
            onClicked: {
                weatherAPI.fetchWeather(cityInput.text)
            }
        }
    }
}
