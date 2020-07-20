_Pragma("once");
#include<string>
using std::string;
namespace HFormatter::NPartIdentifier{
    class PartIdentifier{
        private:
            string part_identifier_;
        public:
            PartIdentifier(const string&);
			virtual void setIdentifier(const string&);
            virtual const string& getIdentifier()const;
    };
}