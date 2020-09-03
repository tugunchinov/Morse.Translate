add_executable(Tests main_test.cpp code.cpp ../src/code.cpp ../src/config.cpp)

target_include_directories(Tests PUBLIC ../include)
target_link_libraries(Tests gtest pthread Qt5::Quick)
