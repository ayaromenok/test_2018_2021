import QtQuick 2.14
import QtQuick.Controls 2.14

Page {
    width: 600
    height: 400

    header: Label {
        text: qsTr("Page 1")
        font.pixelSize: Qt.application.font.pixelSize * 2
        padding: 10
    }
    Text {
          text: "Hello World!"
          font.family: "Helvetica"
          font.pointSize: 24
          color: "red"
      }
    Text {
        x: 0
        y: 63
          text: "<b>Hello(HTML)</b> <i>World!</i>"
      }
    Text {
        x: 0
        y: 127
//        text: "# MD/GitHub\n## Level 2\n - [MD link](http://www.example.com)\n
//                - [local link](#llink)\n\n### Level 3\n Table\n\n
//                | Title #1 | Title #2 |\n|---|---|\n|value #1| value #2|
//                \ - **check** `text`/*MD* output in `console`"
        text: "# MD/GitHub\n## Level 2\n - [MD link](http://www.example.com)\n"
      }
    TextEdit {
        x: 0
        y: 200
        text: "# MD/GitHub\n## Level 2\n - [MD link](http://www.example.com)\n"
      }


}
