int main() {
    string in;
    bool flag = false;


    while (getline(cin, in)) {
        if (flag)
            printf("\n");
        multimap <int, int> mm;
        int arr[128] = {0};

        for (int i = 0; i < in.size(); ++i) {
            arr[in[i]]++;
        }

        for (int j = 127; j > 29; --j) {
            if (arr[j] > 0) {
                mm.insert(pair<int, int>(arr[j], j));
            }
        }

        auto it = mm.begin();

        for (;it != mm.end() ; it++) {
            cout << it->second << " " << it->first << endl;
        }
        flag = true;
    }
}