//change.c
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("����", ({"yang guang", "yang", "guang"}));
       set("long","����ɽ���Ĵ���������ܳ�������֮һ��\n");
       set("title", HIM"�����ɵ��Ĵ�����"NOR);
       set("gender", "Ů��");
       set("age", 17);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�ɹ�");
       set("per", 50);
	set("int", 30);
       set("max_kee", 1000);
       set("max_sen", 1000);
       set("sen", 1000);
       set("kee", 1000);
       set("max_gin", 1000);
       set("max_force", 1000);
       set("max_mana", 1000);
       set("mana", 1000);
       set("force", 1000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 800000);
       set("daoxing", 1200000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 120);
       set_skill("literate", 120);
       set_skill("dodge", 120);
       set_skill("force", 120);
       set_skill("parry", 120);
       set_skill("sword", 120);
       set_skill("spells", 120);
       set_skill("emeiforce", 120);
       set_skill("huifeng-sword", 120);
       set_skill("zhutian-bu", 120);
       set_skill("mahayana", 120);
       set_skill("jinding-zhang", 120);
       map_skill("sword", "huifeng-sword");
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       create_family("������", 4, "����");

setup();

           carry_object("/d/obj/cloth/luoyi")->wear();
           carry_object("/d/emei/obj/emeijian")->wield();
        
}

void attempt_apprentice(object ob)

   {
        if ( ob->query_temp("marks/�յ�") ) {
        if ( (int)ob->query("int") <25){
	 command("shake");
	 command("say ��λ" + RANK_D->query_respect(ob) + "�������̫����ʱ�޷��������Ƕ��ҵ��书��\n");
        return;
        }

        command("pat "+ob->query("id"));
        command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������Ƕ��ҷ�����\n");
        command("recruit " + ob->query("id") );
        message("system", HIM""+this_player()->name()+HIW"�����������ڰ����˶���ɽ���¡�\n"NOR,users());
        ob->set("title", HIM"���������ŵ���"NOR);
        ob->set("class","xian" );
              ob->delete_temp("marks/�յ�");


   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) + "�����Ҷ��ҵĵ��ӣ�������ȥ�������ҵ��Լ��Ľ��ɡ�\n");
        return;
}

