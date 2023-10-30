#include <Serializer.hpp>
#include <Data.hpp>
	
int main()
{
	std::string name = "carl";
	Data a(name);
	std::cout << "original: " << &a << std::endl;
	std::cout << "serialized: " << Serializer::serialize(&a) << std::endl;
	std::cout << "deserialized: " << Serializer::deserialize(Serializer::serialize(&a)) << std::endl;
}
