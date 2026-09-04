#include <cstdint>
#include <cstring>
#include <filesystem>
#include <stdexcept>
#include <sys/uio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

template <typename T = uintptr_t>
void process_vm_readv_pointer(
		pid_t pid,
		struct iovec &lvec,
		struct iovec &rvec,
		unsigned long next_offset){

	if(process_vm_readv(pid,&lvec,1,&rvec,1,0) == lvec.iov_len){

		rvec.iov_base = reinterpret_cast<void*>(
				*static_cast<T*>(lvec.iov_base) + next_offset);

	}else{
		throw std::runtime_error{std::strerror(errno)};
	}
}

template <typename content_type, std::convertible_to<std::uintptr_t> ...T>
content_type dereference_pointer_chain(pid_t pid, uintptr_t base, uintptr_t base_offset, T ...pointer_offset){

	struct iovec rvec{};
	uintptr_t lvec_content{};
	struct iovec lvec{&lvec_content,sizeof(lvec_content)};

	rvec.iov_base = reinterpret_cast<void*>(base + base_offset);
	rvec.iov_len = sizeof(lvec_content);

	(process_vm_readv_pointer(pid,lvec,rvec,pointer_offset),...);

	content_type content{};
	lvec.iov_base = &content;
	lvec.iov_len = rvec.iov_len = sizeof(content);

	if(process_vm_readv(pid,&lvec,1,&rvec,1,0) != lvec.iov_len){
		throw std::runtime_error{std::strerror(errno)};
	}

	return content;
}

int main(int argc, char *argv[]) try{
	if(argc < 3)return 1;

	//opt: fallback file for fallback_start
	uintptr_t fallback_start{};

	std::string fallback_filename{};
	std::fstream fallback_file;
	if(argc == 4){
		fallback_filename = argv[3];
		fallback_file.open(fallback_filename.c_str(), std::ios_base::in);

		//calc fallback_start
		std::string fallback_file_addr{};
		if(fallback_file.is_open()){
			std::getline(fallback_file,fallback_file_addr);
			fallback_start = std::stoll(fallback_file_addr,nullptr,16);
		}
	}

	pid_t pid = std::stoi(argv[1]);
	uintptr_t base = std::stoll(argv[2],nullptr,16);

	uintptr_t start{};

	try{
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x026222c0,0x248,0x90,0xe0,0xb8,0x18,0x1c8);
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x025c2570,0x3b8,0x8,0x18,0x50,0x50);
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x266d6b8,0x80,0x330,0x40,0x78,0x48);
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x260D980,0x38,0xf8,0x28,0x280,0x148,0x48);
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x260D980,0x1c0,0xf8,0x28,0x280,0x148,0x48);
		//start = dereference_pointer_chain<uintptr_t>(pid,base,0x0265df40,0x550,0x4b0,0x40,0x140,0x588,0x1d0,0x108);
		start = dereference_pointer_chain<uintptr_t>(pid,base,0x0287ca30,0x780,0,0x3c0,0xb8,0x28,0x1a8,0x48);

		//dump valid start to fallback_file
		if(fallback_file.is_open()){fallback_file.close();}
		fallback_file.open(fallback_filename, std::ios_base::out | std::ios_base::trunc);
		if(fallback_file.is_open()){
			std::string dump_start = std::format("{:#x}",start);
			fallback_file.write(dump_start.c_str(),dump_start.size());
		}
		
	}catch(std::exception &e){
		//if pointer chain didn't work, fall back to fallback_start
		if(fallback_start){
			start = fallback_start;
		}else{
			throw e;
		}
	}

	printf("%0#.16lX\n",start);

	#if 1
	for(int i=0x20;true;i++){
		uint8_t c = dereference_pointer_chain<uint8_t>(pid,start,i);
		if(isprint(c)){
			putchar(c);
		}else{
			printf("<%d>",c);
		}
		
		if(!c)break;
	}
	#endif

	return 0;
}
catch(std::exception &e){
	std::cout << e.what() << std::endl;
	return 1;
}

