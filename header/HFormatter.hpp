_Pragma("once");

// Begin indexers
#include<indexer.hpp>
// End indexers

// Begin part identifiers
#include<part_identifier.hpp>
// End part identifiers

// Begin part infos
#include<part_info.hpp>
// End part infos

// Begin part iterators
#include<part_iterator.hpp>
// End part iterators

// Begin identifier generators
#include<identifier_generator.hpp>
// End identifier generators

namespace HFormatter{
    class Formatter{
        private:
            NIndexer::Indexer indexer_;
            NPartIterator::PartIterator iterator_;
            NIdentifierGenerator::IdentifierGenerator id_generator_;
        public:

    };
}