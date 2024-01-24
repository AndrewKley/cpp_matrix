#include <exception>
#include <iostream>

using namespace std;

class MatrixSizeError : public exception {
    public:
        MatrixSizeError(const string message);
        const char* what() const noexcept override;
    
    private:
        string message_;
};

class MatrixCalculationError : public exception {
    public:
        MatrixCalculationError(const string message);
        const char* what() const noexcept override;
    
    private:
        string message_;
};
