message(STATUS "FetchContent: abseil")

set(ABSL_PROPAGATE_CXX_STD ON)

# Abseil LTS branch, June 2022, Patch 1
FetchContent_Declare(
    absl
    GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
    GIT_TAG 8c0b94e793a66495e0b1f34a5eb26bd7dc672db0
)
FetchContent_MakeAvailable(absl)
