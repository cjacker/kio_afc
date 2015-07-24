project(kio-afc)
set(PROJECT_VERSION "5.3.2")
set(PROJECT_VERSION_MAJOR 5)

cmake_minimum_required(VERSION 2.8.12 FATAL_ERROR)

include(FeatureSummary)

set(QT_MIN_VERSION "5.4.0")
set(KF5_MIN_VERSION "5.3.0")
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS DBus Network Widgets Svg)

find_package(ECM 0.0.11 REQUIRED NO_MODULE)
set(CMAKE_MODULE_PATH ${ECM_MODULE_PATH} ${ECM_KDE_MODULE_DIR} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(KF5 ${KF5_MIN_VERSION} REQUIRED COMPONENTS
    I18n
    KIO
    Solid
)

include(KDEInstallDirs)
include(KDECMakeSettings)
include(KDECompilerSettings)
include(ECMMarkNonGuiExecutable)
include(ECMMarkAsTest)
include(ECMPackageConfigHelpers)
include(ECMOptionalAddSubdirectory)

find_package(KF5I18n CONFIG REQUIRED)
ki18n_install(po)

FIND_PACKAGE( libimobiledevice REQUIRED )

add_definitions(-DTRANSLATION_DOMAIN=\"kio_afc\")


set(kio_afc_PART_SRCS
        kio_afc.cpp
        afcdevice.cpp
        afcpath.cpp
)

add_library(kio_afc MODULE ${kio_afc_PART_SRCS} )
target_link_libraries(kio_afc ${libimobiledevice_LIBRARIES} Qt5::Core KF5::KIOCore KF5::I18n KF5::Solid)
set_target_properties(kio_afc PROPERTIES OUTPUT_NAME "afc")

install(TARGETS kio_afc DESTINATION ${PLUGIN_INSTALL_DIR}/kf5/kio)

########### install files ###############

#install( FILES mtp-network.desktop  DESTINATION  ${DATA_INSTALL_DIR}/konqueror/dirtree/remote )
#install( FILES solid_mtp.desktop  DESTINATION  ${DATA_INSTALL_DIR}/solid/actions )
install( FILES afc.protocol  DESTINATION  ${SERVICES_INSTALL_DIR} )
install( FILES afc-network.desktop  DESTINATION  ${DATA_INSTALL_DIR}/remoteview )


