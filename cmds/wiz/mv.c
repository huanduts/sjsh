// mv.c
// Modified by island@fyzx

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        string src, dst;
 
        seteuid(geteuid(me));
        if (! arg || sscanf(arg, "%s %s", src, dst) != 2)
                return notify_fail("指令格式: mv <原档名> <目标档名> \n");
 
        src = resolve_path(me->query("cwd"), src);
        dst = resolve_path(me->query("cwd"), dst);
 
        if (file_size(src) == -1)
        {
                write("源文件名字错误。\n");
                return 1;
        }

        SECURITY_D->backup_file(dst);
        if (rename(src, dst) == 0)
        {
                write("Ok.\n");
                log_file("cmds/file/mv", 
                sprintf("[%s] %s mv %s to %s \n",ctime(time()), me->query("id"), src, dst ) );
        }
        else
        {
                if (! SECURITY_D->valid_read(src, me, "ls"))
                {
                        write("源文件名字错误。\n");
                        return 1;
                }
                write("你没有足够的读写权利移动文件。\n");
        }
        return 1;
}
 
int help(object me)
{
        write(@HELP
指令格式 : mv <原档名> <目标档名>
 
此指令可让你修改某个档案或目录名称。

see also: cp, rm
HELP );
        return 1;
}


