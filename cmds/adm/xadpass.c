// xadpass.c

inherit F_CLEAN_UP;
int main(object me, string arg)
{
        object ob;
        string wiz_status;
        string name,pass;
        int flag=0;
        if( me!=this_player(1) ) return 0;


        if( !arg || sscanf(arg, "%s %s", name, pass)!=2 )
                return notify_fail("格式错误!, xadpass user(ID) user(passwd)\n");
        wiz_status=SECURITY_D->get_status(me) ;
        if ( wiz_status != "(admin)" ) 
        { 
                write (wiz_status + "\n");
                return notify_fail("you r not admin !\n");
        }
        seteuid(getuid());
        if(ob=find_player(name))
        {
 
               if(ob->query_temp("link_ob")) {
                        ob = ob->query_temp("link_ob");
                        flag=1;
                }
        }
        if (!flag) {
                ob = new(LOGIN_OB);
                ob->set("id", name);
                if (!ob->restore())
                        return notify_fail("no such user or user data error\n");
        }

        if( !ob->set("ad_password", crypt(pass,0)) ) {
        write(sprintf("%s 管理密码变更失败！\n",name));
                return 0;
        }

   log_file("static/PASS", sprintf("[%s] %s 修改 %s 的管理密码为 %s (指令:xadpass)\n",
                ctime(time())[0..15], geteuid(this_player(1)), name, pass));

        ob->save();
     write(sprintf("%s 管理密码变更成功。\n",name));

        if(!flag) destruct(ob);
        return 1;
}

