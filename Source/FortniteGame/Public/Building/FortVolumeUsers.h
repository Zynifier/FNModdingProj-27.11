// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "FortVolumeUsers.generated.h"

class AFortVolume;
class AFortVolumeManager;

USTRUCT()
struct FVolumePlayerStateInfo : public FFastArraySerializerItem
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	FUniqueNetIdRepl UniquePlayerId;

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> Volume;

};

USTRUCT()
struct FFortVolumeActiveUsers : public FFastArraySerializer
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient)
	TArray<FVolumePlayerStateInfo> Items;

	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<AFortVolumeManager> Manager;

};

