// Here we avoid loading the header multiple times
#ifndef GIOCO1_HEADER
#define GIOCO1_HEADER
// We need the Plasma Applet headers
#include <KIcon>

#include <Plasma/Applet>
#include <Plasma/Svg>

#include "passwordsetup.h"

class QSizeF;

// Define our plasma Applet
class gioco1 : public Plasma::Applet
{
    Q_OBJECT
    public:
        // Basic Create/Destroy
        gioco1(QObject *parent, const QVariantList &args);
        ~gioco1();

        // The paintInterface procedure paints the applet to screen
        void paintInterface(QPainter *painter,
                const QStyleOptionGraphicsItem *option,
                const QRect& contentsRect);
        void init();
        void createConfigurationInterface(KConfigDialog *parent);


    private:
        Plasma::Svg m_svg;
        KIcon m_icon;
        PasswordSetup * m_configDialog;
};
 
// This is the command that links your applet to the .desktop file
K_EXPORT_PLASMA_APPLET(gioco1, gioco1)
#endif
