cmake_minimum_required(VERSION 3.22)

# Setup project if this is top-level
project(TouchGFX)
enable_language(C CXX ASM)

# Root TouchGFX folder - depends on where CMakeLists.txt is located
set(root_tgfx_dir ${CMAKE_CURRENT_LIST_DIR})

# Setup all necessary include directories
# These are used by compiler to search for C or C++ headers
set(touchgfx_include_DIRS

    # Application includes
    ${root_tgfx_dir}/gui/include
    ${root_tgfx_dir}/generated/gui_generated/include
    ${root_tgfx_dir}/generated/images/include
    ${root_tgfx_dir}/generated/bitmaps/include
    ${root_tgfx_dir}/generated/fonts/include
    ${root_tgfx_dir}/generated/texts/include
    ${root_tgfx_dir}/generated/videos/include

    # When running simulator but project started as STM32 project
    ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include
    ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include/common
    ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/common/include

    # When running simulator and project started as simulator project
    ${root_tgfx_dir}/touchgfx/framework/include
    ${root_tgfx_dir}/touchgfx/framework/include/common
    ${root_tgfx_dir}/touchgfx/framework/common/include
)

# Search all source files in to be part of the build
# Use the GLOB to scan everything in the gui and generated folders
# These are essential for generic TouchGFX build
file(GLOB_RECURSE graphics_core_generated_SRCS
    ${root_tgfx_dir}/generated/*.cpp
    ${root_tgfx_dir}/gui/*.cpp
    ${root_tgfx_dir}/gui/*.c
)

# Assuming user would like to build simulator when
# this CMakeLists is used as the top project file
#
# Add simulation source files, update simulation include paths,
# find DLL files and prepare linker
if (PROJECT_IS_TOP_LEVEL)
    # Add platform based source files and include them in list of files
    # This is used for Win32 build
    file(GLOB_RECURSE glob_tmp
        # Simulator file from the project itself
        ${root_tgfx_dir}/simulator/*.cpp

        # When running simulator but project started as STM32 project
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/source/platform/*.cpp

        # When running simulator and project started as simulator project
        ${root_tgfx_dir}/touchgfx/framework/source/platform/*.cpp
    )
    set(graphics_core_generated_SRCS ${graphics_core_generated_SRCS} ${glob_tmp})

    # Prepare include paths for the simulator
    # specific build - these are not necessary for target build
    set(touchgfx_include_DIRS ${touchgfx_include_DIRS}
        ${root_tgfx_dir}/simulator
        ${root_tgfx_dir}/generated/simulator/include

        # When running simulator but project started as STM32 project
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/mvp/include
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor/win32
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include/platform/hal/simulator/sdl2/3rdparty/sdl/include/win32
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/framework/include
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/3rdparty/libjpeg/include

        # When running simulator and project started as simulator project
        ${root_tgfx_dir}/touchgfx/framework/mvp/include
        ${root_tgfx_dir}/touchgfx/framework/include/platform/hal/simulator/sdl2
        ${root_tgfx_dir}/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor
        ${root_tgfx_dir}/touchgfx/framework/include/platform/hal/simulator/sdl2/vendor/win32
        ${root_tgfx_dir}/touchgfx/framework/include/platform/hal/simulator/sdl2/3rdparty/sdl/include/win32
        ${root_tgfx_dir}/touchgfx/framework/include
        ${root_tgfx_dir}/touchgfx/3rdparty/libjpeg/include
    )

    # Prepare linker directories - for the simulator
    set(link_dirs
        # When running simulator but project started as STM32 project
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/lib/win/mingw32
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/lib/sdl2/win32
        ${root_tgfx_dir}/../Middlewares/ST/touchgfx/3rdparty/libjpeg/lib/win32

        # When running simulator and project started as simulator project
        ${root_tgfx_dir}/touchgfx/lib/win/mingw32
        ${root_tgfx_dir}/touchgfx/lib/sdl2/win32
        ${root_tgfx_dir}/touchgfx/3rdparty/libjpeg/lib/win32
    )
    link_directories(${CMAKE_PROJECT_NAME} ${link_dirs})

    # Build executable with sources, include paths and compile definitions
    add_executable(${CMAKE_PROJECT_NAME})
    target_sources(${CMAKE_PROJECT_NAME} PRIVATE ${graphics_core_generated_SRCS})
    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE ${touchgfx_include_DIRS})
    target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE WIN32 NDEBUG _CONSOLE SIMULATOR)

    # Add linked libraries
    target_link_libraries(${CMAKE_PROJECT_NAME}
        :libtouchgfx.a
        :libSDL2.a
        :libSDL2_image.a
        :libjpeg-8.a
    )

    # Copy DLL files to the project path
    file(GLOB_RECURSE dll_files

        # When running simulator but project started as STM32 project
        ${root_tgfx_dir}/*.dll

        # When running simulator and project started as simulator project
        ${root_tgfx_dir}/../Middlewares/ST/*.dll
    )

    # Copy all DLL files to build output folder
    # or the run will fail to find DLL files
    foreach(dll_file ${dll_files})
        add_custom_command(TARGET ${CMAKE_PROJECT_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${dll_file} $<TARGET_FILE_DIR:${CMAKE_PROJECT_NAME}>)
    endforeach()
else()
    #
    # This is when directory is added as subproject.
    #
    # Assuming this is when user wants to build for the target,
    # we add remaining target-specific files for TGFX and remove
    # anything related to simulator
    #
    # Finally, library is created

    # Search for target source files
    file(GLOB_RECURSE glob_tmp
        ${root_tgfx_dir}/App/*.c
        ${root_tgfx_dir}/Target/*.cpp
        ${root_tgfx_dir}/Target/*.c
    )
    set(graphics_core_generated_SRCS ${graphics_core_generated_SRCS} ${glob_tmp})

    # Add target include paths
    set(touchgfx_include_DIRS ${touchgfx_include_DIRS}
    ${root_tgfx_dir}/App
        ${root_tgfx_dir}/Target
        ${root_tgfx_dir}/Target/generated
    )

    # Exclude anything mentioning simulator
    list(FILTER graphics_core_generated_SRCS EXCLUDE REGEX ".*/simulator/.*")
    list(FILTER touchgfx_include_DIRS EXCLUDE REGEX ".*/simulator/.*")

    # Prepare output
    add_library(touchgfx INTERFACE)
    target_sources(touchgfx PUBLIC ${graphics_core_generated_SRCS})
    target_include_directories(touchgfx INTERFACE ${touchgfx_include_DIRS})
endif()