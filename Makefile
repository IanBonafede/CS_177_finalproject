all: ibona001_finalproject_base 

ibona001_finalproject_base:
	g++ --std=c++11 -DCPP -DGPP -I/usr/csshare/pkgs/csim_cpp-19.0/lib -m32 /usr/csshare/pkgs/csim_cpp-19.0/lib/csim.cpp.a -lm -o ibona001_finalproject_base  ibona001_finalproject.cpp

	

