#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <optional>
#include <span>

//sum_two
std::optional<std::pair<int, int> > sum_two(const std::span<std::pair<int, int> > &a, const int target_sum) {
    const int N = a.size();

    int rpnt = N - 1;
    for (int i = 0; i < N; i++) {
        while (rpnt > i && a[i].first + a[rpnt].first > target_sum)
            rpnt--;

        if (rpnt <= i)
            break;

        if (a[rpnt].first + a[i].first == target_sum)
            return std::optional(std::make_pair(a[i].second, a[rpnt].second));
    }
    return std::nullopt;
}

std::optional<std::tuple<int, int, int> > sum_three(const std::span<std::pair<int, int> > &a, const int target_sum) {
    const int N = a.size();
    int X = target_sum;

    for (int j = 0; j < N; j++) {
        X -= a[j].first;
        int rpnt = N - 1;
        for (int i = j + 1; i < N; i++) {
            while (rpnt > i && a[i].first + a[rpnt].first > X)
                rpnt--;

            if (rpnt <= i)
                break;

            if (a[rpnt].first + a[i].first == X)
                return std::optional(std::make_tuple(a[j].second, a[i].second, a[rpnt].second));
        }
        X += a[j].first;
    }
    return std::nullopt; // No solution found
}

std::optional<std::tuple<int, int, int, int> >
sum_four(const std::span<std::pair<int, int> > &a, const int target_sum) {
    const int N = a.size();
    if (N < 4)
        return std::nullopt;

    for (int i = 0; i < N / 2; i++) {
        for (int j = i + 1; j < N / 2; j++) {
            if (auto second_half = sum_two(a.subspan(N / 2, N - N / 2), target_sum - a[i].first - a[j].first);
                second_half.has_value()) {
                return std::optional(std::make_tuple(a[i].second, a[j].second, second_half->first,
                                                     second_half->second));
            }
        }
    }

    for (int i = 0; i < N / 2; i++) {
        if (auto second_half = sum_three(a.subspan(N / 2, N - N / 2), target_sum - a[i].first); second_half.
            has_value()) {
            return std::optional(std::make_tuple(a[i].second, std::get<0>(*second_half), std::get<1>(*second_half),
                                                 std::get<2>(*second_half)));
        }
    }

    for (int i = N / 2; i < N; i++) {
        if (auto first_half = sum_three(a.subspan(0, N / 2), target_sum - a[i].first); first_half.has_value()) {
            return std::optional(std::make_tuple(std::get<0>(*first_half), std::get<1>(*first_half),
                                                 std::get<2>(*first_half), a[i].second));
        }
    }

    auto first_half = sum_four(a.subspan(0, N / 2), target_sum);
    if (first_half.has_value())
        return first_half;
    auto second_half = sum_four(a.subspan(N / 2, N - N / 2), target_sum);
    if (second_half.has_value())
        return second_half;
    return std::nullopt;
}

int main() {
    int N, target_sum;
    std::cin >> N >> target_sum;

    std::vector<std::pair<int, int> > a(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i].first;
        a[i].second = i + 1;
    }
    std::ranges::sort(a);

    const std::span<std::pair<int, int> > range(a);
    if (const auto ans = sum_four(range, target_sum); ans.has_value())
        std::cout << std::get<0>(*ans) << " " << std::get<1>(*ans) << " " << std::get<2>(*ans) << " " << std::get<
            3>(*ans) << "\n";
    else
        std::cout << "IMPOSSIBLE\n";
    return 0;
}
