#include "vivid/conversion.h"
#include "vivid/data/xterm.h"

namespace vivid::name {


////////////////////////////////////////////////////////////////////////////////
const std::string& fromRgb( const rgb_t& rgb ) {
    return name::fromIndex( index::fromRgb( rgb ) );
}


////////////////////////////////////////////////////////////////////////////////
const std::string& fromIndex( const uint8_t index ) {
}


}   //  ::vivid::name
