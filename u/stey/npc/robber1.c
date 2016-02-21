#include <ansi.h>
inherit NPC;
#include "mgb2.h"
void create()
{ 
        set_name("魔界妖神兵士",({"mojie bingshi"}));
        set("long","这是一位攻打天宫的魔界妖神。\n");
        set("gender", "男性" );
        set("age", random(30)+14);
        
        set("vendetta/authority", 1);
        set("attitude", "peaceful");    
        set("bellicosity", 100000);
         set("max_kee", 1000);
         set("eff_kee", 1000);
         set("qi", 1000);
        set("max_sen", 900);
        set("shen", 900);
        set("froce", 500);
        set("max_force", 500);
        set("jiali", 20);
        set("shen_type", -10);
        set("combat_exp", 200000);

        set_skill("force", 80); 
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
     
        setup();
        carry_object(__DIR__"wandao")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void do_change(object ob)
{
      object me;
      mapping hp_status, skill_status;
      string *sname;
      int i, temp;
      me = this_object();
      ob = this_player(); 

      
      if ( mapp(skill_status = me->query_skills()) ) {
                skill_status = me->query_skills();
                sname  = keys(skill_status);
                temp = sizeof(skill_status);
                for(i=0; i<temp; i++) {
                        me->delete_skill(sname[i]);
                }
      }

    if ( mapp(skill_status = ob->query_skills()) ) {
                skill_status = ob->query_skills();
                sname  = keys(skill_status);
                temp = skill_status[0];
                for(i=0; i<sizeof(skill_status); i++) {
                  if(sname[i]=="force")i++;
                  if (skill_status[sname[i]] >= temp)
                  { temp = skill_status[sname[i]];}
              }
        }

//        temp=ob->query_skill("force");
        me->set_skill("zileidao", temp-random(50));
        me->set_skill("unarmed",temp-random(50));
        me->set_skill("huxiaoquan",temp-random(50));
        me->set_skill("dodge", temp-random(50));
        me->set_skill("blade", temp-random(50));
        me->set_skill("parry", temp-random(50));

        me->map_skill("blade","zileidao");
        me->map_skill("parry","zileidao");
        me->map_skill("unarmed","huxiaoquan");
        prepare_skill("unarmed", "huxiaoquan");



/* copy hp */

        hp_status = ob->query_entire_dbase();
        me->set("str", hp_status["str"]+random(2));
        me->set("int", hp_status["int"]);
        me->set("con", hp_status["con"]+random(2));
        me->set("cps", hp_status["cps"]+random(10));
        me->set("combat_exp",hp_status["combat_exp"]/2);

            me->set("ygjg",ob);
}


void die()
{
            object ob;
           object robber;
           object room;
             ob=query_temp("last_damage_from");
        room = environment(ob);   
                  if(ob->query_temp("start_job")==1)
                  {
                        ob->add_temp("killed_mgb",1);
                  }
                  else
                        ob->add_temp("help_killed",1);
                 switch( random(3) ) {
                        case 0:
                        message_vision(HIR"城下又爬上来一个魔界妖神兵士。\n" NOR,ob); 
                        robber=new(__DIR__"robber1");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 1:
                        message_vision(HIR"城下又爬上来一个魔界妖神将领。\n" NOR,ob); 
                        robber=new(__DIR__"robber2");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        case 2:
                        message_vision(HIR"城下又爬上来一个魔界妖神高手。\n" NOR,ob); 
                        robber=new(__DIR__"robber3");
                robber->do_change(ob);
                        robber->move(room);
                        robber->kill_ob(ob);
            ob->kill_ob(robber);
                        break;
                        }       

              message_vision("$N扑在地上挣扎了几下，口中喷出几口"HIR"鲜血"NOR"，死了！\n",this_object());
                   destruct(this_object());
            return;
}

