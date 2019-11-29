#ifndef DI_CONCEPTS_HPP
#define DI_CONCEPTS_HPP

#include <concepts>

namespace concepts {

template <
    typename TClient,
    typename TRequest,
    typename TResponse
>
concept http_client = requires(TClient client, TRequest request) {
    { client.send(request) } -> std::convertible_to<TResponse>;
};

template <
    typename TFormatter,
    typename TYaml,
    typename TString
>
concept yaml_formatter = requires(TFormatter format, TYaml yaml_object, TString string) {
    { format.serialize(yaml_object) } -> std::convertible_to<TString>;
    { format.deserialize(string) } -> std::convertible_to<TYaml>;
};

template <
    typename TStorage,
    typename TRecordSet,
    typename TString,
    typename... TArgs
>
concept database = requires(TStorage persistence, TString sql, TArgs&&... args) {
    { persistence.query(sql, std::forward<TArgs>(args)...) } -> std::convertible_to<TRecordSet>;
};

}

#endif