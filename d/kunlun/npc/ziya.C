// add by xiuxiu
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("������", ({"jiang ziya","jiang","ziya"}));
       set("long","�������У���Ԫʼ�����������ж��꣬�����ܳ�������º󷵻����ء�\n");
       set("title",HIG"�ܳ���������"NOR);
       set("gender", "����");
       set("age", 51);
       set("class", "kunlun");
       set("attitude", "friendly");
       set("rank_info/respect", "����");
       set("per", 30);
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
       set("daoxing", 1800000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 180);
       set_skill("literate", 180);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("sword", 180);
       set_skill("mace", 180);
       set_skill("spells", 180);
       set_skill("xuanzong-force", 180);
       set_skill("wugou-jian", 180);
       set_skill("lingyunbu", 180);
       set_skill("yuxu-spells", 180);
       set_skill("kaitian-zhang", 180);
       set_skill("dashen-bian", 180);
       map_skill("sword", "wugou-jian");
       map_skill("mace", "dashen-bian");
       map_skill("unarmed", "kaitian-zhang");
       map_skill("dodge", "lingyunbu");
       map_skill("force", "xuanzong-force");
       map_skill("spells", "yuxu-spells");
       map_skill("unarmed", "jinding-zhang");
       create_family("����ɽ���鶴", 2, "����");

setup();

           carry_object("/d/lingtai/obj/cloth")->wear();
          carry_object("/d/kunlun/obj/mace")->wield();
        
}

void attempt_apprentice(object ob,object me)
   {
   if ( (string)ob->query("family/family_name")=="����ɽ���鶴") {
   if (((int)ob->query("daoxing") < 800000 )) {
   command("say ���ֵĵ��в���Щ������ô��ѧ�ҵı޷��أ�" + RANK_D->query_respect(ob) + "������Ŭ������ѧ���湦��\n");
   return;
   }
              if (me->query_skill("yuxu-spells")  < 110 ) {
   command("say ���ֵ������ɷ�����Щ������ô��ѧ�ҵı޷��أ�" + RANK_D->query_respect(ob) + "������Ŭ������ѧ���湦��\n");
   return;
   }

        command("smile");
   command("say �ü����ü���ʱ����ħ���������ֺ��С���"  + RANK_D->query_respect(ob) +"����������֮ʿȴ���ټ���\n");;
        command("say �ܺã�" + RANK_D->query_respect(ob) + "���Ŭ�������ձض��гɡ�\n");
       command("recruit " + ob->query("id") );
        ob->set("title", HIM"����ɽ���鶴����޴���"NOR);
        ob->set("class","kunlun" );
   return;
   }
   command("shake");
   command("say �Ϸ������ŵ��ӣ�" + RANK_D->query_respect(ob) + "������Ѱ���˰ɣ�\n");
        return;
}


