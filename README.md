1) Скачиваем проект из репозитория
2) Устанавливаем пакетный менеджер vcpkg
3) Устанавливаем cmake
4) С помощью пакетного менеджера устанвливаем sfml и imgui-sfml ( vcpkg install sfml imgui-sfml imgui )
5) В папке репозитория создаем папку build и переходим в нее ( mkdir build && cd build )
6) Запускаем генерирования проекта ( cmake ../ -DCMAKE_TOOLCHAIN_FILE=C:/{путь до vcpkg}/scripts/buildsystems/vcpkg.cmake ) 
7) Собираем проект ( cmake --build . --config release --parallel )
8) Запускаем исполнемый файл edvard_cw