#pragma once

#include <string_view>
#include <vector>

#include "command.h"

Command MakeCommand(const std::vector<std::string_view>& tokens);
