import QtQuick 2.6
import QtQuick.Window 2.2
import LayerRenderer 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    LayerRenderer{
        id: layerRenderer
        anchors.fill: parent
    }
}
