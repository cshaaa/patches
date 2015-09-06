//Written by LordPsyan

#include "ScriptPCH.h"
#include "Config.h"
#include "SystemConfig.h"

#define GOSSIP_SENDER_MAIN      1000
#define MSG_TYPE                100004
#define MSG_BOT                 100005
#define MAIN_MENU               "<= [Main Menu]"

class Npc_Botmaster : public CreatureScript
{
public:
        Npc_Botmaster() : CreatureScript("Npc_Botmaster") { }

void CreateBot(Player *player, Creature * m_creature, uint32 entry) {

    Creature *creatureTarget = m_creature->SummonCreature(entry, player->GetPositionX(), player->GetPositionY()+2, player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_TIMED_DESPAWN, 50000);
    if(!creatureTarget) return;
        player->CLOSE_GOSSIP_MENU();
        m_creature->MonsterWhisper("Your bot has Arrived. I suggest talking to it before it decides to leave.", player);
        return;
    }

bool OnGossipHello(Player* player, Creature* m_creature)
{
    // Check to see if Only GM is enabled
    if(sConfigMgr->GetBoolDefault("BotMaster.OnlyGMs", false)) // If Npc_Bots.OnlyGMs is enabled in worldserver.conf
        if (player->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            m_creature->MonsterWhisper("Sorry, I can only Provide Bots to Platinum Members.", player);
            return true;
        }
    bool EnableBots = sConfigMgr->GetBoolDefault("BotMaster.EnableBots", true);

    // Main Menu

    // Check config if "Bots" is enabled or not
    if(EnableBots)
        {
        player->ADD_GOSSIP_ITEM( 7, "NPC Bots ->"              , GOSSIP_SENDER_MAIN, 1000);
        player->ADD_GOSSIP_ITEM(6, "Special Items for Sale."   , GOSSIP_SENDER_MAIN, 6007);
        }
    player->SEND_GOSSIP_MENU(MSG_TYPE, m_creature->GetGUID());
return true;
}

bool showBots(Player *player, Creature *m_creature, uint32 showFromId = 0)
{
 QueryResult result;
 result = WorldDatabase.PQuery("SELECT `entry`, `npcClass` FROM `npc_bots`" /*WHERE `cat_number` = 0 ORDER BY `entry` ASC"*/);

 if (result)
 {
 uint32 entryNum = 0;
 std::string npcClass = "";
 uint32 price = 0;

  do
 {
 Field *fields = result->Fetch();
 entryNum = fields[0].GetInt32();
 npcClass = fields[1].GetString();

    player->ADD_GOSSIP_ITEM(9, npcClass, GOSSIP_SENDER_MAIN, entryNum);
}
 while (result->NextRow());

    player->SEND_GOSSIP_MENU(MSG_BOT, m_creature->GetGUID());
 return true;
 }
 else
 {
 if (showFromId = 0)
 {
 //you are too poor
 m_creature->MonsterWhisper("You don't have enough money.", player);
 player->CLOSE_GOSSIP_MENU();
 }
 else
 {

 //show Spells from beginning
 showBots(player, m_creature, 0);
 }
 }

 return false;
}

void SendDefaultMenu(Player* player, Creature* m_creature, uint32 uiAction)
{

// Not allow in combat
if (player->IsInCombat())
{
    player->CLOSE_GOSSIP_MENU();
    m_creature->MonsterSay("You are in combat!", LANG_UNIVERSAL, NULL);
    return;
}

    bool EnableBots = sConfigMgr->GetBoolDefault("BotMaster.EnableBots", true);
    bool OnlyGMs = sConfigMgr->GetBoolDefault("BotMaster.OnlyGMs", true);

  // send name as gossip item
       QueryResult result;
        uint32 entry = 0;
        uint32 cost = 0;
        std::string npcClass = "";

        result = WorldDatabase.PQuery("SELECT * FROM `npc_bots` WHERE `entry` = %u LIMIT 1", uiAction);

if (result)
{
    do {
        Field *fields = result->Fetch();
        entry = fields[0].GetInt32();
        npcClass = fields[1].GetString();
        cost = fields[3].GetInt32();

    if (uiAction != 1000)
            {
    player->CLOSE_GOSSIP_MENU();
    m_creature->MonsterWhisper("Let me get that bot for you.", player);
    CreateBot(player, m_creature, entry);
            } else {
            if (player->GetMoney() < cost)
            {
                m_creature->MonsterWhisper("You dont have enough money!", player);
                player->CLOSE_GOSSIP_MENU();
                return;
            }
        else if (uiAction != 1000)
        {
    player->CLOSE_GOSSIP_MENU();
    CreateBot(player, m_creature, entry);
    player->ModifyMoney(-int(cost));
        }
    }
} while (result->NextRow());
} else {
//player->ADD_GOSSIP_ITEM( 7, MAIN_MENU, GOSSIP_SENDER_MAIN, 5005);
}

 switch(uiAction)
{

case 1000: // Show Bots
        showBots(player, m_creature, 0);
        player->ADD_GOSSIP_ITEM( 7, "<- Main Menu"                            , GOSSIP_SENDER_MAIN, 5005);

    player->SEND_GOSSIP_MENU(MSG_BOT, m_creature->GetGUID());
break;

case 5005: //Back To Main Menu
    // Check to see if Only GM is enabled
    if(sConfigMgr->GetBoolDefault("BotMaster.OnlyGMs", false)) // If Npc_Bots.OnlyGMs is enabled in worldserver.conf
        if (player->GetSession()->GetSecurity() == SEC_PLAYER)
        {
            m_creature->MonsterWhisper("Sorry, I can only Provide Bots to Platinum Members.", player);
        }
    // Main Menu
    // Check config if "Bots" is enabled or not
    player->ADD_GOSSIP_ITEM( 7, "NPC Bots ->"              , GOSSIP_SENDER_MAIN, 1000);
    player->ADD_GOSSIP_ITEM(6, "Special Items for Sale"    , GOSSIP_SENDER_MAIN, 6007);
    player->SEND_GOSSIP_MENU(MSG_TYPE, m_creature->GetGUID());
break;

case 6007:
    player->GetSession()->SendListInventory(m_creature->GetGUID());
    player->CLOSE_GOSSIP_MENU();
    break;

 player->CLOSE_GOSSIP_MENU();
 }

} //end of function

bool OnGossipSelect(Player* player, Creature* m_creature, uint32 uiSender, uint32 uiAction)
{
    // Main menu
    player->PlayerTalkClass->ClearMenus();
    if (uiSender == GOSSIP_SENDER_MAIN)
    SendDefaultMenu(player, m_creature, uiAction);

return true;
}
};

void AddSC_Npc_Botmaster()
{
    new Npc_Botmaster();
}
