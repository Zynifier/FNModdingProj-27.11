// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "SolarisDebugMessage.generated.h"

// A unique id assigned to a debug client when they first connect (not guaranteed to be in any particular integer order)
// Allows a debuggee to maintain communication with several clients at once

UENUM()
enum class ESolarisDebugMessageClientId : int32
{
	None = 0,
	Max = 2147483646,
};

// Possible purposes of a debug message

UENUM()
enum class ESolarisDebugMessageCommand : int32
{
	Connect = 0,
	Disconnect = 1,
	Message = 2,
	PackageMapping = 3,
};

/**
 * Stores a message to be sent to or from a debuggee
 * Reflected as USTRUCT so it can be automagically RPCed
 */
USTRUCT()
struct FSolarisDebugMessage
{
	GENERATED_BODY()

public:
	// The client id this message is from or for

	UPROPERTY()
	ESolarisDebugMessageClientId ClientId;

	// Purpose of this message

	UPROPERTY()
	ESolarisDebugMessageCommand Command;

	// JSON-formatted, UTF8-encoded body of this Debug Adapter Protocol message (request, response, event etc. - empty for connect/disconnect commands)

	UPROPERTY()
	TArray<uint8> MessageBodyUTF8;

};

