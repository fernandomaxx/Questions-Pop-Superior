#include <iostream>
#include <map>

int main()
{
    int n;
    double size;
    std::string name;
    std::cin >> n;
    getchar();

    for (int i = 0; i <= n; ++i) {
        size = 0;
        std::map<std::string, int> mapa;
        while(std::getline(std::cin, name)) {

            if (name == "") {
                break;
            }

            size++;
            auto it = mapa.find(name);

            if (it != mapa.end())
            {
                it->second++;
                continue;
            }

            mapa.insert(mapa.begin(), std::make_pair(name, 1));
        }

        for (auto it = mapa.begin(); it != mapa.end() ; ++it) {
            printf("%s %.4f\n", it->first.c_str(), (it->second/size)*100);
        }
        if (i != 0 and i != n)
            std::cout << std::endl;
    }
}