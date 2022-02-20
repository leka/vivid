cmake_minimum_required( VERSION 3.14 FATAL_ERROR )
include( FetchContent )

Set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare( json
    GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
    GIT_TAG v3.9.1
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)

FetchContent_Declare( glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 0.9.9.8
	GIT_PROGRESS TRUE
	GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable( json glm )
