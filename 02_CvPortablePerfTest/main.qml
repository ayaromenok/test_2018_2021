// Copyright(C) 2018 Andrey Yaromenok, ayaromenok@gmail.com
// MIT License - https://github.com/ayaromenok/OpenCVwithQt/blob/master/LICENSE

import QtQml 2.9 as QML
import QtQuick 2.9 as QQ
import QtQuick.Window 2.9
import QtQuick.Layouts 1.1 as QQL
import QtQuick.Controls 2.2 as QQC
import QtMultimedia 5.9 as QMM

import CvObject 1.0

Window {
    visible: true
    width: 360
    height: 360
    title: qsTr("Test OpenCV: CPU vs OpenCL")

    CvObject{
        id:cvo
    }
    QML.Connections{
        target:cvo
        onTestCPUChanged:{
            console.log("CPU")
            lbResultCPU.text = value;
        }
        onTestCLChanged:{
            console.log("CL")
            lbResultCL.text = value;
        }
    }

    QQL.GridLayout {
        anchors.fill: parent
        rows:1
        columns:4
        QQ.Rectangle{
            color: "darkgrey"
            implicitHeight: 360
            implicitWidth: 360
            QQL.ColumnLayout{
                QQL.RowLayout{
                    QQC.Button{
                        text: "CPU test"
                        onPressed: {
                            cvo.setTestCPU(10);
                        }
                    }
                    QQC.Label{
                        id: lbResultCPU
                        text: cvo.testCPU
                    }
                    QQC.Label{
                        text: "msec"
                    }
                }
                QQL.RowLayout{
                    QQC.Button{
                        text: "CL test"
                        onPressed: {
                            cvo.setTestCL(10);
                        }
                    }
                    QQC.Label{
                        id: lbResultCL
                        text: cvo.testCL
                    }
                    QQC.Label{
                        text: "msec"
                    }
                }
            }
        }

    }
}
