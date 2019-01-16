
set(all_core_src
        source/Library.cpp include/Library.h
        interface/ILibrary.h include/Event.h interface/IEvent.h include/Raise.h include/AlignedArray.h include/AlignedCArray.h)

add_library(all_core ${all_core_src})

target_include_directories(all_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/interface)

target_include_directories(all_core
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include)

