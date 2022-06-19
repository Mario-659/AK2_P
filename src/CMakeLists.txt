set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        Adder.cpp
        ../include/Utils.h
        ../include/Adder.h
        ../include/Multiplier.h
        Multiplier.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
