// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UACNetworkComponent.generated.h"

UCLASS(Transient)
class UACCOMMON_API UUACNetworkComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(Client, Reliable)
	void SendClientHello(uint32 SessionKey);

	UPROPERTY(Replicated)
	int32 PlayerID;

protected:
	UFUNCTION(Client, Reliable)
	void SendPacketToClient(uint8 EnhPacketType, const TArray<uint8>& Data);

	UFUNCTION(Server, Reliable, WithValidation)
	void SendPacketToServer(uint8 EnhPacketType, const TArray<uint8>& Data);

};

