message(STATUS "Fetching miniaudio...")
FetchContent_Declare(
    miniaudio
    GIT_REPOSITORY https://github.com/mackron/miniaudio
    GIT_TAG f40cf03f80cdb7e741d43e53b7e706e8c1394bcf
    GIT_SHALLOW 1
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(miniaudio)
add_library(dependency_miniaudio INTERFACE)
target_include_directories(dependency_miniaudio SYSTEM INTERFACE "${miniaudio_SOURCE_DIR}")