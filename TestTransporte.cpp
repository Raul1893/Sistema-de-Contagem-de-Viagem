#include "gtest/gtest.h"
#include "Transporte.hpp"
#include "Cidade.hpp"

TEST(TransporteTest, GetNome) {
    Cidade cidade("Rio de Janeiro");
    Transporte transporte("Ônibus", 'T', 50, 60, 200, 2, &cidade);
    EXPECT_EQ(transporte.getNome(), "Ônibus");
}
