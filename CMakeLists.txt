cmake_minimum_required(VERSION 3.16)

project(SU_PO_spil LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5Sql REQUIRED)

add_executable(SU_PO_spil main.cpp
    entity.h entity.cpp
    character.h character.cpp
    menu.h menu.cpp

    combat.h combat.cpp
    entityList.h entityList.cpp
    item.h item.cpp
    itemlist.h itemlist.cpp
    cave.h cave.cpp

    databaseComs.h databaseComs.cpp)

# Link each target with other targets or add options, etc.
#add_executable(Main main.cpp)
target_link_libraries(Main PRIVATE sqlite3)

#add_executable(Insert main_insert.cpp)
#target_link_libraries(Insert  Qt5::Core Qt5::Sq


    include(GNUInstallDirs)
install(TARGETS SU_PO_spil
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
