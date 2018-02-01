#include <cppast/cpp_access_specifier.hpp>
#include <cppast/cpp_entity_kind.hpp>

using namespace cppast;

const char* cppast::to_string(cpp_access_specifier_kind access) noexcept
{
    switch (access)
    {
    case cpp_access_specifier_kind::cpp_public:
        return "public";
    case cpp_access_specifier_kind::cpp_protected:
        return "protected";
    case cpp_access_specifier_kind::cpp_private:
        return "private";
    }

    return "should not get here either";
}

cpp_entity_kind cpp_access_specifier::kind() noexcept
{
    return cpp_entity_kind::access_specifier_t;
}

cpp_entity_kind cpp_access_specifier::do_get_entity_kind() const noexcept
{
    return kind();
}
