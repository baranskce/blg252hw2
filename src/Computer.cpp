#include <iostream>
#include "Computer.h"
#include <string>

Computer::Computer(){ 
    std::cout << "Computer is ready" << std::endl; //when computer is created print it out
    this->attachedCPU = NULL; //at first there are no attachedCPU
    this->attachedGPU = NULL; //at first there are no attachedGPU
};

void Computer::operator+(CPU& cpu) const{ //first operator overload
    if(attachedCPU!=NULL){ //if there is already a CPU attached to computer
        std::cout << "There is already a CPU" << std::endl;
    }else{
        attachedCPU = &cpu; //if computer is free attached the cpu
        std::cout << "CPU is attached" << std::endl;
    }
};

void Computer::operator+(GPU& gpu) const{ //second operator overload
    if(attachedGPU!=NULL){ //if there is already a GPU attached to computer
        std::cout << "There is already a GPU" << std::endl;
    }else{
        attachedGPU = &gpu; //if computer is free attached the gpu
        std::cout << "GPU is attached" << std::endl;
    }
};

void Computer::execute(std::string operation) const{ //execute the operations
    if(operation == "subtract" || operation == "add" || operation == "multiply"){ //if wanted operations are from ALU
        attachedCPU->execute_cpu(operation); //go to attached cpu to make the operations
    }else if(operation == "render" || operation == "trainModel"){ //if wanted operations are from CUDA
        attachedGPU->execute_gpu(operation); //go to attached gpu to make the operations
    }
};