cmake_minimum_required(VERSION 3.15)

project(edvard)

include_directories(./)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(ImGui-SFML CONFIG REQUIRED)

set(IMGUISFML
        imgui-sfml/imconfig-SFML.h
        imgui-sfml/imgui-SFML.cpp
        imgui-sfml/imgui-SFML.h
        imgui-sfml/imgui-SFML_export.h
)

set(IMGUI
        imgui/imconfig.h
        imgui/imgui.cpp
        imgui/imgui.h
        imgui/imgui_demo.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_internal.h
        imgui/imgui_tables.cpp
        imgui/imgui_widgets.cpp
        imgui/imstb_rectpack.h
        imgui/imstb_textedit.h
        imgui/imstb_truetype.h
)

add_executable(${PROJECT_NAME} main.cpp ${IMGUISFML} ${IMGUI} app.h)

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window sfml-graphics sfml-system ImGui-SFML::ImGui-SFML imgui::imgui opengl32)