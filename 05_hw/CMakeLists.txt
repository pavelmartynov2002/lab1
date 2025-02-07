cmake_minimum_required(VERSION 3.10)
project(stack LANGUAGES C)

# ���������� �� ������
add_library(stack stack.c stack.h)

# �������� ����������� ���� (������������)
add_executable(main main.c)
target_link_libraries(main stack)

# ��������� ������
enable_testing()

# ����������� ���� � �������
add_executable(tests test.c)
target_link_libraries(tests stack)

# ������� ����� (���� ����� ��� ���� �������)
add_test(NAME StackMethodsTest COMMAND tests)

# ���������
add_executable(benchmarks benchmark_stack.c)
target_link_libraries(benchmarks stack)

# ����� ��� �������� ����
option(ENABLE_COVERAGE "Enable coverage reporting" ON)
if(ENABLE_COVERAGE AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(stack PUBLIC --coverage)
    target_link_libraries(stack PUBLIC --coverage)
    target_compile_options(tests PUBLIC --coverage)
    target_link_libraries(tests PUBLIC --coverage)
    target_compile_options(benchmarks PUBLIC --coverage)
    target_link_libraries(benchmarks PUBLIC --coverage)
endif()

# �����������
option(ENABLE_SANITIZERS "Enable sanitizers" ON)
if(ENABLE_SANITIZERS AND CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(stack PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(stack PUBLIC -fsanitize=address -fsanitize=undefined)
    target_compile_options(tests PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(tests PUBLIC -fsanitize=address -fsanitize=undefined)
    target_compile_options(benchmarks PUBLIC -fsanitize=address -fsanitize=undefined)
    target_link_libraries(benchmarks PUBLIC -fsanitize=address -fsanitize=undefined)
endif()
