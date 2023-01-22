import QtQml 2.12
import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0



Page {
    id: addressBookPage
    width: parent.width
    height: parent.height
    visible: true
    title: "Address Book"

    onWindowChanged: root.showContactsList();

    header: ToolBar {
        id:tBar
        height: 50
        background: Rectangle {
            anchors.fill: parent
            color: "transparent"
        }
        Text {
            id: toolButtonText
            anchors.centerIn: parent
            text: addressBookPage.title
            font.pointSize: 17
            color: "darkmagenta"
        }
    }

    Rectangle {
        id: root
        width: parent.width
        height: parent.height
        anchors.topMargin: 50
        color: "white" 

        Image {
            id: mainImage
            anchors.fill: parent
            anchors.topMargin: 50
            anchors.rightMargin: 130
            anchors.leftMargin: 130
            anchors.bottomMargin: 130
            opacity: 0.50
            source: "images/main.jpg"
            fillMode: Image.PreserveAspectFit
        }

        Rectangle {
            id: name
            anchors.top: parent.top
            height: parent.height / 15
            width: parent.width / 5
            anchors.left: parent.left
            anchors.topMargin: parent.height / 10
            anchors.leftMargin: parent.width / 25
            radius: 20
            color: "magenta"
            Text {
                id: nameText
                anchors.centerIn: parent
                font.pointSize: 12
                text: "Name"
                color: "white"
            }
        }

        Rectangle {
            id: phone
            anchors.top: parent.top
            height: name.height
            width: name.width
            anchors.left: name.right
            anchors.topMargin: root.height / 10
            anchors.leftMargin: 20
            radius: 20
            color: "magenta"
            Text {
                id: phoneText
                anchors.centerIn: parent
                font.pointSize: 12
                text: qsTr("Phone")
                color: "white"
            }
        }

        Rectangle {
            id: eMail
            anchors.top: parent.top
            height: name.height
            width: parent.width / 3.5
            anchors.left: phone.right
            anchors.topMargin: parent.height / 10
            anchors.leftMargin: 20
            radius: 20
            color: "magenta"
            Text {
                id: eMailText
                anchors.centerIn: parent
                font.pointSize: 12
                text: qsTr("E-Mail")
                color: "white"
            }
        }

        Button {
            id: createButton
            anchors.top: eMail.top
            anchors.left: eMail.right
            anchors.bottom: eMail.bottom
            width: name.width
            anchors.leftMargin: 20
            background: Rectangle {
                anchors.fill: parent
                color: createButton.hovered ? "lightgray" : "white"
                border.color: "darkmagenta"
                border.width: 2
                radius: 20
            }
            contentItem: Text {
                id: createButtonText
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                text: "Create"
                font.pointSize: 14
                color: "darkmagenta"
            }
            onClicked: {
                name.visible = false;
                phone.visible = false;
                eMail.visible = false;
                createButton.visible = false;
                contactsList.visible = false;
                createWindow.visible = true;
            }

        }

        Rectangle {
            id: createWindow
            anchors.fill: parent
            opacity: 0.90
            color: "white"
            visible: false

            TextField {
                id: createNameText
                height: parent.height / 15
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: parent.top
                anchors.topMargin: parent.height / 3
                anchors.leftMargin: parent.width / 3
                anchors.rightMargin: parent.width / 3
                placeholderText: "Name"
                background: Rectangle {
                    height: 1
                    anchors.bottom: parent.bottom
                    color: "magenta"
                }
            }

            TextField {
                id: createPhoneText
                height: parent.height / 15
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: createNameText.bottom
                anchors.topMargin: 20
                anchors.leftMargin: parent.width / 3
                anchors.rightMargin: parent.width / 3
                placeholderText: "Phone"
                background: Rectangle {
                    height: 1
                    anchors.bottom: parent.bottom
                    color: "magenta"
                }
            }

            TextField {
                id: createEmailText
                height: parent.height / 15
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.top: createPhoneText.bottom
                anchors.topMargin: 20
                anchors.leftMargin: parent.width / 3
                anchors.rightMargin: parent.width / 3
                placeholderText: "E-Mail"
                background: Rectangle {
                    height: 1
                    anchors.bottom: parent.bottom
                    color: "magenta"
                }
            }

            Button {
                id: acceptButton
                anchors.top: createEmailText.bottom
                anchors.left: createEmailText.left
                anchors.right: createEmailText.right
                anchors.topMargin: 20
                anchors.leftMargin: 20
                anchors.rightMargin: 20
                background: Rectangle {
                    anchors.fill: parent
                    color: acceptButton.hovered ? "lightgray" : "white"
                    border.color: "darkmagenta"
                    border.width: 2
                    radius: 20
                }
                contentItem: Text {
                    id: acceptButtonText
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    text: "Create"
                    font.pointSize: 14
                    color: "darkmagenta"
                }
                onClicked: {
                    contact.createContact(createNameText.text, createPhoneText.text, createEmailText.text);
                    createNameText.text = "";
                    createPhoneText.text = "";
                    createEmailText.text = "";
                }

            }
        }



        Rectangle {
            anchors.top: name.bottom
            anchors.topMargin: 10
            anchors.bottom: parent.bottom
            anchors.left: name.left
            anchors.right: parent.right
            color: "transparent"
            ListModel {
                    id: contactsInfo
            }
            ListView {
                id:contactsList
                anchors.fill: parent
                model: contactsInfo
                clip: true
                spacing: 10
                delegate: Rectangle {
                    height: root.height / 15
                    width: root.width
                    color: "transparent"

                    Label {
                        id: contactName
                        height: parent.height
                        width: root.width / 5
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: contactNameText
                        color: "magenta"
                        background: Rectangle {
                            anchors.fill: parent
                            radius: 20
                            color: "white"
                            border.color: "magenta"
                        }
                    }

                    Label {
                        id: contactPhone
                        height: contactName.height
                        width: root.width / 5
                        anchors.left: contactName.right
                        anchors.leftMargin: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: contactPhoneText
                        color: "magenta"
                        background: Rectangle {
                            anchors.fill: parent
                            radius: 20
                            color: "white"
                            border.color: "magenta"
                        }
                    }

                    Label {
                        id: contactEmail
                        height:  contactName.height
                        width: root.width / 3.5
                        anchors.left: contactPhone.right
                        anchors.leftMargin: 20
                        horizontalAlignment: Text.AlignHCenter
                        verticalAlignment: Text.AlignVCenter
                        text: contactEmailText
                        color: "magenta"
                        background: Rectangle {
                            anchors.fill: parent
                            radius: 20
                            color: "white"
                            border.color: "magenta"
                        }
                    }

                    Button {
                        id: deleteContactButton
                        anchors.top: parent.top
                        height: contactName.height
                        width: contactName.width
                        anchors.left: contactEmail.right
                        anchors.leftMargin: 20
                        background: Rectangle {
                            id: deleteButtonBckg
                            width: parent.width
                            height: parent.height
                            color: deleteContactButton.hovered ? "lightgray" : "white"
                            border.color: "darkmagenta"
                            border.width: 2
                            radius: 20
                        }
                        contentItem: Text {
                            id: deleteContactButtonText
                            text: qsTr("Delete")
                            font.pointSize: 14
                            horizontalAlignment: Text.AlignHCenter
                            verticalAlignment: Text.AlignVCenter
                            color: "darkmagenta"
                        }
                        onClicked: {
                                contact.deleteContact(contactsInfo.get(index).contactNameText,
                                                      contactsInfo.get(index).contactPhoneText,
                                                      contactsInfo.get(index).contactEmailText);
                            }
                        }
                    }
                }
            }

        function showContactsList(contacts = contact.getContactsList()) {
            let splited;
            for (let i = 0; i < contacts.length; ++i) {
                if (contacts[i].length) {
                    splited = contact.split(contacts[i]);
                    contactsInfo.append({ contactNameText: splited[0],
                                          contactPhoneText: splited[1],
                                          contactEmailText: splited[2], })
                }
            }

        }

    }

    Rectangle {
        id: notification
        anchors.fill: parent
        opacity: 0.90
        color: "white"
        visible: false

        Label {
            id: notificationText
            anchors.centerIn: parent
            font.pointSize: 15
            color: "black"
        }

        Button {
            id: okButton
            anchors.top: notificationText.bottom
            anchors.left: notificationText.left
            anchors.right: notificationText.right
            anchors.topMargin: 30
            anchors.leftMargin: 50
            anchors.rightMargin: 50
            background: Rectangle {
                id: okButtonBackground
                width: parent.width
                height: parent.height
                color: okButton.hovered ? "darkmagenta" : "magenta"
                radius: 10
            }
            contentItem: Text {
                id: okButtonText
                text: "Ok"
                color: "white"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
            onClicked: {
                notificationText.text = "";
                notification.visible = false;
            }
        }
    }

    Connections {
        target: contact
        onCreationError: {
            notification.visible = true;
            notificationText.text = type;
            name.visible = true;
            phone.visible = true;
            eMail.visible = true;
            createButton.visible = true;
            contactsList.visible = true;
            createWindow.visible = false;
        }
        onCreationSuccess: {
            notification.visible = true;
            notificationText.text = "Contact added successfully!";
            name.visible = true;
            phone.visible = true;
            eMail.visible = true;
            createButton.visible = true;
            contactsList.visible = true;
            createWindow.visible = false;
            contactsInfo.clear();
            root.showContactsList();
        }
        onDeleteSuccess: {
            notification.visible = true;
            notificationText.text = "Contact successfully deleted!";
            contactsInfo.clear();
            root.showContactsList();
        }
    }
}
