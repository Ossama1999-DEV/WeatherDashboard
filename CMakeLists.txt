cmake_minimum_required(VERSION 3.16)

# Définir le nom du projet et la langue
project(WeatherDashboard LANGUAGES CXX)

# Spécifier la version de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trouver les modules Qt nécessaires
find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick Network)

# Ajouter l'exécutable
add_executable(WeatherDashboard
    src/main.cpp
    src/weatherapi.h src/weatherapi.cpp
    src/weatherdata.h src/weatherdata.cpp
)

# Lier l'exécutable avec les bibliothèques Qt6 requises
target_link_libraries(WeatherDashboard
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::Network
)

# Ajouter le module QML
qt_add_qml_module(WeatherDashboard
    URI WeatherDashboard
    VERSION 1.0
    QML_FILES
        qml/Main.qml
        qml/SearchScreen.qml
        qml/CurrentWeather.qml
        qml/Forecast.qml
)

# Spécifier l'emplacement d'installation
install(TARGETS WeatherDashboard
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
