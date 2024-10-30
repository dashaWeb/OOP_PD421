#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Engine {
public:
	Engine(const string& model, const size_t& power, const double& volume)
		: model{ model }, power{ power }, volume{volume}
	{

	}
	Engine() = default;
	void print() const;
private:
	string model = "nomodel";
	size_t power = 0;
	double volume = 0;
};
inline void Engine::print() const
{
	cout << "Engine model :: " << model << "\t power :: " << power << "\t volume :: " << volume << endl;
}