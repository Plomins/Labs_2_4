
#include "file_utils.h"

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Russian");

    if (argc < 2) {
        printf("�������������: %s <���_�����>\n", argv[0]);
        return 1;
    }

    maintask(argv[1]);
    return 0;
}
