#ifndef LSP_PROBLEM_HPP
#define LSP_PROBLEM_HPP

#include <type_traits>
#include <concepts>

namespace concepts
{

template <typename T>
concept number = std::is_arithmetic_v<T>;

template <typename TPose, typename TNum>
concept pose2d = number<TNum> &&
    requires(TPose pose, TNum num) {
        { pose.x() } -> std::convertible_to<TNum>;
        { pose.y() } -> std::convertible_to<TNum>;
        { pose.theta() } -> std::convertible_to<TNum>;
        pose.x(num);
        pose.y(num);
        pose.theta(num);
    };

template <
    typename TRectangle,
    typename TPose,
    typename TNum
>
concept rectangle = pose2d<TPose, TNum> && 
    requires(TRectangle rect, TPose pose, TNum num) {
        { rect.origin() } -> std::convertible_to<TPose>;
        { rect.width() } -> std::convertible_to<TNum>;
        { rect.height() } -> std::convertible_to<TNum>;
        rect.origin(pose);
        rect.width(num);
        rect.height(num);
    };

template <
    typename TSquare,
    typename TPose,
    typename TNum
>
concept square = rectangle<TSquare, TPose, TNum>;

} // namespace concepts

namespace geom
{

class pose2d {
    double x_{}, y_{}, theta_{};

public:
    constexpr double x() const noexcept { return x_; }
    constexpr double y() const noexcept { return y_; }
    constexpr double theta() const noexcept { return theta_; }
    constexpr void x(double val) noexcept { x_ = val; }
    constexpr void y(double val) noexcept { y_ = val; }
    constexpr void theta(double val) noexcept { theta_ = val; }
};

class rectangle {
    pose2d origin_;
    double height_{1.}, width_{1.};

public:
    constexpr pose2d origin() const noexcept { return origin_; }
    constexpr double width() const noexcept { return width_; }
    constexpr double height() const noexcept { return height_; }
    constexpr void origin(pose2d pose) noexcept { origin_ = pose; }
    constexpr void width(double val) noexcept { width_ = val; }
    constexpr void height(double val) noexcept { height_ = val; }
};

class square : public rectangle {};

}

#endif