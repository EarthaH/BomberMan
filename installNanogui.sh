git clone https://github.com/wjakob/nanogui.git external/nanogui
cd external/nanogui
mkdir build
cd build
git submodule update --init --recursive
cmake ..
make -j 4
cd ../../..