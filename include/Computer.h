#include <iostream>

class ALU{
public:
    ALU(){ //ALU constructor
        numPerCores = 0; //set number per cores 0 at first
        std::cout << "ALU is ready" << std::endl; //print out when it is created
    };
    void set_per_cores(int num){ //set per core number
    numPerCores = num;
    };
    int get_per_cores() const{ // get per core number (UNUSED!)
    return numPerCores;
    };
    int add(int a,int b) const{ //if operation is add return wanted solution
        return a+b;
    };
    int subtract(int a,int b) const{ //if operation is subtract return wanted solution
        return a-b;
    };
    int multiply(int a,int b) const{ //if operation is multiply return wanted solution
        return a * b;
    };
private:
    int numPerCores; //private attribute
};

class CUDA{
public:
    CUDA(){ //CUDA constructor
        numCores = 0; //set number of cores 0 at first
        std::cout << "CUDA is ready" << std::endl; //print out when it is created
    }
    void set_cores(int num){ //set core number
        numCores = num;
    };
    int get_cores()const{ // get core number (UNUSED!)
        return numCores;
    }
    void render() const{ //if operation is render print out wanted output
        std::cout << "Video is rendered" << std::endl;
    };
    void trainModel() const{ //if operation is trainModel print out wanted output
        std::cout << "AI Model is trained" << std::endl;
    };
private:
    int numCores; //private attribute
};

class CPU{
public:
    CPU(int num){ //CPU constructor
        alu.set_per_cores(num); //sets the number per cores
        std::cout << "CPU is ready" << std::endl;
    };
    void execute_cpu(std::string operation) const{ //execute method for cpu
        std::cout << "Enter two integers" << std::endl;
        int num1, num2; 
        std::cin >> num1 >> num2; //takes two integers from user 
        if(operation == "subtract"){ //if the needed operator is subtract
            std::cout << alu.subtract(num1,num2) << std::endl; //get the alu's methods
        }
        else if(operation == "add"){ //if the needed operator is add
            std::cout << alu.add(num1,num2) << std::endl; //get the alu's methods
        } 
        else if(operation == "multiply"){ //if the needed operator is multiply
            std::cout << alu.multiply(num1,num2) << std::endl; //get the alu's methods
        }else
            return;      
    };
private:
    ALU alu; //composition to ALU in CPU
};

class GPU{
public:
    GPU(int num){ //GPU constructor
        cuda.set_cores(num); //sets the number of cores
        std::cout << "GPU is ready" << std::endl; //print out when created
    };
    void execute_gpu(std::string operation){ //execute method for gpu
        if(operation == "render"){ 
            cuda.render(); //get the render method in cuda
        }else if(operation == "trainModel"){
            cuda.trainModel(); //get the trainModel method in cuda
        }
    };
private:
    CUDA cuda; //composition to CUDA in GPU
};

class Computer{
public:
    Computer(); //Computer constructor
    void operator+(CPU&) const; //operator overload to add CPU to computer
    void operator+(GPU&) const; //operator overload to add CPU to computer
    void execute(std::string) const; //execute function to execute given operation
private:
    mutable CPU* attachedCPU; //aggregation to CPU in Computer
    mutable GPU* attachedGPU; //aggregation to GPU in Computer
};

