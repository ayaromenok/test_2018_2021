//Copyrigth (C) 2019 Andrey Yaromenok
#include <QtWidgets>
#include "yissuedragwidget.h"
#include "yissuewidget.h"

static inline QString YIssueMimeType() {
    return QStringLiteral("application/x-fridgemagnet");
}

YIssueDragWidget::YIssueDragWidget(const QString &title, QWidget *parent) :
    QWidget(parent)
{
    _title = title;
    setObjectName(title);
    createUI();
    setAcceptDrops(true);
}

void
YIssueDragWidget::createUI()
{
    _fMain = new QFrame(this);
    _ltMain = new QVBoxLayout(this);
    _lbTitle = new QLabel(_title, this);
    _ltMain->addWidget(_lbTitle);
}

void
YIssueDragWidget::addIssue(YIssueWidget *issue)
{
    _ltMain->addWidget(issue);
}

void
YIssueDragWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (children().contains(event->source())) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->acceptProposedAction();
    }
    qDebug() << __PRETTY_FUNCTION__;
}

void
YIssueDragWidget::dragMoveEvent(QDragMoveEvent *event)
{
    if (children().contains(event->source())) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->acceptProposedAction();
    }
    qDebug() << __PRETTY_FUNCTION__ << event->source()->objectName();
}

void
YIssueDragWidget::dropEvent(QDropEvent *event)
{
    if (event->source() == this) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->acceptProposedAction();
    }

    qDebug() << __PRETTY_FUNCTION__ << event->source()->objectName();
}

void
YIssueDragWidget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << __PRETTY_FUNCTION__;
    YIssueWidget *child = static_cast<YIssueWidget*>(childAt(event->pos()));
    if (!child)
        return;

    QPoint hotSpot = event->pos() - child->pos();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream <<  QPoint(hotSpot);

    QMimeData *mimeData = new QMimeData;
    mimeData->setData(YIssueMimeType(), itemData);
    //        mimeData->setText(child->labelText());

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    //drag->setPixmap(*child->pixmap());
    drag->setHotSpot(hotSpot);

    child->hide();
    if (drag->exec(Qt::MoveAction | Qt::CopyAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else
        child->show();
}
