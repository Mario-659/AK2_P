set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES
        main.cpp
        Adder.cpp
        ../include/Utils.hpp
        ../include/Adder.hpp
        ../include/SimpleMultiplier.hpp
        SimpleMultiplier.cpp
        )

add_executable(${CMAKE_PROJECT_NAME}_run ${SOURCES})

add_library(${CMAKE_PROJECT_NAME}_lib STATIC ${SOURCES})
