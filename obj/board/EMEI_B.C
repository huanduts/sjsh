// emei_b.c

inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
        set_name(HIW"仙石碑"NOR, ({ "board" }) );
        set("location", "/d/emei/huayanding.c");
        set("board_id", "emei_b");
        set("long", "这是一块石碑，上面密密麻麻地记着峨嵋派弟子所立的战功。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
