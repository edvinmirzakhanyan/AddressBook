import QtQml 2.12
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

Window {
    width: 1000
    height: 480
    visible: true
    title: qsTr("Address Book")

    AddressBookPage {
        id:addressBookPage
    }
}
