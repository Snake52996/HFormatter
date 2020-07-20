_Pragma("once");
#include<string>
namespace HFormatter::NStringCounter{
    class StringCounter{
        private:
            std::string value_;
        public:
            StringCounter(const unsigned int&);
            virtual StringCounter& operator++();
            virtual StringCounter operator++(int);
            virtual std::string operator()()const;
    };
}