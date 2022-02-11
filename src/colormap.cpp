#include "vivid/colormap.h"
#include "vivid/conversion.h"
#include "vivid/utility.h"
#include "vivid/data.h"
#include "vivid/stream.h"
#include "vivid/interpolation.h"

#include <glm/common.hpp>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>

namespace vivid {


////////////////////////////////////////////////////////////////////////////////
ColorMap::ColorMap( const Preset preset )
{
}


////////////////////////////////////////////////////////////////////////////////
ColorMap::ColorMap( const std::string& filename ) {
}


////////////////////////////////////////////////////////////////////////////////
srgb_t ColorMap::at( const float t ) const
{
    if ( empty() ) {
        return {};
    }

    const size_t steps = stops_.size() - 1;
    const float s = glm::clamp( t, 0.f, 1.f );
    const float sf = s * steps;
    const size_t k = size_t( glm::floor( sf ) );

    if ( k + 1 == stops_.size() ) {
        return stops_.back();
    }

    const auto u = std::fmod( sf, 1.f );

    switch ( interpolation )
    {
        case Interpolation::Nearest: return stops_[ k ];
        case Interpolation::Linear: return lerp( stops_[ k ], stops_[ k + 1 ], u );
        case Interpolation::Hsv: return rgb::fromHsv( lerp(
            hsv::fromRgb( stops_[ k ] ),
            hsv::fromRgb( stops_[ k + 1 ] ),
            u
        ));
        case Interpolation::Hsl: return rgb::fromHsl( lerp(
            hsl::fromRgb( stops_[ k ] ),
            hsl::fromRgb( stops_[ k + 1 ] ),
            u
        ));
        case Interpolation::Lch: return rgb::saturate(
            srgb::fromLch( lerp(
                lch::fromSrgb( stops_[ k ] ),
                lch::fromSrgb( stops_[ k + 1 ] ),
                u
            )
        ));
    }

    return {};
}


////////////////////////////////////////////////////////////////////////////////
std::string ColorMap::nameForPreset( const Preset preset )
{
    return {};
}

}   //  ::vivid
