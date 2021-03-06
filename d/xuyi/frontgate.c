#include <ansi.h>
inherit ROOM;

int do_knock(string arg);
void create()
{
    set("short", "寺前广场");
    set("long",

    "\n这里是大圣禅寺前的广场，广场由石埕铺就，就黄土垫砌，坚实平\n"
"坦。虽然年代久远，却气派依旧。正前方黄墙碧瓦，飞檐翘檩，正\n"
"中两扇厚厚的铜色大门(gate)，非合数人之力，难以推动。上方一\n"
"块大匾，龙飞凤舞地书着四个大字：\n\n"
HIY"                    『大圣禅寺』\n\n"NOR
"远远望去，后寺中亭台楼阁规模宏大，构筑精丽，宅地连云，其气\n"
"势之盛更胜于五台，普陀等诸处佛门胜地的名山大寺。 \n");
    set("exits", ([
  "south" : __DIR__"xiaolu22",
    ]));

    set("outdoors", 1);
    set("item_desc",([ 
        "gate" : "一道三丈来高的朱红杉木包铜大门。\n"
    ]));
    set("objects",([
    ]));
//    set("no_clean_up", 0);
    setup();
}

void init()
{
        add_action("do_knock","knock");
}

int do_knock(string arg)
{
      object me, room;
      me = this_player(); 

    if (query("exits/north"))
        return notify_fail("大门已经是开着了。\n");
      if (!arg || arg != "gate")
      {
            return notify_fail("你想敲什么？\n");
      }

    if(!( room = find_object(__DIR__"dadian")) )
        room = load_object(__DIR__"dadian");
    if(objectp(room))
    {
        set("exits/north", __DIR__"dadian");
        message_vision("$N轻轻地敲了敲门，只听吱地一声，"
            "一位小沙弥应声打开大门，上上下下打量着$N。\n",
            this_player());
        room->set("exits/south", __FILE__);
        message("vision", "外面传来一阵敲门声，小沙弥应声上前把大门开。\n", room);
        remove_call_out("close_gate");
        call_out("close_gate", 10);
    }
        return 1;
}

int close_gate()
{
    object room;

    if(!( room = find_object(__DIR__"dadian")) )
        room = load_object(__DIR__"dadian");
    if(objectp(room))
    {
        delete("exits/north");
        message("vision", "乒地一声，里面有人把大门关上了。\n",
            this_object());
        room->delete("exits/south");
            message("vision", "小沙弥上前把大门关了起来。\n", room);
    }
    else message("vision", "一阵罡风吹过，大门掩了起来。\n", room);
}

int valid_leave(object me, string dir)
{
    if ( dir == "north" )
    {
    if ( (me->query("family/family_name") != "盱眙山"))
    {    
     if( present("tongpai", me) )
    {
      write("小沙弥合十为礼，侧身让开，说道：原来是贵客驾到，请进请进！\n");
     return 1;
     }
    if (me->query("class") == "yaomo")
     return notify_fail("小沙弥立时从身畔挚出一把雪亮的戒刀来，把明晃晃的\n"
                "刀尖对准你的胸口，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n"
                "以后再敢走近大圣禅寺一步，我立时就斩断你们的狗腿！\n"); 
    if (me->query("class") == "youling")
     return notify_fail("小沙弥立时从身畔挚出一把雪亮的戒刀来，把明晃晃的\n"
                "刀尖对准你的胸口，横眉怒目地说道：你等邪魔外道，还不给我滚开！\n"
                "以后再敢走近大圣禅寺一步，我立时就斩断你们的狗腿！\n");

     return 1;
     return notify_fail("小沙弥施了一礼，道：本寺不接待外客，施主请回。\n");
  }
   return 1;
  } 
        return ::valid_leave(me, dir);
}
