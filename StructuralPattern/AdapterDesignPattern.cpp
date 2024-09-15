class Output {
public:
	virtual void getOutput() {
		std::cout << "Default output" << std::endl;
	}
};

class ThirdParty {
public:
	void getData() {
		std::cout << " Default worst behaviour of 3rd party code" << std::endl;
	}
};

class Adapter : public Output {
private:
	ThirdParty* m_thirdparty;
public:
	Adapter(ThirdParty* pthirdparty) {
		this->m_thirdparty = pthirdparty;
	}
	void getOutput() override {
		// Fetching data from third party
		m_thirdparty->getData();

		// conversion methods
		std::cout << " Conversion happened : Adapter output" << std::endl;
	}
};