#ifndef _KMOD__COPY_TO_SOCK_INIT_VAL_H
#define _KMOD__COPY_TO_SOCK_INIT_VAL_H

#include <linux/tcp.h>
#include "derand_replayer.h"

static inline void copy_to_server_sock(struct sock *sk){
	struct inet_connection_sock *icsk = inet_csk(sk);
	struct tcp_sock *tp = tcp_sk(sk);
	struct tcp_sock_init_data *d = &((struct derand_replayer*)sk->replayer)->init_data;
	tp->tcp_header_len = d->tcp_header_len;
	tp->pred_flags = d->pred_flags;
	tp->segs_in = d->segs_in;
 	tp->rcv_nxt = d->rcv_nxt;
	tp->copied_seq = d->copied_seq;
	tp->rcv_wup = d->rcv_wup;
 	tp->snd_nxt = d->snd_nxt;
 	tp->snd_una = d->snd_una;
 	tp->snd_sml = d->snd_sml;
	tp->rcv_tstamp = d->rcv_tstamp;
	tp->lsndtime = d->lsndtime;
	tp->snd_wl1 = d->snd_wl1;
	tp->snd_wnd = d->snd_wnd;
	tp->max_window = d->max_window;
	tp->window_clamp = d->window_clamp;
	tp->rcv_ssthresh = d->rcv_ssthresh;
	tp->advmss = d->advmss;
	tp->srtt_us = d->srtt_us;
	tp->mdev_us = d->mdev_us;
	tp->mdev_max_us = d->mdev_max_us;
	tp->rttvar_us = d->rttvar_us;
	tp->rtt_seq = d->rtt_seq;
	memcpy(tp->rtt_min, d->rtt_min, sizeof(tp->rtt_min));
	tp->ecn_flags = d->ecn_flags;
	tp->snd_up = d->snd_up;
	memcpy(&tp->rx_opt, &d->rx_opt, sizeof(d->rx_opt));
	tp->snd_cwnd_stamp = d->snd_cwnd_stamp;
 	tp->rcv_wnd = d->rcv_wnd;
	tp->write_seq = d->write_seq;
	tp->pushed_seq = d->pushed_seq;
	tp->total_retrans = d->total_retrans;
	memcpy(&tp->rcvq_space, &d->rcvq_space, sizeof(d->rcvq_space));
	memcpy(&tp->rcv_rtt_est, &d->rcv_rtt_est, sizeof(d->rcv_rtt_est));

	icsk->icsk_rto = d->icsk_rto;
	memcpy(&icsk->icsk_ack, &d->icsk_ack, sizeof(d->icsk_ack));
	memcpy(&icsk->icsk_mtup, &d->icsk_mtup, sizeof(d->icsk_mtup));
	
	sk->sk_rcvbuf = d->sk_rcvbuf;
	sk->sk_sndbuf = d->sk_sndbuf;
	sk->sk_userlocks = d->sk_userlocks;
	sk->sk_pacing_rate = d->sk_pacing_rate;
}

#endif /* _KMOD__COPY_TO_SOCK_INIT_VAL_H */