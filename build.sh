mkdir -p build
cd build

cmake ..
if [ $? -ne 0 ]; then
    echo "CMake configuration failed!"
    exit 1
fi

make
if [ $? -eq 0 ]; then
    echo "Build succeeded!"
else
    echo "Build failed!"
    exit 1
fi

cd ..
