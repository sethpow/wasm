./emsdk install latest
./emsdk activate latest
emcc -v
source ./emsdk_env.sh

cd tmp/hello_world

emcc hello_world.cpp -o <new_file_name>.html --emrun

emrun <new_file_name>.html