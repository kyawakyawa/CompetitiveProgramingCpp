set(CODEFORCES_CLANG_WARNING_FLAGS
  -Wall -Wextra -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-padded -Wno-unused-macros -Wno-missing-prototypes -Wno-missing-variable-declarations -Wno-global-constructors -Wno-exit-time-destructors -Wno-sign-conversion -Wno-gnu-zero-variadic-macro-arguments)
set(CODEFORCES_GCC_WARNING_FLAGS
  -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)
set(CODEFORCES_MSVC_WARNING_FLAGS /W4)

set(CODEFORCES_CLANG_DEFINITIONS _LIBCPP_DEBUG _GLIBCXX_DEBUG)
set(CODEFORCES_GCC_DEFINITIONS _GLIBCXX_DEBUG)
set(CODEFORCES_MSVC_DEFINITIONS )

set(CODEFORCES_BIN_DIR ${PROJECT_BINARY_DIR})

if (USE_STACK_TRACE_LOGGER)
  set(CODEFORCES_CLANG_DEFINITIONS ${CODEFORCES_CLANG_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(CODEFORCES_GCC_DEFINITIONS ${CODEFORCES_GCC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(CODEFORCES_MSVC_DEFINITIONS ${CODEFORCES_MSVC_DEFINITIONS} USE_STACK_TRACE_LOGGER)
  set(CODEFORCES_LINK_LIBRARIES ${CODEFORCES_LINK_LIBRARIES} "glog::glog")
endif()


set(CODEFORCES_COMPILE_FEATURES "cxx_std_17")

add_subdirectory(cf-round646)
