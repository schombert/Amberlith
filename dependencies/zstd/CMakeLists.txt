message(STATUS "Fetching zstd...")
FetchContent_Declare(
    zstd
    GIT_REPOSITORY https://github.com/facebook/zstd
    GIT_TAG ae9f20ca2716f2605822ca375995b7d876389b64
    GIT_SHALLOW 1
    GIT_PROGRESS TRUE
)
FetchContent_MakeAvailable(zstd)

add_library(dependency_zstd INTERFACE)
target_include_directories(dependency_zstd INTERFACE ${zstd_SOURCE_DIR}/lib/)
target_link_libraries(dependency_zstd INTERFACE libzstd_static)
