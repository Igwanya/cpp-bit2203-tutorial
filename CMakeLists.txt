cmake_minimum_required(VERSION 3.22.1)

project(tutorial
  VERSION 0.1
  DESCRIPTION "Learning cpp language"
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Qml LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Qml LinguistTools REQUIRED)

find_package(fmt)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# BOOST dependancy
set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
#set(Boost_USE_DEBUG_LIBS        ON)  # ignore debug libs and
#set(Boost_USE_RELEASE_LIBS       ON)  # only find release libs
set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.77.0 REQUIRED COMPONENTS
  date_time filesystem iostreams system thread regex log program_options unit_test_framework)
if(Boost_FOUND)
  add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
  include_directories(${Boost_INCLUDE_DIRS})
endif()

configure_file(${PROJECT_SOURCE_DIR}/include/config.h.in ${PROJECT_SOURCE_DIR}/include/tut/config.h)

set(PROJECT_TARGET_NAME tutorial_bin)

# UI_UX library configuration
set(UI_UX_TARGET ui_ux)

# ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/ui_en_US.ts
set(TS_FILES )
set(UI_UX_FILES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/qml.qrc
  ${TS_FILES})

set(PROJECT_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/tut/config.h)

set(PROJECT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp

  )

# Tututorial library
set(TUT_TARGET_LIB tutorial)

set(TUT_TARGET_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch1.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch2.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch3.hpp")
set(TUT_TARGET_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch1.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch2.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch3.cpp")

# Dependancies
option(BUILD_DOC "Build documentation" ON)
if (BUILD_DOC)
  find_package(Doxygen
    REQUIRED dot
    OPTIONAL_COMPONENTS mscgen dia)

  if (DOXYGEN_FOUND)
    set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/docs/Doxyfile.in)
    set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
    configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)
    message("Doxygen build started")
    add_custom_target( doc_doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
      COMMENT "Generating API documentation with Doxygen"
      VERBATIM )
  endif(DOXYGEN_FOUND)
endif(BUILD_DOC)

# library configuration
add_library(${TUT_TARGET_LIB} ${TUT_TARGET_HEADERS} ${TUT_TARGET_SOURCES})

target_include_directories(${TUT_TARGET_LIB}
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${TUT_TARGET_LIB}
  PUBLIC Boost::log
  fmt::fmt)

# Main project configuration
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(${PROJECT_TARGET_NAME} MANUAL_FINALIZATION ${PROJECT_HEADERS} ${PROJECT_SOURCES})
  qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src/ui ${TS_FILES})
else()

  add_executable(${PROJECT_TARGET_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${UI_UX_FILES} )

  qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src/ui ${TS_FILES})
endif()

if(QT_VERSION_MAJOR EQUAL 6)
  qt_import_qml_plugins(${PROJECT_TARGET_NAME})
  qt_finalize_executable(${PROJECT_TARGET_NAME})
endif()

target_include_directories(${PROJECT_TARGET_NAME}
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
  "${PROJECT_SOURCE_DIR}/src/ui"
  PUBLIC ${Boost_INCLUDE_DIRS})

target_link_libraries(${PROJECT_TARGET_NAME}
  PUBLIC ${Boost_LIBRARIES}
  PUBLIC ${GSTREAMER_LIBRARIES}
  PUBLIC ${TUT_TARGET_LIB}
  fmt::fmt
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Qml)

target_compile_definitions(${PROJECT_TARGET_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

enable_testing()

set(PROJECT_TEST_TARGET_NAME tests_bin)

set(PROJECT_TEST_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_main.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch2.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch3.cpp"
  )

add_executable(${PROJECT_TEST_TARGET_NAME} ${PROJECT_TEST_SOURCES})

target_include_directories(${PROJECT_TEST_TARGET_NAME}
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
  PRIVATE ${BOOST_INCLUDE_DIRS})

# indicates the shared library variant
target_compile_definitions(${PROJECT_TEST_TARGET_NAME}
  PRIVATE "BOOST_TEST_DYN_LINK=1" )

target_link_libraries(${PROJECT_TEST_TARGET_NAME}
  ${Boost_FILESYSTEM_LIBRARY}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
  ${TUT_TARGET_LIB}
  )
