set(ATCODER_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(ATCODER_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(ATCODER_MSVC_WARNING_FLAGS /W4)

set(ATCODER_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(ATCODER_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(ATCODER_MSVC_DEFINITIONS )

set(ATCODER_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(ATCODER_CLANG_DEFINITIONS ${ATCODER_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_GCC_DEFINITIONS ${ATCODER_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_MSVC_DEFINITIONS ${ATCODER_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(ATCODER_LINK_LIBRARIES ${ATCODER_LINK_LIBRARIES} "glog::glog")
endif()


set(ATCODER_COMPILE_FEATURES "cxx_std_17")

add_executable(atcoder-templete atcoder-templete.cc)
target_link_libraries(atcoder-templete PRIVATE ${ATCODER_LINK_LIBRARIES})
target_compile_options(atcoder-templete PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:${ATCODER_CLANG_WARNING_FLAGS}>
  $<$<CXX_COMPILER_ID:GCC>:  ${ATCODER_GCC_WARNING_FLAGS}>
  $<$<CXX_COMPILER_ID:MSVC>: ${ATCODER_MSVC_WARNING_FLAGS}>)
target_compile_features(atcoder-templete PRIVATE ${ATCODER_COMPILE_FEATURES})
target_compile_definitions(atcoder-templete PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:${ATCODER_CLANG_DEFINITIONS}>
  $<$<CXX_COMPILER_ID:GCC>:  ${ATCODER_GCC_DEFINITIONS}>
  $<$<CXX_COMPILER_ID:MSVC>: ${ATCODER_MSVC_DEFINITIONS}>)
set_target_properties(atcoder-templete PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY ${ATCODER_BIN_DIR})

add_subdirectory(abc065)
add_subdirectory(abc066)
add_subdirectory(abc097)
add_subdirectory(abc098)
add_subdirectory(abc103)
add_subdirectory(abc104)
add_subdirectory(abc105)
add_subdirectory(abc106)
add_subdirectory(abc127)
add_subdirectory(abc131)
add_subdirectory(abc136)
add_subdirectory(abc147)
add_subdirectory(abc150)
add_subdirectory(abc158)
add_subdirectory(abc162)
add_subdirectory(abc163)
add_subdirectory(abc164)
add_subdirectory(abc165)

add_subdirectory(agc029)
add_subdirectory(agc040)
