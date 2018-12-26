import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1 as QQL

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    QQL.ColumnLayout{
        QQL.RowLayout{
            Calendar {
                weekNumbersVisible: true
                minimumDate: new Date(2017, 0, 1)
                maximumDate: new Date(2019, 0, 1)
            }
            Calendar {
                weekNumbersVisible: true
                minimumDate: new Date(2017, 0, 1)
                maximumDate: new Date(2019, 10, 1)
            }
        }
    }

}
