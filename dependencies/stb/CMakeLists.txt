message(STATUS "Fetching stb...")
FetchContent_Declare(
    stb
    GIT_REPOSITORY https://github.com/nothings/stb
    GIT_TAG f1c79c02822848a9bed4315b12c8c8f3761e1296
    GIT_SHALLOW 1
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(stb)
add_library(dependency_stb INTERFACE)
target_include_directories(dependency_stb SYSTEM INTERFACE "${stb_SOURCE_DIR}")