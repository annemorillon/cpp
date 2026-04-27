#include "Serializer.hpp"

int main(void)
{
    // --- Création d'un objet Data ---
    Data  data;
    data.nb = 42;
    data.name  = "Hello 42";

    // --- Pointeur original ---
    Data* ptr = &data;

    // --- Sérialisation ---
    uintptr_t raw = Serializer::serialize(ptr);

    // --- Désérialisation ---
    Data* result = Serializer::deserialize(raw);

    // --- Vérification ---
    std::cout << "ptr     : " << ptr    << std::endl;
    std::cout << "result  : " << result << std::endl;
    std::cout << "equal?  : " << (ptr == result ? "YES ✓" : "NO ✗") << std::endl;
    std::cout << "value   : " << result->nb << std::endl;
    std::cout << "name    : " << result->name  << std::endl;

    return 0;
}