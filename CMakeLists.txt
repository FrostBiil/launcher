cmake_minimum_required(VERSION 3.30)
project(gtk_hello C)
set(CMAKE_C_STANDARD 11)

# --- Force the correct pkg-config (MSYS2 UCRT64) ---
# Adjust these two lines only if your MSYS2 root is not C:/msys64
set(PKG_CONFIG_EXECUTABLE "C:/msys64/ucrt64/bin/pkgconf.exe" CACHE FILEPATH "pkgconf.exe")
set(ENV{PKG_CONFIG_PATH} "C:/msys64/ucrt64/lib/pkgconfig;C:/msys64/ucrt64/share/pkgconfig")

# Optional: make CMake log what it uses
message(STATUS "Using pkg-config: ${PKG_CONFIG_EXECUTABLE}")
message(STATUS "PKG_CONFIG_PATH=$ENV{PKG_CONFIG_PATH}")

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED IMPORTED_TARGET gtk4)

add_executable(hello4 main.c)
# Primary (preferred): use the imported target produced by pkg_check_modules
target_link_libraries(hello4 PRIVATE PkgConfig::GTK4)

# Belt-and-suspenders: also apply raw cflags/includes/libs in case the IDE ignores the imported target
target_include_directories(hello4 PRIVATE ${GTK4_INCLUDE_DIRS})
target_compile_options(hello4 PRIVATE ${GTK4_CFLAGS_OTHER})
target_link_options(hello4 PRIVATE ${GTK4_LDFLAGS_OTHER})
