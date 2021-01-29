
#include "VergilInstantSDT.hpp"
#include "PlayerTracker.hpp"
uintptr_t VergilInstantSDT::jmp_ret1{NULL};
uintptr_t VergilInstantSDT::jmp_ja1{NULL};

uintptr_t VergilInstantSDT::jmp_ret2{NULL};

uintptr_t VergilInstantSDT::jmp_ret3{NULL};
uintptr_t VergilInstantSDT::jmp_out3{NULL};

uintptr_t VergilInstantSDT::jmp_ret4{NULL};
uintptr_t VergilInstantSDT::jmp_out4{NULL};


bool VergilInstantSDT::cheaton{NULL};

// clang-format off
// only in clang/icl mode on x64, sorry

static naked void detour1() {
	__asm {
        cmp [PlayerTracker::playerid], 4 //change this to the char number obviously
        jne code
        cmp byte ptr [VergilInstantSDT::cheaton], 1
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
        cmp byte ptr [VergilInstantSDT::cheaton], 1
        je cheatcode
        jmp code

    code:
        movss xmm3, [rsi+48h]
        jmp qword ptr [VergilInstantSDT::jmp_ret2]

    cheatcode:
		jmp qword ptr [VergilInstantSDT::jmp_ret2]
	}
}

static naked void detour3() { // Disables Doppel on DT input when SDT bar isn't full
	__asm {
        cmp byte ptr [VergilInstantSDT::cheaton], 1
        je cheatcode
        jmp code

    code:
        comisd xmm0, xmm1
        ja jmp_out
        jmp qword ptr [VergilInstantSDT::jmp_ret3]

    cheatcode:
		jmp qword ptr [VergilInstantSDT::jmp_ret3]

    jmp_out:
        jmp qword ptr [VergilInstantSDT::jmp_out3]
	}
}

static naked void detour4() { // Makes SDT bar start to fill instantly when it needs to be loaded with DT
	__asm {
        cmp byte ptr [VergilInstantSDT::cheaton], 1
        je cheatcode
        jmp code

    code:
        comisd xmm2, xmm1
        jae jmp_out
        jmp qword ptr [VergilInstantSDT::jmp_ret4]

    cheatcode:
        comisd xmm2, xmm1
        jmp jmp_out
		jmp qword ptr [VergilInstantSDT::jmp_ret4]

    jmp_out:
        jmp qword ptr [VergilInstantSDT::jmp_out4]
	}
}

// clang-format on

std::optional<std::string> VergilInstantSDT::on_initialize() {
  ischecked            = &VergilInstantSDT::cheaton;
  onpage               = vergilpage;

  full_name_string     = "Instant SDT";
  author_string        = "SSSiyan";
  description_string   = "Removes the need to hold the DT button to enter SDT.";

  auto base = g_framework->get_module().as<HMODULE>(); // note HMODULE
  auto addr1 = utility::scan(base, "66 0F 2F CA 77 D9 F3 0F 10 8F 20");
  if (!addr1) {
    return "Unable to find VergilInstantSDT1 pattern.";
  }

  auto addr2 = utility::scan(base, "00 00 00 F3 0F 10 5E 48");
  if (!addr2) {
    return "Unable to find VergilInstantSDT2 pattern.";
  }

  auto addr3 = utility::scan(base, "66 0F 2F C1 77 19 F3 0F 11 97 34");
  if (!addr3) {
    return "Unable to find VergilInstantSDT3 pattern.";
  }
  VergilInstantSDT::jmp_out3 = addr3.value()+31;

  auto addr4 = utility::scan(base, "66 0F 2F D1 73 25 F3 0F 10 8F 20");
  if (!addr4) {
    return "Unable to find VergilInstantSDT4 pattern.";
  }
  VergilInstantSDT::jmp_out4 = addr4.value() + 43;

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
  if (!install_hook_absolute(addr3.value(), m_function_hook3, &detour3, &jmp_ret3, 6)) {
  //  return a error string in case something goes wrong
  spdlog::error("[{}] failed to initialize", get_name());
  return "Failed to initialize VergilInstantSDT3";
  }
  if (!install_hook_absolute(addr4.value(), m_function_hook4, &detour4, &jmp_ret4, 6)) {
  //  return a error string in case something goes wrong
  spdlog::error("[{}] failed to initialize", get_name());
  return "Failed to initialize VergilInstantSDT4";
  }

  return Mod::on_initialize();
}

void VergilInstantSDT::on_draw_ui() {
}
