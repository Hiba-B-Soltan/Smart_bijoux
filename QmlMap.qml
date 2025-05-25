import QtQuick.Controls 2.15
import QtLocation 5.15

ApplicationWindow {
    visible: true
    width: 800
    height: 600
    title: "OSM Map Example"

    Map {
        anchors.fill: parent
        plugin: Plugin {
            name: "osm"
        }
        center: QtPositioning.coordinate(37.7749, -122.4194)
        zoomLevel: 10

        MapQuickItem {
            anchorPoint.x: image.width / 2
            anchorPoint.y: image.height
            sourceItem: Image {
                id: image
                source: "https://a.tile.openstreetmap.org/{z}/{x}/{y}.png"
            }
        }
    }
}
