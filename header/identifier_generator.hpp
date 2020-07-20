_Pragma("once");
#include<part_identifier.hpp>
#include<string>
namespace HFormatter::NIdentifierGenerator{
    class IdentifierGenerator{
        public:
            virtual HFormatter::NPartIdentifier::PartIdentifier getIdentifier(const std::string&);
    };
}