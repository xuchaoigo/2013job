int rcv(int sck, void * buf, int size, int time_out)
{
	if (sck < 1 || !buf || size < 1)
		return 0;
	timeval tv = { 0, 0}; 
	timeval * ptv = 0;
	if (time_out > 0) 
	{
		tv.tv_sec = time_out; 
		ptv = &tv;
	}
	memset(buf, 0, size);
	int r = 0;
	char * b = (char*) buf;
	int sz = size; 
	fd_set rd, er;
	int total = 0; 
	time_t t0 = time(0); 
	time_t t1 = 0;
	do {
		FD_ZERO(&rd);
		FD_SET(sck, &rd);
		FD_ZERO(&er);
		FD_SET(sck, &er);
		r = select(sck + 1, &rd, 0, &er, ptv);
		if (r == -1)
		{
			nperror("select()");
			return -1;
		}
		if (FD_ISSET(sck, &er))
		{
			nperror("socket(shutdown)");
			return -1;
		}//end if
		if (FD_ISSET(sck, &rd)) 
		{
			r = recv(sck, b, sz, 0);
			if (r == -1)
			{ 
				nperror("recv()");
				return -1;
			}
			total += r;
			sz -= r; 
			b+= r;
		}//end if
		if (time_out > 0) 
			t1 = time(0) - t0;
		else
			t1 = time_out - 1;
		//end if
		// }while(sz && t1 < time_out);
		//  return total;
		//  }//end if
