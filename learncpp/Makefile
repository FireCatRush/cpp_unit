# =====================================================================
#  learncpp 练习自动编译（MinGW gcc + mingw32-make）
#
#  常用命令（在本目录下执行）：
#    mingw32-make            只编译有改动的文件，产物放到 build\
#    mingw32-make clean      删除整个 build\
#
#  不想记命令的话，直接双击 build.bat / cp_and_run.bat 即可。
#
#  新增章节、新增 .cpp 文件都不用改本文件：所有 .cpp 会被自动扫描。
#  build 目录结构照抄源码目录，例如：
#    chapter4/4.10.Q2_prime-number.cpp -> build/chapter4/4.10.Q2_prime-number.exe
#    chapter8/8.6/main.cpp             -> build/chapter8/8.6/8.6.exe
# =====================================================================

CXX      := g++
CXXSTD   := -std=c++20
WARN     := -Wall -Wextra -Wpedantic
OPT      := -O2
CXXFLAGS := $(CXXSTD) $(WARN) $(OPT)
BUILD    := build
OBJDIR   := $(BUILD)/obj

# 检查 .o 里有没有 main：没有 main 的练习文件（比如刚从题目复制过来的空壳）
# 只编译、不链接，避免一片红字。nm 的 -C 会把符号名还原成 main。
has_main = $(shell nm -C $(1) | findstr /R /C:" T main$$")

# 递归找出所有 .cpp：$(call rwildcard,目录前缀,模式)
rwildcard = $(wildcard $(1)$(2)) $(foreach d,$(wildcard $(1)*),$(call rwildcard,$(d)/,$(2)))
SRCS := $(call rwildcard,,*.cpp)

# 规则：某个目录里放了 main.cpp，就把这个目录当作“多文件小项目”，
#       整个目录的 .cpp 链接成一个 exe（exe 名字 = 目录名）。
#       没有 main.cpp 的目录，每个 .cpp 各自编成一个独立 exe。
MAIN_DIRS  := $(patsubst %/main.cpp,%,$(filter %/main.cpp,$(SRCS)))
dir_of      = $(patsubst %/,%,$(dir $(1)))
STANDALONE := $(foreach s,$(SRCS),$(if $(filter $(call dir_of,$s),$(MAIN_DIRS)),,$(s)))

OBJS      := $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(SRCS)))
MAIN_EXES := $(foreach d,$(MAIN_DIRS),$(BUILD)/$(d)/$(notdir $(d)).exe)
ALL_EXES  := $(MAIN_EXES) $(addprefix $(BUILD)/,$(STANDALONE:.cpp=.exe))

# 不要删掉 .o：默认 make 会把模式规则产生的中间文件当临时文件清掉，
# 那样每次都得整份重编，增量编译就白做了。
.SECONDARY: $(OBJS)

.DEFAULT_GOAL := all
.PHONY: all clean

all: $(ALL_EXES)
	@echo.
	@echo Done: $(words $(SRCS)) .cpp files, executables are in $(BUILD)\

# ---- 编译单个 .cpp -> build/obj/**.o ---------------------------------
# -MMD -MP 生成 .d 依赖文件，这样改了 .h 也会自动重编相关 .cpp
# -I 把源文件所在目录加入头文件搜索路径，方便 #include "xxx.h"
$(OBJDIR)/%.o: %.cpp
	@if not exist "$(@D)" mkdir "$(@D)" 2>nul
	$(CXX) $(CXXFLAGS) -I"$(<D)" -MMD -MP -c "$<" -o "$@"

# ---- 单文件程序：一个 .o 链接成一个 exe -------------------------------
$(BUILD)/%.exe: $(OBJDIR)/%.o
	@if not exist "$(@D)" mkdir "$(@D)" 2>nul
	@$(if $(call has_main,$^),$(CXX) $^ $(LDFLAGS) -o "$@",echo   skip $(@F): no main() yet)

# ---- 多文件程序（目录内有 main.cpp）：整目录链接 ----------------------
define link_dir_program
$(BUILD)/$(1)/$(notdir $(1)).exe: $(addprefix $(OBJDIR)/,$(patsubst %.cpp,%.o,$(wildcard $(1)/*.cpp)))
	@if not exist "$$(@D)" mkdir "$$(@D)" 2>nul
	@$$(if $$(call has_main,$$^),$(CXX) $$^ $(LDFLAGS) -o "$$@",echo   skip $$(@F): no main() yet)
endef
$(foreach d,$(MAIN_DIRS),$(eval $(call link_dir_program,$(d))))

clean:
	@if exist "$(BUILD)" rd /s /q "$(BUILD)"
	@echo Removed $(BUILD)\

-include $(OBJS:.o=.d)
