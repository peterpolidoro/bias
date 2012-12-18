#ifndef BIAS_BACKGROUND_HISTOGRAM_UFMF_HPP
#define BIAS_BACKGROUND_HISTOGRAM_UFMF_HPP
#include <memory>
#include <QObject>
#include <QRunnable>
#include "lockable.hpp"

namespace bias
{
    struct StampedImage;
    class BackgroundData_ufmf;

    class BackgroundHistogram_ufmf 
        : public QObject, public QRunnable, public Lockable<Empty>
    {
        Q_OBJECT

        public:
            BackgroundHistogram_ufmf(QObject *parent=0);
            BackgroundHistogram_ufmf(
                    std::shared_ptr<LockableQueue<StampedImage>> bgImageQueuePtr, 
                    std::shared_ptr<LockableQueue<BackgroundData_ufmf>> bgDataQueuePtr,
                    QObject *parent=0
                    );
            void initialize(
                    std::shared_ptr<LockableQueue<StampedImage>> bgImageQueuePtr,
                    std::shared_ptr<LockableQueue<BackgroundData_ufmf>> bgDataQueuePtr
                    );
            void stop();

        private:
            bool ready_;
            bool stopped_;

            // Queue of incoming images for background model
            std::shared_ptr<LockableQueue<StampedImage>> bgImageQueuePtr_;       

            // Queue of outgoing background data for median calculation
            std::shared_ptr<LockableQueue<BackgroundData_ufmf>> bgDataQueuePtr_;

            void run();
    };

}

#endif // #ifndef BAIS_BACKGOUND_HISTOGRAM_UFMF_HPP
