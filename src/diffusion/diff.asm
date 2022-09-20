
diffusion_g:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 4f 00 00 	mov    0x4fd9(%rip),%rax        # 5fe8 <__gmon_start__>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	callq  *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	retq   

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 e2 4f 00 00    	pushq  0x4fe2(%rip)        # 6008 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	ff 25 e4 4f 00 00    	jmpq   *0x4fe4(%rip)        # 6010 <_GLOBAL_OFFSET_TABLE_+0x10>
    102c:	0f 1f 40 00          	nopl   0x0(%rax)

0000000000001030 <free@plt>:
    1030:	ff 25 e2 4f 00 00    	jmpq   *0x4fe2(%rip)        # 6018 <free@GLIBC_2.2.5>
    1036:	68 00 00 00 00       	pushq  $0x0
    103b:	e9 e0 ff ff ff       	jmpq   1020 <.plt>

0000000000001040 <XClearWindow@plt>:
    1040:	ff 25 da 4f 00 00    	jmpq   *0x4fda(%rip)        # 6020 <XClearWindow>
    1046:	68 01 00 00 00       	pushq  $0x1
    104b:	e9 d0 ff ff ff       	jmpq   1020 <.plt>

0000000000001050 <XAllocColor@plt>:
    1050:	ff 25 d2 4f 00 00    	jmpq   *0x4fd2(%rip)        # 6028 <XAllocColor>
    1056:	68 02 00 00 00       	pushq  $0x2
    105b:	e9 c0 ff ff ff       	jmpq   1020 <.plt>

0000000000001060 <XStoreName@plt>:
    1060:	ff 25 ca 4f 00 00    	jmpq   *0x4fca(%rip)        # 6030 <XStoreName>
    1066:	68 03 00 00 00       	pushq  $0x3
    106b:	e9 b0 ff ff ff       	jmpq   1020 <.plt>

0000000000001070 <XDrawPoint@plt>:
    1070:	ff 25 c2 4f 00 00    	jmpq   *0x4fc2(%rip)        # 6038 <XDrawPoint>
    1076:	68 04 00 00 00       	pushq  $0x4
    107b:	e9 a0 ff ff ff       	jmpq   1020 <.plt>

0000000000001080 <getpid@plt>:
    1080:	ff 25 ba 4f 00 00    	jmpq   *0x4fba(%rip)        # 6040 <getpid@GLIBC_2.2.5>
    1086:	68 05 00 00 00       	pushq  $0x5
    108b:	e9 90 ff ff ff       	jmpq   1020 <.plt>

0000000000001090 <XPending@plt>:
    1090:	ff 25 b2 4f 00 00    	jmpq   *0x4fb2(%rip)        # 6048 <XPending>
    1096:	68 06 00 00 00       	pushq  $0x6
    109b:	e9 80 ff ff ff       	jmpq   1020 <.plt>

00000000000010a0 <__stack_chk_fail@plt>:
    10a0:	ff 25 aa 4f 00 00    	jmpq   *0x4faa(%rip)        # 6050 <__stack_chk_fail@GLIBC_2.4>
    10a6:	68 07 00 00 00       	pushq  $0x7
    10ab:	e9 70 ff ff ff       	jmpq   1020 <.plt>

00000000000010b0 <printf@plt>:
    10b0:	ff 25 a2 4f 00 00    	jmpq   *0x4fa2(%rip)        # 6058 <printf@GLIBC_2.2.5>
    10b6:	68 08 00 00 00       	pushq  $0x8
    10bb:	e9 60 ff ff ff       	jmpq   1020 <.plt>

00000000000010c0 <XChangeWindowAttributes@plt>:
    10c0:	ff 25 9a 4f 00 00    	jmpq   *0x4f9a(%rip)        # 6060 <XChangeWindowAttributes>
    10c6:	68 09 00 00 00       	pushq  $0x9
    10cb:	e9 50 ff ff ff       	jmpq   1020 <.plt>

00000000000010d0 <srand@plt>:
    10d0:	ff 25 92 4f 00 00    	jmpq   *0x4f92(%rip)        # 6068 <srand@GLIBC_2.2.5>
    10d6:	68 0a 00 00 00       	pushq  $0xa
    10db:	e9 40 ff ff ff       	jmpq   1020 <.plt>

00000000000010e0 <XOpenDisplay@plt>:
    10e0:	ff 25 8a 4f 00 00    	jmpq   *0x4f8a(%rip)        # 6070 <XOpenDisplay>
    10e6:	68 0b 00 00 00       	pushq  $0xb
    10eb:	e9 30 ff ff ff       	jmpq   1020 <.plt>

00000000000010f0 <fprintf@plt>:
    10f0:	ff 25 82 4f 00 00    	jmpq   *0x4f82(%rip)        # 6078 <fprintf@GLIBC_2.2.5>
    10f6:	68 0c 00 00 00       	pushq  $0xc
    10fb:	e9 20 ff ff ff       	jmpq   1020 <.plt>

0000000000001100 <XNextEvent@plt>:
    1100:	ff 25 7a 4f 00 00    	jmpq   *0x4f7a(%rip)        # 6080 <XNextEvent>
    1106:	68 0d 00 00 00       	pushq  $0xd
    110b:	e9 10 ff ff ff       	jmpq   1020 <.plt>

0000000000001110 <malloc@plt>:
    1110:	ff 25 72 4f 00 00    	jmpq   *0x4f72(%rip)        # 6088 <malloc@GLIBC_2.2.5>
    1116:	68 0e 00 00 00       	pushq  $0xe
    111b:	e9 00 ff ff ff       	jmpq   1020 <.plt>

0000000000001120 <XLookupKeysym@plt>:
    1120:	ff 25 6a 4f 00 00    	jmpq   *0x4f6a(%rip)        # 6090 <XLookupKeysym>
    1126:	68 0f 00 00 00       	pushq  $0xf
    112b:	e9 f0 fe ff ff       	jmpq   1020 <.plt>

0000000000001130 <XSelectInput@plt>:
    1130:	ff 25 62 4f 00 00    	jmpq   *0x4f62(%rip)        # 6098 <XSelectInput>
    1136:	68 10 00 00 00       	pushq  $0x10
    113b:	e9 e0 fe ff ff       	jmpq   1020 <.plt>

0000000000001140 <XPutBackEvent@plt>:
    1140:	ff 25 5a 4f 00 00    	jmpq   *0x4f5a(%rip)        # 60a0 <XPutBackEvent>
    1146:	68 11 00 00 00       	pushq  $0x11
    114b:	e9 d0 fe ff ff       	jmpq   1020 <.plt>

0000000000001150 <XCreateGC@plt>:
    1150:	ff 25 52 4f 00 00    	jmpq   *0x4f52(%rip)        # 60a8 <XCreateGC>
    1156:	68 12 00 00 00       	pushq  $0x12
    115b:	e9 c0 fe ff ff       	jmpq   1020 <.plt>

0000000000001160 <XCreateSimpleWindow@plt>:
    1160:	ff 25 4a 4f 00 00    	jmpq   *0x4f4a(%rip)        # 60b0 <XCreateSimpleWindow>
    1166:	68 13 00 00 00       	pushq  $0x13
    116b:	e9 b0 fe ff ff       	jmpq   1020 <.plt>

0000000000001170 <XSetForeground@plt>:
    1170:	ff 25 42 4f 00 00    	jmpq   *0x4f42(%rip)        # 60b8 <XSetForeground>
    1176:	68 14 00 00 00       	pushq  $0x14
    117b:	e9 a0 fe ff ff       	jmpq   1020 <.plt>

0000000000001180 <XFlush@plt>:
    1180:	ff 25 3a 4f 00 00    	jmpq   *0x4f3a(%rip)        # 60c0 <XFlush>
    1186:	68 15 00 00 00       	pushq  $0x15
    118b:	e9 90 fe ff ff       	jmpq   1020 <.plt>

0000000000001190 <XCheckMaskEvent@plt>:
    1190:	ff 25 32 4f 00 00    	jmpq   *0x4f32(%rip)        # 60c8 <XCheckMaskEvent>
    1196:	68 16 00 00 00       	pushq  $0x16
    119b:	e9 80 fe ff ff       	jmpq   1020 <.plt>

00000000000011a0 <XMapWindow@plt>:
    11a0:	ff 25 2a 4f 00 00    	jmpq   *0x4f2a(%rip)        # 60d0 <XMapWindow>
    11a6:	68 17 00 00 00       	pushq  $0x17
    11ab:	e9 70 fe ff ff       	jmpq   1020 <.plt>

00000000000011b0 <XFreeGC@plt>:
    11b0:	ff 25 22 4f 00 00    	jmpq   *0x4f22(%rip)        # 60d8 <XFreeGC>
    11b6:	68 18 00 00 00       	pushq  $0x18
    11bb:	e9 60 fe ff ff       	jmpq   1020 <.plt>

00000000000011c0 <exit@plt>:
    11c0:	ff 25 1a 4f 00 00    	jmpq   *0x4f1a(%rip)        # 60e0 <exit@GLIBC_2.2.5>
    11c6:	68 19 00 00 00       	pushq  $0x19
    11cb:	e9 50 fe ff ff       	jmpq   1020 <.plt>

00000000000011d0 <fwrite@plt>:
    11d0:	ff 25 12 4f 00 00    	jmpq   *0x4f12(%rip)        # 60e8 <fwrite@GLIBC_2.2.5>
    11d6:	68 1a 00 00 00       	pushq  $0x1a
    11db:	e9 40 fe ff ff       	jmpq   1020 <.plt>

00000000000011e0 <XCloseDisplay@plt>:
    11e0:	ff 25 0a 4f 00 00    	jmpq   *0x4f0a(%rip)        # 60f0 <XCloseDisplay>
    11e6:	68 1b 00 00 00       	pushq  $0x1b
    11eb:	e9 30 fe ff ff       	jmpq   1020 <.plt>

00000000000011f0 <XDrawLine@plt>:
    11f0:	ff 25 02 4f 00 00    	jmpq   *0x4f02(%rip)        # 60f8 <XDrawLine>
    11f6:	68 1c 00 00 00       	pushq  $0x1c
    11fb:	e9 20 fe ff ff       	jmpq   1020 <.plt>

Disassembly of section .text:

0000000000001200 <main>:
    1200:	41 57                	push   %r15
    1202:	ba e8 03 00 00       	mov    $0x3e8,%edx
    1207:	be 6c 07 00 00       	mov    $0x76c,%esi
    120c:	48 8d 3d 26 2e 00 00 	lea    0x2e26(%rip),%rdi        # 4039 <_IO_stdin_used+0x39>
    1213:	41 56                	push   %r14
    1215:	41 55                	push   %r13
    1217:	41 54                	push   %r12
    1219:	55                   	push   %rbp
    121a:	53                   	push   %rbx
    121b:	48 81 ec 38 16 31 00 	sub    $0x311638,%rsp
    1222:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    1229:	00 00 
    122b:	48 89 84 24 28 16 31 	mov    %rax,0x311628(%rsp)
    1232:	00 
    1233:	31 c0                	xor    %eax,%eax
    1235:	e8 f6 1f 00 00       	callq  3230 <flame_open>
    123a:	48 89 c5             	mov    %rax,%rbp
    123d:	e8 3e fe ff ff       	callq  1080 <getpid@plt>
    1242:	89 c7                	mov    %eax,%edi
    1244:	e8 87 fe ff ff       	callq  10d0 <srand@plt>
    1249:	48 83 ec 08          	sub    $0x8,%rsp
    124d:	ba e8 04 00 00       	mov    $0x4e8,%edx
    1252:	31 c0                	xor    %eax,%eax
    1254:	6a 03                	pushq  $0x3
    1256:	48 8b 3d c3 4e 00 00 	mov    0x4ec3(%rip),%rdi        # 6120 <stderr@@GLIBC_2.2.5>
    125d:	b9 e8 04 00 00       	mov    $0x4e8,%ecx
    1262:	41 b9 b8 0e 00 00    	mov    $0xeb8,%r9d
    1268:	41 b8 e8 04 00 00    	mov    $0x4e8,%r8d
    126e:	48 8d 35 db 2d 00 00 	lea    0x2ddb(%rip),%rsi        # 4050 <_IO_stdin_used+0x50>
    1275:	e8 76 fe ff ff       	callq  10f0 <fprintf@plt>
    127a:	58                   	pop    %rax
    127b:	5a                   	pop    %rdx
    127c:	48 8d 9c 24 c0 02 00 	lea    0x2c0(%rsp),%rbx
    1283:	00 
    1284:	eb 1a                	jmp    12a0 <main+0xa0>
    1286:	48 8b 7d 10          	mov    0x10(%rbp),%rdi
    128a:	48 89 de             	mov    %rbx,%rsi
    128d:	e8 6e fe ff ff       	callq  1100 <XNextEvent@plt>
    1292:	83 bc 24 c0 02 00 00 	cmpl   $0x2,0x2c0(%rsp)
    1299:	02 
    129a:	0f 84 0e 07 00 00    	je     19ae <main+0x7ae>
    12a0:	48 8b 7d 10          	mov    0x10(%rbp),%rdi
    12a4:	e8 e7 fd ff ff       	callq  1090 <XPending@plt>
    12a9:	85 c0                	test   %eax,%eax
    12ab:	7f d9                	jg     1286 <main+0x86>
    12ad:	48 89 ef             	mov    %rbp,%rdi
    12b0:	e8 1b 22 00 00       	callq  34d0 <flame_clear_display>
    12b5:	48 8d 8c 24 b0 81 1d 	lea    0x1d81b0(%rsp),%rcx
    12bc:	00 
    12bd:	0f 28 05 fc 2d 00 00 	movaps 0x2dfc(%rip),%xmm0        # 40c0 <_IO_stdin_used+0xc0>
    12c4:	48 8d bc 24 20 75 1d 	lea    0x1d7520(%rsp),%rdi
    12cb:	00 
    12cc:	48 89 8c 24 90 02 00 	mov    %rcx,0x290(%rsp)
    12d3:	00 
    12d4:	48 8d b4 24 20 8e 1d 	lea    0x1d8e20(%rsp),%rsi
    12db:	00 
    12dc:	4c 8d 84 24 18 16 31 	lea    0x311618(%rsp),%r8
    12e3:	00 
    12e4:	49 89 c9             	mov    %rcx,%r9
    12e7:	48 89 f2             	mov    %rsi,%rdx
    12ea:	4c 89 c8             	mov    %r9,%rax
    12ed:	4c 29 ca             	sub    %r9,%rdx
    12f0:	48 83 ea 10          	sub    $0x10,%rdx
    12f4:	48 c1 ea 04          	shr    $0x4,%rdx
    12f8:	48 83 c2 01          	add    $0x1,%rdx
    12fc:	83 e2 07             	and    $0x7,%edx
    12ff:	74 5b                	je     135c <main+0x15c>
    1301:	48 83 fa 01          	cmp    $0x1,%rdx
    1305:	74 49                	je     1350 <main+0x150>
    1307:	48 83 fa 02          	cmp    $0x2,%rdx
    130b:	74 3c                	je     1349 <main+0x149>
    130d:	48 83 fa 03          	cmp    $0x3,%rdx
    1311:	74 2f                	je     1342 <main+0x142>
    1313:	48 83 fa 04          	cmp    $0x4,%rdx
    1317:	74 22                	je     133b <main+0x13b>
    1319:	48 83 fa 05          	cmp    $0x5,%rdx
    131d:	74 15                	je     1334 <main+0x134>
    131f:	48 83 fa 06          	cmp    $0x6,%rdx
    1323:	74 08                	je     132d <main+0x12d>
    1325:	41 0f 11 01          	movups %xmm0,(%r9)
    1329:	49 8d 41 10          	lea    0x10(%r9),%rax
    132d:	0f 11 00             	movups %xmm0,(%rax)
    1330:	48 83 c0 10          	add    $0x10,%rax
    1334:	0f 11 00             	movups %xmm0,(%rax)
    1337:	48 83 c0 10          	add    $0x10,%rax
    133b:	0f 11 00             	movups %xmm0,(%rax)
    133e:	48 83 c0 10          	add    $0x10,%rax
    1342:	0f 11 00             	movups %xmm0,(%rax)
    1345:	48 83 c0 10          	add    $0x10,%rax
    1349:	0f 11 00             	movups %xmm0,(%rax)
    134c:	48 83 c0 10          	add    $0x10,%rax
    1350:	0f 11 00             	movups %xmm0,(%rax)
    1353:	48 83 c0 10          	add    $0x10,%rax
    1357:	48 39 f0             	cmp    %rsi,%rax
    135a:	74 28                	je     1384 <main+0x184>
    135c:	0f 11 00             	movups %xmm0,(%rax)
    135f:	48 83 e8 80          	sub    $0xffffffffffffff80,%rax
    1363:	0f 11 40 90          	movups %xmm0,-0x70(%rax)
    1367:	0f 11 40 a0          	movups %xmm0,-0x60(%rax)
    136b:	0f 11 40 b0          	movups %xmm0,-0x50(%rax)
    136f:	0f 11 40 c0          	movups %xmm0,-0x40(%rax)
    1373:	0f 11 40 d0          	movups %xmm0,-0x30(%rax)
    1377:	0f 11 40 e0          	movups %xmm0,-0x20(%rax)
    137b:	0f 11 40 f0          	movups %xmm0,-0x10(%rax)
    137f:	48 39 f0             	cmp    %rsi,%rax
    1382:	75 d8                	jne    135c <main+0x15c>
    1384:	48 8d b0 88 0c 00 00 	lea    0xc88(%rax),%rsi
    138b:	c7 00 00 00 80 3f    	movl   $0x3f800000,(%rax)
    1391:	49 81 c1 88 0c 00 00 	add    $0xc88,%r9
    1398:	c7 40 04 00 00 00 00 	movl   $0x0,0x4(%rax)
    139f:	4c 39 c6             	cmp    %r8,%rsi
    13a2:	0f 85 3f ff ff ff    	jne    12e7 <main+0xe7>
    13a8:	4c 8d 94 24 a0 e0 09 	lea    0x9e0a0(%rsp),%r10
    13af:	00 
    13b0:	4c 8d 9c 24 c8 09 00 	lea    0x9c8(%rsp),%r11
    13b7:	00 
    13b8:	c7 84 24 d4 06 27 00 	movl   $0x3f800000,0x2706d4(%rsp)
    13bf:	00 00 80 3f 
    13c3:	4c 8d a7 88 94 13 00 	lea    0x139488(%rdi),%r12
    13ca:	4c 8d ac 24 10 d4 09 	lea    0x9d410(%rsp),%r13
    13d1:	00 
    13d2:	c7 84 24 dc 06 27 00 	movl   $0x3f800000,0x2706dc(%rsp)
    13d9:	00 00 80 3f 
    13dd:	4c 8d b4 24 08 5c 1d 	lea    0x1d5c08(%rsp),%r14
    13e4:	00 
    13e5:	4c 8d bc 24 08 d4 09 	lea    0x9d408(%rsp),%r15
    13ec:	00 
    13ed:	c7 84 24 e4 06 27 00 	movl   $0x3f800000,0x2706e4(%rsp)
    13f4:	00 00 80 3f 
    13f8:	c7 84 24 ec 06 27 00 	movl   $0x3f800000,0x2706ec(%rsp)
    13ff:	00 00 80 3f 
    1403:	c7 84 24 f4 06 27 00 	movl   $0x3f800000,0x2706f4(%rsp)
    140a:	00 00 80 3f 
    140e:	c7 84 24 fc 06 27 00 	movl   $0x3f800000,0x2706fc(%rsp)
    1415:	00 00 80 3f 
    1419:	c7 84 24 04 07 27 00 	movl   $0x3f800000,0x270704(%rsp)
    1420:	00 00 80 3f 
    1424:	c7 84 24 0c 07 27 00 	movl   $0x3f800000,0x27070c(%rsp)
    142b:	00 00 80 3f 
    142f:	c7 84 24 14 07 27 00 	movl   $0x3f800000,0x270714(%rsp)
    1436:	00 00 80 3f 
    143a:	c7 84 24 1c 07 27 00 	movl   $0x3f800000,0x27071c(%rsp)
    1441:	00 00 80 3f 
    1445:	c7 84 24 5c 13 27 00 	movl   $0x3f800000,0x27135c(%rsp)
    144c:	00 00 80 3f 
    1450:	c7 84 24 64 13 27 00 	movl   $0x3f800000,0x271364(%rsp)
    1457:	00 00 80 3f 
    145b:	c7 84 24 6c 13 27 00 	movl   $0x3f800000,0x27136c(%rsp)
    1462:	00 00 80 3f 
    1466:	c7 84 24 74 13 27 00 	movl   $0x3f800000,0x271374(%rsp)
    146d:	00 00 80 3f 
    1471:	c7 84 24 7c 13 27 00 	movl   $0x3f800000,0x27137c(%rsp)
    1478:	00 00 80 3f 
    147c:	c7 84 24 84 13 27 00 	movl   $0x3f800000,0x271384(%rsp)
    1483:	00 00 80 3f 
    1487:	c7 84 24 8c 13 27 00 	movl   $0x3f800000,0x27138c(%rsp)
    148e:	00 00 80 3f 
    1492:	c7 84 24 94 13 27 00 	movl   $0x3f800000,0x271394(%rsp)
    1499:	00 00 80 3f 
    149d:	c7 84 24 9c 13 27 00 	movl   $0x3f800000,0x27139c(%rsp)
    14a4:	00 00 80 3f 
    14a8:	c7 84 24 a4 13 27 00 	movl   $0x3f800000,0x2713a4(%rsp)
    14af:	00 00 80 3f 
    14b3:	c7 84 24 e4 1f 27 00 	movl   $0x3f800000,0x271fe4(%rsp)
    14ba:	00 00 80 3f 
    14be:	c7 84 24 ec 1f 27 00 	movl   $0x3f800000,0x271fec(%rsp)
    14c5:	00 00 80 3f 
    14c9:	c7 84 24 f4 1f 27 00 	movl   $0x3f800000,0x271ff4(%rsp)
    14d0:	00 00 80 3f 
    14d4:	c7 84 24 fc 1f 27 00 	movl   $0x3f800000,0x271ffc(%rsp)
    14db:	00 00 80 3f 
    14df:	c7 84 24 04 20 27 00 	movl   $0x3f800000,0x272004(%rsp)
    14e6:	00 00 80 3f 
    14ea:	c7 84 24 0c 20 27 00 	movl   $0x3f800000,0x27200c(%rsp)
    14f1:	00 00 80 3f 
    14f5:	c7 84 24 14 20 27 00 	movl   $0x3f800000,0x272014(%rsp)
    14fc:	00 00 80 3f 
    1500:	c7 84 24 1c 20 27 00 	movl   $0x3f800000,0x27201c(%rsp)
    1507:	00 00 80 3f 
    150b:	c7 84 24 24 20 27 00 	movl   $0x3f800000,0x272024(%rsp)
    1512:	00 00 80 3f 
    1516:	c7 84 24 2c 20 27 00 	movl   $0x3f800000,0x27202c(%rsp)
    151d:	00 00 80 3f 
    1521:	c7 84 24 6c 2c 27 00 	movl   $0x3f800000,0x272c6c(%rsp)
    1528:	00 00 80 3f 
    152c:	c7 84 24 74 2c 27 00 	movl   $0x3f800000,0x272c74(%rsp)
    1533:	00 00 80 3f 
    1537:	c7 84 24 7c 2c 27 00 	movl   $0x3f800000,0x272c7c(%rsp)
    153e:	00 00 80 3f 
    1542:	c7 84 24 84 2c 27 00 	movl   $0x3f800000,0x272c84(%rsp)
    1549:	00 00 80 3f 
    154d:	c7 84 24 8c 2c 27 00 	movl   $0x3f800000,0x272c8c(%rsp)
    1554:	00 00 80 3f 
    1558:	c7 84 24 94 2c 27 00 	movl   $0x3f800000,0x272c94(%rsp)
    155f:	00 00 80 3f 
    1563:	c7 84 24 9c 2c 27 00 	movl   $0x3f800000,0x272c9c(%rsp)
    156a:	00 00 80 3f 
    156e:	c7 84 24 a4 2c 27 00 	movl   $0x3f800000,0x272ca4(%rsp)
    1575:	00 00 80 3f 
    1579:	c7 84 24 ac 2c 27 00 	movl   $0x3f800000,0x272cac(%rsp)
    1580:	00 00 80 3f 
    1584:	c7 84 24 b4 2c 27 00 	movl   $0x3f800000,0x272cb4(%rsp)
    158b:	00 00 80 3f 
    158f:	c7 84 24 f4 38 27 00 	movl   $0x3f800000,0x2738f4(%rsp)
    1596:	00 00 80 3f 
    159a:	c7 84 24 fc 38 27 00 	movl   $0x3f800000,0x2738fc(%rsp)
    15a1:	00 00 80 3f 
    15a5:	c7 84 24 04 39 27 00 	movl   $0x3f800000,0x273904(%rsp)
    15ac:	00 00 80 3f 
    15b0:	c7 84 24 0c 39 27 00 	movl   $0x3f800000,0x27390c(%rsp)
    15b7:	00 00 80 3f 
    15bb:	c7 84 24 14 39 27 00 	movl   $0x3f800000,0x273914(%rsp)
    15c2:	00 00 80 3f 
    15c6:	c7 84 24 1c 39 27 00 	movl   $0x3f800000,0x27391c(%rsp)
    15cd:	00 00 80 3f 
    15d1:	c7 84 24 24 39 27 00 	movl   $0x3f800000,0x273924(%rsp)
    15d8:	00 00 80 3f 
    15dc:	c7 84 24 2c 39 27 00 	movl   $0x3f800000,0x27392c(%rsp)
    15e3:	00 00 80 3f 
    15e7:	c7 84 24 34 39 27 00 	movl   $0x3f800000,0x273934(%rsp)
    15ee:	00 00 80 3f 
    15f2:	c7 84 24 3c 39 27 00 	movl   $0x3f800000,0x27393c(%rsp)
    15f9:	00 00 80 3f 
    15fd:	c7 84 24 7c 45 27 00 	movl   $0x3f800000,0x27457c(%rsp)
    1604:	00 00 80 3f 
    1608:	c7 84 24 84 45 27 00 	movl   $0x3f800000,0x274584(%rsp)
    160f:	00 00 80 3f 
    1613:	c7 84 24 8c 45 27 00 	movl   $0x3f800000,0x27458c(%rsp)
    161a:	00 00 80 3f 
    161e:	c7 84 24 94 45 27 00 	movl   $0x3f800000,0x274594(%rsp)
    1625:	00 00 80 3f 
    1629:	c7 84 24 9c 45 27 00 	movl   $0x3f800000,0x27459c(%rsp)
    1630:	00 00 80 3f 
    1634:	c7 84 24 a4 45 27 00 	movl   $0x3f800000,0x2745a4(%rsp)
    163b:	00 00 80 3f 
    163f:	c7 84 24 ac 45 27 00 	movl   $0x3f800000,0x2745ac(%rsp)
    1646:	00 00 80 3f 
    164a:	c7 84 24 b4 45 27 00 	movl   $0x3f800000,0x2745b4(%rsp)
    1651:	00 00 80 3f 
    1655:	c7 84 24 bc 45 27 00 	movl   $0x3f800000,0x2745bc(%rsp)
    165c:	00 00 80 3f 
    1660:	c7 84 24 c4 45 27 00 	movl   $0x3f800000,0x2745c4(%rsp)
    1667:	00 00 80 3f 
    166b:	c7 84 24 04 52 27 00 	movl   $0x3f800000,0x275204(%rsp)
    1672:	00 00 80 3f 
    1676:	c7 84 24 0c 52 27 00 	movl   $0x3f800000,0x27520c(%rsp)
    167d:	00 00 80 3f 
    1681:	c7 84 24 14 52 27 00 	movl   $0x3f800000,0x275214(%rsp)
    1688:	00 00 80 3f 
    168c:	c7 84 24 1c 52 27 00 	movl   $0x3f800000,0x27521c(%rsp)
    1693:	00 00 80 3f 
    1697:	c7 84 24 24 52 27 00 	movl   $0x3f800000,0x275224(%rsp)
    169e:	00 00 80 3f 
    16a2:	c7 84 24 2c 52 27 00 	movl   $0x3f800000,0x27522c(%rsp)
    16a9:	00 00 80 3f 
    16ad:	c7 84 24 34 52 27 00 	movl   $0x3f800000,0x275234(%rsp)
    16b4:	00 00 80 3f 
    16b8:	c7 84 24 3c 52 27 00 	movl   $0x3f800000,0x27523c(%rsp)
    16bf:	00 00 80 3f 
    16c3:	c7 84 24 44 52 27 00 	movl   $0x3f800000,0x275244(%rsp)
    16ca:	00 00 80 3f 
    16ce:	c7 84 24 4c 52 27 00 	movl   $0x3f800000,0x27524c(%rsp)
    16d5:	00 00 80 3f 
    16d9:	c7 84 24 8c 5e 27 00 	movl   $0x3f800000,0x275e8c(%rsp)
    16e0:	00 00 80 3f 
    16e4:	c7 84 24 94 5e 27 00 	movl   $0x3f800000,0x275e94(%rsp)
    16eb:	00 00 80 3f 
    16ef:	c7 84 24 9c 5e 27 00 	movl   $0x3f800000,0x275e9c(%rsp)
    16f6:	00 00 80 3f 
    16fa:	c7 84 24 a4 5e 27 00 	movl   $0x3f800000,0x275ea4(%rsp)
    1701:	00 00 80 3f 
    1705:	c7 84 24 ac 5e 27 00 	movl   $0x3f800000,0x275eac(%rsp)
    170c:	00 00 80 3f 
    1710:	c7 84 24 b4 5e 27 00 	movl   $0x3f800000,0x275eb4(%rsp)
    1717:	00 00 80 3f 
    171b:	c7 84 24 bc 5e 27 00 	movl   $0x3f800000,0x275ebc(%rsp)
    1722:	00 00 80 3f 
    1726:	c7 84 24 c4 5e 27 00 	movl   $0x3f800000,0x275ec4(%rsp)
    172d:	00 00 80 3f 
    1731:	c7 84 24 cc 5e 27 00 	movl   $0x3f800000,0x275ecc(%rsp)
    1738:	00 00 80 3f 
    173c:	c7 84 24 d4 5e 27 00 	movl   $0x3f800000,0x275ed4(%rsp)
    1743:	00 00 80 3f 
    1747:	c7 84 24 14 6b 27 00 	movl   $0x3f800000,0x276b14(%rsp)
    174e:	00 00 80 3f 
    1752:	c7 84 24 1c 6b 27 00 	movl   $0x3f800000,0x276b1c(%rsp)
    1759:	00 00 80 3f 
    175d:	c7 84 24 24 6b 27 00 	movl   $0x3f800000,0x276b24(%rsp)
    1764:	00 00 80 3f 
    1768:	c7 84 24 2c 6b 27 00 	movl   $0x3f800000,0x276b2c(%rsp)
    176f:	00 00 80 3f 
    1773:	c7 84 24 34 6b 27 00 	movl   $0x3f800000,0x276b34(%rsp)
    177a:	00 00 80 3f 
    177e:	c7 84 24 3c 6b 27 00 	movl   $0x3f800000,0x276b3c(%rsp)
    1785:	00 00 80 3f 
    1789:	c7 84 24 44 6b 27 00 	movl   $0x3f800000,0x276b44(%rsp)
    1790:	00 00 80 3f 
    1794:	c7 84 24 4c 6b 27 00 	movl   $0x3f800000,0x276b4c(%rsp)
    179b:	00 00 80 3f 
    179f:	c7 84 24 54 6b 27 00 	movl   $0x3f800000,0x276b54(%rsp)
    17a6:	00 00 80 3f 
    17aa:	c7 84 24 5c 6b 27 00 	movl   $0x3f800000,0x276b5c(%rsp)
    17b1:	00 00 80 3f 
    17b5:	c7 84 24 9c 77 27 00 	movl   $0x3f800000,0x27779c(%rsp)
    17bc:	00 00 80 3f 
    17c0:	c7 84 24 a4 77 27 00 	movl   $0x3f800000,0x2777a4(%rsp)
    17c7:	00 00 80 3f 
    17cb:	c7 84 24 ac 77 27 00 	movl   $0x3f800000,0x2777ac(%rsp)
    17d2:	00 00 80 3f 
    17d6:	c7 84 24 b4 77 27 00 	movl   $0x3f800000,0x2777b4(%rsp)
    17dd:	00 00 80 3f 
    17e1:	c7 84 24 bc 77 27 00 	movl   $0x3f800000,0x2777bc(%rsp)
    17e8:	00 00 80 3f 
    17ec:	c7 84 24 c4 77 27 00 	movl   $0x3f800000,0x2777c4(%rsp)
    17f3:	00 00 80 3f 
    17f7:	c7 84 24 cc 77 27 00 	movl   $0x3f800000,0x2777cc(%rsp)
    17fe:	00 00 80 3f 
    1802:	c7 84 24 d4 77 27 00 	movl   $0x3f800000,0x2777d4(%rsp)
    1809:	00 00 80 3f 
    180d:	c7 84 24 dc 77 27 00 	movl   $0x3f800000,0x2777dc(%rsp)
    1814:	00 00 80 3f 
    1818:	66 44 0f 28 2d 2f 29 	movapd 0x292f(%rip),%xmm13        # 4150 <_IO_stdin_used+0x150>
    181f:	00 00 
    1821:	c7 84 24 e4 77 27 00 	movl   $0x3f800000,0x2777e4(%rsp)
    1828:	00 00 80 3f 
    182c:	66 44 0f 28 1d 2b 29 	movapd 0x292b(%rip),%xmm11        # 4160 <_IO_stdin_used+0x160>
    1833:	00 00 
    1835:	c7 84 24 74 02 00 00 	movl   $0x0,0x274(%rsp)
    183c:	00 00 00 00 
    1840:	4c 89 94 24 a0 02 00 	mov    %r10,0x2a0(%rsp)
    1847:	00 
    1848:	4c 89 9c 24 b0 02 00 	mov    %r11,0x2b0(%rsp)
    184f:	00 
    1850:	4c 89 a4 24 a8 02 00 	mov    %r12,0x2a8(%rsp)
    1857:	00 
    1858:	4c 89 ac 24 98 02 00 	mov    %r13,0x298(%rsp)
    185f:	00 
    1860:	4c 89 b4 24 b8 02 00 	mov    %r14,0x2b8(%rsp)
    1867:	00 
    1868:	4c 89 bc 24 68 02 00 	mov    %r15,0x268(%rsp)
    186f:	00 
    1870:	0f 31                	rdtsc  
    1872:	48 c1 e2 20          	shl    $0x20,%rdx
    1876:	48 09 d0             	or     %rdx,%rax
    1879:	0f 88 e4 17 00 00    	js     3063 <main+0x1e63>
    187f:	66 0f ef c9          	pxor   %xmm1,%xmm1
    1883:	f2 48 0f 2a c8       	cvtsi2sd %rax,%xmm1
    1888:	f2 0f 11 8c 24 78 02 	movsd  %xmm1,0x278(%rsp)
    188f:	00 00 
    1891:	8b 8c 24 74 02 00 00 	mov    0x274(%rsp),%ecx
    1898:	4c 8b bc 24 b0 02 00 	mov    0x2b0(%rsp),%r15
    189f:	00 
    18a0:	31 db                	xor    %ebx,%ebx
    18a2:	4c 8b b4 24 a0 02 00 	mov    0x2a0(%rsp),%r14
    18a9:	00 
    18aa:	4c 8b ac 24 90 02 00 	mov    0x290(%rsp),%r13
    18b1:	00 
    18b2:	4c 69 c9 1f 85 eb 51 	imul   $0x51eb851f,%rcx,%r9
    18b9:	49 89 c8             	mov    %rcx,%r8
    18bc:	4d 89 fc             	mov    %r15,%r12
    18bf:	0f 28 9c 24 80 02 00 	movaps 0x280(%rsp),%xmm3
    18c6:	00 
    18c7:	4c 8b 94 24 a8 02 00 	mov    0x2a8(%rsp),%r10
    18ce:	00 
    18cf:	49 c1 e9 24          	shr    $0x24,%r9
    18d3:	41 6b f9 32          	imul   $0x32,%r9d,%edi
    18d7:	41 29 f8             	sub    %edi,%r8d
    18da:	44 89 c2             	mov    %r8d,%edx
    18dd:	45 31 db             	xor    %r11d,%r11d
    18e0:	85 d2                	test   %edx,%edx
    18e2:	0f 84 10 01 00 00    	je     19f8 <main+0x7f8>
    18e8:	41 0f 10 65 00       	movups 0x0(%r13),%xmm4
    18ed:	be 10 00 00 00       	mov    $0x10,%esi
    18f2:	41 0f 11 26          	movups %xmm4,(%r14)
    18f6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    18fd:	00 00 00 
    1900:	41 0f 10 6c 35 00    	movups 0x0(%r13,%rsi,1),%xmm5
    1906:	41 0f 10 74 35 10    	movups 0x10(%r13,%rsi,1),%xmm6
    190c:	41 0f 10 7c 35 20    	movups 0x20(%r13,%rsi,1),%xmm7
    1912:	45 0f 10 44 35 30    	movups 0x30(%r13,%rsi,1),%xmm8
    1918:	45 0f 10 4c 35 40    	movups 0x40(%r13,%rsi,1),%xmm9
    191e:	45 0f 10 54 35 50    	movups 0x50(%r13,%rsi,1),%xmm10
    1924:	41 0f 11 2c 36       	movups %xmm5,(%r14,%rsi,1)
    1929:	45 0f 10 64 35 60    	movups 0x60(%r13,%rsi,1),%xmm12
    192f:	45 0f 10 74 35 70    	movups 0x70(%r13,%rsi,1),%xmm14
    1935:	41 0f 11 74 36 10    	movups %xmm6,0x10(%r14,%rsi,1)
    193b:	45 0f 10 bc 35 80 00 	movups 0x80(%r13,%rsi,1),%xmm15
    1942:	00 00 
    1944:	41 0f 11 7c 36 20    	movups %xmm7,0x20(%r14,%rsi,1)
    194a:	45 0f 11 44 36 30    	movups %xmm8,0x30(%r14,%rsi,1)
    1950:	45 0f 11 4c 36 40    	movups %xmm9,0x40(%r14,%rsi,1)
    1956:	45 0f 11 54 36 50    	movups %xmm10,0x50(%r14,%rsi,1)
    195c:	45 0f 11 64 36 60    	movups %xmm12,0x60(%r14,%rsi,1)
    1962:	45 0f 11 74 36 70    	movups %xmm14,0x70(%r14,%rsi,1)
    1968:	45 0f 11 bc 36 80 00 	movups %xmm15,0x80(%r14,%rsi,1)
    196f:	00 00 
    1971:	48 81 c6 90 00 00 00 	add    $0x90,%rsi
    1978:	48 81 fe 70 0c 00 00 	cmp    $0xc70,%rsi
    197f:	0f 85 7b ff ff ff    	jne    1900 <main+0x700>
    1985:	f3 41 0f 10 85 70 0c 	movss  0xc70(%r13),%xmm0
    198c:	00 00 
    198e:	f3 41 0f 10 8d 74 0c 	movss  0xc74(%r13),%xmm1
    1995:	00 00 
    1997:	f3 41 0f 11 86 70 0c 	movss  %xmm0,0xc70(%r14)
    199e:	00 00 
    19a0:	f3 41 0f 11 8e 74 0c 	movss  %xmm1,0xc74(%r14)
    19a7:	00 00 
    19a9:	e9 f5 04 00 00       	jmpq   1ea3 <main+0xca3>
    19ae:	31 f6                	xor    %esi,%esi
    19b0:	48 89 df             	mov    %rbx,%rdi
    19b3:	e8 68 f7 ff ff       	callq  1120 <XLookupKeysym@plt>
    19b8:	3c 71                	cmp    $0x71,%al
    19ba:	0f 85 e0 f8 ff ff    	jne    12a0 <main+0xa0>
    19c0:	48 89 ef             	mov    %rbp,%rdi
    19c3:	e8 28 18 00 00       	callq  31f0 <flame_close>
    19c8:	48 8b 84 24 28 16 31 	mov    0x311628(%rsp),%rax
    19cf:	00 
    19d0:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    19d7:	00 00 
    19d9:	0f 85 ab 16 00 00    	jne    308a <main+0x1e8a>
    19df:	48 81 c4 38 16 31 00 	add    $0x311638,%rsp
    19e6:	31 c0                	xor    %eax,%eax
    19e8:	5b                   	pop    %rbx
    19e9:	5d                   	pop    %rbp
    19ea:	41 5c                	pop    %r12
    19ec:	41 5d                	pop    %r13
    19ee:	41 5e                	pop    %r14
    19f0:	41 5f                	pop    %r15
    19f2:	c3                   	retq   
    19f3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    19f8:	43 0f 10 54 5d 00    	movups 0x0(%r13,%r11,2),%xmm2
    19fe:	49 8d 43 10          	lea    0x10(%r11),%rax
    1a02:	49 8d 4b 20          	lea    0x20(%r11),%rcx
    1a06:	43 0f 10 64 5d 10    	movups 0x10(%r13,%r11,2),%xmm4
    1a0c:	0f 28 0d cd 26 00 00 	movaps 0x26cd(%rip),%xmm1        # 40e0 <_IO_stdin_used+0xe0>
    1a13:	66 0f 28 05 b5 26 00 	movapd 0x26b5(%rip),%xmm0        # 40d0 <_IO_stdin_used+0xd0>
    1a1a:	00 
    1a1b:	0f 28 ea             	movaps %xmm2,%xmm5
    1a1e:	43 0f 11 14 5e       	movups %xmm2,(%r14,%r11,2)
    1a23:	0f c6 d4 dd          	shufps $0xdd,%xmm4,%xmm2
    1a27:	66 44 0f 28 05 a0 26 	movapd 0x26a0(%rip),%xmm8        # 40d0 <_IO_stdin_used+0xd0>
    1a2e:	00 00 
    1a30:	0f c6 ec 88          	shufps $0x88,%xmm4,%xmm5
    1a34:	0f 5c ea             	subps  %xmm2,%xmm5
    1a37:	43 0f 11 64 5e 10    	movups %xmm4,0x10(%r14,%r11,2)
    1a3d:	66 44 0f 28 35 aa 26 	movapd 0x26aa(%rip),%xmm14        # 40f0 <_IO_stdin_used+0xf0>
    1a44:	00 00 
    1a46:	66 0f 6f 15 c2 26 00 	movdqa 0x26c2(%rip),%xmm2        # 4110 <_IO_stdin_used+0x110>
    1a4d:	00 
    1a4e:	66 0f 6f 25 ca 26 00 	movdqa 0x26ca(%rip),%xmm4        # 4120 <_IO_stdin_used+0x120>
    1a55:	00 
    1a56:	66 44 0f 28 3d 91 26 	movapd 0x2691(%rip),%xmm15        # 40f0 <_IO_stdin_used+0xf0>
    1a5d:	00 00 
    1a5f:	0f 12 dd             	movhlps %xmm5,%xmm3
    1a62:	44 0f 5a cd          	cvtps2pd %xmm5,%xmm9
    1a66:	44 0f 28 e5          	movaps %xmm5,%xmm12
    1a6a:	66 45 0f 28 d1       	movapd %xmm9,%xmm10
    1a6f:	0f 5a f3             	cvtps2pd %xmm3,%xmm6
    1a72:	66 0f 28 fe          	movapd %xmm6,%xmm7
    1a76:	0f c2 cd 01          	cmpltps %xmm5,%xmm1
    1a7a:	66 0f c2 3d 4d 26 00 	cmplepd 0x264d(%rip),%xmm7        # 40d0 <_IO_stdin_used+0xd0>
    1a81:	00 02 
    1a83:	66 44 0f c2 c6 01    	cmpltpd %xmm6,%xmm8
    1a89:	66 44 0f c2 15 3d 26 	cmplepd 0x263d(%rip),%xmm10        # 40d0 <_IO_stdin_used+0xd0>
    1a90:	00 00 02 
    1a93:	66 44 0f c2 fe 01    	cmpltpd %xmm6,%xmm15
    1a99:	44 0f c2 25 3e 26 00 	cmpleps 0x263e(%rip),%xmm12        # 40e0 <_IO_stdin_used+0xe0>
    1aa0:	00 02 
    1aa2:	66 41 0f c2 c1 01    	cmpltpd %xmm9,%xmm0
    1aa8:	66 0f c2 35 3f 26 00 	cmplepd 0x263f(%rip),%xmm6        # 40f0 <_IO_stdin_used+0xf0>
    1aaf:	00 02 
    1ab1:	66 45 0f c2 f1 01    	cmpltpd %xmm9,%xmm14
    1ab7:	66 44 0f c2 0d 2f 26 	cmplepd 0x262f(%rip),%xmm9        # 40f0 <_IO_stdin_used+0xf0>
    1abe:	00 00 02 
    1ac1:	44 0f c6 d7 88       	shufps $0x88,%xmm7,%xmm10
    1ac6:	66 45 0f db e2       	pand   %xmm10,%xmm12
    1acb:	66 44 0f db d1       	pand   %xmm1,%xmm10
    1ad0:	41 0f c6 c0 88       	shufps $0x88,%xmm8,%xmm0
    1ad5:	66 44 0f db 15 22 26 	pand   0x2622(%rip),%xmm10        # 4100 <_IO_stdin_used+0x100>
    1adc:	00 00 
    1ade:	45 0f c6 f7 88       	shufps $0x88,%xmm15,%xmm14
    1ae3:	66 45 0f db f4       	pand   %xmm12,%xmm14
    1ae8:	66 0f db e0          	pand   %xmm0,%xmm4
    1aec:	66 44 0f 28 05 db 25 	movapd 0x25db(%rip),%xmm8        # 40d0 <_IO_stdin_used+0xd0>
    1af3:	00 00 
    1af5:	44 0f c6 ce 88       	shufps $0x88,%xmm6,%xmm9
    1afa:	66 45 0f db cc       	pand   %xmm12,%xmm9
    1aff:	66 41 0f db d6       	pand   %xmm14,%xmm2
    1b04:	66 0f 28 0d e4 25 00 	movapd 0x25e4(%rip),%xmm1        # 40f0 <_IO_stdin_used+0xf0>
    1b0b:	00 
    1b0c:	66 45 0f df ca       	pandn  %xmm10,%xmm9
    1b11:	45 0f 10 54 45 10    	movups 0x10(%r13,%rax,2),%xmm10
    1b17:	66 45 0f df f1       	pandn  %xmm9,%xmm14
    1b1c:	45 0f 10 4c 45 00    	movups 0x0(%r13,%rax,2),%xmm9
    1b22:	66 44 0f eb f2       	por    %xmm2,%xmm14
    1b27:	66 0f 28 15 c1 25 00 	movapd 0x25c1(%rip),%xmm2        # 40f0 <_IO_stdin_used+0xf0>
    1b2e:	00 
    1b2f:	45 0f 11 54 46 10    	movups %xmm10,0x10(%r14,%rax,2)
    1b35:	41 0f 28 f1          	movaps %xmm9,%xmm6
    1b39:	45 0f 11 0c 46       	movups %xmm9,(%r14,%rax,2)
    1b3e:	45 0f c6 ca dd       	shufps $0xdd,%xmm10,%xmm9
    1b43:	66 41 0f df c6       	pandn  %xmm14,%xmm0
    1b48:	41 0f c6 f2 88       	shufps $0x88,%xmm10,%xmm6
    1b4d:	41 0f 5c f1          	subps  %xmm9,%xmm6
    1b51:	66 0f 6f e8          	movdqa %xmm0,%xmm5
    1b55:	66 0f eb ec          	por    %xmm4,%xmm5
    1b59:	0f 28 25 80 25 00 00 	movaps 0x2580(%rip),%xmm4        # 40e0 <_IO_stdin_used+0xe0>
    1b60:	43 0f 11 2c 1f       	movups %xmm5,(%r15,%r11,1)
    1b65:	66 0f 28 2d 63 25 00 	movapd 0x2563(%rip),%xmm5        # 40d0 <_IO_stdin_used+0xd0>
    1b6c:	00 
    1b6d:	49 83 c3 30          	add    $0x30,%r11
    1b71:	0f 12 de             	movhlps %xmm6,%xmm3
    1b74:	44 0f 5a e6          	cvtps2pd %xmm6,%xmm12
    1b78:	44 0f 28 fe          	movaps %xmm6,%xmm15
    1b7c:	66 45 0f 28 f4       	movapd %xmm12,%xmm14
    1b81:	0f 5a c3             	cvtps2pd %xmm3,%xmm0
    1b84:	66 0f 28 f8          	movapd %xmm0,%xmm7
    1b88:	0f c2 e6 01          	cmpltps %xmm6,%xmm4
    1b8c:	66 0f c2 3d 3b 25 00 	cmplepd 0x253b(%rip),%xmm7        # 40d0 <_IO_stdin_used+0xd0>
    1b93:	00 02 
    1b95:	66 44 0f c2 c0 01    	cmpltpd %xmm0,%xmm8
    1b9b:	66 44 0f c2 35 2b 25 	cmplepd 0x252b(%rip),%xmm14        # 40d0 <_IO_stdin_used+0xd0>
    1ba2:	00 00 02 
    1ba5:	66 0f c2 d0 01       	cmpltpd %xmm0,%xmm2
    1baa:	44 0f c2 3d 2d 25 00 	cmpleps 0x252d(%rip),%xmm15        # 40e0 <_IO_stdin_used+0xe0>
    1bb1:	00 02 
    1bb3:	66 41 0f c2 ec 01    	cmpltpd %xmm12,%xmm5
    1bb9:	66 0f c2 05 2e 25 00 	cmplepd 0x252e(%rip),%xmm0        # 40f0 <_IO_stdin_used+0xf0>
    1bc0:	00 02 
    1bc2:	66 41 0f c2 cc 01    	cmpltpd %xmm12,%xmm1
    1bc8:	66 44 0f c2 25 1e 25 	cmplepd 0x251e(%rip),%xmm12        # 40f0 <_IO_stdin_used+0xf0>
    1bcf:	00 00 02 
    1bd2:	44 0f c6 f7 88       	shufps $0x88,%xmm7,%xmm14
    1bd7:	66 45 0f db fe       	pand   %xmm14,%xmm15
    1bdc:	66 44 0f db f4       	pand   %xmm4,%xmm14
    1be1:	41 0f c6 e8 88       	shufps $0x88,%xmm8,%xmm5
    1be6:	66 44 0f db 35 11 25 	pand   0x2511(%rip),%xmm14        # 4100 <_IO_stdin_used+0x100>
    1bed:	00 00 
    1bef:	66 44 0f 6f 0d 18 25 	movdqa 0x2518(%rip),%xmm9        # 4110 <_IO_stdin_used+0x110>
    1bf6:	00 00 
    1bf8:	0f c6 ca 88          	shufps $0x88,%xmm2,%xmm1
    1bfc:	66 41 0f db cf       	pand   %xmm15,%xmm1
    1c01:	66 44 0f 6f 15 16 25 	movdqa 0x2516(%rip),%xmm10        # 4120 <_IO_stdin_used+0x120>
    1c08:	00 00 
    1c0a:	66 44 0f 28 05 bd 24 	movapd 0x24bd(%rip),%xmm8        # 40d0 <_IO_stdin_used+0xd0>
    1c11:	00 00 
    1c13:	44 0f c6 e0 88       	shufps $0x88,%xmm0,%xmm12
    1c18:	66 45 0f db e7       	pand   %xmm15,%xmm12
    1c1d:	41 0f 10 44 4d 10    	movups 0x10(%r13,%rcx,2),%xmm0
    1c23:	66 45 0f df e6       	pandn  %xmm14,%xmm12
    1c28:	66 44 0f db c9       	pand   %xmm1,%xmm9
    1c2d:	66 44 0f db d5       	pand   %xmm5,%xmm10
    1c32:	66 41 0f df cc       	pandn  %xmm12,%xmm1
    1c37:	45 0f 10 64 4d 00    	movups 0x0(%r13,%rcx,2),%xmm12
    1c3d:	41 0f 11 44 4e 10    	movups %xmm0,0x10(%r14,%rcx,2)
    1c43:	66 41 0f eb c9       	por    %xmm9,%xmm1
    1c48:	66 44 0f 28 0d 9f 24 	movapd 0x249f(%rip),%xmm9        # 40f0 <_IO_stdin_used+0xf0>
    1c4f:	00 00 
    1c51:	41 0f 28 f4          	movaps %xmm12,%xmm6
    1c55:	45 0f 11 24 4e       	movups %xmm12,(%r14,%rcx,2)
    1c5a:	44 0f c6 e0 dd       	shufps $0xdd,%xmm0,%xmm12
    1c5f:	66 0f df e9          	pandn  %xmm1,%xmm5
    1c63:	0f c6 f0 88          	shufps $0x88,%xmm0,%xmm6
    1c67:	41 0f 5c f4          	subps  %xmm12,%xmm6
    1c6b:	66 41 0f eb ea       	por    %xmm10,%xmm5
    1c70:	44 0f 28 15 68 24 00 	movaps 0x2468(%rip),%xmm10        # 40e0 <_IO_stdin_used+0xe0>
    1c77:	00 
    1c78:	66 0f 28 05 50 24 00 	movapd 0x2450(%rip),%xmm0        # 40d0 <_IO_stdin_used+0xd0>
    1c7f:	00 
    1c80:	43 0f 11 6c 3b e0    	movups %xmm5,-0x20(%r11,%r15,1)
    1c86:	66 0f 28 0d 62 24 00 	movapd 0x2462(%rip),%xmm1        # 40f0 <_IO_stdin_used+0xf0>
    1c8d:	00 
    1c8e:	66 0f 6f 2d 7a 24 00 	movdqa 0x247a(%rip),%xmm5        # 4110 <_IO_stdin_used+0x110>
    1c95:	00 
    1c96:	66 44 0f 6f 25 81 24 	movdqa 0x2481(%rip),%xmm12        # 4120 <_IO_stdin_used+0x120>
    1c9d:	00 00 
    1c9f:	0f 12 de             	movhlps %xmm6,%xmm3
    1ca2:	44 0f 5a f6          	cvtps2pd %xmm6,%xmm14
    1ca6:	0f 28 e6             	movaps %xmm6,%xmm4
    1ca9:	66 41 0f 28 d6       	movapd %xmm14,%xmm2
    1cae:	44 0f 5a fb          	cvtps2pd %xmm3,%xmm15
    1cb2:	66 41 0f 28 ff       	movapd %xmm15,%xmm7
    1cb7:	44 0f c2 d6 01       	cmpltps %xmm6,%xmm10
    1cbc:	66 0f c2 15 0b 24 00 	cmplepd 0x240b(%rip),%xmm2        # 40d0 <_IO_stdin_used+0xd0>
    1cc3:	00 02 
    1cc5:	0f c2 25 13 24 00 00 	cmpleps 0x2413(%rip),%xmm4        # 40e0 <_IO_stdin_used+0xe0>
    1ccc:	02 
    1ccd:	66 0f c2 3d fa 23 00 	cmplepd 0x23fa(%rip),%xmm7        # 40d0 <_IO_stdin_used+0xd0>
    1cd4:	00 02 
    1cd6:	66 41 0f c2 c6 01    	cmpltpd %xmm14,%xmm0
    1cdc:	66 45 0f c2 c7 01    	cmpltpd %xmm15,%xmm8
    1ce2:	66 41 0f c2 ce 01    	cmpltpd %xmm14,%xmm1
    1ce8:	66 44 0f c2 35 fe 23 	cmplepd 0x23fe(%rip),%xmm14        # 40f0 <_IO_stdin_used+0xf0>
    1cef:	00 00 02 
    1cf2:	66 45 0f c2 cf 01    	cmpltpd %xmm15,%xmm9
    1cf8:	66 44 0f c2 3d ee 23 	cmplepd 0x23ee(%rip),%xmm15        # 40f0 <_IO_stdin_used+0xf0>
    1cff:	00 00 02 
    1d02:	0f c6 d7 88          	shufps $0x88,%xmm7,%xmm2
    1d06:	66 0f db e2          	pand   %xmm2,%xmm4
    1d0a:	66 41 0f db d2       	pand   %xmm10,%xmm2
    1d0f:	66 0f db 15 e9 23 00 	pand   0x23e9(%rip),%xmm2        # 4100 <_IO_stdin_used+0x100>
    1d16:	00 
    1d17:	41 0f c6 c0 88       	shufps $0x88,%xmm8,%xmm0
    1d1c:	66 44 0f db e0       	pand   %xmm0,%xmm12
    1d21:	41 0f c6 c9 88       	shufps $0x88,%xmm9,%xmm1
    1d26:	66 0f db cc          	pand   %xmm4,%xmm1
    1d2a:	45 0f c6 f7 88       	shufps $0x88,%xmm15,%xmm14
    1d2f:	66 44 0f db f4       	pand   %xmm4,%xmm14
    1d34:	66 0f db e9          	pand   %xmm1,%xmm5
    1d38:	66 44 0f df f2       	pandn  %xmm2,%xmm14
    1d3d:	66 41 0f df ce       	pandn  %xmm14,%xmm1
    1d42:	66 0f eb cd          	por    %xmm5,%xmm1
    1d46:	66 0f df c1          	pandn  %xmm1,%xmm0
    1d4a:	66 0f 6f f0          	movdqa %xmm0,%xmm6
    1d4e:	66 41 0f eb f4       	por    %xmm12,%xmm6
    1d53:	43 0f 11 74 3b f0    	movups %xmm6,-0x10(%r11,%r15,1)
    1d59:	49 81 fb 30 06 00 00 	cmp    $0x630,%r11
    1d60:	0f 85 92 fc ff ff    	jne    19f8 <main+0x7f8>
    1d66:	f3 45 0f 10 b5 60 0c 	movss  0xc60(%r13),%xmm14
    1d6d:	00 00 
    1d6f:	66 0f ef d2          	pxor   %xmm2,%xmm2
    1d73:	41 b8 00 ff ff ff    	mov    $0xffffff00,%r8d
    1d79:	f3 45 0f 10 bd 64 0c 	movss  0xc64(%r13),%xmm15
    1d80:	00 00 
    1d82:	f3 45 0f 11 b6 60 0c 	movss  %xmm14,0xc60(%r14)
    1d89:	00 00 
    1d8b:	f3 45 0f 5c f7       	subss  %xmm15,%xmm14
    1d90:	f3 45 0f 11 be 64 0c 	movss  %xmm15,0xc64(%r14)
    1d97:	00 00 
    1d99:	f3 41 0f 5a d6       	cvtss2sd %xmm14,%xmm2
    1d9e:	66 0f 2f 15 0a 24 00 	comisd 0x240a(%rip),%xmm2        # 41b0 <_IO_stdin_used+0x1b0>
    1da5:	00 
    1da6:	77 22                	ja     1dca <main+0xbca>
    1da8:	44 0f 2f 35 fc 22 00 	comiss 0x22fc(%rip),%xmm14        # 40ac <_IO_stdin_used+0xac>
    1daf:	00 
    1db0:	41 b8 00 be be be    	mov    $0xbebebe00,%r8d
    1db6:	77 12                	ja     1dca <main+0xbca>
    1db8:	66 0f 2f 15 f8 23 00 	comisd 0x23f8(%rip),%xmm2        # 41b8 <_IO_stdin_used+0x1b8>
    1dbf:	00 
    1dc0:	41 b8 00 a9 a9 a9    	mov    $0xa9a9a900,%r8d
    1dc6:	44 0f 46 c3          	cmovbe %ebx,%r8d
    1dca:	f3 41 0f 10 bd 68 0c 	movss  0xc68(%r13),%xmm7
    1dd1:	00 00 
    1dd3:	66 0f ef c0          	pxor   %xmm0,%xmm0
    1dd7:	f3 41 0f 10 a5 6c 0c 	movss  0xc6c(%r13),%xmm4
    1dde:	00 00 
    1de0:	45 89 87 30 06 00 00 	mov    %r8d,0x630(%r15)
    1de7:	41 b9 00 ff ff ff    	mov    $0xffffff00,%r9d
    1ded:	f3 41 0f 11 be 68 0c 	movss  %xmm7,0xc68(%r14)
    1df4:	00 00 
    1df6:	f3 0f 5c fc          	subss  %xmm4,%xmm7
    1dfa:	f3 41 0f 11 a6 6c 0c 	movss  %xmm4,0xc6c(%r14)
    1e01:	00 00 
    1e03:	f3 0f 5a c7          	cvtss2sd %xmm7,%xmm0
    1e07:	66 0f 2f 05 a1 23 00 	comisd 0x23a1(%rip),%xmm0        # 41b0 <_IO_stdin_used+0x1b0>
    1e0e:	00 
    1e0f:	77 21                	ja     1e32 <main+0xc32>
    1e11:	0f 2f 3d 94 22 00 00 	comiss 0x2294(%rip),%xmm7        # 40ac <_IO_stdin_used+0xac>
    1e18:	41 b9 00 be be be    	mov    $0xbebebe00,%r9d
    1e1e:	77 12                	ja     1e32 <main+0xc32>
    1e20:	66 0f 2f 05 90 23 00 	comisd 0x2390(%rip),%xmm0        # 41b8 <_IO_stdin_used+0x1b8>
    1e27:	00 
    1e28:	41 b9 00 a9 a9 a9    	mov    $0xa9a9a900,%r9d
    1e2e:	44 0f 46 cb          	cmovbe %ebx,%r9d
    1e32:	f3 45 0f 10 85 70 0c 	movss  0xc70(%r13),%xmm8
    1e39:	00 00 
    1e3b:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    1e40:	f3 41 0f 10 8d 74 0c 	movss  0xc74(%r13),%xmm1
    1e47:	00 00 
    1e49:	45 89 8f 34 06 00 00 	mov    %r9d,0x634(%r15)
    1e50:	bf 00 ff ff ff       	mov    $0xffffff00,%edi
    1e55:	f3 45 0f 11 86 70 0c 	movss  %xmm8,0xc70(%r14)
    1e5c:	00 00 
    1e5e:	f3 44 0f 5c c1       	subss  %xmm1,%xmm8
    1e63:	f3 41 0f 11 8e 74 0c 	movss  %xmm1,0xc74(%r14)
    1e6a:	00 00 
    1e6c:	f3 45 0f 5a c8       	cvtss2sd %xmm8,%xmm9
    1e71:	66 44 0f 2f 0d 36 23 	comisd 0x2336(%rip),%xmm9        # 41b0 <_IO_stdin_used+0x1b0>
    1e78:	00 00 
    1e7a:	77 20                	ja     1e9c <main+0xc9c>
    1e7c:	44 0f 2f 05 28 22 00 	comiss 0x2228(%rip),%xmm8        # 40ac <_IO_stdin_used+0xac>
    1e83:	00 
    1e84:	bf 00 be be be       	mov    $0xbebebe00,%edi
    1e89:	77 11                	ja     1e9c <main+0xc9c>
    1e8b:	66 44 0f 2f 0d 24 23 	comisd 0x2324(%rip),%xmm9        # 41b8 <_IO_stdin_used+0x1b8>
    1e92:	00 00 
    1e94:	bf 00 a9 a9 a9       	mov    $0xa9a9a900,%edi
    1e99:	0f 46 fb             	cmovbe %ebx,%edi
    1e9c:	41 89 bf 38 06 00 00 	mov    %edi,0x638(%r15)
    1ea3:	49 81 c5 88 0c 00 00 	add    $0xc88,%r13
    1eaa:	49 81 c6 88 0c 00 00 	add    $0xc88,%r14
    1eb1:	49 81 c7 44 06 00 00 	add    $0x644,%r15
    1eb8:	4d 39 d5             	cmp    %r10,%r13
    1ebb:	0f 85 1c fa ff ff    	jne    18dd <main+0x6dd>
    1ec1:	4c 8b 8c 24 98 02 00 	mov    0x298(%rsp),%r9
    1ec8:	00 
    1ec9:	48 8b 8c 24 90 02 00 	mov    0x290(%rsp),%rcx
    1ed0:	00 
    1ed1:	0f 29 9c 24 80 02 00 	movaps %xmm3,0x280(%rsp)
    1ed8:	00 
    1ed9:	48 8b bc 24 b8 02 00 	mov    0x2b8(%rsp),%rdi
    1ee0:	00 
    1ee1:	4d 89 cf             	mov    %r9,%r15
    1ee4:	31 c0                	xor    %eax,%eax
    1ee6:	49 81 c1 88 0c 00 00 	add    $0xc88,%r9
    1eed:	45 0f 10 bf 10 19 00 	movups 0x1910(%r15),%xmm15
    1ef4:	00 
    1ef5:	45 0f 10 17          	movups (%r15),%xmm10
    1ef9:	4d 8d af 10 19 00 00 	lea    0x1910(%r15),%r13
    1f00:	49 8d 97 90 0c 00 00 	lea    0xc90(%r15),%rdx
    1f07:	45 0f 10 a7 88 0c 00 	movups 0xc88(%r15),%xmm12
    1f0e:	00 
    1f0f:	4d 8d 47 08          	lea    0x8(%r15),%r8
    1f13:	4d 8d 5f 10          	lea    0x10(%r15),%r11
    1f17:	49 8d b7 18 19 00 00 	lea    0x1918(%r15),%rsi
    1f1e:	49 8d 9f 98 0c 00 00 	lea    0xc98(%r15),%rbx
    1f25:	4d 8d 97 20 19 00 00 	lea    0x1920(%r15),%r10
    1f2c:	eb 0f                	jmp    1f3d <main+0xd3d>
    1f2e:	66 90                	xchg   %ax,%ax
    1f30:	44 0f 28 a4 24 30 02 	movaps 0x230(%rsp),%xmm12
    1f37:	00 00 
    1f39:	45 0f 28 fe          	movaps %xmm14,%xmm15
    1f3d:	45 0f 10 04 00       	movups (%r8,%rax,1),%xmm8
    1f42:	41 0f 10 7c 00 10    	movups 0x10(%r8,%rax,1),%xmm7
    1f48:	0f 10 0c 02          	movups (%rdx,%rax,1),%xmm1
    1f4c:	0f 10 5c 02 10       	movups 0x10(%rdx,%rax,1),%xmm3
    1f51:	45 0f 28 f0          	movaps %xmm8,%xmm14
    1f55:	0f 28 35 e4 21 00 00 	movaps 0x21e4(%rip),%xmm6        # 4140 <_IO_stdin_used+0x140>
    1f5c:	44 0f c6 c7 dd       	shufps $0xdd,%xmm7,%xmm8
    1f61:	0f 10 6c 06 10       	movups 0x10(%rsi,%rax,1),%xmm5
    1f66:	44 0f c6 f7 88       	shufps $0x88,%xmm7,%xmm14
    1f6b:	41 0f 5a e6          	cvtps2pd %xmm14,%xmm4
    1f6f:	66 41 0f 59 e5       	mulpd  %xmm13,%xmm4
    1f74:	44 0f 28 c9          	movaps %xmm1,%xmm9
    1f78:	44 0f c6 cb 88       	shufps $0x88,%xmm3,%xmm9
    1f7d:	41 0f 57 f1          	xorps  %xmm9,%xmm6
    1f81:	0f 10 3c 06          	movups (%rsi,%rax,1),%xmm7
    1f85:	0f c6 cb dd          	shufps $0xdd,%xmm3,%xmm1
    1f89:	44 0f 17 74 24 30    	movhps %xmm14,0x30(%rsp)
    1f8f:	0f 5a 44 24 30       	cvtps2pd 0x30(%rsp),%xmm0
    1f94:	66 41 0f 59 c5       	mulpd  %xmm13,%xmm0
    1f99:	0f 5a d6             	cvtps2pd %xmm6,%xmm2
    1f9c:	0f 17 74 24 40       	movhps %xmm6,0x40(%rsp)
    1fa1:	0f 5a 5c 24 40       	cvtps2pd 0x40(%rsp),%xmm3
    1fa6:	66 0f 58 d4          	addpd  %xmm4,%xmm2
    1faa:	0f 28 e7             	movaps %xmm7,%xmm4
    1fad:	0f c6 fd dd          	shufps $0xdd,%xmm5,%xmm7
    1fb1:	0f c6 e5 88          	shufps $0x88,%xmm5,%xmm4
    1fb5:	0f 17 64 24 50       	movhps %xmm4,0x50(%rsp)
    1fba:	41 0f 10 6c 01 10    	movups 0x10(%r9,%rax,1),%xmm5
    1fc0:	66 0f 58 d8          	addpd  %xmm0,%xmm3
    1fc4:	66 0f 5a f2          	cvtpd2ps %xmm2,%xmm6
    1fc8:	0f 5a d4             	cvtps2pd %xmm4,%xmm2
    1fcb:	66 41 0f 59 d5       	mulpd  %xmm13,%xmm2
    1fd0:	66 44 0f 5a f3       	cvtpd2ps %xmm3,%xmm14
    1fd5:	41 0f 16 f6          	movlhps %xmm14,%xmm6
    1fd9:	0f 5a 5c 24 50       	cvtps2pd 0x50(%rsp),%xmm3
    1fde:	0f 17 74 24 60       	movhps %xmm6,0x60(%rsp)
    1fe3:	66 41 0f 59 dd       	mulpd  %xmm13,%xmm3
    1fe8:	0f 5a c6             	cvtps2pd %xmm6,%xmm0
    1feb:	0f 5a 74 24 60       	cvtps2pd 0x60(%rsp),%xmm6
    1ff0:	66 0f 58 c2          	addpd  %xmm2,%xmm0
    1ff4:	66 44 0f 5a f0       	cvtpd2ps %xmm0,%xmm14
    1ff9:	41 0f 28 c4          	movaps %xmm12,%xmm0
    1ffd:	44 0f c6 e5 dd       	shufps $0xdd,%xmm5,%xmm12
    2002:	44 0f 29 64 24 20    	movaps %xmm12,0x20(%rsp)
    2008:	0f c6 c5 88          	shufps $0x88,%xmm5,%xmm0
    200c:	44 0f 5a e0          	cvtps2pd %xmm0,%xmm12
    2010:	66 45 0f 59 e5       	mulpd  %xmm13,%xmm12
    2015:	66 0f 58 f3          	addpd  %xmm3,%xmm6
    2019:	0f 17 44 24 70       	movhps %xmm0,0x70(%rsp)
    201e:	0f 5a 5c 24 70       	cvtps2pd 0x70(%rsp),%xmm3
    2023:	66 41 0f 59 dd       	mulpd  %xmm13,%xmm3
    2028:	0f 10 44 03 10       	movups 0x10(%rbx,%rax,1),%xmm0
    202d:	66 0f 5a e6          	cvtpd2ps %xmm6,%xmm4
    2031:	44 0f 16 f4          	movlhps %xmm4,%xmm14
    2035:	0f 29 84 24 30 02 00 	movaps %xmm0,0x230(%rsp)
    203c:	00 
    203d:	44 0f 17 b4 24 80 00 	movhps %xmm14,0x80(%rsp)
    2044:	00 00 
    2046:	41 0f 5a d6          	cvtps2pd %xmm14,%xmm2
    204a:	0f 5a b4 24 80 00 00 	cvtps2pd 0x80(%rsp),%xmm6
    2051:	00 
    2052:	66 41 0f 58 d4       	addpd  %xmm12,%xmm2
    2057:	44 0f 28 e5          	movaps %xmm5,%xmm12
    205b:	0f c6 e8 dd          	shufps $0xdd,%xmm0,%xmm5
    205f:	44 0f c6 e0 88       	shufps $0x88,%xmm0,%xmm12
    2064:	66 0f 58 f3          	addpd  %xmm3,%xmm6
    2068:	44 0f 17 a4 24 90 00 	movhps %xmm12,0x90(%rsp)
    206f:	00 00 
    2071:	0f 5a 9c 24 90 00 00 	cvtps2pd 0x90(%rsp),%xmm3
    2078:	00 
    2079:	66 41 0f 59 dd       	mulpd  %xmm13,%xmm3
    207e:	66 44 0f 5a f2       	cvtpd2ps %xmm2,%xmm14
    2083:	41 0f 5a d4          	cvtps2pd %xmm12,%xmm2
    2087:	66 41 0f 59 d5       	mulpd  %xmm13,%xmm2
    208c:	45 0f 28 e2          	movaps %xmm10,%xmm12
    2090:	66 0f 5a e6          	cvtpd2ps %xmm6,%xmm4
    2094:	44 0f 16 f4          	movlhps %xmm4,%xmm14
    2098:	44 0f 17 b4 24 a0 00 	movhps %xmm14,0xa0(%rsp)
    209f:	00 00 
    20a1:	41 0f 5a f6          	cvtps2pd %xmm14,%xmm6
    20a5:	44 0f 5a b4 24 a0 00 	cvtps2pd 0xa0(%rsp),%xmm14
    20ac:	00 00 
    20ae:	66 44 0f 58 f3       	addpd  %xmm3,%xmm14
    20b3:	66 0f 58 f2          	addpd  %xmm2,%xmm6
    20b7:	66 41 0f 5a e6       	cvtpd2ps %xmm14,%xmm4
    20bc:	66 0f 5a c6          	cvtpd2ps %xmm6,%xmm0
    20c0:	0f 16 c4             	movlhps %xmm4,%xmm0
    20c3:	41 0f 10 64 07 10    	movups 0x10(%r15,%rax,1),%xmm4
    20c9:	0f 17 84 24 c0 00 00 	movhps %xmm0,0xc0(%rsp)
    20d0:	00 
    20d1:	0f 5a d0             	cvtps2pd %xmm0,%xmm2
    20d4:	0f 5a 9c 24 c0 00 00 	cvtps2pd 0xc0(%rsp),%xmm3
    20db:	00 
    20dc:	44 0f c6 e4 88       	shufps $0x88,%xmm4,%xmm12
    20e1:	44 0f c6 d4 dd       	shufps $0xdd,%xmm4,%xmm10
    20e6:	44 0f 29 54 24 10    	movaps %xmm10,0x10(%rsp)
    20ec:	44 0f 17 a4 24 b0 00 	movhps %xmm12,0xb0(%rsp)
    20f3:	00 00 
    20f5:	45 0f 5a d4          	cvtps2pd %xmm12,%xmm10
    20f9:	0f 5a b4 24 b0 00 00 	cvtps2pd 0xb0(%rsp),%xmm6
    2100:	00 
    2101:	66 45 0f 59 d3       	mulpd  %xmm11,%xmm10
    2106:	44 0f 28 e4          	movaps %xmm4,%xmm12
    210a:	66 41 0f 59 f3       	mulpd  %xmm11,%xmm6
    210f:	66 41 0f 58 d2       	addpd  %xmm10,%xmm2
    2114:	45 0f 10 54 03 10    	movups 0x10(%r11,%rax,1),%xmm10
    211a:	66 0f 58 de          	addpd  %xmm6,%xmm3
    211e:	45 0f c6 e2 88       	shufps $0x88,%xmm10,%xmm12
    2123:	41 0f c6 e2 dd       	shufps $0xdd,%xmm10,%xmm4
    2128:	44 0f 17 a4 24 d0 00 	movhps %xmm12,0xd0(%rsp)
    212f:	00 00 
    2131:	66 44 0f 5a f2       	cvtpd2ps %xmm2,%xmm14
    2136:	41 0f 5a d4          	cvtps2pd %xmm12,%xmm2
    213a:	66 41 0f 59 d3       	mulpd  %xmm11,%xmm2
    213f:	66 0f 5a c3          	cvtpd2ps %xmm3,%xmm0
    2143:	0f 5a 9c 24 d0 00 00 	cvtps2pd 0xd0(%rsp),%xmm3
    214a:	00 
    214b:	44 0f 16 f0          	movlhps %xmm0,%xmm14
    214f:	44 0f 17 b4 24 e0 00 	movhps %xmm14,0xe0(%rsp)
    2156:	00 00 
    2158:	66 41 0f 59 db       	mulpd  %xmm11,%xmm3
    215d:	41 0f 5a f6          	cvtps2pd %xmm14,%xmm6
    2161:	44 0f 5a b4 24 e0 00 	cvtps2pd 0xe0(%rsp),%xmm14
    2168:	00 00 
    216a:	66 0f 58 f2          	addpd  %xmm2,%xmm6
    216e:	66 44 0f 58 f3       	addpd  %xmm3,%xmm14
    2173:	41 0f 10 5c 05 10    	movups 0x10(%r13,%rax,1),%xmm3
    2179:	66 0f 5a c6          	cvtpd2ps %xmm6,%xmm0
    217d:	66 45 0f 5a e6       	cvtpd2ps %xmm14,%xmm12
    2182:	41 0f 16 c4          	movlhps %xmm12,%xmm0
    2186:	45 0f 28 e7          	movaps %xmm15,%xmm12
    218a:	0f 17 84 24 00 01 00 	movhps %xmm0,0x100(%rsp)
    2191:	00 
    2192:	44 0f c6 e3 88       	shufps $0x88,%xmm3,%xmm12
    2197:	41 0f 5a f4          	cvtps2pd %xmm12,%xmm6
    219b:	66 41 0f 59 f3       	mulpd  %xmm11,%xmm6
    21a0:	44 0f 17 a4 24 f0 00 	movhps %xmm12,0xf0(%rsp)
    21a7:	00 00 
    21a9:	44 0f 5a a4 24 f0 00 	cvtps2pd 0xf0(%rsp),%xmm12
    21b0:	00 00 
    21b2:	66 45 0f 59 e3       	mulpd  %xmm11,%xmm12
    21b7:	0f 5a d0             	cvtps2pd %xmm0,%xmm2
    21ba:	0f 5a 84 24 00 01 00 	cvtps2pd 0x100(%rsp),%xmm0
    21c1:	00 
    21c2:	44 0f c6 fb dd       	shufps $0xdd,%xmm3,%xmm15
    21c7:	66 0f 58 d6          	addpd  %xmm6,%xmm2
    21cb:	0f 28 f1             	movaps %xmm1,%xmm6
    21ce:	66 41 0f 58 c4       	addpd  %xmm12,%xmm0
    21d3:	41 0f 59 f1          	mulps  %xmm9,%xmm6
    21d7:	44 0f 28 e3          	movaps %xmm3,%xmm12
    21db:	66 0f 5a d2          	cvtpd2ps %xmm2,%xmm2
    21df:	66 44 0f 5a f0       	cvtpd2ps %xmm0,%xmm14
    21e4:	41 0f 16 d6          	movlhps %xmm14,%xmm2
    21e8:	45 0f 10 74 02 10    	movups 0x10(%r10,%rax,1),%xmm14
    21ee:	0f 17 94 24 20 01 00 	movhps %xmm2,0x120(%rsp)
    21f5:	00 
    21f6:	0f 5a c2             	cvtps2pd %xmm2,%xmm0
    21f9:	45 0f c6 e6 88       	shufps $0x88,%xmm14,%xmm12
    21fe:	44 0f 29 24 24       	movaps %xmm12,(%rsp)
    2203:	45 0f 5a e4          	cvtps2pd %xmm12,%xmm12
    2207:	66 45 0f 59 e3       	mulpd  %xmm11,%xmm12
    220c:	0f 59 f1             	mulps  %xmm1,%xmm6
    220f:	41 0f c6 de dd       	shufps $0xdd,%xmm14,%xmm3
    2214:	66 41 0f 58 c4       	addpd  %xmm12,%xmm0
    2219:	44 0f 28 24 24       	movaps (%rsp),%xmm12
    221e:	44 0f 17 a4 24 10 01 	movhps %xmm12,0x110(%rsp)
    2225:	00 00 
    2227:	44 0f 5a a4 24 10 01 	cvtps2pd 0x110(%rsp),%xmm12
    222e:	00 00 
    2230:	66 45 0f 59 e3       	mulpd  %xmm11,%xmm12
    2235:	0f 5a 94 24 20 01 00 	cvtps2pd 0x120(%rsp),%xmm2
    223c:	00 
    223d:	44 0f 17 84 24 30 01 	movhps %xmm8,0x130(%rsp)
    2244:	00 00 
    2246:	0f 17 bc 24 50 01 00 	movhps %xmm7,0x150(%rsp)
    224d:	00 
    224e:	0f 17 ac 24 90 01 00 	movhps %xmm5,0x190(%rsp)
    2255:	00 
    2256:	66 0f 5a c0          	cvtpd2ps %xmm0,%xmm0
    225a:	66 41 0f 58 d4       	addpd  %xmm12,%xmm2
    225f:	66 44 0f 5a e2       	cvtpd2ps %xmm2,%xmm12
    2264:	0f 28 15 05 1f 00 00 	movaps 0x1f05(%rip),%xmm2        # 4170 <_IO_stdin_used+0x170>
    226b:	41 0f 16 c4          	movlhps %xmm12,%xmm0
    226f:	44 0f 28 25 09 1f 00 	movaps 0x1f09(%rip),%xmm12        # 4180 <_IO_stdin_used+0x180>
    2276:	00 
    2277:	41 0f 5c d1          	subps  %xmm9,%xmm2
    227b:	44 0f 59 e2          	mulps  %xmm2,%xmm12
    227f:	41 0f 5a d0          	cvtps2pd %xmm8,%xmm2
    2283:	44 0f 5a 84 24 30 01 	cvtps2pd 0x130(%rsp),%xmm8
    228a:	00 00 
    228c:	66 45 0f 59 c5       	mulpd  %xmm13,%xmm8
    2291:	66 41 0f 59 d5       	mulpd  %xmm13,%xmm2
    2296:	44 0f 5c e6          	subps  %xmm6,%xmm12
    229a:	41 0f 58 c4          	addps  %xmm12,%xmm0
    229e:	0f 59 05 eb 1e 00 00 	mulps  0x1eeb(%rip),%xmm0        # 4190 <_IO_stdin_used+0x190>
    22a5:	44 0f 28 25 93 1e 00 	movaps 0x1e93(%rip),%xmm12        # 4140 <_IO_stdin_used+0x140>
    22ac:	00 
    22ad:	44 0f 57 e1          	xorps  %xmm1,%xmm12
    22b1:	44 0f 17 a4 24 40 01 	movhps %xmm12,0x140(%rsp)
    22b8:	00 00 
    22ba:	44 0f 58 c8          	addps  %xmm0,%xmm9
    22be:	41 0f 5a c4          	cvtps2pd %xmm12,%xmm0
    22c2:	66 0f 58 c2          	addpd  %xmm2,%xmm0
    22c6:	44 0f 5a a4 24 40 01 	cvtps2pd 0x140(%rsp),%xmm12
    22cd:	00 00 
    22cf:	66 45 0f 58 c4       	addpd  %xmm12,%xmm8
    22d4:	44 0f 5a e7          	cvtps2pd %xmm7,%xmm12
    22d8:	66 45 0f 59 e5       	mulpd  %xmm13,%xmm12
    22dd:	0f 5a bc 24 50 01 00 	cvtps2pd 0x150(%rsp),%xmm7
    22e4:	00 
    22e5:	66 41 0f 59 fd       	mulpd  %xmm13,%xmm7
    22ea:	66 0f 5a c0          	cvtpd2ps %xmm0,%xmm0
    22ee:	66 41 0f 5a d0       	cvtpd2ps %xmm8,%xmm2
    22f3:	0f 16 c2             	movlhps %xmm2,%xmm0
    22f6:	0f 17 84 24 60 01 00 	movhps %xmm0,0x160(%rsp)
    22fd:	00 
    22fe:	44 0f 5a c0          	cvtps2pd %xmm0,%xmm8
    2302:	0f 5a 84 24 60 01 00 	cvtps2pd 0x160(%rsp),%xmm0
    2309:	00 
    230a:	66 45 0f 58 e0       	addpd  %xmm8,%xmm12
    230f:	44 0f 28 44 24 20    	movaps 0x20(%rsp),%xmm8
    2315:	44 0f 17 84 24 70 01 	movhps %xmm8,0x170(%rsp)
    231c:	00 00 
    231e:	66 0f 58 c7          	addpd  %xmm7,%xmm0
    2322:	41 0f 5a f8          	cvtps2pd %xmm8,%xmm7
    2326:	66 41 0f 59 fd       	mulpd  %xmm13,%xmm7
    232b:	66 41 0f 5a d4       	cvtpd2ps %xmm12,%xmm2
    2330:	66 44 0f 5a e0       	cvtpd2ps %xmm0,%xmm12
    2335:	41 0f 16 d4          	movlhps %xmm12,%xmm2
    2339:	44 0f 5a a4 24 70 01 	cvtps2pd 0x170(%rsp),%xmm12
    2340:	00 00 
    2342:	0f 17 94 24 80 01 00 	movhps %xmm2,0x180(%rsp)
    2349:	00 
    234a:	66 45 0f 59 e5       	mulpd  %xmm13,%xmm12
    234f:	0f 5a c2             	cvtps2pd %xmm2,%xmm0
    2352:	0f 5a 94 24 80 01 00 	cvtps2pd 0x180(%rsp),%xmm2
    2359:	00 
    235a:	66 0f 58 c7          	addpd  %xmm7,%xmm0
    235e:	66 44 0f 5a c0       	cvtpd2ps %xmm0,%xmm8
    2363:	0f 5a c5             	cvtps2pd %xmm5,%xmm0
    2366:	66 41 0f 59 c5       	mulpd  %xmm13,%xmm0
    236b:	66 41 0f 58 d4       	addpd  %xmm12,%xmm2
    2370:	0f 5a ac 24 90 01 00 	cvtps2pd 0x190(%rsp),%xmm5
    2377:	00 
    2378:	66 41 0f 59 ed       	mulpd  %xmm13,%xmm5
    237d:	66 0f 5a fa          	cvtpd2ps %xmm2,%xmm7
    2381:	44 0f 16 c7          	movlhps %xmm7,%xmm8
    2385:	44 0f 17 84 24 a0 01 	movhps %xmm8,0x1a0(%rsp)
    238c:	00 00 
    238e:	45 0f 5a e0          	cvtps2pd %xmm8,%xmm12
    2392:	44 0f 5a 84 24 a0 01 	cvtps2pd 0x1a0(%rsp),%xmm8
    2399:	00 00 
    239b:	66 44 0f 58 e0       	addpd  %xmm0,%xmm12
    23a0:	66 44 0f 58 c5       	addpd  %xmm5,%xmm8
    23a5:	66 41 0f 5a d4       	cvtpd2ps %xmm12,%xmm2
    23aa:	44 0f 28 64 24 10    	movaps 0x10(%rsp),%xmm12
    23b0:	44 0f 17 a4 24 b0 01 	movhps %xmm12,0x1b0(%rsp)
    23b7:	00 00 
    23b9:	0f 17 a4 24 d0 01 00 	movhps %xmm4,0x1d0(%rsp)
    23c0:	00 
    23c1:	66 41 0f 5a f8       	cvtpd2ps %xmm8,%xmm7
    23c6:	0f 16 d7             	movlhps %xmm7,%xmm2
    23c9:	44 0f 5a 84 24 b0 01 	cvtps2pd 0x1b0(%rsp),%xmm8
    23d0:	00 00 
    23d2:	0f 17 94 24 c0 01 00 	movhps %xmm2,0x1c0(%rsp)
    23d9:	00 
    23da:	66 45 0f 59 c3       	mulpd  %xmm11,%xmm8
    23df:	41 0f 5a ec          	cvtps2pd %xmm12,%xmm5
    23e3:	0f 5a c2             	cvtps2pd %xmm2,%xmm0
    23e6:	0f 5a 94 24 c0 01 00 	cvtps2pd 0x1c0(%rsp),%xmm2
    23ed:	00 
    23ee:	66 41 0f 59 eb       	mulpd  %xmm11,%xmm5
    23f3:	0f 17 9c 24 10 02 00 	movhps %xmm3,0x210(%rsp)
    23fa:	00 
    23fb:	44 0f 17 bc 24 f0 01 	movhps %xmm15,0x1f0(%rsp)
    2402:	00 00 
    2404:	66 41 0f 58 d0       	addpd  %xmm8,%xmm2
    2409:	66 0f 58 c5          	addpd  %xmm5,%xmm0
    240d:	0f 5a ec             	cvtps2pd %xmm4,%xmm5
    2410:	0f 5a a4 24 d0 01 00 	cvtps2pd 0x1d0(%rsp),%xmm4
    2417:	00 
    2418:	66 41 0f 59 eb       	mulpd  %xmm11,%xmm5
    241d:	66 41 0f 59 e3       	mulpd  %xmm11,%xmm4
    2422:	66 44 0f 5a e2       	cvtpd2ps %xmm2,%xmm12
    2427:	66 0f 5a f8          	cvtpd2ps %xmm0,%xmm7
    242b:	41 0f 16 fc          	movlhps %xmm12,%xmm7
    242f:	45 0f 5a e7          	cvtps2pd %xmm15,%xmm12
    2433:	44 0f 5a bc 24 f0 01 	cvtps2pd 0x1f0(%rsp),%xmm15
    243a:	00 00 
    243c:	66 45 0f 59 fb       	mulpd  %xmm11,%xmm15
    2441:	44 0f 5a c7          	cvtps2pd %xmm7,%xmm8
    2445:	0f 17 bc 24 e0 01 00 	movhps %xmm7,0x1e0(%rsp)
    244c:	00 
    244d:	0f 5a 84 24 e0 01 00 	cvtps2pd 0x1e0(%rsp),%xmm0
    2454:	00 
    2455:	66 45 0f 59 e3       	mulpd  %xmm11,%xmm12
    245a:	66 44 0f 58 c5       	addpd  %xmm5,%xmm8
    245f:	66 0f 58 c4          	addpd  %xmm4,%xmm0
    2463:	66 41 0f 5a d0       	cvtpd2ps %xmm8,%xmm2
    2468:	66 0f 5a f8          	cvtpd2ps %xmm0,%xmm7
    246c:	0f 16 d7             	movlhps %xmm7,%xmm2
    246f:	0f 5a fb             	cvtps2pd %xmm3,%xmm7
    2472:	0f 17 94 24 00 02 00 	movhps %xmm2,0x200(%rsp)
    2479:	00 
    247a:	66 41 0f 59 fb       	mulpd  %xmm11,%xmm7
    247f:	0f 5a 9c 24 10 02 00 	cvtps2pd 0x210(%rsp),%xmm3
    2486:	00 
    2487:	0f 5a ea             	cvtps2pd %xmm2,%xmm5
    248a:	44 0f 5a 84 24 00 02 	cvtps2pd 0x200(%rsp),%xmm8
    2491:	00 00 
    2493:	66 41 0f 59 db       	mulpd  %xmm11,%xmm3
    2498:	66 45 0f 58 c7       	addpd  %xmm15,%xmm8
    249d:	66 41 0f 58 ec       	addpd  %xmm12,%xmm5
    24a2:	66 41 0f 5a e0       	cvtpd2ps %xmm8,%xmm4
    24a7:	44 0f 28 05 f1 1c 00 	movaps 0x1cf1(%rip),%xmm8        # 41a0 <_IO_stdin_used+0x1a0>
    24ae:	00 
    24af:	66 0f 5a c5          	cvtpd2ps %xmm5,%xmm0
    24b3:	0f 16 c4             	movlhps %xmm4,%xmm0
    24b6:	0f 5a d0             	cvtps2pd %xmm0,%xmm2
    24b9:	0f 17 84 24 20 02 00 	movhps %xmm0,0x220(%rsp)
    24c0:	00 
    24c1:	66 0f 58 d7          	addpd  %xmm7,%xmm2
    24c5:	44 0f 5a a4 24 20 02 	cvtps2pd 0x220(%rsp),%xmm12
    24cc:	00 00 
    24ce:	44 0f 59 c1          	mulps  %xmm1,%xmm8
    24d2:	66 44 0f 58 e3       	addpd  %xmm3,%xmm12
    24d7:	41 0f 28 c1          	movaps %xmm9,%xmm0
    24db:	66 0f 5a ea          	cvtpd2ps %xmm2,%xmm5
    24df:	66 45 0f 5a fc       	cvtpd2ps %xmm12,%xmm15
    24e4:	41 0f 16 ef          	movlhps %xmm15,%xmm5
    24e8:	0f 59 2d f1 1b 00 00 	mulps  0x1bf1(%rip),%xmm5        # 40e0 <_IO_stdin_used+0xe0>
    24ef:	41 0f 5c f0          	subps  %xmm8,%xmm6
    24f3:	0f 58 f5             	addps  %xmm5,%xmm6
    24f6:	0f 59 35 93 1c 00 00 	mulps  0x1c93(%rip),%xmm6        # 4190 <_IO_stdin_used+0x190>
    24fd:	0f 58 ce             	addps  %xmm6,%xmm1
    2500:	0f 14 c1             	unpcklps %xmm1,%xmm0
    2503:	44 0f 15 c9          	unpckhps %xmm1,%xmm9
    2507:	0f 11 04 01          	movups %xmm0,(%rcx,%rax,1)
    250b:	44 0f 11 4c 01 10    	movups %xmm9,0x10(%rcx,%rax,1)
    2511:	48 83 c0 20          	add    $0x20,%rax
    2515:	48 3d 60 0c 00 00    	cmp    $0xc60,%rax
    251b:	0f 85 0f fa ff ff    	jne    1f30 <main+0xd30>
    2521:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    2526:	f2 0f 10 3d 92 1c 00 	movsd  0x1c92(%rip),%xmm7        # 41c0 <_IO_stdin_used+0x1c0>
    252d:	00 
    252e:	f2 44 0f 10 0d 89 1c 	movsd  0x1c89(%rip),%xmm9        # 41c0 <_IO_stdin_used+0x1c0>
    2535:	00 00 
    2537:	66 45 0f ef e4       	pxor   %xmm12,%xmm12
    253c:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2541:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2546:	66 0f ef d2          	pxor   %xmm2,%xmm2
    254a:	f3 45 0f 5a 97 68 0c 	cvtss2sd 0xc68(%r15),%xmm10
    2551:	00 00 
    2553:	f2 45 0f 59 ca       	mulsd  %xmm10,%xmm9
    2558:	66 0f ef ed          	pxor   %xmm5,%xmm5
    255c:	f3 41 0f 10 a7 f0 18 	movss  0x18f0(%r15),%xmm4
    2563:	00 00 
    2565:	f3 45 0f 5a a7 78 25 	cvtss2sd 0x2578(%r15),%xmm12
    256c:	00 00 
    256e:	f2 41 0f 59 fc       	mulsd  %xmm12,%xmm7
    2573:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2577:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    257c:	f3 45 0f 5a bf e8 18 	cvtss2sd 0x18e8(%r15),%xmm15
    2583:	00 00 
    2585:	0f 28 cc             	movaps %xmm4,%xmm1
    2588:	0f 57 0d a1 1b 00 00 	xorps  0x1ba1(%rip),%xmm1        # 4130 <_IO_stdin_used+0x130>
    258f:	f3 41 0f 10 b7 f8 18 	movss  0x18f8(%r15),%xmm6
    2596:	00 00 
    2598:	48 81 c1 88 0c 00 00 	add    $0xc88,%rcx
    259f:	f2 44 0f 59 3d 18 1c 	mulsd  0x1c18(%rip),%xmm15        # 41c0 <_IO_stdin_used+0x1c0>
    25a6:	00 00 
    25a8:	f3 41 0f 10 9f f4 18 	movss  0x18f4(%r15),%xmm3
    25af:	00 00 
    25b1:	f3 44 0f 5a f1       	cvtss2sd %xmm1,%xmm14
    25b6:	f3 0f 5a c6          	cvtss2sd %xmm6,%xmm0
    25ba:	66 0f ef c9          	pxor   %xmm1,%xmm1
    25be:	f2 45 0f 58 ce       	addsd  %xmm14,%xmm9
    25c3:	f2 44 0f 10 35 f4 1b 	movsd  0x1bf4(%rip),%xmm14        # 41c0 <_IO_stdin_used+0x1c0>
    25ca:	00 00 
    25cc:	f2 44 0f 59 f0       	mulsd  %xmm0,%xmm14
    25d1:	66 0f ef c0          	pxor   %xmm0,%xmm0
    25d5:	f2 41 0f 5a d1       	cvtsd2ss %xmm9,%xmm2
    25da:	f3 0f 5a ea          	cvtss2sd %xmm2,%xmm5
    25de:	f2 0f 58 fd          	addsd  %xmm5,%xmm7
    25e2:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    25e7:	66 0f ef d2          	pxor   %xmm2,%xmm2
    25eb:	66 0f ef ed          	pxor   %xmm5,%xmm5
    25ef:	f3 41 0f 5a 97 60 0c 	cvtss2sd 0xc60(%r15),%xmm2
    25f6:	00 00 
    25f8:	f2 0f 59 15 c8 1b 00 	mulsd  0x1bc8(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    25ff:	00 
    2600:	f2 44 0f 5a c7       	cvtsd2ss %xmm7,%xmm8
    2605:	f3 45 0f 5a c8       	cvtss2sd %xmm8,%xmm9
    260a:	f2 45 0f 58 cf       	addsd  %xmm15,%xmm9
    260f:	66 0f ef ff          	pxor   %xmm7,%xmm7
    2613:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2618:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    261d:	f2 44 0f 11 b4 24 60 	movsd  %xmm14,0x260(%rsp)
    2624:	02 00 00 
    2627:	f3 45 0f 5a 87 70 0c 	cvtss2sd 0xc70(%r15),%xmm8
    262e:	00 00 
    2630:	f2 41 0f 5a c9       	cvtsd2ss %xmm9,%xmm1
    2635:	f3 0f 5a f9          	cvtss2sd %xmm1,%xmm7
    2639:	f2 41 0f 58 fe       	addsd  %xmm14,%xmm7
    263e:	f2 44 0f 10 0d 81 1b 	movsd  0x1b81(%rip),%xmm9        # 41c8 <_IO_stdin_used+0x1c8>
    2645:	00 00 
    2647:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    264c:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2650:	f3 41 0f 5a 8f 70 25 	cvtss2sd 0x2570(%r15),%xmm1
    2657:	00 00 
    2659:	f2 45 0f 59 c8       	mulsd  %xmm8,%xmm9
    265e:	f2 0f 5a ef          	cvtsd2ss %xmm7,%xmm5
    2662:	f3 44 0f 5a fd       	cvtss2sd %xmm5,%xmm15
    2667:	66 0f ef ff          	pxor   %xmm7,%xmm7
    266b:	f2 41 0f 58 d7       	addsd  %xmm15,%xmm2
    2670:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2674:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2679:	f2 0f 59 0d 47 1b 00 	mulsd  0x1b47(%rip),%xmm1        # 41c8 <_IO_stdin_used+0x1c8>
    2680:	00 
    2681:	f2 0f 5a c2          	cvtsd2ss %xmm2,%xmm0
    2685:	f3 44 0f 5a f0       	cvtss2sd %xmm0,%xmm14
    268a:	66 0f ef c0          	pxor   %xmm0,%xmm0
    268e:	f2 0f 10 15 32 1b 00 	movsd  0x1b32(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    2695:	00 
    2696:	f2 44 0f 11 8c 24 58 	movsd  %xmm9,0x258(%rsp)
    269d:	02 00 00 
    26a0:	f2 45 0f 58 f1       	addsd  %xmm9,%xmm14
    26a5:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    26aa:	f3 45 0f 5a 8f 80 25 	cvtss2sd 0x2580(%r15),%xmm9
    26b1:	00 00 
    26b3:	f2 41 0f 59 d1       	mulsd  %xmm9,%xmm2
    26b8:	f2 41 0f 5a fe       	cvtsd2ss %xmm14,%xmm7
    26bd:	f3 0f 5a ef          	cvtss2sd %xmm7,%xmm5
    26c1:	0f 28 fb             	movaps %xmm3,%xmm7
    26c4:	f2 0f 58 e9          	addsd  %xmm1,%xmm5
    26c8:	f3 0f 59 fb          	mulss  %xmm3,%xmm7
    26cc:	66 0f ef c9          	pxor   %xmm1,%xmm1
    26d0:	f3 44 0f 10 35 cf 19 	movss  0x19cf(%rip),%xmm14        # 40a8 <_IO_stdin_used+0xa8>
    26d7:	00 00 
    26d9:	f3 44 0f 5c f4       	subss  %xmm4,%xmm14
    26de:	f2 44 0f 5a fd       	cvtsd2ss %xmm5,%xmm15
    26e3:	f3 44 0f 59 35 c4 19 	mulss  0x19c4(%rip),%xmm14        # 40b0 <_IO_stdin_used+0xb0>
    26ea:	00 00 
    26ec:	f3 41 0f 5a c7       	cvtss2sd %xmm15,%xmm0
    26f1:	f2 0f 58 c2          	addsd  %xmm2,%xmm0
    26f5:	44 0f 28 fb          	movaps %xmm3,%xmm15
    26f9:	44 0f 57 3d 2f 1a 00 	xorps  0x1a2f(%rip),%xmm15        # 4130 <_IO_stdin_used+0x130>
    2700:	00 
    2701:	f2 0f 11 94 24 50 02 	movsd  %xmm2,0x250(%rsp)
    2708:	00 00 
    270a:	f2 0f 10 15 ae 1a 00 	movsd  0x1aae(%rip),%xmm2        # 41c0 <_IO_stdin_used+0x1c0>
    2711:	00 
    2712:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2716:	f3 0f 59 fc          	mulss  %xmm4,%xmm7
    271a:	f2 0f 5a c8          	cvtsd2ss %xmm0,%xmm1
    271e:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2722:	f3 41 0f 5a c7       	cvtss2sd %xmm15,%xmm0
    2727:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    272c:	f3 44 0f 5c f7       	subss  %xmm7,%xmm14
    2731:	f3 44 0f 58 f1       	addss  %xmm1,%xmm14
    2736:	f2 0f 10 0d 82 1a 00 	movsd  0x1a82(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    273d:	00 
    273e:	f3 44 0f 59 35 6d 19 	mulss  0x196d(%rip),%xmm14        # 40b4 <_IO_stdin_used+0xb4>
    2745:	00 00 
    2747:	f3 44 0f 58 f4       	addss  %xmm4,%xmm14
    274c:	f3 0f 5a e4          	cvtss2sd %xmm4,%xmm4
    2750:	f3 44 0f 11 71 d8    	movss  %xmm14,-0x28(%rcx)
    2756:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    275b:	f3 45 0f 5a b7 6c 0c 	cvtss2sd 0xc6c(%r15),%xmm14
    2762:	00 00 
    2764:	f2 41 0f 59 d6       	mulsd  %xmm14,%xmm2
    2769:	f2 44 0f 11 b4 24 48 	movsd  %xmm14,0x248(%rsp)
    2770:	02 00 00 
    2773:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2778:	f3 45 0f 5a b7 7c 25 	cvtss2sd 0x257c(%r15),%xmm14
    277f:	00 00 
    2781:	f2 41 0f 59 ce       	mulsd  %xmm14,%xmm1
    2786:	f2 44 0f 11 b4 24 30 	movsd  %xmm14,0x230(%rsp)
    278d:	02 00 00 
    2790:	f3 45 0f 5a bf ec 18 	cvtss2sd 0x18ec(%r15),%xmm15
    2797:	00 00 
    2799:	f2 44 0f 59 3d 1e 1a 	mulsd  0x1a1e(%rip),%xmm15        # 41c0 <_IO_stdin_used+0x1c0>
    27a0:	00 00 
    27a2:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    27a7:	f2 0f 59 25 11 1a 00 	mulsd  0x1a11(%rip),%xmm4        # 41c0 <_IO_stdin_used+0x1c0>
    27ae:	00 
    27af:	f2 0f 58 d0          	addsd  %xmm0,%xmm2
    27b3:	66 0f ef c0          	pxor   %xmm0,%xmm0
    27b7:	f2 0f 5a ea          	cvtsd2ss %xmm2,%xmm5
    27bb:	66 0f ef d2          	pxor   %xmm2,%xmm2
    27bf:	f3 0f 5a d5          	cvtss2sd %xmm5,%xmm2
    27c3:	f2 0f 58 ca          	addsd  %xmm2,%xmm1
    27c7:	66 0f ef d2          	pxor   %xmm2,%xmm2
    27cb:	f3 41 0f 10 af fc 18 	movss  0x18fc(%r15),%xmm5
    27d2:	00 00 
    27d4:	f3 0f 5a d5          	cvtss2sd %xmm5,%xmm2
    27d8:	f2 0f 59 15 e0 19 00 	mulsd  0x19e0(%rip),%xmm2        # 41c0 <_IO_stdin_used+0x1c0>
    27df:	00 
    27e0:	f2 0f 5a c1          	cvtsd2ss %xmm1,%xmm0
    27e4:	f3 44 0f 5a f0       	cvtss2sd %xmm0,%xmm14
    27e9:	f2 45 0f 58 f7       	addsd  %xmm15,%xmm14
    27ee:	66 0f ef c9          	pxor   %xmm1,%xmm1
    27f2:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    27f7:	66 0f ef c0          	pxor   %xmm0,%xmm0
    27fb:	f3 41 0f 5a 87 64 0c 	cvtss2sd 0xc64(%r15),%xmm0
    2802:	00 00 
    2804:	f2 0f 59 05 bc 19 00 	mulsd  0x19bc(%rip),%xmm0        # 41c8 <_IO_stdin_used+0x1c8>
    280b:	00 
    280c:	f2 41 0f 5a ce       	cvtsd2ss %xmm14,%xmm1
    2811:	f3 44 0f 5a f9       	cvtss2sd %xmm1,%xmm15
    2816:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    281b:	66 0f ef c9          	pxor   %xmm1,%xmm1
    281f:	f2 44 0f 58 fa       	addsd  %xmm2,%xmm15
    2824:	f2 0f 11 54 24 20    	movsd  %xmm2,0x20(%rsp)
    282a:	66 0f ef d2          	pxor   %xmm2,%xmm2
    282e:	f2 45 0f 5a f7       	cvtsd2ss %xmm15,%xmm14
    2833:	f3 41 0f 5a d6       	cvtss2sd %xmm14,%xmm2
    2838:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    283d:	f2 44 0f 10 3d 82 19 	movsd  0x1982(%rip),%xmm15        # 41c8 <_IO_stdin_used+0x1c8>
    2844:	00 00 
    2846:	f3 45 0f 5a b7 74 0c 	cvtss2sd 0xc74(%r15),%xmm14
    284d:	00 00 
    284f:	f2 0f 58 d0          	addsd  %xmm0,%xmm2
    2853:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2857:	f3 41 0f 5a 87 74 25 	cvtss2sd 0x2574(%r15),%xmm0
    285e:	00 00 
    2860:	f2 45 0f 59 fe       	mulsd  %xmm14,%xmm15
    2865:	f2 0f 59 05 5b 19 00 	mulsd  0x195b(%rip),%xmm0        # 41c8 <_IO_stdin_used+0x1c8>
    286c:	00 
    286d:	f2 0f 5a ca          	cvtsd2ss %xmm2,%xmm1
    2871:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2875:	f3 0f 5a d1          	cvtss2sd %xmm1,%xmm2
    2879:	66 0f ef c9          	pxor   %xmm1,%xmm1
    287d:	f2 41 0f 58 d7       	addsd  %xmm15,%xmm2
    2882:	f2 44 0f 11 7c 24 10 	movsd  %xmm15,0x10(%rsp)
    2889:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    288e:	f2 44 0f 5a fa       	cvtsd2ss %xmm2,%xmm15
    2893:	f2 0f 10 15 2d 19 00 	movsd  0x192d(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    289a:	00 
    289b:	f3 41 0f 5a cf       	cvtss2sd %xmm15,%xmm1
    28a0:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    28a5:	f3 45 0f 5a bf 84 25 	cvtss2sd 0x2584(%r15),%xmm15
    28ac:	00 00 
    28ae:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    28b2:	f3 0f 10 0d fe 17 00 	movss  0x17fe(%rip),%xmm1        # 40b8 <_IO_stdin_used+0xb8>
    28b9:	00 
    28ba:	f2 41 0f 59 d7       	mulsd  %xmm15,%xmm2
    28bf:	f3 0f 59 cb          	mulss  %xmm3,%xmm1
    28c3:	f2 0f 5a c0          	cvtsd2ss %xmm0,%xmm0
    28c7:	f3 0f 5a c0          	cvtss2sd %xmm0,%xmm0
    28cb:	f2 0f 58 c2          	addsd  %xmm2,%xmm0
    28cf:	f2 0f 11 14 24       	movsd  %xmm2,(%rsp)
    28d4:	66 0f ef d2          	pxor   %xmm2,%xmm2
    28d8:	f3 0f 5c f9          	subss  %xmm1,%xmm7
    28dc:	f2 0f 10 0d dc 18 00 	movsd  0x18dc(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    28e3:	00 
    28e4:	f2 0f 5a d0          	cvtsd2ss %xmm0,%xmm2
    28e8:	f3 0f 59 15 bc 17 00 	mulss  0x17bc(%rip),%xmm2        # 40ac <_IO_stdin_used+0xac>
    28ef:	00 
    28f0:	0f 28 c6             	movaps %xmm6,%xmm0
    28f3:	0f 57 05 36 18 00 00 	xorps  0x1836(%rip),%xmm0        # 4130 <_IO_stdin_used+0x130>
    28fa:	f2 41 0f 59 c8       	mulsd  %xmm8,%xmm1
    28ff:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2904:	f3 0f 58 fa          	addss  %xmm2,%xmm7
    2908:	f3 0f 59 3d a4 17 00 	mulss  0x17a4(%rip),%xmm7        # 40b4 <_IO_stdin_used+0xb4>
    290f:	00 
    2910:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2914:	f3 0f 5a d0          	cvtss2sd %xmm0,%xmm2
    2918:	f2 0f 58 d1          	addsd  %xmm1,%xmm2
    291c:	f2 0f 10 0d 9c 18 00 	movsd  0x189c(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2923:	00 
    2924:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2928:	f2 41 0f 59 c9       	mulsd  %xmm9,%xmm1
    292d:	f3 0f 58 fb          	addss  %xmm3,%xmm7
    2931:	f3 0f 5a db          	cvtss2sd %xmm3,%xmm3
    2935:	f3 0f 11 79 dc       	movss  %xmm7,-0x24(%rcx)
    293a:	66 0f ef ff          	pxor   %xmm7,%xmm7
    293e:	66 44 0f 28 c9       	movapd %xmm1,%xmm9
    2943:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2947:	f2 0f 5a fa          	cvtsd2ss %xmm2,%xmm7
    294b:	f3 0f 5a c7          	cvtss2sd %xmm7,%xmm0
    294f:	f2 44 0f 58 c8       	addsd  %xmm0,%xmm9
    2954:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2958:	f3 41 0f 10 bf 00 19 	movss  0x1900(%r15),%xmm7
    295f:	00 00 
    2961:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2965:	f3 0f 5a cf          	cvtss2sd %xmm7,%xmm1
    2969:	f2 0f 59 0d 4f 18 00 	mulsd  0x184f(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2970:	00 
    2971:	f2 41 0f 5a d1       	cvtsd2ss %xmm9,%xmm2
    2976:	f3 44 0f 5a c2       	cvtss2sd %xmm2,%xmm8
    297b:	f2 41 0f 58 e0       	addsd  %xmm8,%xmm4
    2980:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    2985:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    298a:	f2 0f 10 15 36 18 00 	movsd  0x1836(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    2991:	00 
    2992:	f2 44 0f 5a cc       	cvtsd2ss %xmm4,%xmm9
    2997:	f3 41 0f 5a c1       	cvtss2sd %xmm9,%xmm0
    299c:	66 0f ef e4          	pxor   %xmm4,%xmm4
    29a0:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    29a5:	f3 45 0f 5a 8f 78 0c 	cvtss2sd 0xc78(%r15),%xmm9
    29ac:	00 00 
    29ae:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    29b2:	f2 0f 10 0d 0e 18 00 	movsd  0x180e(%rip),%xmm1        # 41c8 <_IO_stdin_used+0x1c8>
    29b9:	00 
    29ba:	f2 41 0f 59 d1       	mulsd  %xmm9,%xmm2
    29bf:	f2 41 0f 59 ca       	mulsd  %xmm10,%xmm1
    29c4:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    29c9:	f2 0f 5a e0          	cvtsd2ss %xmm0,%xmm4
    29cd:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    29d2:	66 0f ef c0          	pxor   %xmm0,%xmm0
    29d6:	66 0f ef e4          	pxor   %xmm4,%xmm4
    29da:	f2 44 0f 58 c1       	addsd  %xmm1,%xmm8
    29df:	66 0f 28 ca          	movapd %xmm2,%xmm1
    29e3:	f2 0f 10 15 dd 17 00 	movsd  0x17dd(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    29ea:	00 
    29eb:	f2 41 0f 5a c0       	cvtsd2ss %xmm8,%xmm0
    29f0:	f3 44 0f 5a d0       	cvtss2sd %xmm0,%xmm10
    29f5:	f2 41 0f 58 ca       	addsd  %xmm10,%xmm1
    29fa:	f2 0f 10 05 c6 17 00 	movsd  0x17c6(%rip),%xmm0        # 41c8 <_IO_stdin_used+0x1c8>
    2a01:	00 
    2a02:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    2a07:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2a0c:	f3 45 0f 5a 97 88 25 	cvtss2sd 0x2588(%r15),%xmm10
    2a13:	00 00 
    2a15:	f2 41 0f 59 c4       	mulsd  %xmm12,%xmm0
    2a1a:	f2 41 0f 59 d2       	mulsd  %xmm10,%xmm2
    2a1f:	f2 0f 5a e1          	cvtsd2ss %xmm1,%xmm4
    2a23:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    2a28:	f3 0f 10 25 78 16 00 	movss  0x1678(%rip),%xmm4        # 40a8 <_IO_stdin_used+0xa8>
    2a2f:	00 
    2a30:	f3 0f 5c e6          	subss  %xmm6,%xmm4
    2a34:	66 44 0f 28 e0       	movapd %xmm0,%xmm12
    2a39:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2a3d:	f2 45 0f 58 e0       	addsd  %xmm8,%xmm12
    2a42:	44 0f 28 c5          	movaps %xmm5,%xmm8
    2a46:	66 0f 28 ca          	movapd %xmm2,%xmm1
    2a4a:	f3 0f 10 15 5e 16 00 	movss  0x165e(%rip),%xmm2        # 40b0 <_IO_stdin_used+0xb0>
    2a51:	00 
    2a52:	f3 44 0f 59 c6       	mulss  %xmm6,%xmm8
    2a57:	f3 0f 59 d4          	mulss  %xmm4,%xmm2
    2a5b:	66 0f ef e4          	pxor   %xmm4,%xmm4
    2a5f:	f2 41 0f 5a c4       	cvtsd2ss %xmm12,%xmm0
    2a64:	66 45 0f ef e4       	pxor   %xmm12,%xmm12
    2a69:	f3 44 0f 5a e0       	cvtss2sd %xmm0,%xmm12
    2a6e:	f2 41 0f 58 cc       	addsd  %xmm12,%xmm1
    2a73:	0f 28 c5             	movaps %xmm5,%xmm0
    2a76:	0f 57 05 b3 16 00 00 	xorps  0x16b3(%rip),%xmm0        # 4130 <_IO_stdin_used+0x130>
    2a7d:	f2 0f 59 1d 3b 17 00 	mulsd  0x173b(%rip),%xmm3        # 41c0 <_IO_stdin_used+0x1c0>
    2a84:	00 
    2a85:	66 45 0f ef e4       	pxor   %xmm12,%xmm12
    2a8a:	f3 44 0f 59 c5       	mulss  %xmm5,%xmm8
    2a8f:	f3 44 0f 5a e0       	cvtss2sd %xmm0,%xmm12
    2a94:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2a98:	f2 0f 5a c9          	cvtsd2ss %xmm1,%xmm1
    2a9c:	f3 41 0f 5c d0       	subss  %xmm8,%xmm2
    2aa1:	f3 0f 58 d1          	addss  %xmm1,%xmm2
    2aa5:	f2 0f 10 0d 13 17 00 	movsd  0x1713(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2aac:	00 
    2aad:	f3 0f 59 15 ff 15 00 	mulss  0x15ff(%rip),%xmm2        # 40b4 <_IO_stdin_used+0xb4>
    2ab4:	00 
    2ab5:	f2 41 0f 59 ce       	mulsd  %xmm14,%xmm1
    2aba:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2abf:	f3 0f 58 d6          	addss  %xmm6,%xmm2
    2ac3:	66 0f ef f6          	pxor   %xmm6,%xmm6
    2ac7:	f2 44 0f 58 e1       	addsd  %xmm1,%xmm12
    2acc:	f2 0f 10 0d ec 16 00 	movsd  0x16ec(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2ad3:	00 
    2ad4:	f3 0f 11 51 e0       	movss  %xmm2,-0x20(%rcx)
    2ad9:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2add:	f2 41 0f 59 cf       	mulsd  %xmm15,%xmm1
    2ae2:	f2 41 0f 5a e4       	cvtsd2ss %xmm12,%xmm4
    2ae7:	f3 0f 5a d4          	cvtss2sd %xmm4,%xmm2
    2aeb:	f3 45 0f 10 a7 04 19 	movss  0x1904(%r15),%xmm12
    2af2:	00 00 
    2af4:	f3 45 0f 5a f4       	cvtss2sd %xmm12,%xmm14
    2af9:	f2 44 0f 59 35 be 16 	mulsd  0x16be(%rip),%xmm14        # 41c0 <_IO_stdin_used+0x1c0>
    2b00:	00 00 
    2b02:	66 44 0f 28 f9       	movapd %xmm1,%xmm15
    2b07:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2b0b:	f2 44 0f 58 fa       	addsd  %xmm2,%xmm15
    2b10:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2b14:	f2 41 0f 5a c7       	cvtsd2ss %xmm15,%xmm0
    2b19:	f3 0f 5a f0          	cvtss2sd %xmm0,%xmm6
    2b1d:	f2 0f 58 de          	addsd  %xmm6,%xmm3
    2b21:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2b26:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2b2a:	f2 0f 5a cb          	cvtsd2ss %xmm3,%xmm1
    2b2e:	f3 44 0f 5a f9       	cvtss2sd %xmm1,%xmm15
    2b33:	f2 45 0f 58 fe       	addsd  %xmm14,%xmm15
    2b38:	f2 0f 10 0d 88 16 00 	movsd  0x1688(%rip),%xmm1        # 41c8 <_IO_stdin_used+0x1c8>
    2b3f:	00 
    2b40:	f2 0f 59 8c 24 48 02 	mulsd  0x248(%rsp),%xmm1
    2b47:	00 00 
    2b49:	66 0f ef db          	pxor   %xmm3,%xmm3
    2b4d:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2b52:	f3 41 0f 5a 9f 7c 0c 	cvtss2sd 0xc7c(%r15),%xmm3
    2b59:	00 00 
    2b5b:	f2 41 0f 5a d7       	cvtsd2ss %xmm15,%xmm2
    2b60:	f3 0f 5a c2          	cvtss2sd %xmm2,%xmm0
    2b64:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2b69:	f2 0f 10 15 57 16 00 	movsd  0x1657(%rip),%xmm2        # 41c8 <_IO_stdin_used+0x1c8>
    2b70:	00 
    2b71:	f2 0f 59 d3          	mulsd  %xmm3,%xmm2
    2b75:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    2b79:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2b7d:	f2 44 0f 5a f0       	cvtsd2ss %xmm0,%xmm14
    2b82:	f3 45 0f 5a fe       	cvtss2sd %xmm14,%xmm15
    2b87:	f2 0f 10 05 39 16 00 	movsd  0x1639(%rip),%xmm0        # 41c8 <_IO_stdin_used+0x1c8>
    2b8e:	00 
    2b8f:	f2 0f 59 84 24 30 02 	mulsd  0x230(%rsp),%xmm0
    2b96:	00 00 
    2b98:	66 0f 28 f2          	movapd %xmm2,%xmm6
    2b9c:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2ba0:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2ba5:	f2 41 0f 58 f7       	addsd  %xmm15,%xmm6
    2baa:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2baf:	f2 0f 5a ce          	cvtsd2ss %xmm6,%xmm1
    2bb3:	f3 0f 5a d1          	cvtss2sd %xmm1,%xmm2
    2bb7:	66 0f ef f6          	pxor   %xmm6,%xmm6
    2bbb:	66 0f 28 e0          	movapd %xmm0,%xmm4
    2bbf:	f2 0f 10 0d 01 16 00 	movsd  0x1601(%rip),%xmm1        # 41c8 <_IO_stdin_used+0x1c8>
    2bc6:	00 
    2bc7:	f2 0f 58 e2          	addsd  %xmm2,%xmm4
    2bcb:	f3 0f 10 15 e5 14 00 	movss  0x14e5(%rip),%xmm2        # 40b8 <_IO_stdin_used+0xb8>
    2bd2:	00 
    2bd3:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2bd7:	f3 41 0f 5a b7 8c 25 	cvtss2sd 0x258c(%r15),%xmm6
    2bde:	00 00 
    2be0:	f2 0f 59 ce          	mulsd  %xmm6,%xmm1
    2be4:	f3 0f 59 d5          	mulss  %xmm5,%xmm2
    2be8:	f2 44 0f 5a fc       	cvtsd2ss %xmm4,%xmm15
    2bed:	f3 41 0f 5a c7       	cvtss2sd %xmm15,%xmm0
    2bf2:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2bf7:	66 0f ef e4          	pxor   %xmm4,%xmm4
    2bfb:	f2 0f 58 c1          	addsd  %xmm1,%xmm0
    2bff:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2c03:	f3 44 0f 5c c2       	subss  %xmm2,%xmm8
    2c08:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2c0c:	f2 0f 5a c8          	cvtsd2ss %xmm0,%xmm1
    2c10:	f3 0f 59 0d 94 14 00 	mulss  0x1494(%rip),%xmm1        # 40ac <_IO_stdin_used+0xac>
    2c17:	00 
    2c18:	0f 28 c7             	movaps %xmm7,%xmm0
    2c1b:	0f 57 05 0e 15 00 00 	xorps  0x150e(%rip),%xmm0        # 4130 <_IO_stdin_used+0x130>
    2c22:	f3 44 0f 5a f0       	cvtss2sd %xmm0,%xmm14
    2c27:	f2 0f 10 05 91 15 00 	movsd  0x1591(%rip),%xmm0        # 41c0 <_IO_stdin_used+0x1c0>
    2c2e:	00 
    2c2f:	f2 41 0f 59 c2       	mulsd  %xmm10,%xmm0
    2c34:	f3 44 0f 58 c1       	addss  %xmm1,%xmm8
    2c39:	f2 0f 10 0d 7f 15 00 	movsd  0x157f(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2c40:	00 
    2c41:	f3 44 0f 59 05 6a 14 	mulss  0x146a(%rip),%xmm8        # 40b4 <_IO_stdin_used+0xb4>
    2c48:	00 00 
    2c4a:	f2 41 0f 59 c9       	mulsd  %xmm9,%xmm1
    2c4f:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    2c54:	66 44 0f 28 d0       	movapd %xmm0,%xmm10
    2c59:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2c5d:	f3 41 0f 5a 87 80 0c 	cvtss2sd 0xc80(%r15),%xmm0
    2c64:	00 00 
    2c66:	f3 44 0f 58 c5       	addss  %xmm5,%xmm8
    2c6b:	f2 0f 59 05 55 15 00 	mulsd  0x1555(%rip),%xmm0        # 41c8 <_IO_stdin_used+0x1c8>
    2c72:	00 
    2c73:	66 0f 28 e9          	movapd %xmm1,%xmm5
    2c77:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2c7b:	f2 41 0f 58 ee       	addsd  %xmm14,%xmm5
    2c80:	f3 44 0f 11 41 e4    	movss  %xmm8,-0x1c(%rcx)
    2c86:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2c8b:	f3 41 0f 5a 8f 08 19 	cvtss2sd 0x1908(%r15),%xmm1
    2c92:	00 00 
    2c94:	f2 0f 59 0d 24 15 00 	mulsd  0x1524(%rip),%xmm1        # 41c0 <_IO_stdin_used+0x1c0>
    2c9b:	00 
    2c9c:	66 45 0f ef f6       	pxor   %xmm14,%xmm14
    2ca1:	f2 44 0f 5a fd       	cvtsd2ss %xmm5,%xmm15
    2ca6:	f3 41 0f 5a d7       	cvtss2sd %xmm15,%xmm2
    2cab:	f2 44 0f 58 d2       	addsd  %xmm2,%xmm10
    2cb0:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2cb4:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2cb9:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2cbd:	f2 41 0f 5a e2       	cvtsd2ss %xmm10,%xmm4
    2cc2:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    2cc7:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    2ccc:	f2 44 0f 58 84 24 60 	addsd  0x260(%rsp),%xmm8
    2cd3:	02 00 00 
    2cd6:	66 0f ef e4          	pxor   %xmm4,%xmm4
    2cda:	f2 41 0f 5a e8       	cvtsd2ss %xmm8,%xmm5
    2cdf:	f3 44 0f 5a cd       	cvtss2sd %xmm5,%xmm9
    2ce4:	f2 41 0f 58 c9       	addsd  %xmm9,%xmm1
    2ce9:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2cee:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2cf2:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    2cf7:	f2 44 0f 5a f1       	cvtsd2ss %xmm1,%xmm14
    2cfc:	f3 45 0f 5a d6       	cvtss2sd %xmm14,%xmm10
    2d01:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2d05:	f2 44 0f 58 94 24 58 	addsd  0x258(%rsp),%xmm10
    2d0c:	02 00 00 
    2d0f:	f3 41 0f 5a 8f 90 25 	cvtss2sd 0x2590(%r15),%xmm1
    2d16:	00 00 
    2d18:	44 0f 28 f7          	movaps %xmm7,%xmm14
    2d1c:	f3 45 0f 59 f4       	mulss  %xmm12,%xmm14
    2d21:	f2 45 0f 5a fa       	cvtsd2ss %xmm10,%xmm15
    2d26:	f3 41 0f 5a d7       	cvtss2sd %xmm15,%xmm2
    2d2b:	f2 0f 58 c2          	addsd  %xmm2,%xmm0
    2d2f:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2d33:	f2 0f 5a e0          	cvtsd2ss %xmm0,%xmm4
    2d37:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    2d3c:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2d40:	f2 44 0f 58 84 24 50 	addsd  0x250(%rsp),%xmm8
    2d47:	02 00 00 
    2d4a:	f2 0f 59 0d 76 14 00 	mulsd  0x1476(%rip),%xmm1        # 41c8 <_IO_stdin_used+0x1c8>
    2d51:	00 
    2d52:	66 0f ef e4          	pxor   %xmm4,%xmm4
    2d56:	f3 44 0f 10 15 49 13 	movss  0x1349(%rip),%xmm10        # 40a8 <_IO_stdin_used+0xa8>
    2d5d:	00 00 
    2d5f:	f3 44 0f 10 3d 48 13 	movss  0x1348(%rip),%xmm15        # 40b0 <_IO_stdin_used+0xb0>
    2d66:	00 00 
    2d68:	f3 45 0f 59 f4       	mulss  %xmm12,%xmm14
    2d6d:	f3 44 0f 5c d7       	subss  %xmm7,%xmm10
    2d72:	f2 41 0f 5a e8       	cvtsd2ss %xmm8,%xmm5
    2d77:	f3 44 0f 5a cd       	cvtss2sd %xmm5,%xmm9
    2d7c:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2d81:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2d85:	f3 45 0f 59 fa       	mulss  %xmm10,%xmm15
    2d8a:	f2 44 0f 58 c9       	addsd  %xmm1,%xmm9
    2d8f:	41 0f 28 cc          	movaps %xmm12,%xmm1
    2d93:	0f 57 0d 96 13 00 00 	xorps  0x1396(%rip),%xmm1        # 4130 <_IO_stdin_used+0x130>
    2d9a:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    2d9f:	f3 45 0f 5a 97 0c 19 	cvtss2sd 0x190c(%r15),%xmm10
    2da6:	00 00 
    2da8:	f2 44 0f 59 15 0f 14 	mulsd  0x140f(%rip),%xmm10        # 41c0 <_IO_stdin_used+0x1c0>
    2daf:	00 00 
    2db1:	f2 41 0f 5a c1       	cvtsd2ss %xmm9,%xmm0
    2db6:	f3 0f 5a d1          	cvtss2sd %xmm1,%xmm2
    2dba:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    2dbf:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2dc3:	f3 45 0f 5c fe       	subss  %xmm14,%xmm15
    2dc8:	f3 44 0f 58 f8       	addss  %xmm0,%xmm15
    2dcd:	f2 0f 10 05 eb 13 00 	movsd  0x13eb(%rip),%xmm0        # 41c0 <_IO_stdin_used+0x1c0>
    2dd4:	00 
    2dd5:	f3 44 0f 59 3d d6 12 	mulss  0x12d6(%rip),%xmm15        # 40b4 <_IO_stdin_used+0xb4>
    2ddc:	00 00 
    2dde:	f2 0f 59 c3          	mulsd  %xmm3,%xmm0
    2de2:	66 0f ef db          	pxor   %xmm3,%xmm3
    2de6:	f3 41 0f 5a 9f 84 0c 	cvtss2sd 0xc84(%r15),%xmm3
    2ded:	00 00 
    2def:	f2 0f 59 1d d1 13 00 	mulsd  0x13d1(%rip),%xmm3        # 41c8 <_IO_stdin_used+0x1c8>
    2df6:	00 
    2df7:	f3 44 0f 58 ff       	addss  %xmm7,%xmm15
    2dfc:	66 0f ef ff          	pxor   %xmm7,%xmm7
    2e00:	f2 0f 58 d0          	addsd  %xmm0,%xmm2
    2e04:	f2 0f 10 05 b4 13 00 	movsd  0x13b4(%rip),%xmm0        # 41c0 <_IO_stdin_used+0x1c0>
    2e0b:	00 
    2e0c:	f3 44 0f 11 79 e8    	movss  %xmm15,-0x18(%rcx)
    2e12:	66 45 0f ef ff       	pxor   %xmm15,%xmm15
    2e17:	f2 0f 59 c6          	mulsd  %xmm6,%xmm0
    2e1b:	f2 0f 5a e2          	cvtsd2ss %xmm2,%xmm4
    2e1f:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    2e24:	66 0f ef d2          	pxor   %xmm2,%xmm2
    2e28:	66 0f ef e4          	pxor   %xmm4,%xmm4
    2e2c:	66 0f 28 f0          	movapd %xmm0,%xmm6
    2e30:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2e34:	f2 41 0f 58 f0       	addsd  %xmm8,%xmm6
    2e39:	66 45 0f ef c0       	pxor   %xmm8,%xmm8
    2e3e:	f2 0f 5a ee          	cvtsd2ss %xmm6,%xmm5
    2e42:	f3 44 0f 5a cd       	cvtss2sd %xmm5,%xmm9
    2e47:	f2 44 0f 58 4c 24 20 	addsd  0x20(%rsp),%xmm9
    2e4e:	66 0f ef f6          	pxor   %xmm6,%xmm6
    2e52:	66 0f ef ed          	pxor   %xmm5,%xmm5
    2e56:	f3 41 0f 5a af 94 25 	cvtss2sd 0x2594(%r15),%xmm5
    2e5d:	00 00 
    2e5f:	f2 0f 59 2d 61 13 00 	mulsd  0x1361(%rip),%xmm5        # 41c8 <_IO_stdin_used+0x1c8>
    2e66:	00 
    2e67:	f2 45 0f 5a f9       	cvtsd2ss %xmm9,%xmm15
    2e6c:	f3 41 0f 5a cf       	cvtss2sd %xmm15,%xmm1
    2e71:	f2 44 0f 58 d1       	addsd  %xmm1,%xmm10
    2e76:	f3 44 0f 10 3d 39 12 	movss  0x1239(%rip),%xmm15        # 40b8 <_IO_stdin_used+0xb8>
    2e7d:	00 00 
    2e7f:	66 45 0f ef c9       	pxor   %xmm9,%xmm9
    2e84:	66 0f ef c9          	pxor   %xmm1,%xmm1
    2e88:	f3 45 0f 59 fc       	mulss  %xmm12,%xmm15
    2e8d:	f2 41 0f 5a fa       	cvtsd2ss %xmm10,%xmm7
    2e92:	f3 0f 5a d7          	cvtss2sd %xmm7,%xmm2
    2e96:	f2 0f 58 54 24 10    	addsd  0x10(%rsp),%xmm2
    2e9c:	66 45 0f ef d2       	pxor   %xmm10,%xmm10
    2ea1:	f2 0f 5a c2          	cvtsd2ss %xmm2,%xmm0
    2ea5:	f3 0f 5a f0          	cvtss2sd %xmm0,%xmm6
    2ea9:	f2 0f 58 de          	addsd  %xmm6,%xmm3
    2ead:	f3 45 0f 5c f7       	subss  %xmm15,%xmm14
    2eb2:	f2 0f 5a e3          	cvtsd2ss %xmm3,%xmm4
    2eb6:	f3 44 0f 5a c4       	cvtss2sd %xmm4,%xmm8
    2ebb:	f2 44 0f 58 04 24    	addsd  (%rsp),%xmm8
    2ec1:	f2 45 0f 5a c8       	cvtsd2ss %xmm8,%xmm9
    2ec6:	f3 45 0f 5a d1       	cvtss2sd %xmm9,%xmm10
    2ecb:	f2 44 0f 58 d5       	addsd  %xmm5,%xmm10
    2ed0:	f2 41 0f 5a ca       	cvtsd2ss %xmm10,%xmm1
    2ed5:	f3 0f 59 0d cf 11 00 	mulss  0x11cf(%rip),%xmm1        # 40ac <_IO_stdin_used+0xac>
    2edc:	00 
    2edd:	f3 44 0f 58 f1       	addss  %xmm1,%xmm14
    2ee2:	f3 44 0f 59 35 c9 11 	mulss  0x11c9(%rip),%xmm14        # 40b4 <_IO_stdin_used+0xb4>
    2ee9:	00 00 
    2eeb:	f3 45 0f 58 f4       	addss  %xmm12,%xmm14
    2ef0:	f3 44 0f 11 71 ec    	movss  %xmm14,-0x14(%rcx)
    2ef6:	4c 39 cf             	cmp    %r9,%rdi
    2ef9:	0f 85 e2 ef ff ff    	jne    1ee1 <main+0xce1>
    2eff:	0f 31                	rdtsc  
    2f01:	48 c1 e2 20          	shl    $0x20,%rdx
    2f05:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2f09:	48 09 d0             	or     %rdx,%rax
    2f0c:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
    2f11:	79 19                	jns    2f2c <main+0x1d2c>
    2f13:	49 89 c6             	mov    %rax,%r14
    2f16:	83 e0 01             	and    $0x1,%eax
    2f19:	66 0f ef c0          	pxor   %xmm0,%xmm0
    2f1d:	49 d1 ee             	shr    %r14
    2f20:	4c 09 f0             	or     %r14,%rax
    2f23:	f2 48 0f 2a c0       	cvtsi2sd %rax,%xmm0
    2f28:	f2 0f 58 c0          	addsd  %xmm0,%xmm0
    2f2c:	f2 0f 5c 84 24 78 02 	subsd  0x278(%rsp),%xmm0
    2f33:	00 00 
    2f35:	b8 01 00 00 00       	mov    $0x1,%eax
    2f3a:	8b b4 24 74 02 00 00 	mov    0x274(%rsp),%esi
    2f41:	48 8d 3d fb 10 00 00 	lea    0x10fb(%rip),%rdi        # 4043 <_IO_stdin_used+0x43>
    2f48:	41 bf 06 00 00 00    	mov    $0x6,%r15d
    2f4e:	e8 5d e1 ff ff       	callq  10b0 <printf@plt>
    2f53:	4d 89 e5             	mov    %r12,%r13
    2f56:	bb f3 01 00 00       	mov    $0x1f3,%ebx
    2f5b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    2f60:	41 8b 45 00          	mov    0x0(%r13),%eax
    2f64:	48 89 ef             	mov    %rbp,%rdi
    2f67:	44 8d 73 ff          	lea    -0x1(%rbx),%r14d
    2f6b:	49 83 c5 10          	add    $0x10,%r13
    2f6f:	41 89 c1             	mov    %eax,%r9d
    2f72:	0f b6 cc             	movzbl %ah,%ecx
    2f75:	c1 e8 18             	shr    $0x18,%eax
    2f78:	41 c1 e9 10          	shr    $0x10,%r9d
    2f7c:	89 c6                	mov    %eax,%esi
    2f7e:	41 0f b6 d1          	movzbl %r9b,%edx
    2f82:	e8 a9 04 00 00       	callq  3430 <flame_set_color>
    2f87:	89 da                	mov    %ebx,%edx
    2f89:	44 89 fe             	mov    %r15d,%esi
    2f8c:	48 89 ef             	mov    %rbp,%rdi
    2f8f:	e8 4c 04 00 00       	callq  33e0 <flame_draw_point>
    2f94:	41 8b 45 f4          	mov    -0xc(%r13),%eax
    2f98:	89 c7                	mov    %eax,%edi
    2f9a:	0f b6 cc             	movzbl %ah,%ecx
    2f9d:	c1 e8 18             	shr    $0x18,%eax
    2fa0:	c1 ef 10             	shr    $0x10,%edi
    2fa3:	89 c6                	mov    %eax,%esi
    2fa5:	40 0f b6 d7          	movzbl %dil,%edx
    2fa9:	48 89 ef             	mov    %rbp,%rdi
    2fac:	e8 7f 04 00 00       	callq  3430 <flame_set_color>
    2fb1:	44 89 f2             	mov    %r14d,%edx
    2fb4:	44 89 fe             	mov    %r15d,%esi
    2fb7:	48 89 ef             	mov    %rbp,%rdi
    2fba:	e8 21 04 00 00       	callq  33e0 <flame_draw_point>
    2fbf:	41 8b 45 f8          	mov    -0x8(%r13),%eax
    2fc3:	44 8d 73 fe          	lea    -0x2(%rbx),%r14d
    2fc7:	48 89 ef             	mov    %rbp,%rdi
    2fca:	41 89 c0             	mov    %eax,%r8d
    2fcd:	0f b6 cc             	movzbl %ah,%ecx
    2fd0:	c1 e8 18             	shr    $0x18,%eax
    2fd3:	41 c1 e8 10          	shr    $0x10,%r8d
    2fd7:	89 c6                	mov    %eax,%esi
    2fd9:	41 0f b6 d0          	movzbl %r8b,%edx
    2fdd:	e8 4e 04 00 00       	callq  3430 <flame_set_color>
    2fe2:	44 89 f2             	mov    %r14d,%edx
    2fe5:	44 89 fe             	mov    %r15d,%esi
    2fe8:	48 89 ef             	mov    %rbp,%rdi
    2feb:	e8 f0 03 00 00       	callq  33e0 <flame_draw_point>
    2ff0:	41 8b 45 fc          	mov    -0x4(%r13),%eax
    2ff4:	44 8d 73 fd          	lea    -0x3(%rbx),%r14d
    2ff8:	48 89 ef             	mov    %rbp,%rdi
    2ffb:	83 eb 04             	sub    $0x4,%ebx
    2ffe:	89 c6                	mov    %eax,%esi
    3000:	0f b6 cc             	movzbl %ah,%ecx
    3003:	c1 e8 18             	shr    $0x18,%eax
    3006:	c1 ee 10             	shr    $0x10,%esi
    3009:	40 0f b6 d6          	movzbl %sil,%edx
    300d:	89 c6                	mov    %eax,%esi
    300f:	e8 1c 04 00 00       	callq  3430 <flame_set_color>
    3014:	44 89 f2             	mov    %r14d,%edx
    3017:	44 89 fe             	mov    %r15d,%esi
    301a:	48 89 ef             	mov    %rbp,%rdi
    301d:	e8 be 03 00 00       	callq  33e0 <flame_draw_point>
    3022:	83 fb 63             	cmp    $0x63,%ebx
    3025:	66 44 0f 28 2d 22 11 	movapd 0x1122(%rip),%xmm13        # 4150 <_IO_stdin_used+0x150>
    302c:	00 00 
    302e:	66 44 0f 28 1d 29 11 	movapd 0x1129(%rip),%xmm11        # 4160 <_IO_stdin_used+0x160>
    3035:	00 00 
    3037:	0f 85 23 ff ff ff    	jne    2f60 <main+0x1d60>
    303d:	49 81 c4 44 06 00 00 	add    $0x644,%r12
    3044:	41 83 c7 01          	add    $0x1,%r15d
    3048:	4c 39 a4 24 68 02 00 	cmp    %r12,0x268(%rsp)
    304f:	00 
    3050:	0f 85 fd fe ff ff    	jne    2f53 <main+0x1d53>
    3056:	83 84 24 74 02 00 00 	addl   $0x1,0x274(%rsp)
    305d:	01 
    305e:	e9 0d e8 ff ff       	jmpq   1870 <main+0x670>
    3063:	48 89 c3             	mov    %rax,%rbx
    3066:	83 e0 01             	and    $0x1,%eax
    3069:	66 0f ef d2          	pxor   %xmm2,%xmm2
    306d:	48 d1 eb             	shr    %rbx
    3070:	48 09 d8             	or     %rbx,%rax
    3073:	f2 48 0f 2a d0       	cvtsi2sd %rax,%xmm2
    3078:	f2 0f 58 d2          	addsd  %xmm2,%xmm2
    307c:	f2 0f 11 94 24 78 02 	movsd  %xmm2,0x278(%rsp)
    3083:	00 00 
    3085:	e9 07 e8 ff ff       	jmpq   1891 <main+0x691>
    308a:	e8 11 e0 ff ff       	callq  10a0 <__stack_chk_fail@plt>
    308f:	90                   	nop

0000000000003090 <set_fast_math>:
    3090:	f3 0f 1e fa          	endbr64 
    3094:	0f ae 5c 24 fc       	stmxcsr -0x4(%rsp)
    3099:	81 4c 24 fc 40 80 00 	orl    $0x8040,-0x4(%rsp)
    30a0:	00 
    30a1:	0f ae 54 24 fc       	ldmxcsr -0x4(%rsp)
    30a6:	c3                   	retq   
    30a7:	66 0f 1f 84 00 00 00 	nopw   0x0(%rax,%rax,1)
    30ae:	00 00 

00000000000030b0 <_start>:
    30b0:	f3 0f 1e fa          	endbr64 
    30b4:	31 ed                	xor    %ebp,%ebp
    30b6:	49 89 d1             	mov    %rdx,%r9
    30b9:	5e                   	pop    %rsi
    30ba:	48 89 e2             	mov    %rsp,%rdx
    30bd:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    30c1:	50                   	push   %rax
    30c2:	54                   	push   %rsp
    30c3:	4c 8d 05 56 06 00 00 	lea    0x656(%rip),%r8        # 3720 <__libc_csu_fini>
    30ca:	48 8d 0d df 05 00 00 	lea    0x5df(%rip),%rcx        # 36b0 <__libc_csu_init>
    30d1:	48 8d 3d 28 e1 ff ff 	lea    -0x1ed8(%rip),%rdi        # 1200 <main>
    30d8:	ff 15 02 2f 00 00    	callq  *0x2f02(%rip)        # 5fe0 <__libc_start_main@GLIBC_2.2.5>
    30de:	f4                   	hlt    
    30df:	90                   	nop

00000000000030e0 <deregister_tm_clones>:
    30e0:	48 8d 3d 29 30 00 00 	lea    0x3029(%rip),%rdi        # 6110 <__TMC_END__>
    30e7:	48 8d 05 22 30 00 00 	lea    0x3022(%rip),%rax        # 6110 <__TMC_END__>
    30ee:	48 39 f8             	cmp    %rdi,%rax
    30f1:	74 15                	je     3108 <deregister_tm_clones+0x28>
    30f3:	48 8b 05 de 2e 00 00 	mov    0x2ede(%rip),%rax        # 5fd8 <_ITM_deregisterTMCloneTable>
    30fa:	48 85 c0             	test   %rax,%rax
    30fd:	74 09                	je     3108 <deregister_tm_clones+0x28>
    30ff:	ff e0                	jmpq   *%rax
    3101:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    3108:	c3                   	retq   
    3109:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000003110 <register_tm_clones>:
    3110:	48 8d 3d f9 2f 00 00 	lea    0x2ff9(%rip),%rdi        # 6110 <__TMC_END__>
    3117:	48 8d 35 f2 2f 00 00 	lea    0x2ff2(%rip),%rsi        # 6110 <__TMC_END__>
    311e:	48 29 fe             	sub    %rdi,%rsi
    3121:	48 89 f0             	mov    %rsi,%rax
    3124:	48 c1 ee 3f          	shr    $0x3f,%rsi
    3128:	48 c1 f8 03          	sar    $0x3,%rax
    312c:	48 01 c6             	add    %rax,%rsi
    312f:	48 d1 fe             	sar    %rsi
    3132:	74 14                	je     3148 <register_tm_clones+0x38>
    3134:	48 8b 05 b5 2e 00 00 	mov    0x2eb5(%rip),%rax        # 5ff0 <_ITM_registerTMCloneTable>
    313b:	48 85 c0             	test   %rax,%rax
    313e:	74 08                	je     3148 <register_tm_clones+0x38>
    3140:	ff e0                	jmpq   *%rax
    3142:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    3148:	c3                   	retq   
    3149:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000003150 <__do_global_dtors_aux>:
    3150:	f3 0f 1e fa          	endbr64 
    3154:	80 3d cd 2f 00 00 00 	cmpb   $0x0,0x2fcd(%rip)        # 6128 <completed.0>
    315b:	75 33                	jne    3190 <__do_global_dtors_aux+0x40>
    315d:	55                   	push   %rbp
    315e:	48 83 3d 92 2e 00 00 	cmpq   $0x0,0x2e92(%rip)        # 5ff8 <__cxa_finalize@GLIBC_2.2.5>
    3165:	00 
    3166:	48 89 e5             	mov    %rsp,%rbp
    3169:	74 0d                	je     3178 <__do_global_dtors_aux+0x28>
    316b:	48 8b 3d 96 2f 00 00 	mov    0x2f96(%rip),%rdi        # 6108 <__dso_handle>
    3172:	ff 15 80 2e 00 00    	callq  *0x2e80(%rip)        # 5ff8 <__cxa_finalize@GLIBC_2.2.5>
    3178:	e8 63 ff ff ff       	callq  30e0 <deregister_tm_clones>
    317d:	c6 05 a4 2f 00 00 01 	movb   $0x1,0x2fa4(%rip)        # 6128 <completed.0>
    3184:	5d                   	pop    %rbp
    3185:	c3                   	retq   
    3186:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    318d:	00 00 00 
    3190:	c3                   	retq   
    3191:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    3198:	00 00 00 00 
    319c:	0f 1f 40 00          	nopl   0x0(%rax)

00000000000031a0 <frame_dummy>:
    31a0:	f3 0f 1e fa          	endbr64 
    31a4:	e9 67 ff ff ff       	jmpq   3110 <register_tm_clones>
    31a9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000031b0 <flame_flush_display>:
    31b0:	48 85 ff             	test   %rdi,%rdi
    31b3:	74 2b                	je     31e0 <flame_flush_display+0x30>
    31b5:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    31b9:	31 c0                	xor    %eax,%eax
    31bb:	48 85 ff             	test   %rdi,%rdi
    31be:	74 18                	je     31d8 <flame_flush_display+0x28>
    31c0:	48 83 ec 08          	sub    $0x8,%rsp
    31c4:	e8 b7 df ff ff       	callq  1180 <XFlush@plt>
    31c9:	b8 01 00 00 00       	mov    $0x1,%eax
    31ce:	48 83 c4 08          	add    $0x8,%rsp
    31d2:	c3                   	retq   
    31d3:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)
    31d8:	c3                   	retq   
    31d9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    31e0:	31 c0                	xor    %eax,%eax
    31e2:	c3                   	retq   
    31e3:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    31ea:	00 00 00 00 
    31ee:	66 90                	xchg   %ax,%ax

00000000000031f0 <flame_close>:
    31f0:	48 85 ff             	test   %rdi,%rdi
    31f3:	74 2b                	je     3220 <flame_close+0x30>
    31f5:	55                   	push   %rbp
    31f6:	48 89 fd             	mov    %rdi,%rbp
    31f9:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    31fd:	48 8b 75 00          	mov    0x0(%rbp),%rsi
    3201:	e8 aa df ff ff       	callq  11b0 <XFreeGC@plt>
    3206:	48 8b 7d 10          	mov    0x10(%rbp),%rdi
    320a:	e8 d1 df ff ff       	callq  11e0 <XCloseDisplay@plt>
    320f:	48 89 ef             	mov    %rbp,%rdi
    3212:	e8 19 de ff ff       	callq  1030 <free@plt>
    3217:	b8 01 00 00 00       	mov    $0x1,%eax
    321c:	5d                   	pop    %rbp
    321d:	c3                   	retq   
    321e:	66 90                	xchg   %ax,%ax
    3220:	31 c0                	xor    %eax,%eax
    3222:	c3                   	retq   
    3223:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    322a:	00 00 00 00 
    322e:	66 90                	xchg   %ax,%ax

0000000000003230 <flame_open>:
    3230:	41 56                	push   %r14
    3232:	41 89 d6             	mov    %edx,%r14d
    3235:	41 55                	push   %r13
    3237:	49 89 fd             	mov    %rdi,%r13
    323a:	bf 28 00 00 00       	mov    $0x28,%edi
    323f:	41 54                	push   %r12
    3241:	55                   	push   %rbp
    3242:	89 f5                	mov    %esi,%ebp
    3244:	53                   	push   %rbx
    3245:	48 81 ec 40 01 00 00 	sub    $0x140,%rsp
    324c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3253:	00 00 
    3255:	48 89 84 24 38 01 00 	mov    %rax,0x138(%rsp)
    325c:	00 
    325d:	31 c0                	xor    %eax,%eax
    325f:	e8 ac de ff ff       	callq  1110 <malloc@plt>
    3264:	31 ff                	xor    %edi,%edi
    3266:	49 89 c4             	mov    %rax,%r12
    3269:	e8 72 de ff ff       	callq  10e0 <XOpenDisplay@plt>
    326e:	49 89 44 24 10       	mov    %rax,0x10(%r12)
    3273:	48 85 c0             	test   %rax,%rax
    3276:	0f 84 2e 01 00 00    	je     33aa <flame_open+0x17a>
    327c:	48 8b 90 e8 00 00 00 	mov    0xe8(%rax),%rdx
    3283:	48 89 c7             	mov    %rax,%rdi
    3286:	31 c0                	xor    %eax,%eax
    3288:	48 8b 4a 40          	mov    0x40(%rdx),%rcx
    328c:	48 85 c9             	test   %rcx,%rcx
    328f:	74 09                	je     329a <flame_open+0x6a>
    3291:	31 c0                	xor    %eax,%eax
    3293:	83 79 10 04          	cmpl   $0x4,0x10(%rcx)
    3297:	0f 94 c0             	sete   %al
    329a:	48 63 b7 e0 00 00 00 	movslq 0xe0(%rdi),%rsi
    32a1:	48 83 ec 08          	sub    $0x8,%rsp
    32a5:	45 89 f1             	mov    %r14d,%r9d
    32a8:	31 c9                	xor    %ecx,%ecx
    32aa:	41 89 44 24 20       	mov    %eax,0x20(%r12)
    32af:	48 c1 e6 07          	shl    $0x7,%rsi
    32b3:	48 01 d6             	add    %rdx,%rsi
    32b6:	31 d2                	xor    %edx,%edx
    32b8:	4c 63 46 60          	movslq 0x60(%rsi),%r8
    32bc:	48 8b 5e 58          	mov    0x58(%rsi),%rbx
    32c0:	48 8b 76 10          	mov    0x10(%rsi),%rsi
    32c4:	41 50                	push   %r8
    32c6:	41 50                	push   %r8
    32c8:	41 89 e8             	mov    %ebp,%r8d
    32cb:	6a 00                	pushq  $0x0
    32cd:	e8 8e de ff ff       	callq  1160 <XCreateSimpleWindow@plt>
    32d2:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    32d7:	ba 40 00 00 00       	mov    $0x40,%edx
    32dc:	c7 44 24 48 02 00 00 	movl   $0x2,0x48(%rsp)
    32e3:	00 
    32e4:	48 83 c4 20          	add    $0x20,%rsp
    32e8:	48 89 c6             	mov    %rax,%rsi
    32eb:	49 89 44 24 08       	mov    %rax,0x8(%r12)
    32f0:	48 89 e1             	mov    %rsp,%rcx
    32f3:	e8 c8 dd ff ff       	callq  10c0 <XChangeWindowAttributes@plt>
    32f8:	49 8b 74 24 08       	mov    0x8(%r12),%rsi
    32fd:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    3302:	4c 89 ea             	mov    %r13,%rdx
    3305:	4c 8d 6c 24 70       	lea    0x70(%rsp),%r13
    330a:	e8 51 dd ff ff       	callq  1060 <XStoreName@plt>
    330f:	49 8b 74 24 08       	mov    0x8(%r12),%rsi
    3314:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    3319:	ba 4d 80 02 00       	mov    $0x2804d,%edx
    331e:	e8 0d de ff ff       	callq  1130 <XSelectInput@plt>
    3323:	49 8b 74 24 08       	mov    0x8(%r12),%rsi
    3328:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    332d:	e8 6e de ff ff       	callq  11a0 <XMapWindow@plt>
    3332:	49 8b 74 24 08       	mov    0x8(%r12),%rsi
    3337:	31 c9                	xor    %ecx,%ecx
    3339:	31 d2                	xor    %edx,%edx
    333b:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    3340:	e8 0b de ff ff       	callq  1150 <XCreateGC@plt>
    3345:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    334a:	48 63 d3             	movslq %ebx,%rdx
    334d:	48 89 c6             	mov    %rax,%rsi
    3350:	49 89 04 24          	mov    %rax,(%r12)
    3354:	4c 8b 8f e8 00 00 00 	mov    0xe8(%rdi),%r9
    335b:	4d 8b 51 50          	mov    0x50(%r9),%r10
    335f:	4d 89 54 24 18       	mov    %r10,0x18(%r12)
    3364:	e8 07 de ff ff       	callq  1170 <XSetForeground@plt>
    3369:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    3370:	49 8b 7c 24 10       	mov    0x10(%r12),%rdi
    3375:	4c 89 ee             	mov    %r13,%rsi
    3378:	e8 83 dd ff ff       	callq  1100 <XNextEvent@plt>
    337d:	83 7c 24 70 13       	cmpl   $0x13,0x70(%rsp)
    3382:	75 ec                	jne    3370 <flame_open+0x140>
    3384:	48 8b 84 24 38 01 00 	mov    0x138(%rsp),%rax
    338b:	00 
    338c:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    3393:	00 00 
    3395:	75 3a                	jne    33d1 <flame_open+0x1a1>
    3397:	48 81 c4 40 01 00 00 	add    $0x140,%rsp
    339e:	4c 89 e0             	mov    %r12,%rax
    33a1:	5b                   	pop    %rbx
    33a2:	5d                   	pop    %rbp
    33a3:	41 5c                	pop    %r12
    33a5:	41 5d                	pop    %r13
    33a7:	41 5e                	pop    %r14
    33a9:	c3                   	retq   
    33aa:	48 8b 0d 6f 2d 00 00 	mov    0x2d6f(%rip),%rcx        # 6120 <stderr@@GLIBC_2.2.5>
    33b1:	ba 30 00 00 00       	mov    $0x30,%edx
    33b6:	be 01 00 00 00       	mov    $0x1,%esi
    33bb:	48 8d 3d 46 0c 00 00 	lea    0xc46(%rip),%rdi        # 4008 <_IO_stdin_used+0x8>
    33c2:	e8 09 de ff ff       	callq  11d0 <fwrite@plt>
    33c7:	bf 01 00 00 00       	mov    $0x1,%edi
    33cc:	e8 ef dd ff ff       	callq  11c0 <exit@plt>
    33d1:	e8 ca dc ff ff       	callq  10a0 <__stack_chk_fail@plt>
    33d6:	66 2e 0f 1f 84 00 00 	nopw   %cs:0x0(%rax,%rax,1)
    33dd:	00 00 00 

00000000000033e0 <flame_draw_point>:
    33e0:	4c 8b 4f 10          	mov    0x10(%rdi),%r9
    33e4:	89 f1                	mov    %esi,%ecx
    33e6:	41 89 d0             	mov    %edx,%r8d
    33e9:	48 8b 77 08          	mov    0x8(%rdi),%rsi
    33ed:	48 8b 17             	mov    (%rdi),%rdx
    33f0:	4c 89 cf             	mov    %r9,%rdi
    33f3:	e9 78 dc ff ff       	jmpq   1070 <XDrawPoint@plt>
    33f8:	0f 1f 84 00 00 00 00 	nopl   0x0(%rax,%rax,1)
    33ff:	00 

0000000000003400 <flame_draw_line>:
    3400:	48 83 ec 10          	sub    $0x10,%rsp
    3404:	41 89 f2             	mov    %esi,%r10d
    3407:	4c 8b 5f 10          	mov    0x10(%rdi),%r11
    340b:	48 8b 77 08          	mov    0x8(%rdi),%rsi
    340f:	41 50                	push   %r8
    3411:	41 89 d0             	mov    %edx,%r8d
    3414:	48 8b 17             	mov    (%rdi),%rdx
    3417:	41 89 c9             	mov    %ecx,%r9d
    341a:	4c 89 df             	mov    %r11,%rdi
    341d:	44 89 d1             	mov    %r10d,%ecx
    3420:	e8 cb dd ff ff       	callq  11f0 <XDrawLine@plt>
    3425:	48 83 c4 18          	add    $0x18,%rsp
    3429:	c3                   	retq   
    342a:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

0000000000003430 <flame_set_color>:
    3430:	53                   	push   %rbx
    3431:	48 89 fb             	mov    %rdi,%rbx
    3434:	48 83 ec 20          	sub    $0x20,%rsp
    3438:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    343c:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3443:	00 00 
    3445:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    344a:	31 c0                	xor    %eax,%eax
    344c:	8b 43 20             	mov    0x20(%rbx),%eax
    344f:	85 c0                	test   %eax,%eax
    3451:	74 3d                	je     3490 <flame_set_color+0x60>
    3453:	c1 e2 08             	shl    $0x8,%edx
    3456:	0f b6 c9             	movzbl %cl,%ecx
    3459:	c1 e6 10             	shl    $0x10,%esi
    345c:	0f b7 d2             	movzwl %dx,%edx
    345f:	81 e6 00 00 ff 00    	and    $0xff0000,%esi
    3465:	09 ca                	or     %ecx,%edx
    3467:	09 f2                	or     %esi,%edx
    3469:	48 63 d2             	movslq %edx,%rdx
    346c:	48 89 14 24          	mov    %rdx,(%rsp)
    3470:	48 8b 33             	mov    (%rbx),%rsi
    3473:	e8 f8 dc ff ff       	callq  1170 <XSetForeground@plt>
    3478:	48 8b 44 24 18       	mov    0x18(%rsp),%rax
    347d:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    3484:	00 00 
    3486:	75 3d                	jne    34c5 <flame_set_color+0x95>
    3488:	48 83 c4 20          	add    $0x20,%rsp
    348c:	5b                   	pop    %rbx
    348d:	c3                   	retq   
    348e:	66 90                	xchg   %ax,%ax
    3490:	c1 e6 08             	shl    $0x8,%esi
    3493:	c1 e2 18             	shl    $0x18,%edx
    3496:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    349d:	00 
    349e:	0f b7 f6             	movzwl %si,%esi
    34a1:	c1 e1 08             	shl    $0x8,%ecx
    34a4:	09 f2                	or     %esi,%edx
    34a6:	48 8b 73 18          	mov    0x18(%rbx),%rsi
    34aa:	66 89 4c 24 0c       	mov    %cx,0xc(%rsp)
    34af:	89 54 24 08          	mov    %edx,0x8(%rsp)
    34b3:	48 89 e2             	mov    %rsp,%rdx
    34b6:	e8 95 db ff ff       	callq  1050 <XAllocColor@plt>
    34bb:	48 8b 14 24          	mov    (%rsp),%rdx
    34bf:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    34c3:	eb ab                	jmp    3470 <flame_set_color+0x40>
    34c5:	e8 d6 db ff ff       	callq  10a0 <__stack_chk_fail@plt>
    34ca:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)

00000000000034d0 <flame_clear_display>:
    34d0:	48 8b 77 08          	mov    0x8(%rdi),%rsi
    34d4:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    34d8:	e9 63 db ff ff       	jmpq   1040 <XClearWindow@plt>
    34dd:	0f 1f 00             	nopl   (%rax)

00000000000034e0 <flame_clear_color>:
    34e0:	53                   	push   %rbx
    34e1:	c1 e6 08             	shl    $0x8,%esi
    34e4:	c1 e2 18             	shl    $0x18,%edx
    34e7:	48 89 fb             	mov    %rdi,%rbx
    34ea:	0f b7 f6             	movzwl %si,%esi
    34ed:	c1 e1 08             	shl    $0x8,%ecx
    34f0:	09 d6                	or     %edx,%esi
    34f2:	48 81 ec 90 00 00 00 	sub    $0x90,%rsp
    34f9:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3500:	00 00 
    3502:	48 89 84 24 88 00 00 	mov    %rax,0x88(%rsp)
    3509:	00 
    350a:	31 c0                	xor    %eax,%eax
    350c:	89 74 24 08          	mov    %esi,0x8(%rsp)
    3510:	48 8b 77 18          	mov    0x18(%rdi),%rsi
    3514:	48 89 e2             	mov    %rsp,%rdx
    3517:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    351b:	66 89 4c 24 0c       	mov    %cx,0xc(%rsp)
    3520:	48 c7 04 24 00 00 00 	movq   $0x0,(%rsp)
    3527:	00 
    3528:	e8 23 db ff ff       	callq  1050 <XAllocColor@plt>
    352d:	48 8b 04 24          	mov    (%rsp),%rax
    3531:	48 8b 73 08          	mov    0x8(%rbx),%rsi
    3535:	48 8d 4c 24 10       	lea    0x10(%rsp),%rcx
    353a:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    353e:	ba 02 00 00 00       	mov    $0x2,%edx
    3543:	48 89 44 24 18       	mov    %rax,0x18(%rsp)
    3548:	e8 73 db ff ff       	callq  10c0 <XChangeWindowAttributes@plt>
    354d:	48 8b 84 24 88 00 00 	mov    0x88(%rsp),%rax
    3554:	00 
    3555:	64 48 2b 04 25 28 00 	sub    %fs:0x28,%rax
    355c:	00 00 
    355e:	75 09                	jne    3569 <flame_clear_color+0x89>
    3560:	48 81 c4 90 00 00 00 	add    $0x90,%rsp
    3567:	5b                   	pop    %rbx
    3568:	c3                   	retq   
    3569:	e8 32 db ff ff       	callq  10a0 <__stack_chk_fail@plt>
    356e:	66 90                	xchg   %ax,%ax

0000000000003570 <flame_event_waiting>:
    3570:	55                   	push   %rbp
    3571:	53                   	push   %rbx
    3572:	48 89 fb             	mov    %rdi,%rbx
    3575:	48 81 ec d8 00 00 00 	sub    $0xd8,%rsp
    357c:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    3580:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3587:	00 00 
    3589:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
    3590:	00 
    3591:	31 c0                	xor    %eax,%eax
    3593:	48 85 ff             	test   %rdi,%rdi
    3596:	74 09                	je     35a1 <flame_event_waiting+0x31>
    3598:	e8 e3 db ff ff       	callq  1180 <XFlush@plt>
    359d:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    35a1:	48 89 e5             	mov    %rsp,%rbp
    35a4:	48 c7 c6 ff ff ff ff 	mov    $0xffffffffffffffff,%rsi
    35ab:	48 89 ea             	mov    %rbp,%rdx
    35ae:	e8 dd db ff ff       	callq  1190 <XCheckMaskEvent@plt>
    35b3:	85 c0                	test   %eax,%eax
    35b5:	74 0d                	je     35c4 <flame_event_waiting+0x54>
    35b7:	8b 04 24             	mov    (%rsp),%eax
    35ba:	8d 50 fe             	lea    -0x2(%rax),%edx
    35bd:	31 c0                	xor    %eax,%eax
    35bf:	83 e2 fd             	and    $0xfffffffd,%edx
    35c2:	74 24                	je     35e8 <flame_event_waiting+0x78>
    35c4:	48 8b 8c 24 c8 00 00 	mov    0xc8(%rsp),%rcx
    35cb:	00 
    35cc:	64 48 2b 0c 25 28 00 	sub    %fs:0x28,%rcx
    35d3:	00 00 
    35d5:	75 24                	jne    35fb <flame_event_waiting+0x8b>
    35d7:	48 81 c4 d8 00 00 00 	add    $0xd8,%rsp
    35de:	5b                   	pop    %rbx
    35df:	5d                   	pop    %rbp
    35e0:	c3                   	retq   
    35e1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    35e8:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    35ec:	48 89 ee             	mov    %rbp,%rsi
    35ef:	e8 4c db ff ff       	callq  1140 <XPutBackEvent@plt>
    35f4:	b8 01 00 00 00       	mov    $0x1,%eax
    35f9:	eb c9                	jmp    35c4 <flame_event_waiting+0x54>
    35fb:	e8 a0 da ff ff       	callq  10a0 <__stack_chk_fail@plt>

0000000000003600 <flame_wait>:
    3600:	41 55                	push   %r13
    3602:	49 89 f5             	mov    %rsi,%r13
    3605:	41 54                	push   %r12
    3607:	49 89 d4             	mov    %rdx,%r12
    360a:	55                   	push   %rbp
    360b:	53                   	push   %rbx
    360c:	48 89 fb             	mov    %rdi,%rbx
    360f:	48 81 ec d8 00 00 00 	sub    $0xd8,%rsp
    3616:	48 8b 7f 10          	mov    0x10(%rdi),%rdi
    361a:	64 48 8b 04 25 28 00 	mov    %fs:0x28,%rax
    3621:	00 00 
    3623:	48 89 84 24 c8 00 00 	mov    %rax,0xc8(%rsp)
    362a:	00 
    362b:	31 c0                	xor    %eax,%eax
    362d:	48 85 ff             	test   %rdi,%rdi
    3630:	74 09                	je     363b <flame_wait+0x3b>
    3632:	e8 49 db ff ff       	callq  1180 <XFlush@plt>
    3637:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    363b:	48 89 e5             	mov    %rsp,%rbp
    363e:	eb 04                	jmp    3644 <flame_wait+0x44>
    3640:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    3644:	e8 47 da ff ff       	callq  1090 <XPending@plt>
    3649:	85 c0                	test   %eax,%eax
    364b:	7e f3                	jle    3640 <flame_wait+0x40>
    364d:	48 8b 7b 10          	mov    0x10(%rbx),%rdi
    3651:	48 89 ee             	mov    %rbp,%rsi
    3654:	e8 a7 da ff ff       	callq  1100 <XNextEvent@plt>
    3659:	8b 04 24             	mov    (%rsp),%eax
    365c:	83 f8 02             	cmp    $0x2,%eax
    365f:	74 1c                	je     367d <flame_wait+0x7d>
    3661:	83 f8 04             	cmp    $0x4,%eax
    3664:	75 da                	jne    3640 <flame_wait+0x40>
    3666:	8b 54 24 40          	mov    0x40(%rsp),%edx
    366a:	8b 4c 24 44          	mov    0x44(%rsp),%ecx
    366e:	0f b6 44 24 54       	movzbl 0x54(%rsp),%eax
    3673:	41 89 55 00          	mov    %edx,0x0(%r13)
    3677:	41 89 0c 24          	mov    %ecx,(%r12)
    367b:	eb 0a                	jmp    3687 <flame_wait+0x87>
    367d:	31 f6                	xor    %esi,%esi
    367f:	48 89 ef             	mov    %rbp,%rdi
    3682:	e8 99 da ff ff       	callq  1120 <XLookupKeysym@plt>
    3687:	48 8b 8c 24 c8 00 00 	mov    0xc8(%rsp),%rcx
    368e:	00 
    368f:	64 48 2b 0c 25 28 00 	sub    %fs:0x28,%rcx
    3696:	00 00 
    3698:	75 0e                	jne    36a8 <flame_wait+0xa8>
    369a:	48 81 c4 d8 00 00 00 	add    $0xd8,%rsp
    36a1:	5b                   	pop    %rbx
    36a2:	5d                   	pop    %rbp
    36a3:	41 5c                	pop    %r12
    36a5:	41 5d                	pop    %r13
    36a7:	c3                   	retq   
    36a8:	e8 f3 d9 ff ff       	callq  10a0 <__stack_chk_fail@plt>
    36ad:	0f 1f 00             	nopl   (%rax)

00000000000036b0 <__libc_csu_init>:
    36b0:	f3 0f 1e fa          	endbr64 
    36b4:	41 57                	push   %r15
    36b6:	4c 8d 3d 03 27 00 00 	lea    0x2703(%rip),%r15        # 5dc0 <__frame_dummy_init_array_entry>
    36bd:	41 56                	push   %r14
    36bf:	49 89 d6             	mov    %rdx,%r14
    36c2:	41 55                	push   %r13
    36c4:	49 89 f5             	mov    %rsi,%r13
    36c7:	41 54                	push   %r12
    36c9:	41 89 fc             	mov    %edi,%r12d
    36cc:	55                   	push   %rbp
    36cd:	48 8d 2d fc 26 00 00 	lea    0x26fc(%rip),%rbp        # 5dd0 <__do_global_dtors_aux_fini_array_entry>
    36d4:	53                   	push   %rbx
    36d5:	4c 29 fd             	sub    %r15,%rbp
    36d8:	48 83 ec 08          	sub    $0x8,%rsp
    36dc:	e8 1f d9 ff ff       	callq  1000 <_init>
    36e1:	48 c1 fd 03          	sar    $0x3,%rbp
    36e5:	74 1f                	je     3706 <__libc_csu_init+0x56>
    36e7:	31 db                	xor    %ebx,%ebx
    36e9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    36f0:	4c 89 f2             	mov    %r14,%rdx
    36f3:	4c 89 ee             	mov    %r13,%rsi
    36f6:	44 89 e7             	mov    %r12d,%edi
    36f9:	41 ff 14 df          	callq  *(%r15,%rbx,8)
    36fd:	48 83 c3 01          	add    $0x1,%rbx
    3701:	48 39 dd             	cmp    %rbx,%rbp
    3704:	75 ea                	jne    36f0 <__libc_csu_init+0x40>
    3706:	48 83 c4 08          	add    $0x8,%rsp
    370a:	5b                   	pop    %rbx
    370b:	5d                   	pop    %rbp
    370c:	41 5c                	pop    %r12
    370e:	41 5d                	pop    %r13
    3710:	41 5e                	pop    %r14
    3712:	41 5f                	pop    %r15
    3714:	c3                   	retq   
    3715:	66 66 2e 0f 1f 84 00 	data16 nopw %cs:0x0(%rax,%rax,1)
    371c:	00 00 00 00 

0000000000003720 <__libc_csu_fini>:
    3720:	f3 0f 1e fa          	endbr64 
    3724:	c3                   	retq   

Disassembly of section .fini:

0000000000003728 <_fini>:
    3728:	f3 0f 1e fa          	endbr64 
    372c:	48 83 ec 08          	sub    $0x8,%rsp
    3730:	48 83 c4 08          	add    $0x8,%rsp
    3734:	c3                   	retq   
