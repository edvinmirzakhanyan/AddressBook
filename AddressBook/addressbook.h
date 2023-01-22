#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <QObject>
#include <QString>

enum Position {
    NameIndex = 0,
    PhoneIndex = 25,
    EmailIndex = 40,
    StatusIndex = 65,
};

enum DataSize {
    NameMaxSize = 15,
    NameMinSize = 3,
    EmailMaxSize = 20,
    EmailMinSize = 5,
    PhoneSize = 9,
    StatusSize = 10,
};

class AddressBook: public QObject
{
    Q_OBJECT;
public:
    explicit AddressBook (QObject* parent = nullptr);
    virtual ~AddressBook() {};
public:
    Q_INVOKABLE void createContact(const QString&, const QString&, const QString&);
    Q_INVOKABLE QStringList getContactsList() const;
    Q_INVOKABLE QStringList split(const QString&);
    Q_INVOKABLE void deleteContact(const QString&, const QString&, const QString&);
signals:
    void creationSuccess();
    void creationError(const QString& type);
    void deleteSuccess();
private:
    void dataSaver();
    bool validName(const QString&);
    bool validPhone(const QString&);
    bool validEmail(const QString&);
private:
    QString m_error;
    QString m_name;
    QString m_phone;
    QString m_eMail;
    QString m_status;
    static const QString fileName;
};

#endif // ADDRESSBOOK_H
