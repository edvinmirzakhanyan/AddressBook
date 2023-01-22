#include <QFile>
#include <QTextStream>

#include "addressbook.h"

const QString AddressBook::fileName = "addressBook.data";

AddressBook::AddressBook(QObject* parent): QObject(parent) {}

QStringList AddressBook::split(const QString& str) {
    int length = str.length();
    QStringList arr;
    QString word;

    for (int i = 0; i < length; ++i) {
        if (str[i] != ' ') { word += str[i]; continue; }
        if (word.length()) { arr.push_back(word); word = "";}
    }
    if (word.length()) { arr.push_back(word); }

    return arr;
}

bool AddressBook::validName(const QString& name) {
    int inputSize = name.size();

    if (inputSize > DataSize::NameMaxSize || inputSize < DataSize::NameMinSize) {
        m_error = "Name must contain from 3 to 15 letters!";
        return false;
    }

    for (int i = 0; i < inputSize; ++i) {

        if ((name[i] < 'a' || name[i] > 'z')
            && (name[i] < 'A' || name[i] > 'Z')) {
            m_error = "Name must contain only letters!";
            return false;
        }
    }
    return true;
}

bool AddressBook::validPhone(const QString& phone) {
    int inputSize = phone.length();

    if (!inputSize || phone[0] != '0') {
        m_error = "Incorrect phone number!";
        return false;
    }

    if (inputSize != DataSize::PhoneSize) {
        m_error = "Phone number must contain 9 digits!";
        return false;
    }

    for (int i = 1; i < DataSize::PhoneSize; ++i) {
        if (phone[i] < '0' || phone[i] > '9') {
            m_error = "Phone number must contain only digits!";
            return false;
        }
    }

    return true;
}

bool AddressBook::validEmail(const QString& eMail) {

    int length = eMail.length();
    int dotCount = 0;
    int i = 0;

    for (i; i < length; ++i) {
        if (eMail[0] == '.' || eMail[i] == ' '
            ||(eMail[i] == '.' && eMail[i + 1] == '.')) {
            m_error = "Don't use dots one after the other!";
            return false;
        }

        if (i != 0 && eMail[i] == '@') {
            ++i;
            break;
        }
    }

    if (i == length || eMail[i] == '.' || eMail[length - 1] == '.') {
        m_error = "Incorrect E-Mail address!";
        return false;
    }

    for (i; i < length; ++i) {
        if (eMail[i] == '@' || eMail[i] == ' ') {
            m_error = "Incorrect E-Mail address!";
            return false;
        }
        if (eMail[i] == '.') {
            ++dotCount;
        }
    }

    if (dotCount != 1) {
        m_error = "Incorrect E-Mail address!";
        return false;
    }

    emit creationSuccess();

    return true;
}

void AddressBook::dataSaver() {

    for (int i = Position::NameIndex + m_name.length(); i < Position::PhoneIndex; ++i) {
        m_name += ' ';
    }

    for (int i = Position::PhoneIndex + m_phone.length(); i < Position::EmailIndex; ++i) {
        m_phone += ' ';
    }

    for (int i = Position::EmailIndex + m_eMail.length(); i < Position::StatusIndex; ++i) {
        m_eMail += ' ';
    }

    for (int i = 0; i < DataSize::StatusSize; ++i) {
        m_status += ' ';
    }

    QFile file(fileName);
    file.open(QIODevice::Append);
    QTextStream append(&file);

    append << m_name + m_phone + m_eMail + m_status + '\n';

    file.close();
}

void AddressBook::createContact(const QString& name, const QString& phone, const QString& eMail) {
    if (!validName(name) || !validPhone(phone) || !validEmail(eMail)) {
        emit creationError(m_error);
        return;
    }

    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream read(&file);
    QString line;
    int length = eMail.length();

    while (!read.atEnd()) {
       line = read.readLine();
       if (line.midRef(Position::EmailIndex, length) == eMail) {
           emit creationError("Contact already exists or deleted!");
           file.close();
           return;
       }
    }

    file.close();

    m_name = name;
    m_phone = phone;
    m_eMail = eMail;
    m_status = "active";

    dataSaver();

    emit creationSuccess();
}

QStringList AddressBook::getContactsList() const {
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);
    QTextStream read(&file);

    QStringList contacts;
    QString line;
    bool deleted = false;

    while (!read.atEnd()) {
        line = read.readLine();

        if(line.midRef(Position::StatusIndex, 7) == "deleted") {
            deleted = true;
            line = line.mid(Position::EmailIndex, DataSize::EmailMaxSize);
            for (int i = 0; i < contacts.length(); ++i) {
                if (contacts[i].midRef(Position::EmailIndex, DataSize::EmailMaxSize) == line) {
                    contacts[i] = "";
                    break;
                }
            }
        }

        if (!deleted) {
            contacts.push_back(line);
        }
        deleted = false;
    }

    file.close();

    return contacts;
}

void AddressBook::deleteContact(const QString& name, const QString& phone, const QString& eMail) {
    m_name = name;
    m_phone = phone;
    m_eMail = eMail;
    m_status = "deleted";

    dataSaver();
    emit deleteSuccess();
}
