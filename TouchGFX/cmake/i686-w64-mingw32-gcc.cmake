set(CMAKE_SYSTEM_NAME               Windows)

# Some default GCC settings
set(CMAKE_C_COMPILER                i686-w64-mingw32-gcc)
set(CMAKE_CXX_COMPILER              i686-w64-mingw32-g++)
set(CMAKE_C_FLAGS                   "-Wall -Wextra -Wpedantic -Wno-unused-parameter")
set(CMAKE_CXX_FLAGS                 "${CMAKE_C_FLAGS}")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
