/*
 * TRLDAPConnection.h vi:ts=4:sw=4:expandtab:
 * Simple LDAP Wrapper
 *
 * Copyright (c) 2005 - 2007 Landon Fuller <landonf@threerings.net>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of Landon Fuller nor the names of any contributors
 *    may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SEfRVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#import <ldap.h>

#import "TRObject.h"

#import "TRLDAPEntry.h"

#import "TRString.h"
#import "TRArray.h"

@interface TRLDAPConnection : TRObject {
@private
    LDAP *ldapConn;
    int _timeout;
}

- (id) initWithURL: (TRString *) url timeout: (int) timeout;
- (BOOL) startTLS;
- (BOOL) TLSReqCert;


- (BOOL) bindWithDN: (TRString *) bindDN password: (TRString *) password;

- (TRArray *) searchWithFilter: (TRString *) filter
              scope: (int) scope
              baseDN: (TRString *) base
              attributes: (TRArray *) attributes;
- (BOOL) compare: (TRString *) dn withAttribute: (TRString *) attribute value: (TRString *) value;
- (BOOL) compareDN: (TRString *) dn withAttribute: (TRString *) attribute value: (TRString *) value;

- (BOOL) setReferralEnabled: (BOOL) enabled;
- (BOOL) setTLSCACertFile: (TRString *) fileName;
- (BOOL) setTLSCACertDir: (TRString *) directory;
- (BOOL) setTLSClientCert: (TRString *) certFile keyFile: (TRString *) keyFile;
- (BOOL) setTLSCipherSuite: (TRString *) cipherSuite;

@end
