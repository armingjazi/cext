
set(ALLCore_SRCS
        source/Library.cpp include/Library.h
        interface/ILibrary.h include/Event.h)

add_library(ALLCore ${ALLCore_SRCS})

target_include_directories(ALLCore
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(ALLCore
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/interface)