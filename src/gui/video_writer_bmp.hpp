#ifndef BIAS_VIDEO_WRITER_BMP_HPP
#define BIAS_VIDEO_WRITER_BMP_HPP
#include "video_writer.hpp"
#include "video_writer_params.hpp"
#include <QDir>
#include <QString>
#include <vector>

namespace bias
{
    class VideoWriter_bmp : public VideoWriter
    {
        public:

            VideoWriter_bmp(QObject *parent=0);
            explicit VideoWriter_bmp(
                    VideoWriterParams_bmp params,
                    QString fileName, 
                    QObject *parent=0
                    );
            virtual ~VideoWriter_bmp();
            virtual void addFrame(StampedImage stampedImg);

            static const QString IMAGE_FILE_BASE;
            static const QString IMAGE_FILE_EXT;
            static const unsigned int DEFAULT_FRAME_SKIP;
            static const VideoWriterParams_bmp DEFAULT_PARAMS;

        protected:

            bool isFirst_;
            QDir baseDir_;
            QDir logDir_;
            QString baseName_;
            void setupOutput();
    };
   
}

#endif // #ifndef BIAS_VIDEO_WRITER_BMP_HPP
