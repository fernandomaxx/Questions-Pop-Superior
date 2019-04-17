#include <iostream>
#include <map>

int main()
{
    int n, m, p;
    double value;
    std::string name;
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        double total = 0;
        std::map<std::string, double> mapa;
        std::cin >> m;
        for (int j = 0; j < m; ++j) {
            std::cin >> name;
            std::cin >> value;
            mapa.insert(mapa.begin(), std::make_pair(name, value));

        }

        std::cin >> p;

        for (int j = 0; j < p; ++j) {
            std::cin >> name;
            std::cin >> value;

            auto it = mapa.find(name);

            if ( it != mapa.end() )
            {
                total += value * it->second;
            }
        }

        printf("R$ %.2f\n", total);
    }
}