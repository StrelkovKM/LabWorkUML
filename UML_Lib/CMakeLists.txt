file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h

add_library(${uml_lib} STATIC ${srcs} ${hdrs})

target_link_libraries(${uml_lib} ${error_lib})
target_link_libraries(${uml_lib} ${string_lib})



