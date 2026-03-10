include(FetchContent)

FetchContent_Declare(
    catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.11.0
)

FetchContent_MakeAvailable(catch2)

function(add_interpreter_test TEST_NAME TEST_FILE)
    add_executable(${TEST_NAME} ${TEST_FILE})
    target_link_libraries(${TEST_NAME} PRIVATE interpreter Catch2::Catch2WithMain)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
endfunction()

add_interpreter_test(test_integer test_integer.cpp)
add_interpreter_test(test_lexer test_lexer.cpp)
add_interpreter_test(test_parser test_parser.cpp)
add_interpreter_test(test_interpreter test_interpreter.cpp)
