#include "SessionManager.h"
#include "ISessionService.generated.h"

UINTERFACE(Blueprintable)
class GRPC_UNREAL_API USessionService : public UInterface
{
	GENERATED_BODY()
};

class GRPC_UNREAL_API ISessionService
{
	GENERATED_BODY()
public:
	//ISessionManager();
	//virtual ~ISessionManager();

	/** Issues an authentication request.
	    Username is the username to authenticate.
	    HashedPassword is the password to authenticate with.
	    Completion the delegate to call when authentication has completed. Ownership of pointer not taken.*/
	void StartAuthentication(const FString& Username, const FString& HashedPassword, AuthCompletionDelegate* Completion);

	/** Gets the current session state. */
	SessionState GetSessionState()
	{
		return Session->GetSessionState();
	}

	/** Gets the current session error message. Only valid when SessionState is SS_AuthenticationFailed. */
	const FString& GetSessionErrorMsg()
	{
		return Session->GetSessionErrorMsg();
	}

	/** Gets the current session authentication cookie. Only valid when SessionState is SS_Authenticated. */
	const FString& GetSessionAuthCookie()
	{
		return Session->GetSessionAuthCookie();
	}

private:
	SessionManager* Session;
};
