#ifndef CPPAST_CPP_ACCESS_SPECIFIER_HPP_INCLUDED
#define CPPAST_CPP_ACCESS_SPECIFIER_HPP_INCLUDED

#include <cppast/cpp_entity.hpp>

namespace cppast {
    /// The C++ access specifiers.
    enum class cpp_access_specifier_kind : int
    {
        cpp_public,
        cpp_protected,
        cpp_private
    };

    /// \returns The access specifier keyword as a string.
    const char* to_string(cpp_access_specifier_kind access) noexcept;

    /// A [cppast::cpp_entity]() modelling a C++ access specifier.
    class cpp_access_specifier final : public cpp_entity
    {
    public:
        static cpp_entity_kind kind() noexcept;

        /// \returns A newly created access specifier.
        /// \notes It is not meant to be registered at the [cppast::cpp_entity_index](),
        /// as nothing can refer to it.
        static std::unique_ptr<cpp_access_specifier> build(cpp_access_specifier_kind kind)
        {
            return std::unique_ptr<cpp_access_specifier>(new cpp_access_specifier(kind));
        }

        /// \returns The kind of access specifier.
        cpp_access_specifier_kind access_specifier() const noexcept
        {
            return access_;
        }

    private:
        cpp_access_specifier(cpp_access_specifier_kind access)
        : cpp_entity(to_string(access)), access_(access)
        {
        }

        cpp_entity_kind do_get_entity_kind() const noexcept override;

        cpp_access_specifier_kind access_;
    };
}

#endif
