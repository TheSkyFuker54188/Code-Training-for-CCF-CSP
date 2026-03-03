#include <stdio.h>
#include <algorithm>
#include <vector>
#include <functional>
#include <cmath>
#include <climits> 
#include <stdint.h>

typedef long long ll;
#define MAXN 300000

// 全局配置
struct Config
{
    ll n, m;
    std::vector<ll> efficiency;  
    std::vector<ll> performance; 
} cfg;

// 辅助函数 - 计算向上取整
inline ll round_up(ll x, ll y)
{
    return y == 0 ? 0 : (x + y - 1) / y;
}

// 策略接口
class Strategy
{
public:
    virtual ll compute(ll val, ll eff, ll perf) = 0;
};

// 高效率策略
class HighEfficiencyStrategy : public Strategy
{
public:
    ll compute(ll val, ll eff, ll perf) override
    {
        return round_up(val, eff);
    }
};

// 高性能策略
class HighPerformanceStrategy : public Strategy
{
public:
    ll compute(ll val, ll eff, ll perf) override
    {
        return round_up(val, perf);
    }
};

// 混合策略
class HybridStrategy : public Strategy
{
public:
    ll compute(ll val, ll eff, ll perf) override
    {
        return cfg.m + round_up(val - cfg.m * eff, perf);
    }
};

// 策略选择器
ll select_best_strategy(ll req_val, ll eff_val, ll perf_val)
{
    // 特殊情况处理
    if (eff_val == 0 && perf_val == 0)
        return LLONG_MAX; 

    // 初始化策略对象
    static HighEfficiencyStrategy eff_strat;
    static HighPerformanceStrategy perf_strat;
    static HybridStrategy hybrid_strat;

    // 决定使用哪个策略
    if (perf_val >= eff_val)
    {
        return perf_strat.compute(req_val, eff_val, perf_val);
    }

    if (perf_val == 0)
    {
        return eff_strat.compute(req_val, eff_val, perf_val);
    }

    if (cfg.m * eff_val >= req_val)
    {
        return eff_strat.compute(req_val, eff_val, perf_val);
    }

    return hybrid_strat.compute(req_val, eff_val, perf_val);
}

// 资源计算器
class ResourceCalculator
{
private:
    ll target;

public:
    ResourceCalculator(ll t) : target(t) {}

    __int128_t calculate_total()
    {
        __int128_t total = 0;
        for (size_t i = 0; i < cfg.n; i++)
        {
            total += select_best_strategy(target, cfg.efficiency[i], cfg.performance[i]);
        }
        return total;
    }
};

// 二分查找最优解
ll binary_search_solution(ll left_bound, ll right_bound)
{
    if (right_bound - left_bound <= 1)
        return left_bound;
    ll mid_point = left_bound + ((right_bound - left_bound) >> 1);
    ResourceCalculator calculator(mid_point);
    return (calculator.calculate_total() <= (__int128_t)cfg.m * cfg.n) ? binary_search_solution(mid_point, right_bound) : binary_search_solution(left_bound, mid_point);
}

ll upper_bound()
{
    ll max_val = 0;
    for (ll val : cfg.efficiency)
        if (val > max_val)
            max_val = val;
    for (ll val : cfg.performance)
        if (val > max_val)
            max_val = val;
    return max_val * cfg.m;
}

int main()
{
    // 处理scanf的返回值
    int read_status;
    read_status = scanf("%lld%lld", &cfg.n, &cfg.m);

    cfg.efficiency.resize(cfg.n);
    cfg.performance.resize(cfg.n);

    for (ll i = 0; i < cfg.n; i++)
        read_status = scanf("%lld", &cfg.efficiency[i]);

    for (ll i = 0; i < cfg.n; i++)
        read_status = scanf("%lld", &cfg.performance[i]);

    printf("%lld\n", binary_search_solution(0, upper_bound() + 1));
    return 0;
}
