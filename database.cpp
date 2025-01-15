#include "mainwindow.h"
#include "credentials.h"

void MainWindow::db_connect() {
    db.setHostName(DB_HOST);
    db.setDatabaseName(DB_NAME);
    db.setPort(DB_PORT);
    db.setUserName(DB_USERNAME);
    db.setPassword(DB_PASSWORD);
    db.open();
}

void MainWindow::db_init_queries() {
    register_query.prepare("INSERT INTO users (first_name, last_name, user_name, user_email, user_password_hash) "
                           "VALUES ( :first_name, :last_name, :user_name, :user_email, :user_password_hash)");
    db_fetch_query.exec("SELECT user_name, user_email FROM users") ? qDebug() << "Fetched database successfully" :
        qDebug() << "Error while fetching database";
    while (db_fetch_query.next()) {
        existingUsernames.insert(db_fetch_query.value(0).toString());
        existsingEmails.insert(db_fetch_query.value(1).toString());
    }
    login_query_username.prepare("SELECT user_password_hash FROM users WHERE user_name = :user_name");
    
    login_query_email.prepare("SELECT user_password_hash FROM users WHERE user_email = :user_email");

}