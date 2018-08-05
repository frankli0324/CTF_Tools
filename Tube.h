#pragma once
#include<string>
#include<WinSock2.h>
#pragma comment(lib,"Ws2_32.lib ")
namespace pwn {

	class Tube {
	public:
		void interactive() {}

		std::string recieve(int bytes = 4096, time_t timeout = 200) { return std::string(); }
		std::string recvall() { return std::string(); }
		std::string recvline(bool keepends = true) { return std::string(); }
		std::string recvuntil(std::string pattern, bool drop) { return std::string(); }

		void send(std::string data) {}
		void sendline(std::string data) {}

		void close() {}
	};
	class RemoteSession :public Tube {
		SOCKET sock;
	public:
		RemoteSession(std::string host, int port);
		~RemoteSession();
		void interactive();

		std::string recieve(int bytes = 4096, time_t timeout = 0);
		std::string recvall(time_t timeout = 0);
		std::string recvline(bool keepends = true);
		std::string recvuntil(std::string pattern, bool drop);

		void send(std::string data);
		void sendline(std::string data);

		void close();
	};
	class ProcessSession :public Tube {
		void interactive();

		std::string recieve(int bytes = 4096, time_t timeout = 200);
		std::string recvall();
		std::string recvline(bool keepends = true);
		std::string recvuntil(std::string pattern, bool drop);

		void send(std::string data);
		void sendline(std::string data);

		void close();
	};
	class Listen_Session :public Tube {

	};
	RemoteSession remote(std::string addr, int port);
	ProcessSession process(std::string proc);
	Listen_Session listen();
}