//Credit to alandtse for orginal code used in FRIK.

#pragma once

#include "f4se/NiObjects.h"
#include <optional>
#include "include/json.hpp"


namespace Holsters {

	enum Mode {
		normal = 0,
		powerArmor,
		noPASneak,
		sneakinpowerArmor,
		noPA,
	};

	class WeaponOffset {
	public:

		WeaponOffset() {
			offsets.clear();
		}

		std::optional<NiTransform> getOffset(const std::string& name, const Mode mode = normal);
		void addOffset(const std::string& name, NiTransform someData, const Mode mode = normal);
		void deleteOffset(const std::string& name, const Mode mode = normal);
		std::size_t getSize();
		std::map<std::string, NiTransform> offsets;
	};

	static const std::string powerArmorSuffix{ "-PowerArmor" };
	static const std::string noPASneakSuffix{ "-Sneak" };
	static const std::string PASneakSuffix{ "-PASneak" };
	static const std::string NoPASuffix{ "-Normal" };
	static const std::string defaultJson{ ".\\Data\\F4SE\\plugins\\VRH_weapon_offsets.json" };
	static std::string offsetsPath{ ".\\Data\\F4SE\\plugins\\VRH_weapon_offsets" } ;
	void readOffsetJson();
	void loadOffsetJsonFile(const std::string& file = defaultJson);
	void writeOffsetJson();
	void saveOffsetJsonFile(const nlohmann::json& weaponJson, const std::string& file = defaultJson);
	extern WeaponOffset* g_weaponOffsets;
}