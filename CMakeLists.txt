cmake_minimum_required(VERSION 3.22.1)

set (CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-Wall -Wextra -pedantic -Werror")
#set(CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall")
# add_compile_options(-Wall -Wextra -pedantic -Werror)

project(tutorial
  VERSION 0.1.0
  DESCRIPTION ""
  LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")


set(CMAKE_DEBUG_POSTFIX "-${CMAKE_BUILD_TYPE}_${CMAKE_HOST_SYSTEM_PROCESSOR}")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
set(QT_QMAKE_EXECUTABLE /opt/Qt/5.15.2/gcc_64/bin/qmake)
set(QT_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
set(Qt5_DIR "/opt/Qt/5.12.11/gcc_64/lib/cmake/Qt5")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH}
  ${QT_QMAKE_EXECUTABLE}
  ${QT_DIR}
  ${Qt5_DIR}
  "/opt/Qt/5.15.2/gcc_64")

set(QT_DIR "" CACHE STRING "${QT_DIR}" " ")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Qml LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Qml LinguistTools REQUIRED)

find_package(fmt)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# BOOST dependancy
set(Boost_USE_STATIC_LIBS        OFF)  # only find static libs
set(Boost_USE_DEBUG_LIBS        ON)  #  debug libs
set(Boost_USE_RELEASE_LIBS       ON)  # ignore release libs
set(Boost_USE_MULTITHREADED      ON)
#set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.77.0 REQUIRED COMPONENTS
  date_time filesystem iostreams system thread regex log program_options unit_test_framework)
if(Boost_FOUND)
  add_definitions(${Boost_LIB_DIAGNOSTIC_DEFINITIONS})
  include_directories(${Boost_INCLUDE_DIRS})
endif()

message(STATUS "[ = ] ${BOOST_ROOT}")

configure_file(${PROJECT_SOURCE_DIR}/include/config.h.in ${PROJECT_SOURCE_DIR}/include/tut/config.h)

set(PROJECT_TARGET_NAME tutorial_bin)

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
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch3.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch4.hpp")
set(TUT_TARGET_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch1.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch2.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch3.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch4.cpp")

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
    add_custom_target( doc_doxygen ALL
      COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
      WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
      COMMENT "- Generating API documentation with Doxygen"
      VERBATIM )
  endif(DOXYGEN_FOUND)
endif(BUILD_DOC)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core Quick Qml LinguistTools REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core Quick Qml LinguistTools REQUIRED)

find_package(fmt)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

configure_file(${PROJECT_SOURCE_DIR}/include/config.h.in ${PROJECT_SOURCE_DIR}/include/tut/config.h)

set(PROJECT_TARGET_NAME tutorial_bin)

# ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/ui_en_US.ts
set(TS_FILES )

set(PROJECT_HEADERS
  ${CMAKE_CURRENT_SOURCE_DIR}/include/main.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/include/tut/config.h)

set(PROJECT_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/qml.qrc
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/res.qrc
  ${TS_FILES}
  )

# Tututorial library
set(TUT_TARGET_LIB tutorial)
set(TUT_TARGET_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch1.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch2.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch3.hpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/include/tut/ch4.hpp")
set(TUT_TARGET_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch1.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch2.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch3.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/tut_lib/ch4.cpp")

# library configuration
add_library(${TUT_TARGET_LIB} ${TUT_TARGET_HEADERS} ${TUT_TARGET_SOURCES})
set_property(TARGET ${TUT_TARGET_LIB} PROPERTY VERSION "1.0.0")
set_property(TARGET ${TUT_TARGET_LIB} PROPERTY SOVERSION "1")

target_include_directories(${TUT_TARGET_LIB}
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${TUT_TARGET_LIB}
  PUBLIC Boost::log
  fmt::fmt)

#Course work in bit2203 practice quiz/exercises

set(BIT2203_TARGET bit2203)
set(BIT2203_HEADERS
  "${CMAKE_CURRENT_SOURCE_DIR}/include/bit2203/bit2203.hpp")
set(BIT2203_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/src/bit2203_lib/bit2203.cpp")

add_library(${BIT2203_TARGET} ${BIT2203_HEADERS} ${BIT2203_SOURCES})

target_include_directories(${BIT2203_TARGET}
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(${BIT2203_TARGET}
  PUBLIC Boost::log
  fmt::fmt)

# UI library configuration
# UI_UX library configuration

# ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/ui_en_US.ts
set(TS_FILES )

set(UI_TARGET_NAME "ui_${CMAKE_DEBUG_POSTFIX}")

set(UI_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ui/qml.qrc
  ${TS_FILES})

# Main project configuration
if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
  qt_add_executable(${PROJECT_TARGET_NAME} MANUAL_FINALIZATION ${PROJECT_HEADERS} ${PROJECT_SOURCES} ${UI_SOURCES})
  qt_create_translation(QM_FILES ${CMAKE_SOURCE_DIR}/src/ui ${TS_FILES})
else()

  add_executable(${PROJECT_TARGET_NAME} ${PROJECT_HEADERS} ${PROJECT_SOURCES})

  set_target_properties(${PROJECT_TARGET_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

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

  ${TUT_TARGET_LIB}
  ${BIT2203_TARGET}

  PUBLIC ${TUT_TARGET_LIB}

  fmt::fmt
  PRIVATE Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Quick Qt${QT_VERSION_MAJOR}::Qml)

target_compile_definitions(${PROJECT_TARGET_NAME}
  PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>)

option(BUILD_TESTING "Builds only the test executable." ON)
option(CODE_COVERAGE "Collect coverage from test library" ON)

set(PROJECT_TEST_TARGET_NAME tests_bin)

set(PROJECT_TEST_SOURCES
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_main.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch2.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch3.cpp"
  )

if(BUILD_TESTING)
  include(CTest)

  enable_testing()

  set(PROJECT_TEST_TARGET_NAME "Boost_Tests_run_v${PROJECT_VERSION}")

  set(PROJECT_TEST_SOURCES
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_main.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch2.cpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch3.cpp"
    )

  add_executable(${PROJECT_TEST_TARGET_NAME}
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_main.cpp")

  target_include_directories(${PROJECT_TEST_TARGET_NAME}
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE ${BOOST_INCLUDE_DIRS})

  target_link_libraries(${PROJECT_TEST_TARGET_NAME}
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${TUT_TARGET_LIB}
    ${BIT2203_TARGET})

  add_test(NAME ${PROJECT_TEST_TARGET_NAME} COMMAND ${PROJECT_TEST_TARGET_NAME})

  add_executable(ch2_test
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch2.cpp")

  target_include_directories(ch2_test
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE ${BOOST_INCLUDE_DIRS})

  target_link_libraries(ch2_test
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${TUT_TARGET_LIB}
    ${BIT2203_TARGET})

  add_test(NAME ch2_test COMMAND ch2_test)

  add_executable(ch3_test
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch3.cpp")

  target_include_directories(ch2_test
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE ${BOOST_INCLUDE_DIRS})

  target_link_libraries(ch3_test
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${TUT_TARGET_LIB}
    ${BIT2203_TARGET})

  add_test(NAME ch3_test COMMAND ch3_test)

  add_executable(ch4_test
     "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch4.cpp")
  target_compile_definitions(ch4_test PRIVATE "BOOST_TEST_DYN_LINK=1")

  target_include_directories(ch4_test
    PUBLIC "${PROJECT_BINARY_DIR}"
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include"
    PRIVATE ${BOOST_INCLUDE_DIRS})

  target_link_libraries(ch4_test
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${TUT_TARGET_LIB}
    ${BIT2203_TARGET})

  add_test(NAME ch4_test COMMAND ch4_test)

  add_executable(ch5_test
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/tests_ch5.cpp")
  target_compile_definitions(ch5_test PRIVATE "BOOST_TEST_DYN_LINK=1")

  target_include_directories(ch5_test
    PUBLIC "${PROJECT_BINARY_DIR}"
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    ${BOOST_INCLUDE_DIRS})

  target_link_libraries(ch5_test
    ${Boost_FILESYSTEM_LIBRARY}
    ${Boost_SYSTEM_LIBRARY}
    ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ${TUT_TARGET_LIB})

  add_test(NAME ch5_test COMMAND ch5_test)

  if(CODE_COVERAGE)
    include(CodeCoverage)

    append_coverage_compiler_flags()
    setup_target_for_coverage_lcov(
      NAME coverage
      EXECUTABLE ctest -j 4
#      BASE_DIRECTORY "${PROJECT_SOURCE_DIR}/src"
      # EXCLUDE "${PROJECT_SOURCE_DIR}/src/dir1/*" "/path/to/my/src/dir2/*"
      DEPENDENCIES
      ${PROJECT_TEST_TARGET_NAME}
      ch2_test
      ch3_test
      ch4_test
      ch5_test
      )
# indicates the shared library variant
target_compile_definitions(${PROJECT_TEST_TARGET_NAME}
  PRIVATE "BOOST_TEST_DYN_LINK=1" )

  endif(CODE_COVERAGE)
endif(BUILD_TESTING)
