#ifndef CRTP_HPP
#define CRTP_HPP

template <
    typename TDerived,
    template<typename> typename TBase
>
struct crtp {
    constexpr TDerived& underlying() noexcept { return static_cast<TDerived&>(*this); }
    constexpr const TDerived& underlying() const noexcept { return static_cast<const TDerived&>(*this); }

private:
    constexpr crtp() = default;
    friend TBase<TDerived>;
};

#endif