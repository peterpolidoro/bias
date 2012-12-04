#ifndef BIAS_IMAGE_PROCESSOR_HPP
#define BIAS_IMAGE_PROCESSOR_HPP

#include <memory>
#include <QMutex>
#include <QObject>
#include <QRunnable>
#include <opencv2/core/core.hpp>
#include "fps_estimator.hpp"
#include "lockable.hpp"

namespace bias
{

    struct StampedImage;

    class ImageDispatcher : public QObject, public QRunnable, public Lockable<Empty>
    {
        Q_OBJECT

        public:
            ImageDispatcher(QObject *parent=0);

            ImageDispatcher( 
                    bool logging,
                    std::shared_ptr<LockableQueue<StampedImage>> newImageQueuePtr, 
                    std::shared_ptr<LockableQueue<StampedImage>> logImageQueuePtr, 
                    QObject *parent = 0
                    );

            void initialize( 
                    bool logging,
                    std::shared_ptr<LockableQueue<StampedImage>> newImageQueuePtr,
                    std::shared_ptr<LockableQueue<StampedImage>> logImageQueuePtr 
                    );

            // Use lock when calling these methods
            // ----------------------------------
            void stop();
            cv::Mat getImage();
            double getTimeStamp();
            double getFPS();
            unsigned long getFrameCount();
            // -----------------------------------

        private:
            bool ready_;
            bool logging_;
            std::shared_ptr<LockableQueue<StampedImage>> newImageQueuePtr_;
            std::shared_ptr<LockableQueue<StampedImage>> logImageQueuePtr_;

            // use lock when setting these values
            // -----------------------------------
            bool stopped_;
            cv::Mat currentImage_;
            double currentTimeStamp_;
            FPS_Estimator fpsEstimator_;
            unsigned long frameCount_;
            // ------------------------------------

            void run();
    };

} // namespace bias


#endif // #ifndef BIAS_IMAGE_PROCESSOR_HPP