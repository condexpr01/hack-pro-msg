#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <sys/uio.h>
#include <unistd.h>

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
	if(argc != 3)return 1;

	pid_t pid = std::stoi(argv[1]);
	uintptr_t base = std::stoll(argv[2],nullptr,16);

	//uintptr_t start = dereference_pointer_chain<uintptr_t>(pid,base,0x026222c0,0x248,0x90,0xe0,0xb8,0x18,0x1c8);
	uintptr_t start = dereference_pointer_chain<uintptr_t>(pid,base,0x025c2570,0x3b8,0x8,0x18,0x50,0x50);

	//printf("%0#.16lX\n",start);

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
	printf("%s\n",e.what());
	return 1;
}
