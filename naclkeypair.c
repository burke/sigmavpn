//
//  naclkeypair.c
//  Sigma NaCl keypair generator
//
//  Copyright (c) 2011, Neil Alexander T.
//  All rights reserved.
// 
//  Redistribution and use in source and binary forms, with
//  or without modification, are permitted provided that the following
//  conditions are met:
// 
//  - Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//  - Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
// 
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
//  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
//  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
//  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
//  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
//  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
//  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
//  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
//  POSSIBILITY OF SUCH DAMAGE.
//

#include <stdio.h>
#include <sodium.h>

int main(void)
{
	unsigned char pk[crypto_box_curve25519xsalsa20poly1305_PUBLICKEYBYTES];
	unsigned char sk[crypto_box_curve25519xsalsa20poly1305_SECRETKEYBYTES];
	
	crypto_box_curve25519xsalsa20poly1305_keypair(pk, sk);
	
	int i;
	
	printf("PRIVATE KEY: ");
	
	for (i = 0; i < crypto_box_curve25519xsalsa20poly1305_SECRETKEYBYTES; i ++)
		printf("%02x", sk[i]);
	
	printf("\n PUBLIC KEY: ");
	
	for (i = 0; i < crypto_box_curve25519xsalsa20poly1305_PUBLICKEYBYTES; i ++)
		printf("%02x", pk[i]);
	
	printf("\n");
}

