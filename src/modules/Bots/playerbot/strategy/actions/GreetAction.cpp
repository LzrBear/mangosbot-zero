#include "botpch.h"
#include "../../playerbot.h"
#include "GreetAction.h"

#include "../../PlayerbotAIConfig.h"
using namespace ai;

GreetAction::GreetAction(PlayerbotAI* ai) : Action(ai, "greet")
{
}

bool GreetAction::Execute(Event event)
{
    ObjectGuid guid = AI_VALUE(ObjectGuid, "new player nearby");
    if (!guid || !guid.IsPlayer()) return false;

    Player* player = dynamic_cast<Player*>(ai->GetUnit(guid));
    if (!player) return false;

    if (!bot->IsInFront(player, sPlayerbotAIConfig.sightDistance, M_PI / 6.0f))
    {
        bot->SetFacingToObject(player);
        return true;
    }

    ObjectGuid oldSel = bot->GetSelectionGuid();
    bot->SetSelectionGuid(guid);
    bot->HandleEmote(EMOTE_ONESHOT_WAVE);
    ai->PlaySound(TEXTEMOTE_HELLO);
    bot->SetSelectionGuid(oldSel);

    set<ObjectGuid>& alreadySeenPlayers = ai->GetAiObjectContext()->GetValue<set<ObjectGuid>& >("already seen players")->Get();
    alreadySeenPlayers.insert(guid);
    return true;
}
