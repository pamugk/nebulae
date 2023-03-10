cmake_minimum_required(VERSION 3.5)

project(nebulae VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Gui NetworkAuth SvgWidgets WebEngineWidgets Widgets LinguistTools)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Gui NetworkAuth SvgWidgets Widgets WebEngineWidgets LinguistTools)

set(TS_FILES nebulae_en_US.ts)

set(QRC_FILES resources.qrc)

set(PROJECT_SOURCES
        main.cpp

        api/gogapiclient.h api/gogapiclient.cpp

        api/models/catalog.h api/models/catalogfilter.h
        api/models/catalogproductinfo.h
        api/models/filters.h
        api/models/metatag.h
        api/models/order.h api/models/orderfilter.h
        api/models/ownedproduct.h
        api/models/ownedproductinfo.h
        api/models/price.h
        api/models/product.h
        api/models/productshared.h
        api/models/review.h
        api/models/sort.h
        api/models/statistics.h
        api/models/tag.h
        api/models/user.h
        api/models/wishlist.h

        api/utils/catalogserialization.h api/utils/catalogserialization.cpp
        api/utils/catalogproductserialization.h api/utils/catalogproductserialization.cpp
        api/utils/orderserialization.h api/utils/orderserialization.cpp
        api/utils/ownedproductserialization.h api/utils/ownedproductserialization.cpp
        api/utils/ownedproductinfoserialization.h api/utils/ownedproductinfoserialization.cpp
        api/utils/priceserialization.h api/utils/priceserialization.cpp
        api/utils/reviewserialization.h api/utils/reviewserialization.cpp
        api/utils/serialization.h api/utils/serialization.cpp
        api/utils/statisticsserialization.h api/utils/statisticsserialization.cpp

        internals/navigationdestination.h
        internals/pages.h
        internals/settingsmanager.h internals/settingsmanager.cpp

        layouts/flowlayout.h layouts/flowlayout.cpp

        pages/allgamespage.h pages/allgamespage.cpp pages/allgamespage.ui
        pages/basepage.h pages/basepage.cpp
        pages/catalogproductpage.h pages/catalogproductpage.cpp pages/catalogproductpage.ui
        pages/orderspage.h pages/orderspage.cpp pages/orderspage.ui
        pages/ownedgamepage.h pages/ownedgamepage.cpp pages/ownedgamepage.ui
        pages/ownedgamespage.h pages/ownedgamespage.cpp pages/ownedgamespage.ui
        pages/storepage.h pages/storepage.cpp pages/storepage.ui
        pages/wishlistpage.h pages/wishlistpage.cpp pages/wishlistpage.ui

        widgets/bonusitem.h widgets/bonusitem.cpp widgets/bonusitem.ui
        widgets/checkeditem.h widgets/checkeditem.cpp widgets/checkeditem.ui
        widgets/collapsiblearea.h widgets/collapsiblearea.cpp widgets/collapsiblearea.ui
        widgets/featureitem.h widgets/featureitem.cpp widgets/featureitem.ui
        widgets/filtercheckbox.h widgets/filtercheckbox.cpp widgets/filtercheckbox.ui
        widgets/imageholder.h widgets/imageholder.cpp widgets/imageholder.ui
        widgets/ordergroup.h widgets/ordergroup.cpp widgets/ordergroup.ui
        widgets/orderitem.h widgets/orderitem.cpp widgets/orderitem.ui
        widgets/ownedproductgriditem.h widgets/ownedproductgriditem.cpp widgets/ownedproductgriditem.ui
        widgets/pagination.h widgets/pagination.cpp widgets/pagination.ui
        widgets/reviewitem.h widgets/reviewitem.cpp widgets/reviewitem.ui
        widgets/storegridtile.h widgets/storegridtile.cpp widgets/storegridtile.ui
        widgets/storelistitem.h widgets/storelistitem.cpp widgets/storelistitem.ui
        widgets/videoholder.h widgets/videoholder.cpp widgets/videoholder.ui
        widgets/wishlistitem.h widgets/wishlistitem.cpp widgets/wishlistitem.ui

        windows/authdialog.h windows/authdialog.cpp windows/authdialog.ui
        windows/mainwindow.cpp windows/mainwindow.h windows/mainwindow.ui
        windows/searchdialog.h windows/searchdialog.cpp windows/searchdialog.ui
        windows/settingsdialog.h windows/settingsdialog.cpp windows/settingsdialog.ui
        ${TS_FILES}
        ${QRC_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(nebulae
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET unofficial-gog-client APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation

    qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
else()
    if(ANDROID)
        add_library(nebulae SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(nebulae
            ${PROJECT_SOURCES}
        )
    endif()

    qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
endif()

target_link_libraries(nebulae PRIVATE Qt${QT_VERSION_MAJOR}::Gui Qt${QT_VERSION_MAJOR}::SvgWidgets Qt${QT_VERSION_MAJOR}::NetworkAuth Qt${QT_VERSION_MAJOR}::WebEngineWidgets Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(nebulae PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS nebulae
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(nebulae)
endif()
