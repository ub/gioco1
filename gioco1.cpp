#include "gioco1.h"
#include "ui_passwordsetup.h"
#include "GiocoConfig.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <KLocale>

#include <KWallet/Wallet>

#include <KDE/KConfigDialog>



#include <plasma/svg.h>
#include <plasma/theme.h>

#include <KDebug>

gioco1::gioco1(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
    m_svg(this),
    m_icon(Plasma::Applet::icon()), // Use icon associated with the applet
    m_configDialog(0)
{
    // this will get us the standard applet background, for free!
    setBackgroundHints(DefaultBackground);
    m_svg.setImagePath("widgets/background");
    setHasConfigurationInterface(true);  
    resize(200, 200);
}


gioco1::~gioco1()
{
    if (hasFailedToLaunch()) {
        // Do some cleanup here
    } else {

        // Save settings
    }
}

void gioco1::init()
{
    // A small demonstration of the setFailedToLaunch function
    if (m_icon.isNull()) {
        setFailedToLaunch(true, i18n("No world to say hello"));
    }
}

 void gioco1::createConfigurationInterface(KConfigDialog *parent)
 {

  parent->addPage((m_configDialog = new PasswordSetup()), //parent is responsible for deletion
                  GiocoConfig::self() ,
                  parent->windowTitle() ,icon()); // use applet icon for settings page
 }



void gioco1::paintInterface(QPainter *p,
        const QStyleOptionGraphicsItem * /*unused_option*/, const QRect &contentsRect)
{
    p->setRenderHint(QPainter::SmoothPixmapTransform);
    p->setRenderHint(QPainter::Antialiasing);


    // Now we draw the applet, starting with our svg
    m_svg.resize((int)contentsRect.width(), (int)contentsRect.height());
    m_svg.paint(p, (int)contentsRect.left(), (int)contentsRect.top());

    // We place the icon and text
    p->drawPixmap(7, 0, m_icon.pixmap((int)contentsRect.width(),(int)contentsRect.width()-14));
    p->save();
    p->setPen(Qt::gray);
    p->drawText(contentsRect,
                Qt::AlignBottom | Qt::AlignHCenter,
                i18n("Hello Plasmoid!"));


    p->restore();

}


#include "gioco1.moc"
