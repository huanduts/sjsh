//   added to adm
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
	string msg,start;
	target = offensive_target(me);
	//always use the one who is fighting me as target.

	if( me->is_busy())
		return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不够了！\n");

	if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
		return notify_fail("你精神太差，难以集中精力念咒。\n");

	if( (int)me->query_skill("yuxu-spells", 1) < 60)
		return notify_fail("你还没学会火遁。\n");

	if(environment(me)->query("under_water"))
		return notify_fail("你在水中，没法施用火遁！\n");


	if(!me->is_fighting() )
	{
		message_vision(HIR"$N突然消失在一片火光中了。\n"NOR,me);
		me->add("sen", 50);
		me->add("mana", -100);
		me->move("/d/kunlun/dadian");
		message("vision", HIR+me->name()+"突然从一片火海中走了出来。\n"NOR,
				  environment(me), me);
		tell_object(me, HIR"你的身影突然出现在一片火海中。\n"NOR);
		return 1; 
	}
        return 1;
}

