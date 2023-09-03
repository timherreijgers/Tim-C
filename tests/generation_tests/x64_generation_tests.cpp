/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "generation/generation_factory.h"

#include "parser/abstract_syntax_tree/program_node.h"

#include <gtest/gtest.h>
#include <string>

namespace TimC::Generation
{

class X64GenerationTests : public ::testing::Test
{
protected:
    void SetUp() override
    {
        m_generation = GenerationFactory().getGenerationForArchitecture(Architecture::X64);
    }

    std::unique_ptr<IGeneration> m_generation;
};

//TEST_F(X64GenerationTests, EmptyMainASTGeneratesCorrectAssembly)
//{
//    using namespace Parser::AbstractSyntaxTree;
//
//    FunctionDeclarationNode main{};
//    main.functionName = "main";
//    main.returnType = "int64";
//
//    ProgramNode programNode{};
//    programNode.content.push_back(main);
//
//    const auto assembly = m_generation->generateAssembly(programNode);
//
//    ASSERT_EQ(assembly, "global main\n"
//                        "\n"
//                        "main:\n"
//                        "\tpush rbp\n"
//                        "\tmov rbp, rsp\n"
//                        "\tmov aex, 0\n"
//                        "\tleave"
//                        "\tret\n");
//}

} // namespace TimC::Lexer