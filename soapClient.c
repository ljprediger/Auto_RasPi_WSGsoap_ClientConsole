/* soapClient.c
   Generated by gSOAP 2.8.7 from auto.h

Copyright(C) 2000-2011, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#if defined(__BORLANDC__)
#pragma option push -w-8060
#pragma option push -w-8004
#endif
#include "soapH.h"
#ifdef __cplusplus
extern "C" {
#endif

SOAP_SOURCE_STAMP("@(#) soapClient.c ver 2.8.7 2015-10-27 01:11:48 GMT")


SOAP_FMAC5 int SOAP_FMAC6 soap_call_ns__setAuto(struct soap *soap, const char *soap_endpoint, const char *soap_action, double a, double b, double *result)
{	struct ns__setAuto soap_tmp_ns__setAuto;
	struct ns__setAutoResponse *soap_tmp_ns__setAutoResponse;
	if (!soap_endpoint)
		soap_endpoint = "http://192.168.1.120:8080";
	soap->encodingStyle = "";
	soap_tmp_ns__setAuto.a = a;
	soap_tmp_ns__setAuto.b = b;
	soap_begin(soap);
	soap_serializeheader(soap);
	soap_serialize_ns__setAuto(soap, &soap_tmp_ns__setAuto);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put_ns__setAuto(soap, &soap_tmp_ns__setAuto, "ns:setAuto", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_connect(soap, soap_endpoint, soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put_ns__setAuto(soap, &soap_tmp_ns__setAuto, "ns:setAuto", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!result)
		return soap_closesock(soap);
	soap_default_double(soap, result);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	if (soap_recv_fault(soap, 1))
		return soap->error;
	soap_tmp_ns__setAutoResponse = soap_get_ns__setAutoResponse(soap, NULL, "", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	if (result && soap_tmp_ns__setAutoResponse->result)
		*result = *soap_tmp_ns__setAutoResponse->result;
	return soap_closesock(soap);
}

#ifdef __cplusplus
}
#endif

#if defined(__BORLANDC__)
#pragma option pop
#pragma option pop
#endif

/* End of soapClient.c */
