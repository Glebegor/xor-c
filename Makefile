.PHONY: all build run build-run clean

# Default target
all: build-run

# Build target
build:
	@chmod +x ./build.sh
	@./build.sh
	@if [ $$? -ne 0 ]; then \
		echo "Build failed!"; \
		exit 1; \
	fi

# Run target
run:
	chmod +x ./run.sh
	./run.sh

# Build and Run target
build-run: build run

# remove any generated files
clean:
	rm -f my_program  # Update this with your actual target name
