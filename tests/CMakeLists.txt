# include(FetchContent)
# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
# )

# FetchContent_MakeAvailable(googletest)

# enable_testing()

# # Insert files below
# add_executable(sqlite_clone_test)

# target_link_libraries(
#     sqlite_clone_test
#     sqlite_clone_lib
#     GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(sqlite_clone_test)