class Connection {
private:
	Connection() {
		std::cout << "New connection" << std::endl;
	};
	static Connection* m_conn;
public:
	static Connection *getInstance();
};

Connection* Connection::m_conn = nullptr;

Connection* Connection::getInstance() {
	if (m_conn != nullptr) {
		std::cout << "Already existing" << std::endl;
		return m_conn;
	}
	std::cout << "New instance" << std::endl;
	return m_conn = new Connection();
}

//int main() {
//Connection* conn1 = Connection::getInstance();
//Connection* conn2 = Connection::getInstance();
//return 0;
//}