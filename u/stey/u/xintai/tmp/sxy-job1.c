#include <ansi.h>
#include <condition.h>

inherit F_CLEAN_UP;

mapping *sxy = ({ 
         ([ "sxy":"十字街头","where":"/d/city/center"   ]),
         ([ "sxy":"白虎大街","where":"/d/city/baihu-w1"]),   
         ([ "sxy":"白虎大街","where":"/d/city/baihu-w2"   ]),   
         ([ "sxy":"长安城西门","where":"/d/city/ximen" ]),   
         ([ "sxy":"玄武大街","where":"/d/city/xuanwu-n0"]),   
         ([ "sxy":"泾水之滨","where":"/d/changan/wside1"]),   
         ([ "sxy":"泾水桥北","where":"/d/changan/nbridge"]),   
         ([ "sxy":"大官道","where":"/d/changan/broadway1"]),   
         ([ "sxy":"南岳","where":"/d/changan/nanyue"]),   
         ([ "sxy":"南海之滨","where":"/d/changan/southseashore"]),   
         ([ "sxy":"高家大门","where":"/d/gao/gate"]),   
         ([ "sxy":"汴京铁塔","where":"/d/kaifeng/tieta"]),   
         ([ "sxy":"尧王街","where":"/d/kaifeng/yao5"]),   
         ([ "sxy":"古亭道","where":"/d/kaifeng/guting3"]),   
         ([ "sxy":"西湖路","where":"/d/kaifeng/xihu6"]),    
         ([ "sxy":"禹王道","where":"/d/kaifeng/yuwang1"]),    
         ([ "sxy":"辰龙道","where":"/d/city/southjie3"]),    
         ([ "sxy":"开封城门","where":"/d/kaifeng/chengmen"]),    
         ([ "sxy":"长安城东门","where":"/d/city/dongmen"]),    
         ([ "sxy":"望南街","where":"/d/eastway/wangnan5"])    
                });
                
mapping query_sxy()
{
        return sxy[random(sizeof(sxy))];
}

int update_condition(object me, int duration)
{
        mapping sxy,sxywhere;
        object ob;
        sxy = this_object()->query_sxy();
        sxywhere = sxy["where"];
            
   if( duration < 1 )
   {
      tell_object(me, HIB "你的守卫长安任务时限到了，快回去报告吧\n" NOR );     
      me->delete("job/sxy");
      me->set("job/sxy-done",1);   
      return 0;
   }
   if( !living(me) ) {
      message("vision", me->name() + "大呼道：守城不利，天亡我大唐呀！！\n", environment(me), me);
   }
   else {
      tell_object(me, HIB "忽然城里有人大呼，叛军打到" + sxy["sxy"] + "来了！\n" NOR );
        ob = new("/d/obj/npc/yaoguai");
        ob->move(sxywhere);
   }

   me->apply_condition("sxy-job", duration - 1);

   if( duration < 1 )
   {
      tell_object(me, HIB "你的守长安任务时限到了，快回去报告吧\n" NOR );
      me->delete("job/sxy");
      me->set("job/sxy-done",1);        
      return 0;
   }
   return CND_CONTINUE;
}

