
# file(GLOB HEADER_LIST CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")

# # Insert files below
# add_library(sqlite_clone_lib ${HEADER_LIST})

# # We need this directory, and users of our library will need it too
# target_include_directories(sqlite_clone_lib PUBLIC ../include)

# This depends on (header only) boost
# target_link_libraries(modern_library PRIVATE Boost::boost)

# All users of this library will need at least C++11
# target_compile_features(modern_library PUBLIC cxx_std_11)

# IDEs should put the headers in a nice place
# source_group(
#   TREE "${PROJECT_SOURCE_DIR}/include"
#   PREFIX "Header Files"
#   FILES ${HEADER_LIST})
