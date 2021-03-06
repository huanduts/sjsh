// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
int do_yell(string arg);
void reset();

#include <ansi.h>

void create ()
{
  set ("short", "南赡部洲海岸");
  set ("long", @LONG

这里就是南赡部洲的海岸，金色的沙滩在阳光下闪闪发光，白浪如雪。不
远处有一条青石板路蜿蜒通往远方。海面上隐约看到一叶扁舟（ＢＯＡＴ），
可以试着（ＹＥＬＬ）。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"island1",
  "north" : __DIR__"path",
  "east" : __DIR__"island2",
]));

  setup();
}

/*
int valid_leave(object me, string dir)
{
   if( (string)me->query("family/family_name")=="盱眙山" ) return 1;
        if( wizardp(me)) return 1;

        if (dir == "west"
   || dir=="east" 
   || dir=="north") {
        if (objectp(present("zhao shenjiang", environment(me))))
        return notify_fail("赵神将伸手挡住了你的去路：王府岂能随便进出。\n");
        if (objectp(present("wei shi", environment(me))))
        return notify_fail("王府卫士喊道：我家将军不在，小人不敢放您进去！\n");
        }   
        return ::valid_leave(me, dir);
}
*/

void init()
{
        add_action("do_yell", "yell"); 
}
 
void check_trigger()
{
    object room;

    if(!query("exits/enter") ) {
        if( !(room = find_object("/d/changan/duchuan")) )
            room = load_object("/d/changan/duchuan");
        if( room = find_object("/d/changan/duchuan") ) {
            if((int)room->query("yell_trigger")==0 ) {
                room->set("yell_trigger", 1);
                set("exits/enter", "/d/changan/duchuan");
                room->set("exits/out", __FILE__);
                message("vision", "一叶扁舟缓缓地驶了过来，艄公将一块踏脚"
                    "板搭上海滩，以便乘客\n上下。\n", this_object() );
                message("vision", "艄公将一块踏脚板搭上海滩，形成一个向上"
                    "的阶梯。\n", room);
                remove_call_out("on_board");
                call_out("on_board", 15);
            }
            else
                message("vision", "只听得海面上隐隐传来：“别急嘛，"
                    "这儿正忙着呐……”\n",this_object() );
        }
        else
            message("vision", "ERROR: boat not found\n", this_object() );
    }
    else 
        message("vision", "岸边一只渡船上的老艄公说道：正等着你呢，上来吧。\n",
            this_object() );
}


void on_board()
{
    object room;

    if( !query("exits/enter") ) return;

    message("vision", "艄公把踏脚板收了起来，竹篙一点，扁舟向波涛中驶去。\n",
        this_object() );

    if( room = find_object("/d/changan/duchuan") )
    {
        room->delete("exits/out");
        message("vision", "艄公把踏脚板收起来，说了一声“坐稳喽”，"
            "竹篙一点，扁舟向\n波涛中驶去。\n", room );
    }
    delete("exits/enter");

    remove_call_out("arrive");
    call_out("arrive", 20);
}

void arrive()
{
    object room;
    if( room = find_object("/d/changan/duchuan") )
    {
        room->set("exits/out", "/d/changan/jiaoshi");
        message("vision", "艄公说“到啦，上岸吧”，随即把一块踏脚板"
            "搭上海滩。\n",room );
    }
    remove_call_out("close_passage");
    call_out("close_passage", 20);
}

void close_passage()
{
    object room;
    if( room = find_object("/d/changan/duchuan") ) {
        room->delete("exits/out");
        message("vision","艄公把踏脚板收起来，把扁舟驶向波涛中。\n", room);
        room->delete("yell_trigger"); 
    }
}

int do_yell(string arg)
{
    string dir;

    if( !arg || arg=="" ) return notify_fail("你要吆喝什么？\n");

    if( arg=="boat" ) arg = "船家";
    if( (int)this_player()->query("age") < 16 )
        message_vision("$N使出吃奶的力气喊了一声：“" + arg + "”\n",
            this_player());
    else if( (int)this_player()->query("force") > 500 )
        message_vision("$N吸了口气，一声“" + arg + "”，声音中正平和地远远传"
            "了出去。\n", this_player());
    else
        message_vision("$N鼓足中气，长啸一声：“" + arg + "！”\n",
            this_player());
    if( arg=="船家")
    {
        check_trigger();
        return 1;
    }
    else
        message_vision("江面上远远传来一阵回声：“" + arg +
            "～～～”\n", this_player());
    return 1;
}

void reset()
{
    object room;

    ::reset();
    if( room = find_object("/d/changan/duchuan") )
        room->delete("yell_trigger"); 
}

