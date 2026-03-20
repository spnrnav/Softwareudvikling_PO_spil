cmake_minimum_required(VERSION 3.16)

project(SU_PO_spil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SU_PO_spil main.cpp
    entity.h entity.cpp
    character.h character.cpp)

include(GNUInstallDirs)
install(TARGETS SU_PO_spil
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
