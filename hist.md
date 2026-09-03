```asm
   0x7f46be5dc560 <__start_il2cpp+1537216>:	push   %rbp
   0x7f46be5dc561 <__start_il2cpp+1537217>:	push   %r15
   0x7f46be5dc563 <__start_il2cpp+1537219>:	push   %r14
   0x7f46be5dc565 <__start_il2cpp+1537221>:	push   %rbx
   0x7f46be5dc566 <__start_il2cpp+1537222>:	push   %rax
   0x7f46be5dc567 <__start_il2cpp+1537223>:	mov    %edx,%ebp
   0x7f46be5dc569 <__start_il2cpp+1537225>:	mov    %rsi,%r14
   0x7f46be5dc56c <__start_il2cpp+1537228>:	mov    %rdi,%r15
   0x7f46be5dc56f <__start_il2cpp+1537231>:	cmpb   $0x0,0x1688f9b(%rip)        # 0x7f46bfc65511
   0x7f46be5dc576 <__start_il2cpp+1537238>:	jne    0x7f46be5dc58b <__start_il2cpp+1537259>
   0x7f46be5dc578 <__start_il2cpp+1537240>:	lea    0x15ed361(%rip),%rdi        # 0x7f46bfbc98e0
   0x7f46be5dc57f <__start_il2cpp+1537247>:	call   0x7f46be44db60
   0x7f46be5dc584 <__start_il2cpp+1537252>:	movb   $0x1,0x1688f86(%rip)        # 0x7f46bfc65511
   0x7f46be5dc58b <__start_il2cpp+1537259>:	test   %ebp,%ebp
   0x7f46be5dc58d <__start_il2cpp+1537261>:	jle    0x7f46be5dc663 <__start_il2cpp+1537475>
   0x7f46be5dc593 <__start_il2cpp+1537267>:	mov    %ebp,%r8d
   0x7f46be5dc596 <__start_il2cpp+1537270>:	xor    %ecx,%ecx
   0x7f46be5dc598 <__start_il2cpp+1537272>:	nopl   0x0(%rax,%rax,1)
   0x7f46be5dc5a0 <__start_il2cpp+1537280>:	mov    0x18(%r15),%eax
   0x7f46be5dc5a4 <__start_il2cpp+1537284>:	mov    %eax,%edx
   0x7f46be5dc5a6 <__start_il2cpp+1537286>:	add    $0x1,%edx
   0x7f46be5dc5a9 <__start_il2cpp+1537289>:	sar    $0x1f,%edx
   0x7f46be5dc5ac <__start_il2cpp+1537292>:	shr    $0x18,%edx
   0x7f46be5dc5af <__start_il2cpp+1537295>:	lea    (%rax,%rdx,1),%edx
   0x7f46be5dc5b2 <__start_il2cpp+1537298>:	add    $0x1,%edx
   0x7f46be5dc5b5 <__start_il2cpp+1537301>:	and    $0xffffff00,%edx
   0x7f46be5dc5bb <__start_il2cpp+1537307>:	neg    %edx
   0x7f46be5dc5bd <__start_il2cpp+1537309>:	lea    (%rax,%rdx,1),%esi
   0x7f46be5dc5c0 <__start_il2cpp+1537312>:	add    $0x1,%esi
   0x7f46be5dc5c3 <__start_il2cpp+1537315>:	mov    %esi,0x18(%r15)
   0x7f46be5dc5c7 <__start_il2cpp+1537319>:	mov    0x10(%r15),%rdx
   0x7f46be5dc5cb <__start_il2cpp+1537323>:	test   %rdx,%rdx
   0x7f46be5dc5ce <__start_il2cpp+1537326>:	je     0x7f46be5dc673 <__start_il2cpp+1537491>
   0x7f46be5dc5d4 <__start_il2cpp+1537332>:	mov    0x18(%rdx),%ebp
   0x7f46be5dc5d7 <__start_il2cpp+1537335>:	cmp    %ebp,%esi
   0x7f46be5dc5d9 <__start_il2cpp+1537337>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc5df <__start_il2cpp+1537343>:	movslq %esi,%rdi
   0x7f46be5dc5e2 <__start_il2cpp+1537346>:	movzbl 0x20(%rdx,%rdi,1),%ebx
   0x7f46be5dc5e7 <__start_il2cpp+1537351>:	add    0x1c(%r15),%ebx
   0x7f46be5dc5eb <__start_il2cpp+1537355>:	mov    %ebx,%eax
   0x7f46be5dc5ed <__start_il2cpp+1537357>:	sar    $0x1f,%eax
   0x7f46be5dc5f0 <__start_il2cpp+1537360>:	shr    $0x18,%eax
   0x7f46be5dc5f3 <__start_il2cpp+1537363>:	add    %ebx,%eax
   0x7f46be5dc5f5 <__start_il2cpp+1537365>:	and    $0xffffff00,%eax
   0x7f46be5dc5fa <__start_il2cpp+1537370>:	sub    %eax,%ebx
   0x7f46be5dc5fc <__start_il2cpp+1537372>:	mov    %ebx,0x1c(%r15)
   0x7f46be5dc600 <__start_il2cpp+1537376>:	cmp    %ebp,%ebx
   0x7f46be5dc602 <__start_il2cpp+1537378>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc604 <__start_il2cpp+1537380>:	movslq %ebx,%rbp
   0x7f46be5dc607 <__start_il2cpp+1537383>:	movzbl 0x20(%rdx,%rdi,1),%ebx
   0x7f46be5dc60c <__start_il2cpp+1537388>:	movzbl 0x20(%rdx,%rbp,1),%eax
   0x7f46be5dc611 <__start_il2cpp+1537393>:	mov    %bl,0x20(%rdx,%rbp,1)
   0x7f46be5dc615 <__start_il2cpp+1537397>:	cmp    0x18(%rdx),%esi
   0x7f46be5dc618 <__start_il2cpp+1537400>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc61a <__start_il2cpp+1537402>:	mov    %al,0x20(%rdx,%rdi,1)
   0x7f46be5dc61e <__start_il2cpp+1537406>:	mov    0x10(%r15),%rdx
   0x7f46be5dc622 <__start_il2cpp+1537410>:	test   %rdx,%rdx
   0x7f46be5dc625 <__start_il2cpp+1537413>:	je     0x7f46be5dc673 <__start_il2cpp+1537491>
   0x7f46be5dc627 <__start_il2cpp+1537415>:	movslq 0x18(%r15),%rax
   0x7f46be5dc62b <__start_il2cpp+1537419>:	mov    0x18(%rdx),%esi
   0x7f46be5dc62e <__start_il2cpp+1537422>:	cmp    %esi,%eax
   0x7f46be5dc630 <__start_il2cpp+1537424>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc632 <__start_il2cpp+1537426>:	movslq 0x1c(%r15),%rdi
   0x7f46be5dc636 <__start_il2cpp+1537430>:	cmp    %esi,%edi
   0x7f46be5dc638 <__start_il2cpp+1537432>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc63a <__start_il2cpp+1537434>:	movzbl 0x20(%rdx,%rdi,1),%edi
   0x7f46be5dc63f <__start_il2cpp+1537439>:	movzbl 0x20(%rdx,%rax,1),%eax
   0x7f46be5dc644 <__start_il2cpp+1537444>:	add    %edi,%eax
   0x7f46be5dc646 <__start_il2cpp+1537446>:	movzbl %al,%eax
   0x7f46be5dc649 <__start_il2cpp+1537449>:	cmp    %esi,%eax
   0x7f46be5dc64b <__start_il2cpp+1537451>:	jae    0x7f46be5dc66e <__start_il2cpp+1537486>
   0x7f46be5dc64d <__start_il2cpp+1537453>:	movzbl 0x20(%rdx,%rax,1),%eax
   0x7f46be5dc652 <__start_il2cpp+1537458>:	xor    %al,(%r14,%rcx,1)  #<===============decrypt to
   0x7f46be5dc656 <__start_il2cpp+1537462>:	add    $0x1,%rcx
   0x7f46be5dc65a <__start_il2cpp+1537466>:	cmp    %rcx,%r8
   0x7f46be5dc65d <__start_il2cpp+1537469>:	jne    0x7f46be5dc5a0 <__start_il2cpp+1537280>
   0x7f46be5dc663 <__start_il2cpp+1537475>:	add    $0x8,%rsp
   0x7f46be5dc667 <__start_il2cpp+1537479>:	pop    %rbx
   0x7f46be5dc668 <__start_il2cpp+1537480>:	pop    %r14
   0x7f46be5dc66a <__start_il2cpp+1537482>:	pop    %r15
   0x7f46be5dc66c <__start_il2cpp+1537484>:	pop    %rbp
   0x7f46be5dc66d <__start_il2cpp+1537485>:	ret
```


```c
void rc4_crypt(struct rc4_ctx *ctx, uint8_t *buf, int len) {
	if (!initialized) {
		rc4_ksa(ctx);          // 调用 0x7f46be44db60
		initialized = 1;
	}
	if (len <= 0) return;

	uint8_t *s = ctx->sbox_ptr->s;
	int length = ctx->sbox_ptr->length;  // 应为 256

	for (int n = 0; n < len; n++) {
		ctx->i = (ctx->i + 1) & 0xFF;
		uint8_t si = s[ctx->i];
		ctx->j = (ctx->j + si) & 0xFF;
		uint8_t sj = s[ctx->j];
		s[ctx->i] = sj;
		s[ctx->j] = si;
		uint8_t t = (s[ctx->i] + s[ctx->j]) & 0xFF;
		uint8_t K = s[t];
		buf[n] ^= K;
	}
}
```

```asm
() x/g $r14
0x7f457e074020:	8948226114518997951
() x/g $r15
0x7f45b785d7e0:	139941335456256
() p $ebp
$2 = 249
() p $rbp
$3 = (void *) 0xf9
() detach
```

```sh
getmsg=./promsg
msg=$($getmsg $(pgrep PROClient) 0x$(grep 'GameAssembly' /proc/$(pgrep PROClient)/maps| grep ' 00000000 '|cut -d'-' -f1) | grep -oP "A.{0,128}attacks") && echo $msg > /tmp/dump_var
grep "Pikachu" /tmp/dump_var || xdotool type --window $(xdotool search --onlyvisible --pid $(pgrep PROClient)) adadadad4
```
