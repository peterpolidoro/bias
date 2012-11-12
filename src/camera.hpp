#ifndef BIAS_CAMERA_HPP
#define BIAS_CAMERA_HPP

#include <set>
#include <list>
#include <memory>
#include <iostream>
#include "guid.hpp"
#include "basic_types.hpp"
#include "property.hpp"
#include "camera_device.hpp"

namespace bias {

    class Camera {

        // --------------------------------------------------------------------
        // Facade wrapper for cameras. Provides a unified interface for cameras 
        // which are accessed via different underlying libraries e.g. libdc1394, 
        // flycapture2, etc.
        // --------------------------------------------------------------------
       
        public:
            Camera();
            explicit Camera(Guid guid);
            ~Camera();
            CameraLib getCameraLib();

            Guid getGuid();

            void connect();
            void disconnect();      

            void startCapture(); 
            void stopCapture();
            void grabImage();

            bool isConnected();
            bool isCapturing();
            bool isColor();

            VideoMode getVideoMode();
            FrameRate getFrameRate();
            ImageMode getImageMode();
            VideoModeList getAllowedVideoModes();
            FrameRateList getAllowedFrameRates(VideoMode videoMode);
            ImageModeList getAllowedImageModes();
            Property getProperty(PropertyType propertyType);
            PropertyInfo getPropertyInfo(PropertyType propertyType);

            unsigned int getPropertyValue(PropertyType propertyType);
            unsigned int getPropertyMinValue(PropertyType propertyType);
            unsigned int getPropertyMaxValue(PropertyType propertyType);

            float getPropertyAbsoluteValue(PropertyType propertyType);
            float getPropertyMinAbsoluteValue(PropertyType propertyType);
            float getPropertyMaxAbsoluteValue(PropertyType propertyType);
            
            void setProperty(Property property);
            void setPropertyValue(PropertyType propertyType, unsigned int value);
            void setPropertyAbsoluteValue(PropertyType propertyType, float absoluteValue);

            unsigned int getBrightness();
            unsigned int getMinBrightness();
            unsigned int getMaxBrightness();
            void setBrightness(unsigned int brightness);
            
            void setVideoMode(VideoMode videoMode) {}; // TO DO //
            void setFrameRate(FrameRate frameRate) {}; // TO DO //
            void setImageMode(ImageMode imageMode) {}; // TO DO //
                
            void printInfo();
            void printGuid();

            friend std::ostream& operator<< (std::ostream &out, Camera &camera);

        private:
            CameraDevicePtr cameraDevicePtr_;
            void createCameraDevice_fc2(Guid guid);
            void createCameraDevice_dc1394(Guid guid);

    };

    typedef std::shared_ptr<Camera> CameraPtr;

    class CameraPtrCmp : public std::binary_function<CameraPtr, CameraPtr, bool>
    {
        // Comparison object for shared_ptrs to Guid objects  
        public:
            bool operator() (const CameraPtr &camPtr0, const CameraPtr &camPtr1);
    };

    typedef std::set<CameraPtr> CameraPtrSet;
    typedef std::list<CameraPtr> CameraPtrList;
}


#endif // #ifndef BIAS_CAMERA_HPP
