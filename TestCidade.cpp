#include "gtest/gtest.h"
#include "Cidade.hpp"

TEST(CidadeTest, GetNome) {
    Cidade cidade("São Paulo");
    EXPECT_EQ(cidade.getNome(), "São Paulo");
}
