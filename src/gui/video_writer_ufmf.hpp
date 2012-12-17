#ifndef BIAS_VIDEO_WRITER_UFMF_HPP
#define BIAS_VIDEO_WRITER_UFMF_HPP

#include "video_writer.hpp"
#include <memory>
#include <QPointer>
#include <opencv2/highgui/highgui.hpp>

class QThreadPool;

namespace bias
{
    class BackgroundHistogram_ufmf;
    template <class T> class Lockable;
    template <class T> class LockableQueue;

    class VideoWriter_ufmf : public VideoWriter
    {
        Q_OBJECT

        public:

            VideoWriter_ufmf(QObject *parent=0);
            VideoWriter_ufmf(QString fileName, QObject *parent=0);
            virtual ~VideoWriter_ufmf();
            virtual void addFrame(StampedImage stampedImg);

            static const unsigned int MAX_THREAD_COUNT;
            static const unsigned int DEFAULT_FRAME_SKIP;
            static const QString DUMMY_FILENAME;

        protected:

            bool isFirst_;
            QPointer<QThreadPool> threadPoolPtr_;
            QPointer<BackgroundHistogram_ufmf> bgHistogramPtr_;
            std::shared_ptr<LockableQueue<StampedImage>> bgImageQueuePtr_;

            void checkImageFormat(StampedImage stampedImg);
            void setupOutput(StampedImage stampedImg);

            void startBackgroundModeling();
            void stopBackgroundModeling();
            
    };
   
}

#endif // #ifndef BIAS_VIDEO_WRITER_UFMF_HPP
