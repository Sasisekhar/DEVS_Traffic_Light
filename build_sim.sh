if [ -d "build" ]; then rm -Rf build; fi
mkdir -p build
cd build || exit
rm -rf *
cmake ..
make
cd ..
echo Compilation done. Executable in the bin folder