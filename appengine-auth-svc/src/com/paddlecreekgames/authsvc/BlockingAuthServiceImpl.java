package com.paddlecreekgames.authsvc;

import com.google.protobuf.RpcController;
import com.google.protobuf.ServiceException;
import com.paddlecreekgames.ExampleService.AuthRequest;
import com.paddlecreekgames.ExampleService.AuthResponse;
import com.paddlecreekgames.ExampleService.AuthService.BlockingInterface;
import com.paddlecreekgames.ExampleService.FailedAuthResponse;
import com.paddlecreekgames.ExampleService.SuccessfullAuthResponse;

public class BlockingAuthServiceImpl implements BlockingInterface {

	@Override
	public AuthResponse authenticate(RpcController controller,
			AuthRequest request) throws ServiceException {
		AuthResponse response = null;
		if (request.getUsername().equals("san") && request.getHash().equals("some_secure_hash")) {
			response = AuthResponse.newBuilder().setSuccessfullAuthData(SuccessfullAuthResponse.newBuilder().setAuthToken("auth_token").build()).build();
		} else {
			response = AuthResponse.newBuilder().setFailedAuthData(FailedAuthResponse.newBuilder().setErrorMessage("authentication failed").build()).build();
		}
		return response;
	}
}
