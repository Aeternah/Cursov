# Указываем минимальную версию CMake
cmake_minimum_required(VERSION 3.10)

# Указываем имя проекта и его версию
project(COURCE_PROJECT VERSION 1.0)

# Устанавливаем локаль для Windows


# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20) # Graaf может использовать современные возможности C++20
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем исполняемый файл
add_executable(MyExecutable main.cpp graph.cpp)

# Указываем директорию для заголовочных файлов библиотеки Graaf
include_directories("Q:/Course_project/graaf/include/graaflib")
include_directories("Q:/Course_project/graaf/include")  


# Указываем директорию для заголовочных файлов библиотеки fmt
include_directories("Q:/Course_project/fmt/include")

# Подключение библиотеки fmt, если она не является header-only
add_subdirectory("Q:/Course_project/fmt" ${CMAKE_CURRENT_BINARY_DIR}/fmt)

# Линковка с библиотеками Graaf и fmt
target_link_libraries(MyExecutable PRIVATE fmt::fmt) # fmt подключается через CMake
