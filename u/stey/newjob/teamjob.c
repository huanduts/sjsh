#include <ansi.h>
mixed names = ({
        ({
        "������","������","������","������","���չ�",
        "��ȸ��","ͨ����","ն��̨","���������","���԰԰��",
        "��ǧ�����԰","��ϼͤ",       
        }),
        ({
         "ħ��","ħ����","ħ���","ħ����","�칬��ʿ","��ʥ���","���","���","���",
		 "����","��ɨ��ʿ","������Ů",
        }),
        });

string ask_jianxi()
{     object guo,ob;
      object *team;
	  int i=0,count=0,minexp,maxexp;
      string where;
	  guo =this_object();
	  ob=this_player();
	  
	  if (guo->query_condition("zzz_busy"))
	  return "��û���յ��κ���Ϣ��";//guo busy time 
	  
	  if(ob->query("combat_exp")<500000)
      return  "��Ĺ���̫���ˡ�";//too low exp
      team=ob->query_team();
      count=sizeof(team);
	 // write("\n"+sprintf("%d",count));
	  if(count<=1)
      return "����һ����?"; //too few people
      if(count>=5)
	  return "���²������"; //too many people
	  minexp=team[0]->query("combat_exp");
	  maxexp=minexp;
      
	  for(i=1;i<count;i++)
      { if(team[i]!=0)
	  { if(team[i]->query("combat_exp")<minexp)
	    minexp=team[i]->query("combat_exp");
		if(team[i]->query("combat_exp")>maxexp)
        maxexp=team[i]->query("combat_exp");
	  }
	  }
	  if ((maxexp-minexp)>800000)
      return "���ǵ��书���̫���⡣";//exp too far
     //check ok
      
	  where=names[0][random(40)];
	  guo->apply_condition("zzz_busy",30);
	  ob->set_temp("team_count",count);
	  ob->apply_condition("zzz_busy",60);
	  for(i=0;i<count;i++)
	 //team[i]->set_temp("zzz_job_zhuji",1);
	  team[i]->apply_condition("zzz_busy",60);
	  for(i=100;i*i*i/10<=maxexp;i++);
      call_out("job",60,ob,where,i,count+2);
     // message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·?\n"NOR, obj);
	  return    "�Ҹյõ���Ϣ����һ��ħ���ϸ͵��������칬���򹬱��\n"+
		        "          ���ǸϿ�ȥ"+where+"�����أ������򹬱����͵ؼ���(jihui)��\n"+
			    "          ħ��϶����������Ӧ�������С�ġ�"; 
}


void job(object ob,string where,int maxpot,int ckiller)
{    object *team,obj,gift;
      
     int i=0;
    // team=ob->query_team();
	 //for(i=0;i<sizeof(team);i++)
	 if(environment(ob)->query("short")==where&&ob->query_condition("zzz_busy"))
	 {  if (ckiller>0)
	    {if (random(20)>16)
			{ obj=new(__DIR__"mengbing");   
	          obj->do_copy(ob,maxpot,3);
	          obj->set("title",HIY"ħ���ͳ��"NOR);     
              obj->move(environment(ob));
              obj->kill_ob(ob);
			}
		     else 
			{ obj=new(__DIR__"mengbing"); 
		      obj->do_copy(ob,maxpot,1);
	          //obj->set("title",HIY"�ɹŰٷ�"NOR);
	          obj->move(environment(ob));
              obj->kill_ob(ob);
	          obj=new(__DIR__"mengbing");
		      if (random(20)>10)
			  {obj->do_copy(ob,maxpot,2);
	           obj->set("title",HIY"ħ��Сͳ��"NOR);
			  }
			   else 
               obj->do_copy(ob,maxpot,1);
		       obj->move(environment(ob));
               obj->kill_ob(ob);
			 }  
	  	  call_out("job",120,ob,where,maxpot,ckiller-1);
	    }else 
		 {if (present("menggu dahan",environment(ob)))
			{//present menggu dahan,then mission failed
			 tell_room(environment(ob),HIC"ħ�������ӻ��֣�ʾ��ħ���ϸ���ߡ�\n��ϸ�Ҵ�ææ���뿪�ˡ�\n"NOR);
             tell_object(ob, HIY "\nħ���ϸ�����ˣ�������ʧ�ܣ�\n" NOR); 
			}
		   else{
				obj=new(__DIR__"jianxi"); 
				obj->do_copy(ob,maxpot);
				obj->set("title",HIR"ħ���ϸ"NOR);
				obj->move(environment(ob));
				message_vision(HIY"$N��Ц���ѣ���ƾ���Ǽ���Ҳ�뵲ס�ҵ�ȥ·?\n"NOR, obj);
				obj->kill_ob(ob);
				gift=new(__DIR__"mijian");
				gift->set_temp("host",ob->query("id"));
				gift->move(obj);
				}
		}
	 }
      else
      tell_object(ob, HIY "\nħ���ϸ͵͵����˳ǣ�������ʧ�ܣ�\n" NOR); 
	  
	  return;
}			//make killer
       
	   
       
     



