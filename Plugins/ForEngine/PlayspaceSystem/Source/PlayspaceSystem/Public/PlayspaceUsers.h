// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Net/Serialization/FastArraySerializer.h"
#include "PlayspaceUsers.generated.h"

class AController;
class APlayerState;
class APlayspace;

USTRUCT(BlueprintType)
struct PLAYSPACESYSTEM_API FPlayspaceUser : public FFastArraySerializerItem
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="PlayspaceUser")
	FUniqueNetIdRepl UserId;

	UPROPERTY(BlueprintReadOnly, Category="PlayspaceUser")
	TObjectPtr<APlayspace> LeafPlayspace;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="PlayspaceUser")
	TObjectPtr<APlayerState> PlayerStateCached;

	UPROPERTY(BlueprintReadOnly, NotReplicated, Category="PlayspaceUser")
	TObjectPtr<AController> ControllerCached;

};

USTRUCT()
struct PLAYSPACESYSTEM_API FPlayspaceUserList : public FFastArraySerializer
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient, NotReplicated)
	TObjectPtr<APlayspace> Playspace;

protected:
	UPROPERTY(Transient)
	TArray<FPlayspaceUser> PlayspaceUsers;

	UPROPERTY(Transient, NotReplicated)
	bool bIsInitialized;

};

