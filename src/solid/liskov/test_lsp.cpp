#include "lsp_problem.hpp"

template <
    typename TPose = geom::pose2d,
    typename TNum = double
>
constexpr void double_width(concepts::rectangle<TPose, TNum> auto& rect) noexcept {
    const auto width = rect.width() * 2;
    rect.width(width);
}

void disaster() {
    geom::square square;
    double_width(square);
}