add_library(liblist list_double.cpp)

target_link_libraries(liblist PRIVATE liblogs)

target_include_directories(liblist PUBLIC
                        ${CMAKE_CURRENT_LIST_DIR})