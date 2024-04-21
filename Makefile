conan_d:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Debug -s compiler.cppstd=17 --output-folder=. --build missing

conan_r:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Release -s compiler.cppstd=17 --output-folder=. --build missing

build_all:
	cd build && cmake ..  && make -j8

build_all_l:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Release -s compiler.cppstd=17 --output-folder=. --build missing
	cd build && cmake -DCMAKE_BUILD_TYPE=Release .. && make -j16 

clean_all:
	rm -rf build

build_test:
	rm -rf build
	mkdir build
	cd build && conan install .. -s build_type=Release -s compiler.cppstd=17 --output-folder=. --build missing
	cd build && cmake -DENABLE_UNIT_TEST=ON -DCMAKE_BUILD_TYPE=Release .. && make -j16

run_server:
	pwd
	bash run.sh

run_test:
	cd build/tests
	bash test.sh