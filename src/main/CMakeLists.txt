#executable
add_executable(rules main.c rules.c)

file(GLOB EXAMPLE "example.*.txt")

file(COPY ${EXAMPLE}
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})



