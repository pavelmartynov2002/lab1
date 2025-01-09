cmake_minimum_required(VERSION 3.10)
project(stack LANGUAGES C)

# Библиотека со стеком
add_library(stack stack.c stack.h)

# Основной исполняемый файл (демонстрация)
add_executable(main main.c)
target_link_libraries(main stack)

# Включение тестов
enable_testing()

# Исполняемый файл с тестами
add_executable(tests test.c)
target_link_libraries(tests stack)

# Создаем тесты (один общий для всех методов)
add_test(NAME StackMethodsTest COMMAND tests)

# Бенчмарки
add_executable(benchmarks benchmark_stack.c)
target_link_libraries(benchmarks stack)

# Опция для покрытия кода
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(stack PUBLIC --coverage)
    target_link_libraries(stack PUBLIC --coverage)
    target_compile_options(tests PUBLIC --coverage)
    target_link_libraries(tests PUBLIC --coverage)
    target_compile_options(benchmarks PUBLIC --coverage)
    target_link_libraries(benchmarks PUBLIC --coverage)
endif()

# Санитайзеры
option(ENABLE_SANITIZERS "Enable sanitizers" ON)
if(ENABLE_SANITIZERS AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(stack PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(stack PUBLIC -fsanitize=address -fsanitize=undefined)
    target_compile_options(tests PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(tests PUBLIC -fsanitize=address -fsanitize=undefined)
    target_compile_options(benchmarks PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(benchmarks PUBLIC -fsanitize=address -fsanitize=undefined)
endif()
