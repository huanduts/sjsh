// shishi3.c
// by lestat/2000.1.31

inherit ROOM;
#include <ansi.h>;
void create()
{
	set("short", "��ң��");
	set("long", @LONG
������һ�������ʯ�ң���֮������κ�һ������������������һ����
��������ľ�Ƴɵ����,���������ȴ�յ�������һ����Ҳû�С�
���л���һ�ź�����(bed)��
LONG );
	set("exits", ([
		"south" : __DIR__"shidong",
	]));
	set("item_desc", ([
		"bed"   : "һ��ǧ�꺮����,����������ƶ�һ������\n",
		"shelf" : "���������һ��С�����������֮����������֮�磬�����������Ϊ��ң����\n",
	]));
		set("objects",([
		__DIR__"obj/guo" : 3,
	]));
//	set("book1_count",1);
	set("no_clean_up", 0);
	setup();
}

/*void init()
{
       add_action("do_strike","strike");
        add_action("do_move","move");
}

int do_strike(string arg)
{
        object me;

        me=this_player();
        if(!arg || arg!="shelf") return 0;
        message_vision("$N���ſ��ţ���Ȼ�͵�һ������ܴ�ȥ�������ܡ������������������˼�����\n",me);
	if ( random(100) > 94)
	{
message_vision("��Ȼ��$N����һ�������ٺٵؼ�Ц�����������ϵ�������\n",me);
message_vision("���ţ���֪���������һ֧������������$N��\n",me);
		me->die();
	}
	if (random(100)==50 && !present("miji1",me) && query("book1_count")>=1)
	{
     		add("book1_count", -1);
		me=new("/clone/book/strike_book");
		me->move(__DIR__"shishi3");
message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+this_player()->query("name")+"�õ����Ʒ���������\n"NOR, users());
		tell_object(me, "ͻȻž��һ������һ������������ϵ���������\n");
	}
        return 1; 
}
*/
int do_move(string arg)
{
	object me;

	me=this_player();
	if(!arg || arg!="bed") return 0;
	message_vision("$N������С���ƿ����������澹Ȼ��һ������ͨ����\n",me);
	me->move(__DIR__"midao1");
	tell_object(me,"������һ���¡¡���������㶨��һ�����Լ��Ѿ�����������ͨ�����ˡ�\n");
	return 1; 
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
		add_action("do_move","move");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\nɴ������һ����$N���˽�����\n" NOR, me);
                return 1;
}