cmake_minimum_required(VERSION 3.5)

project(ParkingSystem VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH $ENV{usr}/local)
set(CMAKE_PREFIX_PATH $ENV{HOME}/local)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)

include_directories(${Tesseract_INCLUDE_DIRS})


set(PROJECT_SOURCES
        main.cpp
        widget.cpp
        widget.h
        Car.cpp
        Car.h
        widget.ui
        src/header/car.h
        src/header/initial_setting.h
        src/header/car_info.h
        src/header/parking_status.h
        src/car_init/car.cpp
        src/car_init/car_info.cpp
        src/parking_status/initial_setting.cpp
        src/parking_status/parking_status.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ParkingSystem
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ParkingSystem APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ParkingSystem SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ParkingSystem
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ParkingSystem PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(ParkingSystem PRIVATE ${Tesseract_LIBRARIES})

set_target_properties(ParkingSystem PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ParkingSystem)
endif()
