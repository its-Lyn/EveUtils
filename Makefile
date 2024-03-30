.PHONY: build

CC = clang++
BUILD_DIR = build

CLASS_SOURCES = src/greeter/*
CLASS_INCLUDE = -Iinclude/greeter

build_greeter:
	mkdir -p build
	${CC} ${CLASS_SOURCES} ${CLASS_INCLUDE} -o ${BUILD_DIR}/greeter

