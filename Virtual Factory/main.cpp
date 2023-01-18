#include <iostream>
struct AnimalInterface {
	virtual void AnimalSound() = 0;
};
struct Dog :public AnimalInterface {
	virtual void AnimalSound() override {
		std::cout << "Bark!\n";

	}
};
struct Cow :public AnimalInterface {
	virtual void AnimalSound() override {
		std::cout << "Moo!\n";

	}
};
struct Cat :public AnimalInterface {
	virtual void AnimalSound() override {
		std::cout << "Meow!\n";

	}
};



class AnimalFactory {
private:
	std::unique_ptr<AnimalInterface> Animal;
public:
	enum {
		COW,
		CAT,
		DOG
	};

	AnimalFactory(int type) {
		if (type == COW) {
			Animal = std::make_unique<Cow>();
		}
		if (type == CAT) {
			Animal = std::make_unique<Cat>();
		}
		if (type == DOG) {
			Animal = std::make_unique<Dog>();

		}
	}
	AnimalInterface* GetAnimal() {
		return Animal.get();
	}
	~AnimalFactory() {
		Animal.release();
	}

};



int main(void) {
	AnimalFactory Animal(AnimalFactory::CAT);
	Animal.GetAnimal()->AnimalSound();


}