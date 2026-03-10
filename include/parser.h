#pragma once

#include <string_view>
#include <vector>

#include "command.h"
#include "integer.h"

Command MakeCommand(const std::vector<std::string_view>& tokens);
Integer MakeInteger(std::string_view operand);
