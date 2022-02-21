#pragma once

#include "vivid/types.h"

namespace vivid {

namespace lrgb {
    lrgb_t fromOklab( const oklab_t& );
}

namespace oklab {
    oklab_t fromLrgb( const lrgb_t& );
}


}   //  ::vivid
