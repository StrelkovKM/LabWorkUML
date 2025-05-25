cmake_minimum_required(VERSION 3.5)

set(PROJECT_NAME LabWorkUML)
project(${PROJECT_NAME})

set(application UML_Application)

set(uml_lib UML_Library)
set(error_lib Error_Library)
set(string_lib String_Library)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/UML_Lib) 
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Error_Lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/String_Lib)

add_subdirectory(UML_App)
add_subdirectory(UML_Lib)
add_subdirectory(UML_Test)

add_subdirectory(Error_Lib)
add_subdirectory(String_Lib)

add_subdirectory(gtest)



