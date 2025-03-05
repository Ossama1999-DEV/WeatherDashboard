cmake_minimum_required(VERSION 3.16)

project(WeatherDashboard LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Network)

add_executable(WeatherDashboard
    src/main.cpp
    src/weatherapi.h src/weatherapi.cpp
    src/weatherdata.h src/weatherdata.cpp
)

target_link_libraries(WeatherDashboard
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Network
)

qt_add_qml_module(WeatherDashboard
    URI WeatherDashboard
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/SearchScreen.qml
        qml/CurrentWeather.qml
        qml/Forecast.qml
)

install(TARGETS WeatherDashboard
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
