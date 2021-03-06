#include "botpch.h"
#include "../../playerbot.h"
#include "ShamanActions.h"
#include "ShamanAiObjectContext.h"
#include "ShamanNonCombatStrategy.h"
#include "HealShamanStrategy.h"
#include "MeleeShamanStrategy.h"
#include "ShamanTriggers.h"
#include "../NamedObjectContext.h"
#include "TotemsShamanStrategy.h"
#include "CasterShamanStrategy.h"

using namespace ai;



namespace ai
{
    namespace shaman
    {
        using namespace ai;

        class StrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            StrategyFactoryInternal()
            {
                creators["nc"] = &shaman::StrategyFactoryInternal::nc;
                creators["totems"] = &shaman::StrategyFactoryInternal::totems;
                creators["melee aoe"] = &shaman::StrategyFactoryInternal::melee_aoe;
                creators["caster aoe"] = &shaman::StrategyFactoryInternal::caster_aoe;
                creators["cure"] = &shaman::StrategyFactoryInternal::cure;
            }

        private:
            static Strategy* nc(PlayerbotAI* ai) { return new ShamanNonCombatStrategy(ai); }
            static Strategy* totems(PlayerbotAI* ai) { return new TotemsShamanStrategy(ai); }
            static Strategy* melee_aoe(PlayerbotAI* ai) { return new MeleeAoeShamanStrategy(ai); }
            static Strategy* caster_aoe(PlayerbotAI* ai) { return new CasterAoeShamanStrategy(ai); }
            static Strategy* cure(PlayerbotAI* ai) { return new ShamanCureStrategy(ai); }
        };

        class BuffStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            BuffStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["bmana"] = &shaman::BuffStrategyFactoryInternal::bmana;
                creators["bdps"] = &shaman::BuffStrategyFactoryInternal::bdps;
            }

        private:
            static Strategy* bmana(PlayerbotAI* ai) { return new ShamanBuffManaStrategy(ai); }
            static Strategy* bdps(PlayerbotAI* ai) { return new ShamanBuffDpsStrategy(ai); }
        };

        class CombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
        {
        public:
            CombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
            {
                creators["heal"] = &shaman::CombatStrategyFactoryInternal::heal;
                creators["melee"] = &shaman::CombatStrategyFactoryInternal::dps;
                creators["dps"] = &shaman::CombatStrategyFactoryInternal::dps;
                creators["caster"] = &shaman::CombatStrategyFactoryInternal::caster;
            }

        private:
            static Strategy* heal(PlayerbotAI* ai) { return new HealShamanStrategy(ai); }
            static Strategy* dps(PlayerbotAI* ai) { return new MeleeShamanStrategy(ai); }
            static Strategy* caster(PlayerbotAI* ai) { return new CasterShamanStrategy(ai); }
        };
    };
};

namespace ai
{
    namespace shaman
    {
        using namespace ai;

        class TriggerFactoryInternal : public NamedObjectContext<Trigger>
        {
        public:
            TriggerFactoryInternal()
            {
                creators["windfury totem"] = &TriggerFactoryInternal::windfury_totem;
                creators["mana spring totem"] = &TriggerFactoryInternal::mana_spring_totem;
                creators["flametongue totem"] = &TriggerFactoryInternal::flametongue_totem;
                creators["strength of earth totem"] = &TriggerFactoryInternal::strength_of_earth_totem;
                creators["magma totem"] = &TriggerFactoryInternal::magma_totem;
                creators["searing totem"] = &TriggerFactoryInternal::searing_totem;
                creators["purge"] = &TriggerFactoryInternal::purge;
                creators["shaman weapon"] = &TriggerFactoryInternal::shaman_weapon;
                creators["lightning shield"] = &TriggerFactoryInternal::lightning_shield;
                creators["water breathing"] = &TriggerFactoryInternal::water_breathing;
                creators["water walking"] = &TriggerFactoryInternal::water_walking;
                creators["water breathing on party"] = &TriggerFactoryInternal::water_breathing_on_party;
                creators["water walking on party"] = &TriggerFactoryInternal::water_walking_on_party;
                creators["shock"] = &TriggerFactoryInternal::shock;
                creators["frost shock snare"] = &TriggerFactoryInternal::frost_shock_snare;
            }

        private:

            static Trigger* water_breathing(PlayerbotAI* ai) { return new WaterBreathingTrigger(ai); }
            static Trigger* water_walking(PlayerbotAI* ai) { return new WaterWalkingTrigger(ai); }
            static Trigger* water_breathing_on_party(PlayerbotAI* ai) { return new WaterBreathingOnPartyTrigger(ai); }
            static Trigger* water_walking_on_party(PlayerbotAI* ai) { return new WaterWalkingOnPartyTrigger(ai); }
            static Trigger* windfury_totem(PlayerbotAI* ai) { return new WindfuryTotemTrigger(ai); }
            static Trigger* mana_spring_totem(PlayerbotAI* ai) { return new ManaSpringTotemTrigger(ai); }
            static Trigger* flametongue_totem(PlayerbotAI* ai) { return new FlametongueTotemTrigger(ai); }
            static Trigger* strength_of_earth_totem(PlayerbotAI* ai) { return new StrengthOfEarthTotemTrigger(ai); }
            static Trigger* magma_totem(PlayerbotAI* ai) { return new MagmaTotemTrigger(ai); }
            static Trigger* searing_totem(PlayerbotAI* ai) { return new SearingTotemTrigger(ai); }
            static Trigger* purge(PlayerbotAI* ai) { return new PurgeTrigger(ai); }
            static Trigger* shaman_weapon(PlayerbotAI* ai) { return new ShamanWeaponTrigger(ai); }
            static Trigger* lightning_shield(PlayerbotAI* ai) { return new LightningShieldTrigger(ai); }
            static Trigger* shock(PlayerbotAI* ai) { return new ShockTrigger(ai); }
            static Trigger* frost_shock_snare(PlayerbotAI* ai) { return new FrostShockSnareTrigger(ai); }
          
        };
    };
};


namespace ai
{
    namespace shaman
    {
        using namespace ai;

        class AiObjectContextInternal : public NamedObjectContext<Action>
        {
        public:
            AiObjectContextInternal()
            {
                creators["lightning shield"] = &AiObjectContextInternal::lightning_shield;
                creators["strength of earth totem"] = &AiObjectContextInternal::strength_of_earth_totem;
                creators["flametongue totem"] = &AiObjectContextInternal::flametongue_totem;
                creators["searing totem"] = &AiObjectContextInternal::searing_totem;
                creators["magma totem"] = &AiObjectContextInternal::magma_totem;
                creators["windfury totem"] = &AiObjectContextInternal::windfury_totem;
                creators["mana spring totem"] = &AiObjectContextInternal::mana_spring_totem;
                creators["mana tide totem"] = &AiObjectContextInternal::mana_tide_totem;
                creators["healing stream totem"] = &AiObjectContextInternal::healing_stream_totem;
                creators["rockbiter weapon"] = &AiObjectContextInternal::rockbiter_weapon;
                creators["flametongue weapon"] = &AiObjectContextInternal::flametongue_weapon;
                creators["frostbrand weapon"] = &AiObjectContextInternal::frostbrand_weapon;
                creators["windfury weapon"] = &AiObjectContextInternal::windfury_weapon;
                creators["purge"] = &AiObjectContextInternal::purge;
                creators["healing wave"] = &AiObjectContextInternal::healing_wave;
                creators["lesser healing wave"] = &AiObjectContextInternal::lesser_healing_wave;
                creators["healing wave on party"] = &AiObjectContextInternal::healing_wave_on_party;
                creators["lesser healing wave on party"] = &AiObjectContextInternal::lesser_healing_wave_on_party;
                creators["chain heal"] = &AiObjectContextInternal::chain_heal;
                creators["stormstrike"] = &AiObjectContextInternal::stormstrike;
                creators["fire nova totem"] = &AiObjectContextInternal::fire_nova_totem;
                creators["ancestral spirit"] = &AiObjectContextInternal::ancestral_spirit;
                creators["water walking"] = &AiObjectContextInternal::water_walking;
                creators["water breathing"] = &AiObjectContextInternal::water_breathing;
                creators["water walking on party"] = &AiObjectContextInternal::water_walking_on_party;
                creators["water breathing on party"] = &AiObjectContextInternal::water_breathing_on_party;
                creators["flame shock"] = &AiObjectContextInternal::flame_shock;
                creators["earth shock"] = &AiObjectContextInternal::earth_shock;
                creators["frost shock"] = &AiObjectContextInternal::frost_shock;
                creators["chain lightning"] = &AiObjectContextInternal::chain_lightning;
                creators["lightning bolt"] = &AiObjectContextInternal::lightning_bolt;
            }

        private:
            static Action* lightning_bolt(PlayerbotAI* ai) { return new CastLightningBoltAction(ai); }
            static Action* chain_lightning(PlayerbotAI* ai) { return new CastChainLightningAction(ai); }
            static Action* frost_shock(PlayerbotAI* ai) { return new CastFrostShockAction(ai); }
            static Action* earth_shock(PlayerbotAI* ai) { return new CastEarthShockAction(ai); }
            static Action* flame_shock(PlayerbotAI* ai) { return new CastFlameShockAction(ai); }
            static Action* water_walking(PlayerbotAI* ai) { return new CastWaterWalkingAction(ai); }
            static Action* water_breathing(PlayerbotAI* ai) { return new CastWaterBreathingAction(ai); }
            static Action* water_walking_on_party(PlayerbotAI* ai) { return new CastWaterWalkingOnPartyAction(ai); }
            static Action* water_breathing_on_party(PlayerbotAI* ai) { return new CastWaterBreathingOnPartyAction(ai); }
            static Action* lightning_shield(PlayerbotAI* ai) { return new CastLightningShieldAction(ai); }
            static Action* strength_of_earth_totem(PlayerbotAI* ai) { return new CastStrengthOfEarthTotemAction(ai); }
            static Action* flametongue_totem(PlayerbotAI* ai) { return new CastFlametongueTotemAction(ai); }
            static Action* magma_totem(PlayerbotAI* ai) { return new CastMagmaTotemAction(ai); }
            static Action* searing_totem(PlayerbotAI* ai) { return new CastSearingTotemAction(ai); }
            static Action* fire_nova_totem(PlayerbotAI* ai) { return new CastFireNovaTotemAction(ai); }
            static Action* windfury_totem(PlayerbotAI* ai) { return new CastWindfuryTotemAction(ai); }
            static Action* mana_spring_totem(PlayerbotAI* ai) { return new CastManaSpringTotemAction(ai); }
            static Action* mana_tide_totem(PlayerbotAI* ai) { return new CastManaTideTotemAction(ai); }
            static Action* healing_stream_totem(PlayerbotAI* ai) { return new CastHealingStreamTotemAction(ai); }
            static Action* rockbiter_weapon(PlayerbotAI* ai) { return new CastRockbiterWeaponAction(ai); }
            static Action* flametongue_weapon(PlayerbotAI* ai) { return new CastFlametongueWeaponAction(ai); }
            static Action* frostbrand_weapon(PlayerbotAI* ai) { return new CastFrostbrandWeaponAction(ai); }
            static Action* windfury_weapon(PlayerbotAI* ai) { return new CastWindfuryWeaponAction(ai); }
            static Action* purge(PlayerbotAI* ai) { return new CastPurgeAction(ai); }
            static Action* healing_wave(PlayerbotAI* ai) { return new CastHealingWaveAction(ai); }
            static Action* lesser_healing_wave(PlayerbotAI* ai) { return new CastLesserHealingWaveAction(ai); }
            static Action* healing_wave_on_party(PlayerbotAI* ai) { return new CastHealingWaveOnPartyAction(ai); }
            static Action* lesser_healing_wave_on_party(PlayerbotAI* ai) { return new CastLesserHealingWaveOnPartyAction(ai); }
            static Action* chain_heal(PlayerbotAI* ai) { return new CastChainHealAction(ai); }
            static Action* stormstrike(PlayerbotAI* ai) { return new CastStormstrikeAction(ai); }
            static Action* ancestral_spirit(PlayerbotAI* ai) { return new CastAncestralSpiritAction(ai); }
            
        };
    };
};



ShamanAiObjectContext::ShamanAiObjectContext(PlayerbotAI* ai) : AiObjectContext(ai)
{
    strategyContexts.Add(new ai::shaman::StrategyFactoryInternal());
    strategyContexts.Add(new ai::shaman::CombatStrategyFactoryInternal());
    strategyContexts.Add(new ai::shaman::BuffStrategyFactoryInternal());
    actionContexts.Add(new ai::shaman::AiObjectContextInternal());
    triggerContexts.Add(new ai::shaman::TriggerFactoryInternal());
}
