package com.paddlecreekgames.authsvc;

import com.google.protobuf.RpcController;
import com.google.protobuf.ServiceException;
import com.paddlecreekgames.ExampleService.AuthRequest;
import com.paddlecreekgames.ExampleService.AuthResponse;
import com.paddlecreekgames.ExampleService.AuthService.BlockingInterface;

public class BlockingAuthServiceImpl implements BlockingInterface {

	@Override
	public AuthResponse authenticate(RpcController controller,
			AuthRequest request) throws ServiceException {
		// TODO Auto-generated method stub
		return null;
	}

}
