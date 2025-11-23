#include "AST.hpp"
#include <sstream>

NumNode::NumNode(double v) \
    : val(v) {}

std::string NumNode::toString() const {
    std::ostringstream out;
    out << val;
    return out.str();
}

VarNode::VarNode(const std::string& x) \
    : name(x) {}

std::string VarNode::toString() const {
    std::ostringstream out;
    out << name;
    return out.str();
}

UnaryOpsNode::UnaryOpsNode(const std::string& op, std::shared_ptr<ASTNode> child)
    : op(op), child(child) {}

std::string UnaryOpsNode::toString() const {
    std::ostringstream out;
    out << "(" + op + " " + child->toString() + ")";
    return out.str();
}

BinaryOpsNode::BinaryOpsNode(const std::string& op, std::shared_ptr<ASTNode> left, std::shared_ptr<ASTNode> right)
    : op(op), left(left), right(right) {}

std::string BinaryOpsNode::toString() const {
    std::ostringstream out;
    out << "(" << left->toString() << " " << op << " " << right->toString() << ")";
    return out.str();
}