//TODO: &opt 的试验没成功

#include "iostream"
#include "boost/program_options.hpp"
//#include <iterator>
using namespace std;

// A helper function to simplify the main part.
template<class T>
ostream& operator<<(ostream& os, const vector<T>& v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(os, " "));
    return os;
}
//./main -Iqqq  -Iwww -Iwwwe -Iqwe

int main(int ac, char * av[]){
    boost::program_options::options_description desc("Allowed options");
    int opt;
    desc.add_options()
        ("help,h", "produce help message")
        ("compression,c", boost::program_options::value<int>(), "set compression level")
        ("optimization,o", boost::program_options::value<int>(&opt)->default_value(111),"optimization level")
        ("include-path,I", boost::program_options::value< std::vector<string> >(), "include path")
        ;

    boost::program_options::variables_map vm;
    try{
        boost::program_options::store(boost::program_options::parse_command_line(ac, av ,desc), vm);
    }
    catch(std::exception& e){
        std::cerr << "error:" << e.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "unknow exception \n";
        return 1;
    }

    if(vm.count("help")){
        std::cout << desc << std::endl;
        return 1;
    }

    size_t a = vm.count("compression");
    if(vm.count("compression")){
        std::cout << vm["compression"].as<int>() << std::endl;
    }else{
        std::cout << desc << std::endl;
    }

    if(vm.count("optimization")){
        std::cout << "the optimization input is:" << vm["optimization"].as<int>() << std::endl;
    }

    std::cout << "the int is : " << opt << "\n";
    if(vm.count("include-path")){
        //std::cout << vm["include-path"].as< std::vector<string> >()[0] << "\n";
        std::cout << "include path:" << vm["include-path"].as< std::vector<string> >() << "\n";
    }
    return 0;
}