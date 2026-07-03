// src/fileio.h
#pragma once
#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QUrl>

class FileIO : public QObject {
    Q_OBJECT
public:
    explicit FileIO(QObject *parent = nullptr) : QObject(parent) {}

    Q_INVOKABLE bool write(const QString &localPath, const QString &content) {
        if (localPath.isEmpty()) return false;
        QString cleanPath = localPath;
        if (cleanPath.startsWith("file://")) {
            cleanPath = QUrl(cleanPath).toLocalFile();
        }
        QFile file(cleanPath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) return false;
        QTextStream out(&file);
        out << content;
        file.close();
        return true;
    }
};