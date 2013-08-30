project(books_grantlee)

cmake_minimum_required(VERSION 2.6)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Script REQUIRED)
find_package(Grantlee REQUIRED)

add_definitions(${QT_DEFINITIONS})
add_definitions(-DQT_GUI_LIB)
add_definitions(-DQT_WIDGETS_LIB)
ADD_DEFINITIONS(-DQT_NO_KEYWORDS)

include_directories(
  ${Grantlee_INCLUDE_DIRS}
  ${PROJECT_BINARY_DIR}
)

configure_file(grantlee_paths.h.cmake ${PROJECT_BINARY_DIR}/grantlee_paths.h)

set(books_example_SRCS
  main.cpp
  bookwindow.cpp
  bookwrapper.cpp
  bookdelegate.cpp
)

set(books_example_RCSS
  books.qrc
)

set(books_example_UI
  bookwindow.ui
)

set(CMAKE_AUTOMOC TRUE)

QT5_WRAP_UI(books_example_UI_SRCS ${books_example_UI})

qt5_add_resources(
  books_example_RCS_SRCS
  ${books_example_RCSS}
)

add_executable(books
  ${books_example_SRCS}
  ${books_example_RCS_SRCS}
  ${books_example_UI_SRCS}
)

target_link_libraries(
  books
  ${Grantlee_CORE_LIBRARIES}
)

qt5_use_modules(books Core Widgets Script Gui Sql)



