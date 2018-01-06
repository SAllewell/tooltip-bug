cmake_minimum_required(VERSION 2.8.11)
project(tooltip)

# Find includes in corresponding build directories
include_directories (BEFORE ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/src)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets REQUIRED)

set(tooltip_SRC
  src/main.cpp
  src/tooltip.cpp
  src/tooltiptest.cpp
  src/tooltipdialog.cpp
)

# Create code from a list of Qt designer ui files.
#set(CMAKE_AUTOUIC ON) # use this if you have CMake 3.x instead of the following
qt5_wrap_ui(tooltip_SRC
    src/tooltip.ui
    src/tooltipdlg.ui
)

# Tell CMake to create the helloworld executable
add_executable(tooltip ${tooltip_SRC})

# Use the Widgets module from Qt 5.
target_link_libraries(tooltip
    Qt5::Widgets
)

# Install the executable
install(TARGETS tooltip DESTINATION bin)
