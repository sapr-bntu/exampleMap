#ifndef SVGVIEW_H
#define SVGVIEW_H

#include <QGraphicsView>

class QWheelEvent;
class QPaintEvent;
class QFile;

class SvgView : public QGraphicsView
{
    Q_OBJECT

public:
    enum RendererType { Native, OpenGL, Image };

    SvgView(QWidget *parent = 0);

    void openFile(const QFile &file);
    void setRenderer(RendererType type = Native);
    void drawBackground(QPainter *p, const QRectF &rect);

public slots:
    void setHighQualityAntialiasing(bool highQualityAntialiasing);
    void setViewBackground(bool enable);
    void setViewOutline(bool enable);

protected:
    void wheelEvent(QWheelEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    RendererType m_renderer;

    QGraphicsItem *m_svgItem;
    QGraphicsRectItem *m_backgroundItem;
    QGraphicsRectItem *m_outlineItem;

    QImage m_image;
};

#endif // SVGVIEW_H
