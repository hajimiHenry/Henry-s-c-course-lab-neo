#include <stdio.h>

/* 家用：只用电价 + 1% 服务费（在电费上按“分”四舍五入） */
static int home_elec_price_fen(int p) {
    if (p == 0) return 81; /* 高峰 */
    if (p == 1) return 50; /* 平段 */
    return 27;             /* 低谷 */
}

/* 充电站：电价模式为“服务费 + 管理费”，不再单独收 0.81/0.5/0.27 的电费 */
static int station_service_price_fen(int p) {
    if (p == 0) return 150; /* 高峰 */
    if (p == 1) return 100; /* 平段 */
    return 70;              /* 低谷 */
}

static int station_manage_price_fen(int u) {
    if (u == 1) return 10; /* 钻级 */
    if (u == 2) return 20; /* 星级 */
    return 30;             /* 普通 */
}

int main(void) {
    int T, P, U, N;

    if (scanf("%d%d", &T, &P) != 2) {
        return 0;
    }

    if (T == 1) {
        /* 家用：输入格式 T P N */
        if (scanf("%d", &N) != 1) {
            return 0;
        }

        int price_fen = home_elec_price_fen(P);
        long long elec_fen = 1LL * N * price_fen;

        /* 1% 服务费，按“分”四舍五入：round(elec_fen / 100.0) */
        long long service_fen = (elec_fen + 50) / 100;
        long long total_fen = elec_fen + service_fen;

        printf("%.2f", total_fen / 100.0);
    } else if (T == 2) {
        /* 充电站：输入格式 T P U N */
        if (scanf("%d%d", &U, &N) != 2) {
            return 0;
        }

        int service_price_fen = station_service_price_fen(P);
        int manage_price_fen = station_manage_price_fen(U);

        long long total_fen = 1LL * N * (service_price_fen + manage_price_fen);
        printf("%.2f", total_fen / 100.0);
    }

    return 0;
}
