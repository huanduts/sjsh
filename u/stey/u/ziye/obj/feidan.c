#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_zha", "zha");
       add_action("do_zha", "fire");
}
void create()
{
       set_name("��ë�ȵ���", ({"fbsdan"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
               set("long",
       "������ʦר�õķ������ĺ�������ר�ŶԸ���Щ�ϲ�������ʦ\n");
               set("value", 0);
               set("unit", "ö");
               set("no_get", 0);
               set("no_drop", 0);
       }
}

int do_zha(string target)
{
       object me, conc;

       me = this_object();


             if(!(conc = find_living(target)))
             {
                   write("û������˻����\n");
                   return 1;
             }

       message_vision(HIR "��ë�ȵ�������$n��\n" NOR, me, conc);


       me->move(environment(conc));

       message_vision(HIR "$N���˹��������һ��ը����\n" NOR, me);
       conc->set_temp("last_damage_from", "��" + me->name() + "ը");
       CHANNEL_D->do_channel(this_object(), "rumor", sprintf("%s����ë�ȵ���ը����������", 
       conc->name(1)));

       conc->set("invisibility",10);  
       conc->set("env/invisibility",0);

        conc->set("immortal",1);
        conc->set("env/immortal",0);


           find_player(target)->reincarnate();
       find_player(target)->delete_temp("apply/name");
       find_player(target)->delete_temp("apply/id");
       find_player(target)->delete_temp("apply/short");
       find_player(target)->delete_temp("apply/long");

       destruct(this_object());
       return 1;
}
