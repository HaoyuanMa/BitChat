#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <mysql/mysql.h>

int clientfd[1024]={0};
int used[1024]={0};
int id = 49999;
MYSQL mysql;
int userLogin(char *buf,int confd)
{
//"2|501|123"
        MYSQL_RES *result;
        MYSQL_ROW  row;
        MYSQL_ROW  row_1;

        char userName[32]={0};
        char userId[32]={0};
        char pWord[32]={0};
        sscanf(buf+2,"%[^|]|%s",userId,pWord);
        char sqlStr[1024]={0};
        char sendBuf[512]={0};
        int count;    
 
        sprintf(sqlStr,"%s'%s'", "select pWord from user where userId=",userId);
        printf("sqlStr=%s\n",sqlStr);
/*
        mysql_init(&mysql);
        if(mysql_real_connect(&mysql,"127.0.0.1","root","root","chatroom",0,NULL,0) == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
 */     
	if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
      	}

        if(row = mysql_fetch_row(result))
        {
                      
                if(strcmp(row[0], pWord) == 0)
                {
                         sprintf(sqlStr,"%s'%s'", "update user set Online = true where userId = ", userId);
                        printf("sqlStr=%s\n",sqlStr);
                        if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                return -1;
                        }
	               
                         sprintf(sqlStr,"%s%d%s'%s'", "update user set confd =",confd," where userId = ", userId);
                         printf("sqlStr=%s\n",sqlStr);
                         if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                return -1;
                        }
                    
                        printf("登录成功\n");

                        strcpy(sendBuf,"1|登录成功|");

                       //查询用户昵称
                         sprintf(sqlStr,"%s'%s'", "select uName from user where userId=",userId);
                        printf("sqlStr=%s\n",sqlStr);
                       if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                 return -1;
                         }
			result = mysql_store_result(&mysql);
			 if(result== NULL)
  			{
				printf("%s\n",mysql_error(&mysql));
               			 return -1;
			}
                         count=mysql_num_rows(result);
                         if(count)
                        { row_1= mysql_fetch_row(result);
                         
                         strcpy(userName ,row_1[0]);
                         strcat(sendBuf,userName);
                        }
                      
                 }
                else
                {
                        printf("密码错误\n");
                        strcpy(sendBuf,"0|密码错误\n");
                }
        }else
        {
                strcpy(sendBuf,"用户不存在\n");
                printf("0|用户不存在\n");
        }

        send(confd,sendBuf,strlen(sendBuf),0);

        sprintf(sqlStr,"%s'%s'", "select friendId from friendList  where userId = ",userId);
         printf("sqlStr=%s\n",sqlStr);
         if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
          while(row = mysql_fetch_row(result))
        {
                char newbuf[1024] = {0};
                strcpy(newbuf,"8|");
                strcat(newbuf,row[0]);

                findFriend(newbuf);
           }



        return atoi(userId);
}

int userRegister(char *buf,int confd)
{
//"1|Cindy|123|how old am I|18"
      //  MYSQL mysql;
        MYSQL_RES *result;
        MYSQL_ROW  row;

        char uName[32]={0};
        char pWord[32]={0};
        char Question[1024]={0};
        char Answer [1024]={0};
        char userId[7]= {0};
         id++;
        sprintf(userId,"%d",id);    
        sscanf(buf+2,"%[^|]|%[^|]|%[^|]|%s",uName,pWord,Question,Answer);
        char sqlStr[1024]={0};
        char sendBuf[512]={0};

        sprintf(sqlStr,"%s'%s'%s'%s'%s'%s'%s'%s'%s'%s'%s", "insert into user (userId,uName,pWord,Question,Answer,Online,confd) values (", userId , ",",uName , "," , pWord , "," ,Question, "," ,Answer , ",0,0)");
        printf("sqlStr=%s\n",sqlStr);

        /*mysql_init(&mysql);
        if(mysql_real_connect(&mysql,"127.0.0.1","root","root","chatroom",0,NULL,0) == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }*/
        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                printf("注册失败\n");

                strcpy(sendBuf,"0|注册失败\n");
                return -1;
        }

        

       strcpy(sendBuf,"1|注册成功\t你的ID是:");
       strcat(sendBuf,userId); 

        send(confd,sendBuf,strlen(sendBuf),0);

}
int Addfriend(char *buf)
{
//"4|501|502"
        //MYSQL mysql;
        MYSQL_RES *result;
        MYSQL_ROW  row;
        MYSQL_ROW  row_1;

        char userId[32]={0};
        char friendId[32]={0};
        sscanf(buf+2,"%[^|]|%s",userId,friendId);
        char sqlStr[1024]={0};
        char sendBuf[512]={0};
        char friendName[32]={0};
        char userName[32]={0};
        char newbuf_1[32]={0};
        strcpy(newbuf_1,"8|");
        strcat(newbuf_1,userId);
        printf("%s",newbuf_1);
         
        char newbuf_2[32]={0};
	strcpy(newbuf_2,"8|");
        strcat(newbuf_2,friendId);
        printf("%s",newbuf_2);


        sprintf(sqlStr,"%s", "select userId from user");
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }


        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        while(row = mysql_fetch_row(result))
       {
        
    
                 if(strcmp(row[0],friendId) == 0)
                {
                       
                        printf("查询用户昵称\n");
                      
                        //查询好友昵称
                        sprintf(sqlStr,"%s'%s'", "select uName from user where userId=",friendId);
       		        printf("sqlStr=%s\n",sqlStr);
        	        if(mysql_query(&mysql,sqlStr) != 0)
	                {
                                printf("%s\n",mysql_error(&mysql));
                                 return -1;
                         }
                         result = mysql_store_result(&mysql);
                         row_1= mysql_fetch_row(result);
                         strcpy(friendName ,row_1[0]);
                        //查询用户昵称
                         sprintf(sqlStr,"%s'%s'", "select uName from user where userId=",userId);
                        printf("sqlStr=%s\n",sqlStr);
                       if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                 return -1;
                         }
                         result = mysql_store_result(&mysql);
                         row_1= mysql_fetch_row(result);
                         strcpy(userName ,row_1[0]);

                         //鍦ㄥソ鍙嬪垪琛ㄩ噷娣诲姞濂藉弸鍏崇郴
                        sprintf(sqlStr,"%s'%s'%s'%s'%s'%s'%s", "insert into friendList(userId,friendId,friendName) values(",userId,",",friendId,",",friendName,")");
       		        printf("sqlStr=%s\n",sqlStr);

                         if(mysql_query(&mysql,sqlStr) != 0)
		         {
                		printf("%s\n",mysql_error(&mysql));
               			 return -1;
       			 }

                       sprintf(sqlStr,"%s'%s'%s'%s'%s'%s'%s", "insert into friendList(userId,friendId,friendName) values(",friendId,",",userId,",",userName,")");
                        printf("sqlStr=%s\n",sqlStr);

                         if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                 return -1;
                         }
                        findFriend(newbuf_1);
                        findFriend(newbuf_2);
                        strcpy(sendBuf,"1|添加成功\0");
                        break;
                }
                else
                {
                        printf("用户不存在\n");
                        strcpy(sendBuf,"0|用户不存在\0");
                }
          }

        sprintf(sqlStr,"%s'%s'", "select confd from user where userId= ",userId);
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
         if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }
       row=mysql_fetch_row(result);
       int confd =atoi(row[0]);
    
    send(confd,sendBuf,strlen(sendBuf),0);
        
}

int findFriend(char * buf)
{

        char userid[32]={0};
        MYSQL_RES *result;
        MYSQL_ROW  row;
        int len;
        char sqlStr[1024]={0}; 
        sscanf(buf+2,"%s",userid);


        sprintf(sqlStr,"%s%s", "select confd from user where userId= ",userid);
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
         if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        row = mysql_fetch_row(result);
        int confd =atoi(row[0]);

        sprintf(sqlStr,"%s'%s'%s", "select friendId, friendName ,Online from friendList,user where friendList.userId = ",userid,"and user.userId=friendList.friendId");
	 printf("sqlStr=%s\n",sqlStr);

       /* if(mysql_real_connect(&mysql,"127.0.0.1","root","root","chatroom",0,NULL,0) == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }*/
        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
        char sendBuf[1024]={0}; 
        while(row = mysql_fetch_row(result))
        {
             
               
                  strcat(sendBuf,row[0]);
                  strcat(sendBuf,"|");
                  strcat(sendBuf,row[1]);
                  strcat(sendBuf,"|");
                  strcat(sendBuf,row[2]);
                  strcat(sendBuf,"|");
       
   
                 
        }
       send(confd,sendBuf,strlen(sendBuf),0);

}

void findHistory(char *buf)
{
//6|50001|50002
        char userid[32]={0};
        char friendid[31]={0};
        int confd;
        char sendBuf[1024]={0};
        int count;
        MYSQL_RES *result;
        MYSQL_ROW  row;
        char sqlStr[1024]={0};
        sscanf(buf+2,"%[^|]|%s",userid,friendid);
     
        sprintf(sqlStr,"%s'%s'%s'%s'%s'%s'%s'%s'%s", "select time,message,senderId,receiverId from record where (senderId= ",userid,"and receiverId = ",friendid,")or (senderId = ",friendid,"and receiverId =",userid,")");
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }
         count=mysql_num_rows(result);
          sprintf(sendBuf,"%s","6");
 

         if(count>0)    
	 {   
               while(row= mysql_fetch_row(result))
                {
		  strcat(sendBuf,"|");
                  strcat(sendBuf,row[0]);
		  strcat(sendBuf,"|");
                  strcat(sendBuf,row[1]);
		  strcat(sendBuf,"|");
                  strcat(sendBuf,row[2]);
                  strcat(sendBuf,"|");
                  strcat(sendBuf,row[3]);

		 }
	}

 sprintf(sqlStr,"%s%s", "select confd from user where userId= ",userid);
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
         if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }
        row = mysql_fetch_row(result);

        confd =atoi(row[0]);
   send(confd,sendBuf,strlen(sendBuf),0);

}

int sendMessage(char *buf)
{//5|2019:09:03:10:26:25|hello|50000|50004
        char sendbuf[1024] = {0};
        char time[50] = {0};
        char sender[32] = {0};
        char senderName[32] ={0};
        char receiver[32] = {0};
        char message[1024] = {0};
        char sqlStr[1024] = {0};
        int isOnline = 0;
        int confd;
        MYSQL_RES *result;
        MYSQL_ROW row;

        sscanf(buf+2,"%[^|]|%[^|]|%[^|]|%s",time, message, sender, receiver);
        
        sprintf(sqlStr, "%s%s","select Online, confd from user where userId = ", receiver);
        printf("%s\n",sqlStr);

        /*mysql_init(&mysql);
        if(mysql_real_connect(&mysql,"127.0.0.1","root","644999","chatroom",0,NULL,0) == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }*/
        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }                
        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
        row = mysql_fetch_row(result);
        if (row[0][0]== '1')
            isOnline = 1;
        confd = atoi(row[1]);

 sprintf(sqlStr, "%s%s","select uName from user where userId = ", sender);
        printf("%s\n",sqlStr);
 if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
        row = mysql_fetch_row(result);
        strcpy(senderName ,row[0]);
        if(isOnline)
        {
                sprintf(sendbuf, "5|%s|%s|%s|%s", time, message ,sender,senderName);
                send(confd, sendbuf, strlen(sendbuf), 0);
        
        }
        sprintf(sqlStr, "insert into record values('%s', '%s', '%s', '%s', %d)", time, sender, receiver, message, isOnline);
        printf("%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }    

        

}
void updateConfd(char *buf,int confd)
{//9|50000
  char userId[32]={0};
  char sqlStr[1024]={0};
  char newconfd[32]={0};
  char sendBuf[1024]={0}; 
 int count;
 MYSQL_RES *result;
 MYSQL_ROW row;


  sprintf(newconfd,"%d",confd); 

 sscanf(buf+2,"%s",userId );
                  
  sprintf(sqlStr,"%s%s", "update user set Online =true where userId= ", userId);
   printf("sqlStr=%s\n",sqlStr);

  if(mysql_query(&mysql,sqlStr) != 0)
   {
       printf("%s\n",mysql_error(&mysql));
       return ;
  
  }
  
  sprintf(sqlStr,"%s'%s'%s'%s'", "update user set confd =",newconfd,"where userId= ", userId);
   printf("sqlStr=%s\n",sqlStr);

  if(mysql_query(&mysql,sqlStr) != 0)
   {
       printf("1%s\n",mysql_error(&mysql));
       return ;
   }

sprintf(sqlStr,"%s'%s'%s", "select time,message,senderId,user.uName from record,user where record.sended =false and record.receiverId= ", userId,"and user.userId= record.senderId");
                        printf("sqlStr=%s\n",sqlStr);

                        if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("1%s\n",mysql_error(&mysql));
                                return ;
                        }
                        result = mysql_store_result(&mysql);
                          if(result == NULL)
                        {
                                printf("2%s\n",mysql_error(&mysql));
                                 return;
                        }
                          count=mysql_num_rows(result);
                        if(count>0)
                        {     
                               while(row= mysql_fetch_row(result))
 	            	       {
                               strcat(sendBuf,"5|");
                               strcat(sendBuf,row[0]);
                               strcat(sendBuf,"|");
                               strcat(sendBuf,row[1]);
                               strcat(sendBuf,"|");
                               strcat(sendBuf,row[2]);
                               strcat(sendBuf,"|");
                               strcat(sendBuf,row[3]);
                               send(confd,sendBuf,strlen(sendBuf),0);

                              }

                       sprintf(sqlStr,"%s'%s'", "update record set sended =true where sended =false and receiverId= ", userId);
                        printf("sqlStr=%s\n",sqlStr);

	                        if(mysql_query(&mysql,sqlStr) != 0)
                	        {
                                	printf("1%s\n",mysql_error(&mysql));
                                	return ;
                       	        }
                  }
                 findFriend(buf);
                       

}

int offline(char *buf)
{//0|50000
        char userId[32] = {0};
        char friendId[32] = {0};
         int i;
        char sqlStr[1024]={0};
        int confd;
	 MYSQL_RES *result;
         MYSQL_ROW row;

        sscanf(buf+2,"%s",userId);
        sprintf(sqlStr,"%s%s%s", "update user set Online = 0 where userId = ", userId," and Online = 1" );
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
                 
        sprintf(sqlStr,"%s%s", "select confd from user where userId= ",userId);
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        result = mysql_store_result(&mysql);
         if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
        row=mysql_fetch_row(result);

        confd =atoi(row[0]);
       
        for(i = 0; i < 1023; i++)
        {
                if(clientfd[i] == confd)
                {
                        used[i] = 0;
                        break;
                }
        
       }
          sprintf(sqlStr,"%s'%s'", "select friendId from friendList  where userId = ",userId);
	 printf("sqlStr=%s\n",sqlStr);
         if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }
          while(row = mysql_fetch_row(result))
        {
                char buf[1024] = {0};
                strcpy(buf,"8|");
                strcat(buf,row[0]);            
             
                findFriend(buf);
           }
      return  0;



}
void transfer(char *buf)
{//d|500001|500000(receiver|sender)
char sqlStr[1024]={0};
char senderId[32]={0};
char receiverId[32]={0};
char sendBuf[1024]={0};
int confd;
 MYSQL_RES *result;
 MYSQL_ROW row;

strcpy(sendBuf,buf);
sscanf(buf+2,"%[^|]|%s",receiverId,senderId);

 sprintf(sqlStr,"%s%s", "select confd from user where userId= ",senderId);
        printf("sqlStr=%s\n",sqlStr);

        if(mysql_query(&mysql,sqlStr) != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
         if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }
        row=mysql_fetch_row(result);

        confd =atoi(row[0]);
 send(confd,sendBuf,strlen(sendBuf),0);

}

void * handClient(void *arg)
{
        char buf[1024]={0};
        char sqlStr[1024]={0};
        int userId;
        int *p = arg;
        int confd = *p;
       
        while(1)
        {
		memset(buf,0,sizeof(buf));
                 if(recv(confd,buf,sizeof(buf),0) == 0)
                {
                    
                    /*    mysql_init(&mysql);
                        if(mysql_real_connect(&mysql,"127.0.0.1","root","root","chatroom",0,NULL,0) == NULL)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                return ;
                        }
                        if(mysql_query(&mysql,sqlStr) != 0)
                        {2
                                printf("%s\n",mysql_error(&mysql));
                                return ;
                        }
                       int i;
                         for(i = 0; i < 1023; i++)
                        {
                                if(clientfd[i] == confd)
                                {
                                        used[i] = 0;
                                        break;
                                }
                        }

                        */

                          sprintf(sqlStr,"%s%d%s", "update user set Online = 0 where userId = ", userId," and Online = 1" );
                        printf("sqlStr=%s\n",sqlStr);

                        if(mysql_query(&mysql,sqlStr) != 0)
                        {
                                printf("%s\n",mysql_error(&mysql));
                                return ;
                        }
     
                         int i;
                         for(i = 0; i < 1023; i++)
                        {
                                if(clientfd[i] == confd)
                                {
                                        used[i] = 0;
                                        break;
                                }
                        }

 
                        pthread_exit(NULL);
                }
                printf("recv=%s\n",buf);
                switch(buf[0])
                {
                        case '0':
                                offline(buf);
                                break;
                        case '1':
                               userId=userRegister(buf,confd);
                                break;
                        case '2':
                               
                                userLogin(buf,confd);
                                break;
                       // case '3':find_password
                       case '4':
                                Addfriend(buf);
                                 break;
                       case '5':
                               sendMessage(buf);
                               break;

                       case '6':
                                findHistory(buf);
                                break;
                     /*  case '8':
           			findFriend(buf);
                                break;*/
                       case '9':
                                updateConfd(buf,confd);
                                break;
                       case 'd':
                                transfer(buf);
                                break;
                }
                //send(confd,buf,strlen(buf),0);
        }

}

void getMaxId()
{	MYSQL_RES *result;
        MYSQL_ROW  row;

	if(mysql_query(&mysql,"select max(userId) from user") != 0)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
        }

        result = mysql_store_result(&mysql);
        if(result == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return ;
      	}
	else{
	 if(row= mysql_fetch_row(result))
         	id = atoi(row[0])  ;
	else
		printf("%s\n",mysql_error(&mysql));
        }

}

int main()
{
        int i = 0;
        pthread_t tid;
        struct sockaddr_in myaddr;
        struct sockaddr_in cliaddr;
        int socklen = sizeof(cliaddr);
        

        mysql_init(&mysql);
        if(mysql_real_connect(&mysql,"127.0.0.1","root","root","chatroom",0,NULL,0) == NULL)
        {
                printf("%s\n",mysql_error(&mysql));
                return -1;
        }

	getMaxId();

        memset(&myaddr,0,sizeof(myaddr));
        myaddr.sin_family = AF_INET;
        myaddr.sin_addr.s_addr = inet_addr("192.168.170.128");
        myaddr.sin_port = htons(8888);

        int lisfd = socket(AF_INET,SOCK_STREAM,0);
        if(lisfd == 0)
        {
                printf("socket error\n");
                return -1;
        }

	int val = 1;
	//setsockopt(lisfd,SOL_SOCKET,REUSERADDR,&val,sizeof(val));
         
        if(bind(lisfd, (struct sockaddr*)&myaddr,sizeof(myaddr)) != 0)
        {
                printf("bind error\n");
                return -1;
        }
        listen(lisfd, 10);
        printf("begin accpet\n");
 while(1)
        {
                int confd = accept(lisfd, (struct sockaddr*)&cliaddr,&socklen);
                if(confd == -1)
                {
                        printf("accpet error\n");
                        return -1;
                }

                 for(i = 0; i < 1024; i++)
                {
                        if(used[i] == 0)
                        {
                                clientfd[i] = confd;
                                used[i] = 1;
                                break;
                        }
                }

                printf("newclient ip=%s\t,port=%d\n",inet_ntoa(cliaddr.sin_addr),ntohs(cliaddr.sin_port));

                pthread_create(&tid,NULL,handClient,&clientfd[i]);

           

          

        }

}

