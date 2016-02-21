inherit ROOM;
void create()
{
        set("short", "�ٺ�ɽ��");
        set("long", @LONG
������ˮ�鲻ʱ�ؽ���ɽ�������²������꣬����������ɽ��
�ںܰ�������Լ���ɿ�������ռ�ܴ�������ǰ��ȥ������ǰ��
�м�����С�Ķ��ֱ�ͨ������ɽ���С��������ڶ��ڼ��䣬����
����������ס�ˡ�
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
	//   "west" : __DIR__"waterfall",
	]));
        set("objects", ([
                "/obj/money/thousand-cash" :1,
                        ]) );
	set("frozen",10);
        set("item_desc", ([
                "����": "
���ǰѺ����ҿ��������򣩣�����û�취����ɽ���С�\n",
        ]) );

        set("coor/x",230);
	set("coor/y",-290);
	set("coor/z",40);
	setup();
}

void init()
{
	add_action("do_break", "break");
}

int do_break()
{
	object me=this_player();
	int i;
	i=(int)me->query("force_factor")*5 + (int)me->query("str");

	if( this_object()->query("open") )
		return notify_fail("�����Ѿ�������һ��С�������������ڷѾ��ˡ�\n");

	message_vision("$N������Ѻ����ҿ���\n", me);
	
	if( i > 200)
		tell_room(this_object(), "�����е��ɶ��ˡ�����\n");
	else if( i > 150)
		tell_room(this_object(), "�����ҿ���һ�㡭����\n");
	else
		tell_room(this_object(), "��������û��ʲô����������\n");

	this_object()->add("break", i);
	me->receive_damage("kee", 30);
	me->add("force", -(int)me->query("force_factor"));
	
	if( (int)me->query("force") < 0 ){
		me->set("force", 0);
	}

	if ( (int)this_object()->query("break") > 3000 ){
		tell_room(this_object(),"������ķ�϶�㹻һ�������ȥ�ˡ�\n");
		this_object()->set("open", 1);
		set("long", @LONG

�������̧ͷ��ȥ���ڰ�����ϡ����ɽ��������͹��ƽ����������
����ٽ�֯�ɵĳ�Ѩ��Ҳ��֪����ι̶�������ģ��պ���һֻС
���Ѩ�зɳ����ض�������һ�ܣ������������˻�ȥ���������Ǻ�
����
LONG);
		this_object()->set("exits/enter", "/d/youxia/leftcave");
	}
	return 1;
}

int valid_leave(object me, string dir)
{
        if (dir == "enter" ) {
		if( !this_object()->query("exits/enter"))
			return notify_fail("�������û�г�·��\n");
		message_vision("$N�����Ӻ�����϶�����˳�ȥ��\n", me);
		return 1;
        }   
	
}




