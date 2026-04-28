cmake_minimum_required(VERSION 3.10)
project(shepherd)

set(CMAKE_C_STANDARD 11)

file(GLOB COMMON_SOURCES "src/common/*.c")
if(WIN32)
    file(GLOB OS_SOURCES "src/windows/*.c")
else()
    file(GLOB OS_SOURCES "src/linux/*.c")
endif()

add_executable(${PROJECT_NAME} ${COMMON_SOURCES} ${OS_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE 
    include
    external/gtk/include/gtk-3.0
    external/gtk/include/glib-2.0
    external/gtk/lib/glib-2.0/include
    external/gtk/include/pango-1.0
    external/gtk/include/harfbuzz       
    external/gtk/include/cairo
    external/gtk/include/gdk-pixbuf-2.0
    external/gtk/include/atk-1.0
)

target_link_directories(${PROJECT_NAME} PRIVATE 
    lib 
    external/gtk/lib
) 

target_link_libraries(${PROJECT_NAME} PRIVATE 
    gtk-3 
    gdk-3
    z
    pangocairo-1.0
    pango-1.0
    harfbuzz
    atk-1.0
    cairo
    gdk_pixbuf-2.0
    gio-2.0
    glib-2.0 
    gobject-2.0
    intl
)