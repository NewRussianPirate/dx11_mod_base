
#include "VergilInstantSDT.hpp"

uintptr_t VergilInstantSDT::jmp_ret1{NULL};
uintptr_t VergilInstantSDT::jmp_ja1{NULL};
uintptr_t VergilInstantSDT::jmp_ret2{NULL};
uintptr_t VergilInstantSDT::cheaton{NULL};

bool vergilinstantsdtcheck;

// clang-format off
// only in clang/icl mode on x64, sorry

static naked void detour1() {
	__asm {
        push rax
        mov rax, [VergilInstantSDT::cheaton]
        cmp byte ptr [rax], 1
        pop rax
        je cheatcode
        jmp code

    cheatcode:
        movss xmm1, [rdi+00001B20h]
		jmp qword ptr [VergilInstantSDT::jmp_ret1]

    code:
        comisd xmm1, xmm2
        ja jajmp
        jmp qword ptr [VergilInstantSDT::jmp_ret1]

    jajmp:
        jmp qword ptr [VergilInstantSDT::jmp_ja1]
	}
}

static naked void detour2() {
	__asm {
        push rax
        mov rax, [VergilInstantSDT::cheaton]
        cmp byte ptr [rax], 1
        pop rax
        je cheatcode
        jmp code

    code:
        movss xmm3, [rsi+48h]
        jmp qword ptr [VergilInstantSDT::jmp_ret2]

    cheatcode:
		jmp qword ptr [VergilInstantSDT::jmp_ret2]
	}
}

// clang-format on

std::optional<std::string> VergilInstantSDT::on_initialize() {
  ischecked            = false;
  onpage               = dantepage;
  full_name_string     = "Instant SDT";
  author_string        = "SSSiyan";
  description_string   = "Allow Vergil to enter SDT instantly.";
  VergilInstantSDT::cheaton = (uintptr_t)&ischecked;
  auto base = g_framework->get_module().as<HMODULE>(); // note HMODULE
  auto addr1 = utility::scan(base, "66 0F 2F CA 77 D9 F3 0F 10 8F 20");
  if (!addr1) {
    return "Unable to find VergilInstantSDT1 pattern.";
  }
  auto addr2 = utility::scan(base, "00 00 00 F3 0F 10 5E 48");
  if (!addr2) {
    return "Unable to find VergilInstantSDT2 pattern.";
  }

  VergilInstantSDT::jmp_ja1 = utility::scan(base, "02 02 48 8B 5C 24 30 32").value()+2;

  if (!install_hook_absolute(addr1.value(), m_function_hook1, &detour1, &jmp_ret1, 6)) {
    //  return a error string in case something goes wrong
    spdlog::error("[{}] failed to initialize", get_name());
    return "Failed to initialize VergilInstantSDT1";
  }
  if (!install_hook_absolute(addr2.value()+3, m_function_hook2, &detour2, &jmp_ret2, 5)) {
    //  return a error string in case something goes wrong
    spdlog::error("[{}] failed to initialize", get_name());
    return "Failed to initialize VergilInstantSDT2";
  }
  return Mod::on_initialize();
}

void VergilInstantSDT::on_draw_ui() {
  ImGui::Checkbox("Vergil Instant SDT", &vergilinstantsdtcheck);
}
