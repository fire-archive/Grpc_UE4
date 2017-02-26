package com.paddlecreekgames.protobuf;

import com.google.protobuf.RpcCallback;
import com.google.protobuf.RpcController;

public class RpcControllerImpl implements RpcController {

	@Override
	public void reset() {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean failed() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public String errorText() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void startCancel() {
		// TODO Auto-generated method stub

	}

	@Override
	public void setFailed(String reason) {
		// TODO Auto-generated method stub

	}

	@Override
	public boolean isCanceled() {
		// TODO Auto-generated method stub
		return false;
	}

	@Override
	public void notifyOnCancel(RpcCallback<Object> callback) {
		// TODO Auto-generated method stub

	}

}
