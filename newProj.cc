#include <iostream>
#include <stdexcept>
#include <sstream>
#include <string>
#include <memory>
#include <vector>

template<typename Arithmetic> 
Arithmetic divide(Arithmetic numerator, Arithmetic denominator){
    return (numerator/denominator);
}

class mathCheck
{
    private:
        size_t x;

    public:
        mathCheck(size_t x_val): x(x_val)
        {
            if(x == 0)
            {
                throw std::invalid_argument("x cannot be zero");
            }
            else
            {
                std::cout << x << std::endl;
            }
        }
};

int main() {
    
    // Exception handling through library
    std::vector<mathCheck> m1;
    std::array<size_t,4> values = {49,0, 2,11};
    
    for (size_t val : values) {
        try {
            m1.emplace_back(val);
        } catch (const std::invalid_argument& e) {
            std::cerr << "Exception caught: " << e.what() << std::endl;
        }
    }

    // Invoke Template
    std::cout << "Template Result: "<< divide(10,5)<<std::endl;
    
    // Example usage of std::stringstream for string manipulation
    std::stringstream ss;
    ss << "The answer is: " << 42;
    std::string result = ss.str();
    std::cout << result << std::endl;

    return 0;
}
