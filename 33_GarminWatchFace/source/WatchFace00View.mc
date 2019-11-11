using Toybox.WatchUi;
using Toybox.Graphics;
using Toybox.System;
using Toybox.Lang;

class WatchFace00View extends WatchUi.WatchFace {
    var ft24 = null;
    var ftb24 = null;
    var ft28 = null;
    var ftb28 = null;
    var ft32 = null;
    var ftb32 = null;
    var ftb60d = null;

    function initialize() {
        WatchFace.initialize();
        System.println("function initialize()");
        
    }

    // Load your resources here
    function onLayout(dc) {
        //setLayout(Rez.Layouts.WatchFace(dc));
        ft24 = WatchUi.loadResource(Rez.Fonts.ft24);
        ftb24 = WatchUi.loadResource(Rez.Fonts.ftb24);
        ft28 = WatchUi.loadResource(Rez.Fonts.ft28);
        ftb28 = WatchUi.loadResource(Rez.Fonts.ftb28);
        ft32 = WatchUi.loadResource(Rez.Fonts.ft32);
        ftb32 = WatchUi.loadResource(Rez.Fonts.ftb32);
        ftb60d = WatchUi.loadResource(Rez.Fonts.ftb60d);
        System.println("onLayout()");
    }

    // Called when this View is brought to the foreground. Restore
    // the state of this View and prepare it to be shown. This includes
    // loading resources into memory.
    function onShow() {
        System.println("onShow()");
    }

    // Update the view
    function onUpdate(dc) {
        // Get and show the current time
        var clockTime = System.getClockTime();
        var timeString = Lang.format("$1$:$2$", [clockTime.hour, clockTime.min.format("%02d")]);

        //set backgroud to black
        dc.setColor(Graphics.COLOR_BLACK, Graphics.COLOR_BLACK);
        dc.clear(); 
                //240pix round screen
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawArc(120,120,120,Graphics.ARC_CLOCKWISE, 315, 225);
        dc.drawArc(120,120,115,Graphics.ARC_CLOCKWISE, 315, 225);
        dc.setColor(Graphics.COLOR_BLUE, Graphics.COLOR_BLACK);
        dc.fillCircle(160, 120, 20);
        dc.fillPolygon([[100,100],[120,140],[130,135],[140,100]]);
         
        //60d
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(120, 10, ftb60d, timeString, Graphics.TEXT_JUSTIFY_CENTER);
        //24
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(25, 60, ft24, "abcABC", Graphics.TEXT_JUSTIFY_LEFT);
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(215, 60, ftb24, "abcABC", Graphics.TEXT_JUSTIFY_RIGHT);       
        //28
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(5, 90, ft28, "abcABC", Graphics.TEXT_JUSTIFY_LEFT);
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(235, 90, ftb28, "abcABC", Graphics.TEXT_JUSTIFY_RIGHT);       
        
        //32
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(5, 125, ft32, "abcABC", Graphics.TEXT_JUSTIFY_LEFT);
        dc.setColor(Graphics.COLOR_WHITE, Graphics.COLOR_BLACK);
        dc.drawText(235, 125, ftb32, "abcABC", Graphics.TEXT_JUSTIFY_RIGHT);       
        //32Color(32x16)       
        dc.setColor(Graphics.COLOR_RED, Graphics.COLOR_BLACK);
        dc.drawText(20, 160, ftb32, "abAB", Graphics.TEXT_JUSTIFY_LEFT);
        dc.setColor(Graphics.COLOR_GREEN, Graphics.COLOR_BLACK);
        dc.drawText(84, 160, ftb32, "abAB", Graphics.TEXT_JUSTIFY_LEFT);
        dc.setColor(Graphics.COLOR_BLUE, Graphics.COLOR_BLACK);
        dc.drawText(148, 160, ftb32, "abAB", Graphics.TEXT_JUSTIFY_LEFT);
        // Call the parent onUpdate function to redraw the layout
        //View.onUpdate(dc);
        System.println("width:" + dc.getWidth() + ", height:" + dc.getHeight());
        System.println("onUpdate()" + timeString);
    }

    // Called when this View is removed from the screen. Save the
    // state of this View here. This includes freeing resources from
    // memory.
    function onHide() {
        System.println("onHide()");
    }

    // The user has just looked at their watch. Timers and animations may be started here.
    function onExitSleep() {
        System.println("onExitSleep()");
    }

    // Terminate any active timers and prepare for slow updates.
    function onEnterSleep() {
        System.println("onEnterSleep()");
    }

}
