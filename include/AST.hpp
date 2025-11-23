#pragma once
#include<string>
#include<memory>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual std::string toString() const = 0;
};

class NumNode : public ASTNode {
    double val;
public:
    NumNode(double val);
    std::string toString() const override;
};

class VarNode : public ASTNode {
    std::string name;
public:
    VarNode(const std::string& s);
    std::string toString() const override;
};

class BinaryOpsNode : public ASTNode {
    std::string op;
    std::shared_ptr<ASTNode> left;
    std::shared_ptr<ASTNode> right;
public:
    BinaryOpsNode(const std::string& op, std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right);
    std::string toString() const override;
};

class UnaryOpsNode : public ASTNode {
    std::string op;
    std::shared_ptr<ASTNode> child;
public:
    UnaryOpsNode(const std::string& op, std::shared_ptr<ASTNode> child);
    std::string toString() const override;
};