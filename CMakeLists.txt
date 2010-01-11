# Project Needs a name ofcourse
project(plasma-gioco1)
 
# Find the required Libaries
find_package(KDE4 REQUIRED)
include(KDE4Defaults)
 
add_definitions (${QT_DEFINITIONS} ${KDE4_DEFINITIONS})
include_directories(
   ${CMAKE_SOURCE_DIR}
   ${CMAKE_BINARY_DIR}
   ${KDE4_INCLUDES}
   )
 
# We add our source code here
set(gioco1_SRCS gioco1.cpp
                passwordsetup.cpp
 )

kde4_add_ui_files(gioco1_SRCS passwordsetup.ui)

kde4_add_kcfg_files(gioco1_SRCS GiocoConfig.kcfgc)


# Now make sure all files get to the right place
kde4_add_plugin(plasma_applet_gioco1 ${gioco1_SRCS})


target_link_libraries(plasma_applet_gioco1 
                      ${KDE4_PLASMA_LIBS} ${KDE4_KDEUI_LIBS})
 
install(TARGETS plasma_applet_gioco1
        DESTINATION ${PLUGIN_INSTALL_DIR})
 
install(FILES plasma-applet-gioco1.desktop
        DESTINATION ${SERVICES_INSTALL_DIR})

install(FILES gioco1.kcfg
        DESTINATION ${KCFG_INSTALL_DIR})

kde4_install_icons(${ICON_INSTALL_DIR})

