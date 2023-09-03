/*
 * Copyright © 2022 Tim Herreijgers
 * Licensed using the MIT license
 */

#include "x64_generation.h"

namespace TimC::Generation
{

std::unique_ptr<AssemblyProgram> X64Generation::generateAssembly(const Parser::AbstractSyntaxTree::ProgramNode &programNode)
{
    auto assemblyProgram = std::make_unique<AssemblyProgram>();

    for(const auto & baseContent : programNode.content)
    {
        struct ProgramNodeVisitor
        {
            explicit ProgramNodeVisitor(AssemblyProgram & assemblyProgram): m_assemblyProgram(assemblyProgram) {}

            void operator()(const Parser::AbstractSyntaxTree::AssignmentNode & /*node*/)
            {
                throw std::runtime_error("Not implemented!");
            }

            void operator()(const Parser::AbstractSyntaxTree::FunctionDeclarationNode & node)
            {
                m_assemblyProgram.addGlobalFunction(node.functionName);
                m_assemblyProgram.addInstruction("main:");
                m_assemblyProgram.addInstruction("\tpush rbp");
                m_assemblyProgram.addInstruction("\tmov rbp, rsp");
                m_assemblyProgram.addInstruction("\tmov rax, 0");
                m_assemblyProgram.addInstruction("\tpop rbp");
                m_assemblyProgram.addInstruction("\tret");

            }

        private:
            AssemblyProgram & m_assemblyProgram;
        };

        std::visit(ProgramNodeVisitor(*assemblyProgram), baseContent);
    }

    return assemblyProgram;
}

} // namespace TimC::Generation