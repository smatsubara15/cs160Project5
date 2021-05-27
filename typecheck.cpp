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
  this->classTable = new ClassTable;
  node->visit_children(this);
  if(this->classTable->find("Main")==this->classTable->end()){
    typeError(no_main_class);
  }
  else if((*classTable)["Main"].members->size()!=0){
    typeError(main_class_members_present);
  }
  else if((*classTable)["Main"].methods->find("main")==(*classTable)["Main"].methods->end()){
    typeError(no_main_method);
  }
  else if((*classTable)["Main"].methods->operator[]("main").returnType.baseType != bt_none || (*classTable)["Main"].methods->operator[]("main").parameters->size()!=0){
    typeError(main_method_incorrect_signature);
  }
}
void TypeCheck::visitClassNode(ClassNode* node) {
  ClassInfo myInfo;
  currentClassName = node->identifier_1->name;
  currentMethodTable = NULL;
  currentMemberOffset = 0;
  //initialize variableTable
  currentVariableTable = new VariableTable;
  if(node->identifier_2){
    myInfo = {node->identifier_2->name, this->currentMethodTable, this->currentVariableTable};
  }
  else{
    myInfo = {"", this->currentMethodTable, this->currentVariableTable};
  }
  this->classTable->insert({node->identifier_1->name, myInfo});
  //visit the member declarations first
  //update member table ASAP for type checking
  if(node->declaration_list){
    for(auto iter=node->declaration_list->begin(); iter!=node->declaration_list->end(); iter++){
    (*iter)->accept(this);
    }
  }

  //initialize methodTable
  currentMethodTable = new MethodTable;
  this->classTable->find(currentClassName)->second.methods = currentMethodTable;
  //vist method nodes and update method table
  if(node->method_list){
    for(auto iter=node->method_list->begin(); iter!=node->method_list->end(); iter++){
      (*iter)->accept(this);
    }
  }
}

void TypeCheck::visitMethodNode(MethodNode* node) {
  /*
  create a MethodInfo struct and insert it into currentMethodTable
  */
  currentLocalOffset = -4;
  currentParameterOffset = 12;
  currentVariableTable = new VariableTable;
  std::list<CompoundType> *myParameters = new std::list<CompoundType>;
  //uninitated info
  MethodInfo myInfo = {
    {
      bt_none,
      ""
    },
    currentVariableTable,
    myParameters,
    0
  };
  currentMethodTable->insert({node->identifier->name, myInfo});

  //set parameter type, populate variable list with parameters, set currentParameterOffset
  if(node->parameter_list){
    for(auto iter=node->parameter_list->begin(); iter!=node->parameter_list->end(); iter++){
      (*iter)->accept(this);
    }
  }
  node->type->accept(this);
  node->basetype = node->type->basetype;
  node->objectClassName = node->type->objectClassName;
  currentMethodTable->find(node->identifier->name)->second.returnType.baseType = node->basetype;
  currentMethodTable->find(node->identifier->name)->second.returnType.objectClassName = node->objectClassName;
  if(node->identifier->name == currentClassName){
    if(node->basetype != bt_none || node->objectClassName != "")
      typeError(constructor_returns_type);
  }
  //update return type, populate variable table with local variables, set currentLocalOffset
  node->methodbody->accept(this);
  if(node->methodbody->basetype != node->basetype || node->methodbody->objectClassName != node->objectClassName)
    typeError(return_type_mismatch);
  currentMethodTable->find(node->identifier->name)->second.localsSize = (-currentLocalOffset-4);
  //create parameter list from node->parameter_list, set currentParameterOffset
  for(auto iter=node->parameter_list->begin(); iter!=node->parameter_list->end(); iter++){
    (*iter)->accept(this);
    myParameters->push_back({
      (*iter)->basetype,
      (*iter)->objectClassName
    });
  }

}

void TypeCheck::visitMethodBodyNode(MethodBodyNode* node) {
  /*
  populate currentVariableTable with declarations, set currentLocalOffset,
  set return type(MethodBodyNode type)
  */
  //populate currentVariableTable, set currentLocalOffset, set return type(ReturnStatementNode type)
  node->visit_children(this);
  //set return type(MethodBodyNode type)
  if(node->returnstatement){
    node->basetype = node->returnstatement->basetype;
    node->objectClassName = node->returnstatement->objectClassName;
  }
  else{
    node->basetype = bt_none;
    node->objectClassName = "";
  }
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
  node->basetype = node->type->basetype;
  node->objectClassName = node->type->objectClassName;
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
  CompoundType assignee_type;
  //member access
  if(node->identifier_2){
    //creat dummy member access node for type checking
    MemberAccessNode man = MemberAccessNode(node->identifier_1, node->identifier_2);
    man.accept(this);
    assignee_type = {
      man.basetype,
      man.objectClassName
    };
  }
  //straight forward variable
  else{
    //check for variable existance, update type info
    node->identifier_1->accept(this);
    assignee_type = {
      node->identifier_1->basetype,
      node->identifier_1->objectClassName
    };
  }
  //check lhs, update type info
  node->expression->accept(this);
  CompoundType assigner_type = {
    node->expression->basetype,
    node->expression->objectClassName
  };
  if(assignee_type.baseType != assigner_type.baseType)
    typeError(assignment_type_mismatch);
  //objects can be assigned to objects of its superclass type, check for that here
  if(assignee_type.baseType == bt_object){
    if(assignee_type.objectClassName != assigner_type.objectClassName){
      auto assigner_class_iter = this->classTable->find(assignee_type.objectClassName);
      //check for assignee class existence (probably redundant)
      if(assigner_class_iter == this->classTable->end())
        typeError(undefined_class);
      //check if assigner class superclass matches assignee class
      auto assigner_class_info = assigner_class_iter->second;
      if(assigner_class_info.superClassName != assignee_type.objectClassName)
        typeError(assignment_type_mismatch);
    }
  }

}

void TypeCheck::visitCallNode(CallNode* node) {
  /*
  check method call, update node type based on method call
  */
  node->visit_children(this);
  node->basetype = node->methodcall->basetype;
  node->objectClassName = node->methodcall->objectClassName;
}

void TypeCheck::visitIfElseNode(IfElseNode* node) {
  // check if guard expression is of the type boolean
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(if_predicate_type_mismatch);
  }
}

void TypeCheck::visitWhileNode(WhileNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(while_predicate_type_mismatch);
  }
}

void TypeCheck::visitDoWhileNode(DoWhileNode* node) {
  node->visit_children(this);
  if(node->expression->basetype != bt_boolean){
    typeError(do_while_predicate_type_mismatch);
  }
}

void TypeCheck::visitPrintNode(PrintNode* node) {
  node->visit_children(this);
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
  node->visit_children(this);
  if(node->expression_1->basetype != node->expression_2->basetype){
    typeError(expression_type_mismatch);
  }
  else if(node->expression_1->basetype != bt_integer && node->expression_1->basetype != bt_boolean){
    typeError(expression_type_mismatch);
  }
  else{
    node->basetype = bt_boolean;
    node->objectClassName = "";
  }
}

void TypeCheck::visitAndNode(AndNode* node) {
  //And, Or, Not all expect boolean operands (two or one) and produce a boolean.
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
  /*
  checks method existence, signature, updates node type
  */
  //check for method existence
  //current class method call
  MethodInfo method_info;
  ClassInfo class_info;
  std::string method_name;
  //external class method call
  if(node->identifier_2){
    node->identifier_1->accept(this);
    if(node->identifier_1->basetype!=bt_object)
      typeError(not_object);
    //get class info from found class
    class_info = this->classTable->find(node->identifier_1->objectClassName)->second;
    method_name = node->identifier_2->name;
  }
  else{
    //get current class info
    class_info = this->classTable->find(currentClassName)->second;
    method_name = node->identifier_1->name;
  }
  
  //search for method in base class
  auto method_iter = class_info.methods->find(method_name);
  //no base class method found, check for superclass method
  if(method_iter == class_info.methods->end()){
    auto super_class_name = class_info.superClassName;
    auto super_class_iter = this->classTable->find(super_class_name);
    //check if the class has a valid superclass  
    if(super_class_iter==this->classTable->end())
      typeError(undefined_method);
    auto super_class_info = super_class_iter->second;
    method_iter = super_class_info.methods->find(method_name);
    //superclass doesn't have method either
    if(method_iter == super_class_info.methods->end())
      typeError(undefined_method);
  }
  method_info = method_iter->second;

  //check parameter size
  if(node->expression_list->size() != method_info.parameters->size()) 
    typeError(argument_number_mismatch); 
  
  //check parameter type
  if(node->expression_list){
    auto call_iter = node->expression_list->begin();
    auto meth_iter = method_info.parameters->begin();
    while(call_iter != node->expression_list->end()){
      (*call_iter)->accept(this);
      if((*call_iter)->basetype != meth_iter->baseType)
        typeError(argument_type_mismatch);
      if((*call_iter)->basetype==bt_object &&((*call_iter)->objectClassName!=meth_iter->objectClassName))
        typeError(argument_type_mismatch);
      call_iter++;
      meth_iter++;
    }
  }
  //update node type based on method return type
  node->basetype = method_info.returnType.baseType;
  node->objectClassName = method_info.returnType.objectClassName;
}

void TypeCheck::visitMemberAccessNode(MemberAccessNode* node) {
  /*
  Check for class and member existence
  Updates the type of the member access expression
  */
  //update identifier type
  node->identifier_1->accept(this);
  //variable is not an object
  if(node->identifier_1->basetype != bt_object)
    typeError(not_object);
  auto class_iter = this->classTable->find(node->identifier_1->objectClassName);
  //variable class not defined (could be redundant)
  if(class_iter == this->classTable->end())
    typeError(undefined_class);
  auto class_info = class_iter->second;
  //check base class first
  auto member_iter = class_info.members->find(node->identifier_2->name);
  //if not found, check superclass next
  if(member_iter == class_info.members->end()){
    //no superclass
    if(class_info.superClassName == "")
      typeError(undefined_member);
    class_iter = this->classTable->find(class_info.superClassName);
    //super class does not exist either(could be redudant)
    if(class_iter == this->classTable->end())
      typeError(undefined_class);
    class_info = class_iter->second;
    member_iter = class_info.members->find(node->identifier_2->name);
    //superclass also doesn't contain member either
    if(member_iter == class_info.members->end())
      typeError(undefined_member);
  }
  node->basetype = member_iter->second.type.baseType;
  node->objectClassName = member_iter->second.type.objectClassName;
}

void TypeCheck::visitVariableNode(VariableNode* node) {
  node->visit_children(this);
  node->basetype = node->identifier->basetype;
  node->objectClassName = node->identifier->objectClassName;
}

void TypeCheck::visitIntegerLiteralNode(IntegerLiteralNode* node) {
  node->basetype = bt_integer;
  node->objectClassName = "";
}

void TypeCheck::visitBooleanLiteralNode(BooleanLiteralNode* node) {
  node->basetype = bt_boolean;
  node->objectClassName = "";
}

void TypeCheck::visitNewNode(NewNode* node) {
  //New produces an object of the class whose constructor is called.
  if(this->classTable->find(node->identifier->name)==this->classTable->end()){
    typeError(undefined_class);
  }
  if(node->expression_list){
    //creat dummy methodCall node for type checking
    // MethodCallNode mcn = MethodCallNode(node->identifier, NULL,node->expression_list);
    // mcn.accept(this);
    // for(auto iter=node->expression_list->begin(); iter!=node->expression_list->end(); iter++){
    //   (*iter)->accept(this);
    // }
  }
  node->basetype = bt_object;
  node->objectClassName = node->identifier->name;
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
  //check local variable first
  auto var_iter = this->currentVariableTable->find(node->name);
  //check for member
  if(var_iter == this->currentVariableTable->end()){
    //check base class member list
    var_iter = this->classTable->find(currentClassName)->second.members->find(node->name);
    //base class member list does not contain symbol, check superclass
    if(var_iter == this->classTable->find(currentClassName)->second.members->end()){
      auto superclass_name = this->classTable->find(this->currentClassName)->second.superClassName;
      auto superclass_iter = this->classTable->find(superclass_name);
      //no superclass
      if(superclass_iter == this->classTable->end())
        typeError(undefined_variable);
      var_iter = superclass_iter->second.members->find(node->name);
      //superclass does not contain member either
      if(var_iter == superclass_iter->second.members->end())
        typeError(undefined_variable);
    }
  }
  node->basetype = var_iter->second.type.baseType;
  node->objectClassName = var_iter->second.type.objectClassName;
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