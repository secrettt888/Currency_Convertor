#include <stdio.h>

// Function prototypes
float sell(float e, float u, float g, float r, int x, float y);
float buy(float e, float u, float g, float r, int x, float y);
float calculator(int b, int vi, int vf, float y);
float vals(int currency_idx, int day_idx);
float valp(int currency_idx, int day_idx);
float general(float ec, float uc, float gc, float r, float ev, float uv, float gv, int vi, int vf, float y);

int main() {
    float s;
    int i, f, b, ok;
   
    const char* day[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

    for (b = 0; b <= 6; b++) {
        printf("\nWhat sum do you wish to convert?\n");
        scanf("%f", &s);
        
        printf("\nFrom what currency do you wish to convert the sum?\n(1-ron, 2-eur, 3-gbp, 4-usd)\n");
        scanf("%d", &i);
        
        printf("\nIn what currency do you wish to convert this sum?\n(1-ron, 2-eur, 3-gbp, 4-usd)\n");
        scanf("%d", &f);
        
        printf("\nSum converted for %s is %.2f\n", day[b], calculator(b, i, f, s));

        int m = 0;
        while (m == 0) {
            printf("\nDo you wish to exchange a sum for the next day? 1-yes, 2-no\n");
            scanf("%d", &ok);
            if (ok == 2) {
                b = 7; // Break the outer loop
                m = 1;
            } else if (ok != 1) {
                printf("Please re-enter your answer.\n");
            } else {
                m = 1;
            }
        }
    }
    return 0;
}

float calculator(int b, int vi, int vf, float y) {
    float suma;
    float ec, uc, gc, r, uv, ev, gv;

    // Mapping: 0: EUR, 1: GBP, 2: USD
    ev = vals(0, b); // EUR Sell
    gv = vals(1, b); // GBP Sell
    uv = vals(2, b); // USD Sell
    
    ec = valp(0, b); // EUR Buy
    gc = valp(1, b); // GBP Buy
    uc = valp(2, b); // USD Buy
    
    r = 1.0;

    if (vi == 1) {
        suma = buy(ec, uc, gc, r, vf, y);
    } else {
        if (vf == 1) {
            suma = sell(ev, uv, gv, r, vi, y);
        } else if (vi > 4 || vf > 4 || vi < 1 || vf < 1) { 
            printf("!!!ERROR!!! Invalid currency selection.\n");
            suma = 0;
        } else {
            suma = general(ec, uc, gc, r, ev, uv, gv, vi, vf, y);
        }
    }
    return suma;
}

float general(float ec, float uc, float gc, float r, float ev, float uv, float gv, int vi, int vf, float y) {
    if (vi != vf) {
        return buy(ec, uc, gc, r, vf, sell(ev, uv, gv, r, vi, y));
    }
    return y;
}

float sell(float e, float u, float g, float r, int x, float y) {
    if (x == 1) return y * r; // RON
    if (x == 2) return y * e; // EUR
    if (x == 3) return y * g; // GBP
    if (x == 4) return y * u; // USD
    
    printf("!!!ERROR!!!\n");
    return 0;
}

float buy(float e, float u, float g, float r, int x, float y) {
    if (x == 1) return y / r; // RON
    if (x == 2) return y / e; // EUR
    if (x == 3) return y / g; // GBP 
    if (x == 4) return y / u; // USD 
    
    printf("!!!ERROR!!!\n");
    return 0;
}

float vals(int currency_idx, int day_idx) {
    float matrix[7][3] = {
        {5.12,  5.942, 4.612},
        {5.23,  5.910, 4.593},
        {5.10,  5.922, 4.579},
        {5.042, 6.100, 4.603},
        {5.152, 6.200, 4.621},
        {5.20,  5.990, 4.640},
        {5.020, 5.980, 4.599}
    };
    return matrix[day_idx][currency_idx]; 
}

float valp(int currency_idx, int day_idx) {
    float matrix[7][3] = {
        {4.976, 5.737, 4.506},
        {4.970, 5.718, 4.4909},
        {4.974, 5.732, 4.478},
        {4.969, 5.727, 4.500},
        {4.971, 5.731, 4.511},
        {4.972, 5.738, 4.513},
        {4.975, 5.734, 4.514}
    };
    return matrix[day_idx][currency_idx]; 
}
