project(fcitx-light-ui)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_MODULE_PATH})
FIND_PACKAGE(Libintl REQUIRED)
FIND_PACKAGE(Gettext REQUIRED)
FIND_PACKAGE(Fcitx 4.1.2 REQUIRED)
FIND_PACKAGE(X11 REQUIRED)
FIND_PACKAGE(PkgConfig REQUIRED)

pkg_check_modules(FONTCONFIG "fontconfig" REQUIRED)
pkg_check_modules(FREETYPE2 "freetype2" REQUIRED)

# uninstall target
configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
    IMMEDIATE @ONLY)

add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

if(NOT DEFINED LIB_INSTALL_DIR)
    set(LIB_INSTALL_DIR ${CMAKE_INSTALL_PREFIX}/lib)
endif()

include(FindPkgConfig)

set(prefix      ${CMAKE_INSTALL_PREFIX})
set(exec_prefix ${CMAKE_INSTALL_PREFIX})
set(bindir ${prefix}/bin)
set(libdir ${LIB_INSTALL_DIR})
set(addondir ${libdir}/${package} )
set(pkgdatadir ${CMAKE_INSTALL_PREFIX}/share/${package})
set(localedir ${CMAKE_INSTALL_PREFIX}/share/locale)
set(includedir  ${CMAKE_INSTALL_PREFIX}/include)
add_definitions("-D_GNU_SOURCE")
set(CMAKE_C_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-sign-compare -Wno-unused-parameter -fvisibility=hidden ${CMAKE_CXX_FLAGS}")
set(CMAKE_SHARED_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_SHARED_LINKER_FLAGS}")
set(CMAKE_MODULE_LINKER_FLAGS "-Wl,--as-needed ${CMAKE_MODULE_LINKER_FLAGS}")

configure_file(config.h.in config.h)

set(libdir ${LIB_INSTALL_DIR})

add_subdirectory(src)
add_subdirectory(data)
add_subdirectory(po)
add_subdirectory(xpm)
