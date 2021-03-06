// 神话世界·西游记之（世纪）
/* <SecCrypt CPL V3R05> */
 
// create by night 2000.7.25

inherit ROOM;

void create ()
{
  set ("short", "宫门");
  set ("long", @LONG

你正站在一座豪华的宫门前，门前有两只极大的石狮子，门上高悬一块横
匾，上书「圣义宫」三个金字，门口还站着几名卫士。从这里往南是御街，
往北就进入皇宫了。
LONG);

  set("exits", ([
        "north"   : __DIR__"qiandian",
        "south"  : __DIR__"yujie",
      ]));
  set("objects", ([
         __DIR__"npc/wang" : 1,
         __DIR__"npc/weishi" : 3,

      ]));
  set("outdoors", __DIR__);

  setup();
}
int valid_leave(object me, string dir)
{
   if( (string)me->query("family/family_name")=="盱眙山" ) return 1;
        if( wizardp(me)) return 1;

        if (dir == "north") {
        if (objectp(present("wang shenjiang", environment(me))))
        return notify_fail("王神将伸手挡住了你的去路：皇宫岂能随便进出。\n");
        if (objectp(present("wei shi", environment(me))))
        return notify_fail("王府卫士喊道：我家将军不在，小人不敢放您进去！\n");
        }   
        return ::valid_leave(me, dir);
}

