// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/OnlineReplStructs.h"
#include "Math/MathFwd.h"
#include "Components/PlayspaceGameStateComponent.h"
#include "PlayspaceGameStateComponent_PlayerSpawningManager.generated.h"

class AActor;
class APlayspace;

USTRUCT()
struct FPlayspaceSpawningInfo
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FUniqueNetIdRepl UserId;

	UPROPERTY()
	TWeakObjectPtr<APlayspace> RequestingPlayspace;

	UPROPERTY()
	TObjectPtr<AActor> SpawnLocationActor;

	UPROPERTY()
	FVector SpawnLocation;

	UPROPERTY()
	FRotator SpawnRotation;

	UPROPERTY()
	float SpawnTimeServer;

	UPROPERTY()
	FVector LastLocation;

	UPROPERTY()
	float MinTimeForCameraFadeTransition;

	UPROPERTY(NotReplicated)
	bool bIsRespawnFromDeath;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class PLAYSPACESYSTEM_API UPlayspaceGameStateComponent_PlayerSpawningManager : public UPlayspaceGameStateComponent
{
	GENERATED_BODY()

protected:
	UPROPERTY(Transient)
	TArray<FPlayspaceSpawningInfo> SpawningUsersArray;

};

