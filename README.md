TrinityCore-Patches now has a web site. There is a specific topic for patches. The url is:

http://www.realmsofwarcraft.com/bb

This site also has the test servers for upcoming patches. Dark Psyon is the test server for 335a.

Instead of posting an "issue" with suggestions or questions, try using the forums. I will try to check often and answer questions.

There is a new prepatch. This patch must be used before using the patches you want, unless you are using an ALL patch, which already has the prepatch in it. You can now pick and choose which patches you wish to use, instead of being stuck with all of the patches.

If you add GuildLevelSystem or Individual XP Rate patches, you must change a "PrepatchGI.Added = 0" to 1 or they won't work. This was the only way I could get those patches included in the prepatch. Setting this to 0 with either of those patches added will not disable the patch... it will crash the realm. (not test, but most likely). This is located at the top of the config file.

Now for the patches...
I will start with the ALL patch. Apply Bots patch of your choice after applying ALL

* ALL without any bots.

I am also accepting donations. I am only adding this because a few people have asked how to donate. I never
thought about it, and never expected to get donations. I do this because I enjoy it. If you want to donate,
I won't deny you, but I will not be upset if you don't.

to donate, go here: http://www.realmsofwarcraft.com/donate.php or make a donation through paypal... realmsofwarcraft@gmail.com

Here is a list of the patches, and a detailed description of each. (Not finished, but working on it.)

* **All-In-One-NPC.patch** - 
  NPC that does a variety of things, from buffing to morphing.

* **ArenaGambler.patch** - Someone give me a good description of this. I am assuming you bet on the winner of a battle in an arena.
* **Arena_Template.patch** - This script has a bunch of LearnSpell commands. Other than that, I have no clue. Probably needs an SQL file, so if anyone plays around with this, send me a message explaining what it does. THanks.
* **Beastmaster.patch** - 
  NPC that offers the sale of hunter pets. My version has pets in DB, and you can turn on/off hunter only, and GM only. You can also decide how much gold or tokens per pet, instead of per pet type (normal or exotic) like all the other beastmaster patches do.

* **BountyHunter.patch**
  Place a bounty on a player.

* **CongratsOnLevel.patch** (broken)
  Small script that gives a reward for playing the game. Currently set for 2 items, gold and a spell for each 10 levels obtained.

* **CrossFactionBG.patch** - 
  Assuming this permits both factions on same team in BG.

* **Fake_Players.patch** - 
  Populates the "who" list with up to 49 fake online players. Message appears saying they do not want to be disturbed when whispered to.

* **Fatigue.patch** - 
  Turn on or off the fatigue timer.

* **GuildHouses.patch** - 
  NPC that offers guild leaders a guild house. Once a leader purchases the house, and member of that guild can teleport using this NPC to the guild. Non guild members will not be able to teleport.

* **GuildLevelSystem.patch** - 

* **Individual-XP-Rate.patch** - 
  Allows setting of different XP rates. I have not tested, so not sure how to set them.

* **KillStreak.patch** - 
  Rewards for pvp based on number of successful wins in a row... I think.

* **LevelNPC.patch** - 
  NPC that offers level using gold or tokens. Config option (forgot to put those in, will get right on that)

* **New_NPCBots**.patch - 
  Server controlled "players" that run in your party. Must be prespawned, and factions set (a,h,m - Alliance, Horde, Monster) NPCBots tend to be a bit over powered, but great for low population servers

* **NPCBuff.patch** - 
  NPC that casts buffs on players. Buffs and cost in DB.

* **npc-enchant.patch** - 
  An npc that will enchant items for you. No more searching for a player that can do it. Just give ME your gold :)

* **Old_NPCBots.patch** - 
  Same as New NPCBots exept that you can use commands to add them to your party, or you can spawn an NPC Giver guy that will spawn them for you.

* **Passive_Anticheat.patch** - 
  Best anti cheat out there. checks for speed hacks, flying, etc.

* **Player_Events.patch**
  Rewards based on specific events. Example: Level rewards. First honorable kill rewards. Check readme file for details.

* **Playerbot-NPCBots.patch** - 
  Old NPCBots patch plus a playerbot patch that allows you to "log in" another character on your account, controlled by the server. Buggy at best, but fun to play with.

* **ProfessionNPC.patch** - 
  NPC that will give you +10 to any profession... for a price. Price can be token or gold, set in config file.

* **Reforging.patch** - 
  Blizzlike reforging Change 40% of your item stats to something else Sends item packets so you can see the changes on item tooltips Simple and easy to use interface Made for 3.3.5a.

* **Summon_NPC.patch** -
  This is an item, that when right-clicked, will spawn an npc (default entry number 100000). I use it to summon my TeleNPC2 NPC, so players can teleport anywhere any time. The NPC will automatically vanish after a few minutes.
 
* **TeleNPC2.patch** - 
  The best of the best teleport scripts. an NPC with well organized coordinates for teleporting. You can add catagories, and locations, and restrict those locations in many way, such as by cost, specific guild, level required, etc.

* **Transmogrification.patch** - 
  Transmogrification allows you to change the display of an item to something else. You can use any item in your bags as source of display, as long as it fits the requirements. Requirements can be tweaked in the server configuration file. Basically any item should work with transmogrification. Custom items as well. No item is hardcoded to the system. Has a feature to store sets of displays. This can be removed before compiling or in the configuration file. Made for 3.3.5a.

* **TriniIRC.patch** - (broken)
  Allows players to join a channel (set in config) and chat to people in an IRC channel. Configs are a bit confusing, but once working, you can admin the realm via IRC (so you can connect to IRC on your smartphone, and kick\ban players, chat, and do other commands). On the flip side, you can join the IRC chat room (on your computer, tablet or phone) and chat with in game players.

Added some details, but check the website for more information on the patches.