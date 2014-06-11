#include"sender.h"


int
main ()
{
  int qid, snd, qid1, rcv, qid2, qid3, snd1, rcv1;
  struct chat chat_size;
  qid = msgget (1234, IPC_CREAT | 0666);
  if (qid != -1)
    printf ("Message queue is created=%d\n", qid);
  else
    printf ("Message queue is not created\n");
  qid1 = msgget (1233, IPC_CREAT | 0666);
  if (qid1 != -1)
    printf ("Another Message queue is created=%d\n", qid1);
  else
    printf ("Another Message queue is not created\n");
  qid2 = msgget (1232, IPC_CREAT | 0666);
  if (qid2 != -1)
    printf ("Second Message queue is created=%d\n", qid2);
  else
    printf ("Second Message queue is not created\n");
  qid3 = msgget (1231, IPC_CREAT | 0666);
  if (qid3 != -1)
    printf ("Third Message queue is created=%d\n", qid3);
  else
    printf ("Third Message queue is not created\n");

  while (1)
    {
      chat_size.msgtype = 1;
      gets (chat_size.mtext);
      snd = msgsnd (qid, (void *) &chat_size, 100, 0);
      if (snd != -1)
	{
	  printf ("Message send\n");
	  if (strncmp (chat_size.mtext, "end", 3) == 0)
	    exit (0);
	}
      else
	printf ("Message not send\n");

      chat_size.msgtype = 1;
      rcv = msgrcv (qid1, (void *) &chat_size, 100, 1, 0);
      if (rcv != -1)
	{
	  printf ("Message receive\n");
	  puts (chat_size.mtext);
	  if (strncmp (chat_size.mtext, "end", 3) == 0)
	    exit (0);
	}
      else
	printf ("Message not received\n");

      chat_size.msgtype = 1;
      gets (chat_size.mtext);
      snd1 = msgsnd (qid2, (void *) &chat_size, 100, 0);
      if (snd1 != -1)
	{
	  printf ("Second Message send\n");
	  if (strncmp (chat_size.mtext, "end", 3) == 0)
	    exit (0);
	}
      else
	printf ("Second Message not send\n");

      chat_size.msgtype = 1;
      rcv1 = msgrcv (qid3, (void *) &chat_size, 100, 1, 0);
      if (rcv1 != -1)
	{
	  printf ("Final Message receive\n");
	  puts (chat_size.mtext);
	  if (strncmp (chat_size.mtext, "end", 3) == 0)
	    exit (0);
	}
      else
	printf ("Final Message not received\n");
    }
}
