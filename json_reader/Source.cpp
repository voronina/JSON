
#include "Header.h"


void main(void)
{
	//const char* json = "{\"a\":1}";
	const char* json = "{ \"k1\":\"v1\", \"k2\" : 42, \"k3\" : [1,2,3,4,true] }";

	ifstream myfile("json.txt");

	picojson::value v;
	std::string err;

	/*if (myfile.is_open())
	{
		myfile >> v;
		myfile.close();
	}*/

	const char* json_end = picojson::parse(v, json, json + strlen(json), &err);

	if (!err.empty()) 
	{
		std::cerr << err << std::endl;
	}

	cout << v << endl;

	// check if the type of the value is "object"
	if (!v.is<picojson::object>()) {
		std::cerr << "JSON is not an object" << std::endl;
		exit(2);
	}
	
	// obtain a const reference to the map, and print the contents
	const picojson::value::object& obj = v.get<picojson::object>();
	std::string a;
	double d;

	for (picojson::value::object::const_iterator i = obj.begin();	i != obj.end();	++i) 
	{
		std::cout << i->first << ": " << i->second << std::endl;
		a = i->second.to_str();
	}

	/*d = std::stod(a);
	cout << d << endl;*/

	system("pause");
}
