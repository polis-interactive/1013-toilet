
#include "application/config.hpp"
#include "application/service.hpp"

#include <iostream>
#include <signal.h>
#include <cstdio>

std::function<void(int)> shutdown_handler;
void signal_handler(int signal) { shutdown_handler(signal); }

int main() {

    const Config conf{};
    auto service = Service::Create(conf);
    service->Start();

    bool exit = false;

    shutdown_handler = [&](int signal) {
        std::cout << "Server shutdown...\n";
        exit = true;
    };

    signal(SIGINT, signal_handler);

    while(!exit){
        std::this_thread::sleep_for(1s);
    }


}
