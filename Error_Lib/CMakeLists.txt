file(GLOB hdrs "*.h*")

file(GLOB srcs "*.cpp")

add_library(${error_lib} STATIC ${srcs} ${hdrs})

target_link_libraries(${error_lib} ${string_lib})