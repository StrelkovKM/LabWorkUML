set(target UML_Test)

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../gtest")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${error_lib})
target_link_libraries(${target} gtest ${string_lib})
target_link_libraries(${target} gtest ${uml_lib})


