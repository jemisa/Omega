TOOLCHAIN = apple
EXE = bin

APPLE_PLATFORM = macos
APPLE_PLATFORM_MIN_VERSION = 10.10

ARCHS = x86_64

EPSILON_SIMULATOR_HAS_LIBPNG = 1

ifdef ARCH
BUILD_DIR := $(BUILD_DIR)/$(ARCH)
endif
