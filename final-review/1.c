#include <stdio.h>

/* 家用电价：单位“分/度” */
int home_price_fen(int p) {
    if (p == 0) return 81;  /* 高峰期 0.81 元 */
    if (p == 1) return 50;  /* 平段 0.50 元 */
    return 27;              /* 低谷 0.27 元 */
}

/* 充电站服务费：单位“分/度” */
int station_service_price_fen(int p) {
    if (p == 0) return 150; /* 高峰 1.5 元 */
    if (p == 1) return 100; /* 平段 1.0 元 */
    return 70;              /* 低谷 0.7 元 */
}

/* 充电站管理费：单位“分/度” */
int station_manage_price_fen(int u) {
    if (u == 1) return 10;  /* 钻级 0.1 元 */
    if (u == 2) return 20;  /* 星级 0.2 元 */
    return 30;              /* 普通 0.3 元 */
}

int main(void) {
    int T, P, U, N;

    if (scanf("%d%d", &T, &P) != 2) return 0;

    long long total_fen = 0;

    if (T == 1) {
        /* 家用：输入格式 T P N */
        if (scanf("%d", &N) != 1) return 0;

        int price_fen = home_price_fen(P);
        long long elec_fen = 1LL * N * price_fen;

        /* 1% 服务费：在“分”上四舍五入 */
        long long service_fen = (elec_fen + 50) / 100;
        total_fen = elec_fen + service_fen;
    } else if (T == 2) {
        /* 充电站：输入格式 T P U N */
        if (scanf("%d%d", &U, &N) != 2) return 0;

        int service_fen = station_service_price_fen(P);
        int manage_fen = station_manage_price_fen(U);

        /* 只收“服务费 + 管理费” */
        total_fen = 1LL * N * (service_fen + manage_fen);
    } else {
        return 0;
    }

    printf("%.2f", total_fen / 100.0);
    return 0;
}
