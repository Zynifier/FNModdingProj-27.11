// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "GameplayMessageReplicator.generated.h"

class UObject;

USTRUCT()
struct FReplicatedMessage
{
	GENERATED_BODY()

};

// On the client once we receive the USTRUCT payload type we need to malloc some memory to deserialize the payload into.
// To manage the lifetime and freeing of this memory we wrap it in a shared pointer inside the container which is replicated.

USTRUCT()
struct FReplicatedMessageData
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UObject> StructType;

};

UCLASS()
class AGameplayMessageReplicator : public AActor
{
	GENERATED_BODY()

private:
	UFUNCTION(NetMulticast, Reliable)
	void Multicast_ServerMessageTriggered(FEventMessageTag Channel, const FReplicatedMessage& MessageData);

};

