#include <stdio.h>

static double electricity_price(int time_segment) {
    if (time_segment == 0) return 0.81; /* 高峰 */
    if (time_segment == 1) return 0.50; /* 平段 */
    return 0.27;                        /* 低谷(含其它输入) */
}

static double service_price(int time_segment) {
    if (time_segment == 0) return 1.50; /* 高峰 */
    if (time_segment == 1) return 1.00; /* 平段 */
    return 0.70;                        /* 低谷(含其它输入) */
}

static double manage_price(int user_level) {
    if (user_level == 1) return 0.10; /* 钻级 */
    if (user_level == 2) return 0.20; /* 星级 */
    return 0.30;                      /* 普通(含其它输入) */
}

int main(void) {
    int type;
    if (scanf("%d", &type) != 1) return 0;

    double total = 0.0;

    if (type == 1) {
        int time_segment;
        double kwh;
        if (scanf("%d%lf", &time_segment, &kwh) != 2) return 0;

        double elec_cost = kwh * electricity_price(time_segment);
        double service_fee = 0.01 * elec_cost; /* 额外 1% 服务费 */
        total = elec_cost + service_fee;
    } else if (type == 2) {
        int time_segment, user_level;
        double kwh;
        if (scanf("%d%d%lf", &time_segment, &user_level, &kwh) != 3) return 0;

        double elec_cost = kwh * electricity_price(time_segment);
        double service_cost = kwh * service_price(time_segment);
        double manage_cost = kwh * manage_price(user_level);
        total = elec_cost + service_cost + manage_cost;
    } else {
        return 0;
    }

    printf("%.2f", total);
    return 0;
}

