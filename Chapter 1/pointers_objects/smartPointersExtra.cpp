#include <iostream>
#include <memory>

class Something {
    public:
        Something(){
            var1 = 1;
        };
        int getVar1(){
            std::cout << var1 << std::endl;
        };

        ~Something(){
            std::cout << "Dealoca something" << std::endl;
        }

    private:
        int var1;


};

int main(){
    std::shared_ptr<Something> s;
    std::weak_ptr<Something> sw;
    if(true){
        std::shared_ptr<Something> sp1 = std::make_shared<Something>();
        s = sp1;
    }
    s->getVar1();
    //std::shared_ptr<Something> sp2 = sp1;
    // std::unique_ptr<Something> up2 = std::make_unique<Something>(); //One way to alocate memory and in this way it can deal with execptions

    return 0;
}