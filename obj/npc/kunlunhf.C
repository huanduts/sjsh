// jingang.c

#include <ansi.h>

inherit NPC;

void create()
{
	object ob1, ob2;
	
	 set_name("������", ({ "leizhen zi" }) );
        set("long", "����һλ�콫��ר�ŵ������ػ���֮��\n");
	 set("attitude", "friendly");
        set("max_gin", 1200);
        set("max_kee", 1200);
        set("max_sen", 1200);
        set("max_mana", 1200);
        set("mana", 1200);
        set("max_force", 1200);
        set("force", 1200);
	 set("str", 40);
        set("cor", 40);
        set("cps", 40);

        set("combat_exp", 800000);
        set_skill("dashen-bian", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("mace", 100);
        set_skill("lingyunbu", 100);

	map_skill("dodge", "lingyunbu");
	map_skill("mace", "dashen-bian");
	map_skill("parry", "dashen-bian");
        setup();

        ob1=carry_object("/d/obj/armor/jinjia");
	ob1->wear();
	ob1->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
        ob2=carry_object("/d/obj/weapon2/mace/mace");
	ob2->wield();
	ob2->set("no_sell", "�ƹ�����һ�۵����ⶫ��һ�������ӵ�Ʒ����Ҫ����Ҫ��\n");
}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	message("vision",
               HIY + name() + "˵���������ӷ���ٻ��������Ѿ���ɻ������񣬾ʹ˸�ǣ�\n\n"
                + name() + "����һƬ�׹⣬��ʧ�����ˡ�\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
                HIB "ֻ���䣡��һ����һ���׹�һ�����ֳ�һ��������׵������ӡ�\n\n"
                + name() + "˵���������ӷ���ٻ�������������\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
}