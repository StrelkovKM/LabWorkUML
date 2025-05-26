file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
file(GLOB srcs "*.cpp")#Добавляем в переменную srcs все файлы с расширением .h
add_executable(${application} ${srcs} ${hdrs})

target_link_libraries(${application} ${uml_lib})
target_link_libraries(${application} ${string_lib})
target_link_libraries(${application} ${error_lib})



