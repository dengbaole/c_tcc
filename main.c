#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define SIZE 200 // 数组大小
#define MAX_VALUE 70 // 中间最大值
#define PI 3.14159265358979323846

void generateSPWMArray(uint16_t *spwmArray, int size) {
    for (int i = 0; i < size; i++) {
        // 计算正弦波值并映射到 0 到 MAX_VALUE 的范围
        spwmArray[i] = (uint16_t)((sin((-0.25*PI+(PI * i) / (size - 1))*2) * 0.5 + 0.5) * MAX_VALUE);
    }
}

int main(void) {
    uint16_t spwmWave[SIZE];

    generateSPWMArray(spwmWave, SIZE);

    // 打印生成的 SPWM 数组，以便复制
    printf("uint16_t spwmWave[%d] = {", SIZE);
    for (int i = 0; i < SIZE; i++) {
        printf("%u", spwmWave[i]);
        if (i < SIZE - 1) {
            printf(", ");
        }
    }
    printf("};\n");

    return 0;
}
