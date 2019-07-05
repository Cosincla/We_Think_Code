#include <iostream>
#include <stdlib.h>

struct Data {
    std::string s1;
    int n;
    std::string s2;
};
void *serialize(){
    char *c = new char[20];
    for (int i = 0; i < 20; i++){
        if (i < 8 || i > 11)
            c[i] = rand() % 26 + 'a';
        else
            c[i] = rand() % 256;
    }
    c[20] = '\0';
    return (c);
}
Data *deserialize(void *raw){
    Data *data = new Data;
    for (int i = 0; i < 20; i++){
            if (i < 8)
                data->s1 += *(reinterpret_cast<char *>(raw) + i);
            else if (i > 11)
                data->s2 += *(reinterpret_cast<char *>(raw) + i);
    }
    data->n = *(reinterpret_cast<int *>(raw) + 2);
    return data;
}

int main(){
    srand(time(NULL));
    void *v = serialize();
    std::cout << "THIS IS THE SERIALIZED CRAP: " << reinterpret_cast<char *>(v) << std::endl;
    Data *data = deserialize(v);
    std::cout << "THIS IS THE FIRST STRING: " << data->s1 << std::endl;
    std::cout << "THIS IS THE INT: " << data->n << std::endl;
    std::cout << "THIS IS THE SECOND STRING: " << data->s2 << std::endl;
    delete data;
    return 0;
}