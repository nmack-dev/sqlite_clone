add_executable(sqlite_clone sqlite_clone.cpp)
# target_compile_features(sqlite_clone PRIVATE cxx_std_17)

# Add sqlite_clone_lib
target_link_libraries(sqlite_clone)
