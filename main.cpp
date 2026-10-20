#include <Geode/Geode.hpp>

using namespace geode::prelude;

namespace YcukenDecorator {
    struct StylePreset {
        char const* name;
        char const* description;
    };

    static constexpr StylePreset kStyles[] = {
        {"Modern Glow", "Cyan/purple glow and smooth gradients"},
        {"Neon", "Bright neon accents and high contrast"},
        {"Dark", "Dark blocks with restrained highlights"},
        {"Rainbow", "Multicolor accents"},
        {"AI Custom", "Balanced preset for future smart analysis"},
        {"Cyber", "Digital grid motifs and electric blue"},
        {"Nature", "Organic greens and flowing details"},
        {"Minimal", "Simple geometry and low object count"},
        {"Inferno", "Warm orange/red palette"},
        {"Ice", "Cool cyan/white palette"}
    };

    void logAvailableStyles() {
        log::info("Ycuken Decorator loaded. Available styles:");
        for (auto const& style : kStyles) {
            log::info(" - {}: {}", style.name, style.description);
        }

        auto selected = Mod::get()->getSettingValue<std::string>("style");
        log::info("Selected style: {}", selected);

        bool previewOnly = Mod::get()->getSettingValue<bool>("preview-only");
        log::info("Preview-only mode: {}", previewOnly ? "enabled" : "disabled");
    }
}

$on_mod(Loaded) {
    YcukenDecorator::logAvailableStyles();
}
