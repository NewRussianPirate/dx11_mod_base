
#include <spdlog/spdlog.h>
#include "Mods.hpp"
// Example
         #include "mods/SimpleMod.hpp"

// Hitch
    // Background
        #include "mods/PlayerTracker.hpp"
        #include "mods/StyleRank.hpp"
        #include "mods/SinCoordinate.hpp"
        #include "mods/CosCoordinate.hpp"
        //#include "mods/MoveID.hpp"
        #include "mods/EnemyNumber.hpp"
    // Common
        #include "mods/HeavyDay.hpp"
    // Gameplay
        #include "mods/AllOrNothing.hpp"
    // Nero
    // Dante
    // V
    // Vergil

// Siyan
    // Background
        #include "mods/DamageTypeLean.hpp"
    // Common
        #include "mods/DeepTurbo.hpp"
        #include "mods/FreezeBPTimer.hpp"
        #include "mods/NoScreenShake.hpp"
        #include "mods/DisplayEnemyHPInOrbs.hpp"
        #include "mods/MovingTargetSwitch.hpp"
        #include "mods/HideHUD.hpp"
        #include "mods/CameraSettings.hpp"
        #include "mods/KeyboardCamera.hpp"
    // Gameplay
        #include "mods/BufferedReversals.hpp"
        #include "mods/NoJCCooldown.hpp"
        #include "mods/AlwaysSTaunts.hpp"
        #include "mods/AllStart.hpp"
        #include "mods/JumpStart.hpp"
        #include "mods/DamageMultiplier.hpp"
        #include "mods/InfDT.hpp"
        #include "mods/EntitySpeeds.hpp"
        #include "mods/FileFrameCuts.hpp"
        #include "mods/DisableEnemyAI.hpp"
    // Nero
        #include "mods/NeroInfBreakers.hpp"
        #include "mods/NeroDisableWiresnatch.hpp"
        #include "mods/NeroSwapWiresnatch.hpp"
    // Dante
        #include "mods/BypassBPCav.hpp"
        #include "mods/DanteMaxSDT.hpp"
        #include "mods/DanteQuickSDT.hpp"
        #include "mods/DanteAlwaysQ4SDT.hpp"
        #include "mods/DanteInfQ4ExitWindow.hpp"
        #include "mods/DanteTwoTricks.hpp"
        #include "mods/DanteAlwaysOvertop.hpp"
        #include "mods/DanteInfIgnition.hpp"
    // V
    // Vergil
        #include "mods/VergilAirTrickNoSS.hpp"
        #include "mods/VergilDirectionalMappings.hpp"
        #include "mods/VergilInfJdCs.hpp"
        #include "mods/VergilInfSDT.hpp"
        #include "mods/VergilInstantSDT.hpp"
        #include "mods/VergilInfConcentration.hpp"
        #include "mods/VergilNoTrickRestriction.hpp"
Mods::Mods()
{
// Example
        m_mods.emplace_back(std::make_unique<SimpleMod>());
// Hitch
    // Background
        m_mods.emplace_back(std::make_unique<PlayerTracker>());
        m_mods.emplace_back(std::make_unique<StyleRank>());
        m_mods.emplace_back(std::make_unique<SinCoordinate>());
        m_mods.emplace_back(std::make_unique<CosCoordinate>());
        //m_mods.emplace_back(std::make_unique<MoveID>());
        m_mods.emplace_back(std::make_unique<EnemyNumber>());
    // Common
        m_mods.emplace_back(std::make_unique<HeavyDay>());
    // Gameplay
        m_mods.emplace_back(std::make_unique<AllOrNothing>());
    // Nero
    // Dante
    // V
    // Vergil

// Siyan
    // Background
        m_mods.emplace_back(std::make_unique<DamageTypeLean>());
    // Common
        m_mods.emplace_back(std::make_unique<DeepTurbo>());
        m_mods.emplace_back(std::make_unique<FreezeBPTimer>());
        m_mods.emplace_back(std::make_unique<NoScreenShake>());
        m_mods.emplace_back(std::make_unique<DisplayEnemyHPInOrbs>());
        m_mods.emplace_back(std::make_unique<MovingTargetSwitch>());
        m_mods.emplace_back(std::make_unique<HideHUD>());
        m_mods.emplace_back(std::make_unique<CameraSettings>());
        m_mods.emplace_back(std::make_unique<KeyboardCamera>());
    // Game
        m_mods.emplace_back(std::make_unique<BufferedReversals>());
        m_mods.emplace_back(std::make_unique<NoJCCooldown>());
        m_mods.emplace_back(std::make_unique<AlwaysSTaunts>());
        m_mods.emplace_back(std::make_unique<AllStart>());
        m_mods.emplace_back(std::make_unique<JumpStart>()); // Must initialize after AllStart
        m_mods.emplace_back(std::make_unique<DamageMultiplier>());
        m_mods.emplace_back(std::make_unique<InfDT>());
        m_mods.emplace_back(std::make_unique<EntitySpeeds>());
        m_mods.emplace_back(std::make_unique<FileFrameCuts>());
        m_mods.emplace_back(std::make_unique<DisableEnemyAI>());
    // Nero
        m_mods.emplace_back(std::make_unique<NeroInfBreakers>());
        m_mods.emplace_back(std::make_unique<NeroDisableWiresnatch>());
        m_mods.emplace_back(std::make_unique<NeroSwapWiresnatch>());
    // Dante
        m_mods.emplace_back(std::make_unique<BypassBPCav>());
        m_mods.emplace_back(std::make_unique<DanteMaxSDT>());
        m_mods.emplace_back(std::make_unique<DanteQuickSDT>());
        m_mods.emplace_back(std::make_unique<DanteAlwaysQ4SDT>());
        m_mods.emplace_back(std::make_unique<DanteInfQ4ExitWindow>());
        m_mods.emplace_back(std::make_unique<DanteTwoTricks>());
        m_mods.emplace_back(std::make_unique<DanteAlwaysOvertop>());
        m_mods.emplace_back(std::make_unique<DanteInfIgnition>());
    // V
    // Vergil
        m_mods.emplace_back(std::make_unique<VergilAirTrickNoSS>());
        m_mods.emplace_back(std::make_unique<VergilDirectionalMappings>());
        m_mods.emplace_back(std::make_unique<VergilInfJdCs>());
        m_mods.emplace_back(std::make_unique<VergilInfSDT>());
        m_mods.emplace_back(std::make_unique<VergilInstantSDT>());
        m_mods.emplace_back(std::make_unique<VergilInfConcentration>());
        m_mods.emplace_back(std::make_unique<VergilNoTrickRestriction>());

#ifdef DEVELOPER
    m_mods.emplace_back(std::make_unique<DeveloperTools>());
#endif
}

std::optional<std::string> Mods::on_initialize() const {
    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_initialize()", mod->get_name().data());

        if (auto e = mod->on_initialize(); e != std::nullopt) {
            spdlog::info("{:s}::on_initialize() has failed: {:s}", mod->get_name().data(), *e);
            return e;
        }
    }

    /*utility::Config cfg{ "re2_fw_config.txt" };

    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_config_load()", mod->get_name().data());
        mod->on_config_load(cfg);
    }
    */
    load_mods();
    //this is still very not great
    focusedmod = "nomod";
    return std::nullopt;
}
std::shared_ptr<Mod> Mods::get_mod(std::string modname) const {
    //recursive call in case we can't find the mod being looked for
  for (auto& mod : m_mods) {
    if (modname == mod->get_name()) {
      return mod;
    }
  }
  return get_mod("SimpleMod");
}

std::string Mods::get_focused_mod() const {
  return focusedmod;
}

void Mods::on_frame() const {
    for (auto& mod : m_mods) {
        mod->on_frame();
    }
}
void Mods::save_mods() const {
  utility::Config cfg{"DMC2_fw_config.txt"};
    for (auto& mod : m_mods) {
        spdlog::info("{:s}::on_config_save()", mod->get_name().data());
        std::string togglename = std::string{mod->get_name()};
        togglename.append("_on");
        cfg.set<bool>(togglename, mod->ischecked);
        mod->on_config_save(cfg);
        //and then probably call the rest of the stuff here;
    }
    // dorime
    //namespace fs = std::filesystem;
    //std::filesystem::path mypath = fs::current_path() / "DMC2_fw_config.txt" ;
    //auto m_conf_path             = mypath.string();
    // ameno
    cfg.save("DMC2_fw_config.txt");

}


void Mods::load_mods() const {
  utility::Config cfg{"DMC2_fw_config.txt"};
  for (auto& mod : m_mods) {
    spdlog::info("{:s}::on_config_load()", mod->get_name().data());
    std::string togglename = std::string{mod->get_name()};
    togglename.append("_on");
    mod->ischecked = cfg.get<bool>(togglename).value_or(false);
    mod->on_config_load(cfg);
    // and then probably call the rest of the stuff here;
  }
}

void Mods::on_draw_debug_ui() const {
	for (auto& mod : m_mods) {
		mod->on_draw_debug_ui();
	}
}

void Mods::on_draw_ui() const {
    for (auto& mod : m_mods) {
        mod->on_draw_ui();
    }
}



void Mods::on_pagelist_ui(int page) const{
  for (auto& mod : m_mods) {
    std::string checkboxname = "##";
    std::string hotkeyname   = "key ";
    checkboxname.append(std::string{mod->get_name()});
    hotkeyname.append(std::string{mod->get_name()});
    if (page == mod->onpage) {
      ImGui::Checkbox(checkboxname.c_str(), &mod->ischecked);
      ImGui::SameLine();
      if (ImGui::Selectable(mod->full_name_string.c_str(), focusedmod == mod->get_name())) {
        focusedmod = mod->get_name();
      }
      //mod->modkeytoggle.draw(mod->get_name());
    }
  }
}

