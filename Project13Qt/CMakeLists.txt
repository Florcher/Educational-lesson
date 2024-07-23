set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_PREFIX_PATH "C:/Qt/6.7.1/msvc2019_64")

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(QtProject
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}









        errordialog.h errordialog.cpp errordialog.ui

        createlinedialog.h createlinedialog.cpp createlinedialog.ui
        createcircledialog.h createcircledialog.cpp createcircledialog.ui
        createrectangledialog.h createrectangledialog.cpp createrectangledialog.ui
        createpolylinedialog.h createpolylinedialog.cpp createpolylinedialog.ui
        linecreator.h linecreator.cpp
        drawclickscene.h drawclickscene.cpp
        errordatadialog.h errordatadialog.cpp errordatadialog.ui








    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET QtProject APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(QtProject SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(QtProject
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(QtProject PRIVATE Qt${QT_VERSION_MAJOR}::Widgets kernel)



include(GNUInstallDirs)
install(TARGETS QtProject
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QtProject)
endif()

