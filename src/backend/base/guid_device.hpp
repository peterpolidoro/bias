#ifndef BIAS_GUID_DEVICE_HPP
#define BIAS_GUID_DEVICE_HPP

#include <string>
#include <iostream>
#include <memory>
#include "basic_types.hpp"

namespace bias {

    class GuidDevice 
    {
        // --------------------------------------------------------------------
        // Base clase for device (library) specific guid's
        // --------------------------------------------------------------------

        
        public:
            GuidDevice() {};
            virtual ~GuidDevice() {};
            virtual CameraLib getCameraLib() { return CAMERA_LIB_UNDEFINED; };
            virtual void printValue() { std::cout << toString() << std::endl; };
            virtual std::string toString() { return std::string("guid value not defined"); };

            friend bool operator== (GuidDevice &guid0, GuidDevice &guid1)
            {
                return guid0.isEqual(guid1);
            };
            
            friend bool operator!= (GuidDevice &guid0, GuidDevice &guid1)
            {
                return !(guid0.isEqual(guid1));
            };

            friend bool operator< (GuidDevice &guid0, GuidDevice &guid1)
            {
                return guid0.lessThan(guid1);
            };

            friend bool operator<= (GuidDevice guid0, GuidDevice &guid1)
            {
                return guid0.lessThanEqual(guid1);
            };

            friend bool operator> (GuidDevice &guid0, GuidDevice &guid1)
            {
                return !(guid0.lessThanEqual(guid1));
            };

            friend bool operator>= (GuidDevice guid0, GuidDevice &guid1)
            {
                return !(guid0.lessThan(guid1));
            };

        private:
            virtual bool isEqual(GuidDevice &guid) { return false; };
            virtual bool lessThan(GuidDevice &guid) { return false; };
            virtual bool lessThanEqual(GuidDevice &guid) { return false; };

    }; // class GuidDevice

    typedef std::shared_ptr<GuidDevice> GuidDevicePtr;

} // namespace bias

#endif // #ifndef BIAS_GUID_DEVICE_HPP
