#ifdef WITH_DC1394
#ifndef BIAS_UTILS_DC1394_HPP
#define BIAS_UTILS_DC1394_HPP

#include "basic_types.hpp"
#include "property.hpp"
#include "format7.hpp"
#include <string>
#include <dc1394/dc1394.h>

namespace bias 
{


    // Conversion from BIAS types to libdc1394 types
    // ------------------------------------------------------------------------
    dc1394video_mode_t convertVideoMode_to_dc1394(VideoMode vidMode, ImageMode imgMode);

    // Conversion from libdc1394 types to BIAS types
    // ------------------------------------------------------------------------
    VideoMode convertVideoMode_from_dc1394(dc1394video_mode_t vidMode_dc1394);
    
    // Print functions for libdc1394 configurations, settings and info
    //-------------------------------------------------------------------------
    void printVideoModes_dc1394(dc1394video_modes_t modes);

    // libdc1394 enumeration to string converstions
    // ------------------------------------------------------------------------
    std::string getVideoModeString_dc1394(dc1394video_mode_t vidMode);
    std::string getColorCodingString_dc1394(dc1394color_coding_t colorCoding);


    //// Image conversion - for mapping from FlyCapture2 to opencv 
    //// -----------------------------------------------------------------------
    //fc2PixelFormat getSuitablePixelFormat(fc2PixelFormat pixFormat);
    //int getCompatibleOpencvFormat(fc2PixelFormat pixFormat);
    
    //** // Conversion from BIAS types to FlyCapture2  types
    //// ------------------------------------------------------------------------
    //
    //fc2PropertyType convertPropertyType_to_fc2(PropertyType propType);
    //fc2FrameRate convertFrameRate_to_fc2(FrameRate frmRate);
    //fc2VideoMode convertVideoMode_to_fc2(VideoMode vidMode);
    //fc2Mode convertImageMode_to_fc2(ImageMode imgMode);
    //fc2Property convertProperty_to_fc2(Property prop);
    //fc2PixelFormat convertPixelFormat_to_fc2(PixelFormat pixFormat);
    //fc2Format7ImageSettings convertFormat7Settings_to_fc2(Format7Settings settings);

    //** // Conversion from FlyCapture2 types to BIAS types
    //// ------------------------------------------------------------------------
    //PropertyType convertPropertyType_from_fc2(fc2PropertyType propType_fc2);
    //VideoMode convertVideoMode_from_fc2(fc2VideoMode vidMode_fc2);
    //FrameRate convertFrameRate_from_fc2(fc2FrameRate frmRate_fc2);
    //ImageMode convertImageMode_from_fc2(fc2Mode mode_fc2);
    //Property convertProperty_from_fc2(fc2Property prop_fc2); 
    //PropertyInfo convertPropertyInfo_from_fc2(fc2PropertyInfo propInfo_fc2); 
    //PixelFormat convertPixelFormat_from_fc2(fc2PixelFormat pixFormat_fc2);
    //Format7Settings convertFormat7Settings_from_fc2(fc2Format7ImageSettings settings_fc2);

    //** // Print functions for FlyCapture2 configurations, settings and info
    ////-------------------------------------------------------------------------
    //
    //void printImageInfo_fc2(fc2Image &image);
    //void printFormat7ImageSettings_fc2(fc2Format7ImageSettings &imageSettings);
    //void printFormat7PacketSettings_fc2(unsigned int packetSize, float percentage);
    //void printFormat7Configuration_fc2(
    //        fc2Format7ImageSettings &imageSettings,
    //        unsigned int packetSize,
    //        float percentage
    //        );
    //void printFormat7Info_fc2(fc2Format7Info &format7Info);
    //void printFormat7PacketInfo_fc2(fc2Format7PacketInfo &packetInfo);
    //void printPropertyInfo_fc2(fc2PropertyInfo &propInfo);
    //void printProperty_fc2(fc2Property &prop);
    //void printTriggerMode_fc2(fc2TriggerMode &trigMode);
    //void printTriggerModeInfo_fc2(fc2TriggerModeInfo &trigModeInfo);

    //// FlyCapture2 enumeration to string converstions
    //// ------------------------------------------------------------------------
    //
    //std::string getInterfaceTypeString_fc2(fc2InterfaceType ifaceType);
    //std::string getPixelFormatString_fc2(fc2PixelFormat foramt);
    //std::string getBayerTileFormatString_fc2(fc2BayerTileFormat bayerFormat);
    //std::string getVideoModeString_fc2(fc2VideoMode vidMode);
    //std::string getFrameRateString_fc2(fc2FrameRate frmRate);
    //std::string getModeString_fc2(fc2Mode mode);
    //std::string getPropertyTypeString_fc2(fc2PropertyType propType);


}  // namespace bias

#endif // #ifndef BIAS_UTILS_DC1394_HPP
#endif // #ifdef WITH_DC1394