
#include <progbase-cpp/net.h>
#include <progbase.h>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStringList>
#include <vector>
#include <iostream>

using namespace std;
using namespace progbase::net;


typedef struct {
  bool status;
  vector <std::string> *data;
  string error;
} ServerMessage;

void printVector(vector<std::string> *list){
    for(auto it = list->begin(); it != list->end(); it++){
        cout << *it << ", ";
    }

    cout << endl;
}

bool get_status(const QJsonObject &jsonObject){
    return jsonObject[QString::fromStdString("status")].toBool();
}

vector <std::string> * get_data(const QJsonObject &jsonObject){
    vector <string> *list = new vector<string>;
    QJsonArray jsonArray = jsonObject[QString::fromStdString("data")].toArray();
    int size = jsonArray.size();

    for(int i = 0; i < size; i++){
        list->push_back(jsonArray.at(i).toString().toStdString());
    }

    return list;
}


ServerMessage parse (const QString &jsonStr){
    ServerMessage message;
    QJsonDocument jsonDocument = QJsonDocument::fromJson(jsonStr.toUtf8());
    if(jsonDocument.isObject()){
        QJsonObject jsonObject = jsonDocument.object();
        message.status = get_status(jsonObject);
        if(message.status){
            vector <string> * dataList = new vector <string>;
            QJsonArray jsonArray = jsonObject[QString::fromStdString("data")].toArray();
            int size = jsonArray.size();

            for(int i = 0; i < size; i++){
                dataList->push_back(jsonArray.at(i).toString().toStdString());
            }

            message.data = dataList;
            message.error = "";
        } else{
            message.error = jsonObject[QString::fromStdString("error")].toString().toStdString();
            message.data = NULL;
        }
    }
    return message;
}

void printMessage(ServerMessage &message){
    if(message.status){
        cout << "Дані були успішно отримані" << endl;
        printVector(message.data);

        cout << endl;
    } else{
        cout << "Сталася помилка" << endl;
        cout << "Повідомлення про помилку: " << message.error << endl;
    }
}

void deleteWords(vector<std::string> *list){
    cout << endl << "Залишити у векторі тільки ті строки, довжина яких менша 6." << endl;
    for(auto it =list->begin(); it != list->end(); it++){
        if((*it).size() >= 6){
            list->erase(it);
            it--;
        }
    }
}

int main()
{
    string jsonStr = "";
    TcpClient client;
        NetMessage message(100);
        cout << "Enter the string" << endl;
        string request = "";
        cin >> request;
        message.setDataString(request);
        try {
            client.connect(IpAddress("127.0.0.1", 9997));
            client.send(message);
            cout << ">> Request sent" << endl;
            do {
                client.receive(message);
                std::string str = message.dataAsString();
                cout << ">> Received " << str.length() << " bytes: " << endl << str << endl;
                jsonStr += str;
            } while (!message.isEmpty());
        } catch(NetException const & exc) {
            cerr << exc.what() << endl;
        }

    ServerMessage serverMsg = parse(QString::fromStdString(jsonStr));
    printMessage(serverMsg);

    if(serverMsg.data != NULL){
        deleteWords(serverMsg.data);
        printVector(serverMsg.data);

        delete serverMsg.data;
    }


    return 0;
}
