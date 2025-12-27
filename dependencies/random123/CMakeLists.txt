message(STATUS "Fetching random123...")
FetchContent_Declare(
    random123
    GIT_REPOSITORY https://github.com/lemire/random123
    GIT_TAG ff4443af61194bb57a042cd4945f2c73bdf1d0dd
    GIT_SHALLOW 1
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(random123)
add_library(dependency_random123 INTERFACE)
target_include_directories(dependency_random123 SYSTEM INTERFACE "${random123_SOURCE_DIR}/include")
