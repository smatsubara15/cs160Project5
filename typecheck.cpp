#include "typecheck.hpp"

// Defines the function used to throw type errors. The possible
// type errors are defined as an enumeration in the header file.
void typeError(TypeErrorCode code) {
  switch (code) {
    case undefined_variable:
      std::cerr << "Undefined variable." << std::endl;
      break;
    case undefined_method:
      std::cerr << "Method does not exist." << std::endl;
      break;
    case undefined_class:
      std::cerr << "Class does not exist." << std::endl;
      break;
    case undefined_member:
      std::cerr << "Class member does not exist." << std::endl;
      break;
    case not_object:
      std::cerr << "Variable is not an object." << std::endl;
      break;
    case expression_type_mismatch:
      std::cerr << "Expression types do not match." << std::endl;
      break;
    case argument_number_mismatch:
      std::cerr << "Method called with incorrect number of arguments." << std::endl;
      break;
    case argument_type_mismatch:
      std::cerr << "Method called with argument of incorrect type." << std::endl;
      break;
    case while_predicate_type_mismatch:
      std::cerr << "Predicate of while loop is not boolean." << std::endl;
      break;
    case do_while_predicate_type_mismatch:
      std::cerr << "Predicate of do while loop is not boolean." << std::endl;
      break;
    case if_predicate_type_mismatch:
      std::cerr << "Predicate of if statement is not boolean." << std::endl;
      break;
    case assignment_type_mismatch:
      std::cerr << "Left and right hand sides of assignment types mismatch." << std::endl;
      break;
    case return_type_mismatch:
      std::cerr << "Return statement type does not match declared return type." << std::endl;
      break;
    case constructor_returns_type:
      std::cerr << "Class constructor returns a value." << std::endl;
      break;
    case no_main_class:
      std::cerr << "The \"Main\" class was not found." << std::endl;
      break;
    case main_class_members_present:
      std::cerr << "The \"Main\" class has members." << std::endl;
      break;
    case no_main_method:
      std::cerr << "The \"Main\" class does not have a \"main\" method." << std::endl;
      break;
    case main_method_incorrect_signature:
      std::cerr << "The \"main\" method of the \"Main\" class has an incorrect signature." << std::endl;
      break;
  }
  exit(1);
}

// TypeCheck Visitor Functions: These are the functions you will
// complete to build the symbol table and type check the program.
// Not all functions must have code, many may be left empty.

void TypeCheck::visitProgramNode(ProgramNode* node) {
  // WRITEME: Replace with code if necessary
  this->classTable = new ClassTable;
  node->visit_children(this);
}

void TypeCheck::visitClassNode(ClassNode* node) {
  // WRITEME: Replace with code if necessary
  ClassInfo myInfo;
  currentMethodTable = NULL;
  currentVariableTable = new VariableTable;
  currentMemberOffset = 0;
  currentClassName = node->identifier_1->name;
  //visit the member declarations
  if(node->declaration_list){
    for(auto iter=node->declaration_list->begin(); iter!=node->declaration_list->end(); iter++){
    (*iter)->accept(this);
    }
  }
  //update member table ASAP for type checking in methods
  if(node->identifier_2){
    myInfo = {node->identifier_2->name, this->currentMethodTable, this->currentVariableTable};
  }
  else{
    myInfo = {"", this->currentMethodTable, this->currentVariableTable};
  }
  this->classTable->insert({node->identifier_1->name, myInfo});
  //update method table
  if(node->method_list){
    for(auto iter=node->method_list->begin(); iter!=node->method_list->end(); iter++){
      (*iter)->accept(this);
    }
  }
  this->classTable->find(currentClassName)->second.methods = currentMethodTable;
}

void TypeCheck::visitMethodNode(MethodNode* node) {
  /*
  create a MethodInfo struct and insert it into currentMethodTable
  */
  //save current metadata
  //MethodTable* savedMethodTable = currentMethodTable;
  VariableTable* savedVariableTable = currentVariableTable;
  if(!currentMethodTable)
  currentMethodTable =  new MethodTable();
  currentLocalOffset = -4;
  currentParameterOffset = 12;
  currentVariableTable = new VariableTable;
  //set parameter type, create variable list, set return type, set currentLocalOffset
  node->visit_children(this);
  node->basetype = node->type->basetype;
  node->objectClassName = node->type->objectClassName;
  //create parameter list from node->parameter_list, set currentParameterOffset
  std::list<CompoundType> *myParameters = new std::list<CompoundType>;
  for(auto iter=node->parameter_list->begin(); iter!=node->parameter_list->end(); iter++){
    myParameters->push_back({
      (*iter)->basetype,
      (*iter)->objectClassName
    });
  }
  MethodInfo myInfo = {
    {
      node->basetype,
      node->objectClassName
    },
    currentVariableTable,
    myParameters,
    -currentLocalOffset-4
  };
  currentMethodTable->insert({node->identifier->name, myInfo});
  //restore metadata
  //currentMethodTable = savedMethodTable;
  currentVariableTable = savedVariableTable;
}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
  /*
  populate currentVariableTable with declarations, set currentLocalOffset,
  set return type(MethodBodyNode type)
  */
  //populate currentVariableTable, set currentLocalOffset, set return type(ReturnStatementNode type)
  node->visit_children(this);
  //set return type(MethodBodyNode type)
  // node->basetype = node->returnstatement->basetype;
  // node->objectClassName = node->returnstatement->objectClassName;
}

void TypeCheck::visitParameterNode(ParameterNode* node) {
  /*
  insert current parameter info into currentVariableTable, increment currentParameterOffset
  */
  node->type->accept(this);
  VariableInfo myInfo = {
    {
      node->type->basetype,
      node->type->objectClassName
    },
    currentParameterOffset,
    4
  };
  currentParameterOffset += 4;
  currentVariableTable->insert({
    node->identifier->name,
    myInfo
  });
}

void TypeCheck::visitDeclarationNode(DeclarationNode* node) {
  /*
  insert current variables in declaration node into currentVariableTable, increment currentLocalOffset
  */
  //update basetype of type node
  node->type->accept(this);
  //get basetype from type node
  node->basetype = node->type->basetype;
  node->objectClassName = node->type->objectClassName;
  int offset;
  if(!currentMethodTable){
    offset = currentMemberOffset;
  }
  else{
    offset = currentLocalOffset;
  }
  for(auto iter=node->identifier_list->begin(); iter!=node->identifier_list->end(); iter++){
    VariableInfo myInfo = {
        {
          node->basetype,
          node->objectClassName
        },
        offset,
        4
      };
    this->currentVariableTable->insert({
      (*iter)->name,
      myInfo
    });
    if(!currentMethodTable){
      offset += 4;
    }
    else{
      offset -= 4;
    }
  }
  if(!currentMethodTable){
    currentMemberOffset = offset;
  }
  else{
    currentLocalOffset = offset;
  }
}

void TypeCheck::visitReturnStatementNode(ReturnStatementNode* node) {
  /*set up return type*/
  node->visit_children(this);
  node->basetype = bt_none;
  node->objectClassName = "";
  node->basetype = node->expression->basetype;
  node->objectClassName = node->expression->objectClassName;
}

void TypeCheck::visitAssignmentNode(AssignmentNode* node) {
  /*
  Undefined variable
  Not an object
  Undefined Member
  Undefined Class
  assignment type mismatch
  */
  // CompoundType assignee_type;
  // //first check for variable existance
  // node->identifier_1->accept(this);
  // //member access
  // if(node->identifier_2){
  //   //creat dummy member access node for type checking
  //   MemberAccessNode man = MemberAccessNode(node->identifier_1, node->identifier_2);
  //   man.accept(this);
  //   assignee_type = {
  //     man.basetype,
  //     man.objectClassName
  //   };
  // }
  // //straight forward variable
  // else{
  //   assignee_type = {
  //     node->identifier_1->basetype,
  //     node->identifier_1->objectClassName
  //   };
  // }
  // node->expression->accept(this);
  // CompoundType assigner_type = {
  //   node->expression->basetype,
  //   node->expression->objectClassName
  // };
  // if(assignee_type.baseType != assigner_type.baseType || 
  //   assignee_type.objectClassName != assigner_type.objectClassName)
  //   typeError(assignment_type_mismatch);
}

void TypeCheck::visitCallNode(CallNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitWhileNode(WhileNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitDoWhileNode(DoWhileNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitPrintNode(PrintNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitPlusNode(PlusNode* node) {
  node->visit_children(this);
  //Plus, Minus, Times, Divide, Negation all expect integer operands (two or one) and produce an integer.
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_integer;
    node->objectClassName = "";
  }
}

void TypeCheck::visitMinusNode(MinusNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_integer;
    node->objectClassName = "";
  }
}

void TypeCheck::visitTimesNode(TimesNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_integer;
    node->objectClassName = "";
  }
} 

void TypeCheck::visitDivideNode(DivideNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_integer;
    node->objectClassName = "";
  }
}

void TypeCheck::visitGreaterNode(GreaterNode* node) {
  //Greater and GreaterEqual expect two integer operands and produce a boolean.
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitGreaterEqualNode(GreaterEqualNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_integer || node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitEqualNode(EqualNode* node) {
  //Equal expects two operands of the same type, which must be both integer or both boolean.
  if(node->expression_1->basetype != node->expression_2->basetype){
    typeError(expression_type_mismatch);
  }
  else if(node->expression_1->basetype != bt_integer ^ node->expression_2->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else if(node->expression_1->basetype != bt_boolean ^ node->expression_2->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitAndNode(AndNode* node) {
  // And, Or, Not all expect boolean operands (two or one) and produce a boolean.
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitOrNode(OrNode* node) {
  node->visit_children(this);
  if(node->expression_1->basetype != bt_boolean || node->expression_2->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitNotNode(NotNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitNegationNode(NegationNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_integer){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_integer;
    node->objectClassName = "";
  }
}

void TypeCheck::visitMethodCallNode(MethodCallNode* node) {
  
}

void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
  /*
  Check for class and member existence
  */
  // //update identifier type
  // node->identifier_1->accept(this);
  // //member access
  // if(node->identifier_2){
  //   //variable is not an object
  //   if(node->identifier_1->basetype != bt_object)
  //     typeError(not_object);
  //   auto class_iter = this->classTable->find(node->identifier_1->objectClassName);
  //   //variable class not defined (could be redundant)
  //   if(class_iter == this->classTable->end())
  //     typeError(undefined_class);
  //   auto class_info = class_iter->second;
  //   //check base class first
  //   auto member_iter = class_info.members->find(node->identifier_2->name);
  //   //if not found, check superclass next
  //   if(member_iter == class_info.members->end()){
  //     //no superclass
  //     if(class_info.superClassName == "")
  //       typeError(undefined_member);
  //     class_iter = this->classTable->find(class_info.superClassName);
  //   }
  //   //super class does not exist either(could be redudant)
  //   if(class_iter == this->classTable->end())
  //     typeError(undefined_class);
  //   class_info = class_iter->second;
  //   member_iter = class_info.members->find(node->identifier_2->name);
  //   //superclass also doesn't contain member either
  //   if(member_iter == class_info.members->end())
  //     typeError(undefined_member);
  //   node->basetype = member_iter->second.type.baseType;
  //   node->objectClassName = member_iter->second.type.objectClassName;
  // }
}

void TypeCheck::visitVariableNode(VariableNode* node) {
  node->visit_children(this);
  node->basetype = node->identifier->basetype;
  node->objectClassName = node->identifier->objectClassName;

  // Variable and MemberAccess produce the type of the corresponding variable or member.

  // std::string var = node->identifier->name;
  // if(currentVariableTable->find(var)==currentVariableTable->end()){
  //   typeError(undefined_variable);
  // }
  // else{
  //   node->basetype = (*currentVariableTable)[var].type.baseType;
  //   node->objectClassName = (*currentVariableTable)[var].type.objectClassName;
  //   return;
  // }
  // if((*classTable)[currentClassName].members->find(var)==(*classTable)[currentClassName].members->end()){
  //   typeError(undefined_variable);
  // }
  // else{
  //   node->basetype = (*classTable)[currentClassName].members->operator[](var).type.baseType;
  //   node->basetype = (*classTable)[currentClassName].members->operator[](var).type.objectClassName;
  //   return;
  // }
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
  // WRITEME: Replace with code if necessary
  node->basetype = bt_integer;
  node->objectClassName = "";
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
  // WRITEME: Replace with code if necessary
  node->basetype = bt_boolean;
  node->objectClassName = "";
}

void TypeCheck::visitNewNode(NewNode* node) {
  // WRITEME: Replace with code if necessary
}

void TypeCheck::visitIntegerTypeNode(IntegerTypeNode* node) {
  node->basetype = bt_integer;
  node->objectClassName = "";
}

void TypeCheck::visitBooleanTypeNode(BooleanTypeNode* node) {
  node->basetype = bt_boolean;
  node->objectClassName = "";
}

void TypeCheck::visitObjectTypeNode(ObjectTypeNode* node) {
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
}

void TypeCheck::visitNoneNode(NoneNode* node) {
  node->basetype = bt_none;
  node->objectClassName = "";
}

void TypeCheck::visitIdentifierNode(IdentifierNode* node) {
  /*
  checks for existence of symbol in local space and class space (member)
  */
//   //check local variable first
//   auto var_iter = this->currentVariableTable->find(node->name);
//   if(var_iter == this->currentVariableTable->end()){
//       //check member list
//       var_iter = this->classTable->find(currentClassName)->second.members->find(node->name);
//       //member list does not contain symbol
//       if(var_iter == this->classTable->find(currentClassName)->second.members->end()){
//         typeError(undefined_variable);
//       }
//   }
//   node->basetype = var_iter->second.type.baseType;
//   node->objectClassName = var_iter->second.type.objectClassName;
}

void TypeCheck::visitIntegerNode(IntegerNode* node) {
}


// The following functions are used to print the Symbol Table.
// They do not need to be modified at all.

std::string genIndent(int indent) {
  std::string string = std::string("");
  for (int i = 0; i < indent; i++)
    string += std::string(" ");
  return string;
}

std::string string(CompoundType type) {
  switch (type.baseType) {
    case bt_integer:
      return std::string("Integer");
    case bt_boolean:
      return std::string("Boolean");
    case bt_none:
      return std::string("None");
    case bt_object:
      return std::string("Object(") + type.objectClassName + std::string(")");
    default:
      return std::string("");
  }
}


void print(VariableTable variableTable, int indent) {
  std::cout << genIndent(indent) << "VariableTable {";
  if (variableTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (VariableTable::iterator it = variableTable.begin(); it != variableTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << string(it->second.type);
    std::cout << ", " << it->second.offset << ", " << it->second.size << "}";
    if (it != --variableTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(MethodTable methodTable, int indent) {
  std::cout << genIndent(indent) << "MethodTable {";
  if (methodTable.size() == 0) {
    std::cout << "}";
    return;
  }
  std::cout << std::endl;
  for (MethodTable::iterator it = methodTable.begin(); it != methodTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    std::cout << genIndent(indent + 4) << string(it->second.returnType) << "," << std::endl;
    std::cout << genIndent(indent + 4) << it->second.localsSize << "," << std::endl;
    print(*it->second.variables, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --methodTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}";
}

void print(ClassTable classTable, int indent) {
  std::cout << genIndent(indent) << "ClassTable {" << std::endl;
  for (ClassTable::iterator it = classTable.begin(); it != classTable.end(); it++) {
    std::cout << genIndent(indent + 2) << it->first << " -> {" << std::endl;
    if (it->second.superClassName != "")
      std::cout << genIndent(indent + 4) << it->second.superClassName << "," << std::endl;
    print(*it->second.members, indent + 4);
    std::cout << "," << std::endl;
    print(*it->second.methods, indent + 4);
    std::cout <<std::endl;
    std::cout << genIndent(indent + 2) << "}";
    if (it != --classTable.end())
      std::cout << ",";
    std::cout << std::endl;
  }
  std::cout << genIndent(indent) << "}" << std::endl;
}

void print(ClassTable classTable) {
  print(classTable, 0);
}
