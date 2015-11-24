package com.paddlecreekgames.authsvc;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.CharBuffer;
import java.nio.charset.Charset;
import java.util.Arrays;

import javax.servlet.http.*;

import com.google.protobuf.BlockingService;
import com.google.protobuf.Descriptors.MethodDescriptor;
import com.google.protobuf.InvalidProtocolBufferException;
import com.google.protobuf.ServiceException;
import com.paddlecreekgames.ExampleService;
import com.paddlecreekgames.ExampleService.AuthService;
import com.paddlecreekgames.protobuf.RpcControllerImpl;
import com.google.protobuf.Message;


@SuppressWarnings("serial")
public class Appengine_auth_svcServlet extends HttpServlet {
	public void doGet(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		resp.setContentType("text/plain");
		resp.getWriter().println("We don't support gets");
	}
	
	public void doPost(HttpServletRequest req, HttpServletResponse resp)
			throws IOException {
		// TODO(san): Cache the service somewhere.
		BlockingAuthServiceImpl svcImpl = new BlockingAuthServiceImpl();
		BlockingService blockingSvc = ExampleService.AuthService.newReflectiveBlockingService(svcImpl);
		
		// Decode the method descriptor.
		String methodName = "TODO";
		MethodDescriptor method = blockingSvc.getDescriptorForType().findMethodByName(methodName);
		if (method == null) {
			resp.sendError(500, "Unknown method");
			return;
		}
		
		// Decode the request protobuf based on the content-type.
		Message requestProto = null;
		switch (req.getContentType().toLowerCase()) {
		case "application/x-protobuf":
			try {
				char[] charArray = new char[req.getContentLength()];
				req.getReader().read(charArray);
				CharBuffer charBuffer = CharBuffer.wrap(charArray);
				ByteBuffer byteBuffer = Charset.forName("UTF-8").encode(charBuffer);
				byte[] byteArray = Arrays.copyOfRange(byteBuffer.array(), byteBuffer.position(),  byteBuffer.limit());
				requestProto = blockingSvc.getRequestPrototype(method).toBuilder().mergeFrom(byteArray).build();
			} catch (InvalidProtocolBufferException e) {
				resp.sendError(500, "Bad request");
				return;
			}
			break;
		case "application/x-protobuf-text":
			break;
		case "application/json":
			break;
		default:
			resp.sendError(500,  "Unsupported request format");
			return;
		}
		
		// Dispatch the request to the appropriate handler.
		RpcControllerImpl controller = new RpcControllerImpl();
		Message response = null;
		try {
			response = blockingSvc.callBlockingMethod(method, controller, requestProto);
		} catch (ServiceException e) {
			resp.sendError(500, "Request failed (" + e.toString() + ")");
			return;
		}
		
		// Encode the response protobuf based on the request content-type.
		
	}
}
