// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "EntityDataBackedComponent.h"
#include "EntityActorPlayerComponent.generated.h"

class APlayerController;
class APlayerState;

UCLASS()
class ENTITYACTOR_API UEntityActorPlayerComponent : public UEntityDataBackedComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	virtual void OnRep_PlayerID();

	UPROPERTY(Transient, ReplicatedUsing=OnRep_PlayerID)
	FUniqueNetIdRepl PlayerID;

private:
	UPROPERTY()
	TSoftObjectPtr<APlayerController> PlayerControllerCache;

	UPROPERTY()
	TSoftObjectPtr<APlayerState> PlayerStateCache;

};

