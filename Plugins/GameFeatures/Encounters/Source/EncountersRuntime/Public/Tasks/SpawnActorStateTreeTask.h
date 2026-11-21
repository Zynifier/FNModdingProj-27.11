// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "StateTreeTaskBase.h"
#include "UObject/NoExportTypes.h"
#include "SpawnActorStateTreeTask.generated.h"

class AActor;
class USpawnActorTaskHelper;

USTRUCT(meta=(Category="Encounter", DisplayName="Spawn Actor"))
struct FSpawnActorStateTreeTask : public FStateTreeTaskCommonBase
{
	GENERATED_BODY()

};

USTRUCT()
struct FSpawnActorStateTreeTaskInstanceData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="Encounter")
	TSoftClassPtr<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category="Encounter")
	FGameplayTagQuery AnchorQuery;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer ActorTags;

	UPROPERTY(EditAnywhere, Category="Parameter")
	FGameplayTagContainer ActorIdentifierTags;

	UPROPERTY(EditAnywhere, Category="Context")
	TObjectPtr<AActor> UserActor;

private:
	UPROPERTY(Transient)
	TObjectPtr<USpawnActorTaskHelper> SpawnActorHelper;

};

UCLASS(MinimalAPI)
class USpawnActorTaskHelper : public UObject
{
	GENERATED_BODY()

};

