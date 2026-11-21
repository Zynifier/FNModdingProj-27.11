// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "FortAthenaLivingWorldSpawnAction.generated.h"

class AActor;
class IFortAthenaLivingWorldPointProviderInterface;
class UFortAthenaLivingWorldSpawnAction;

USTRUCT()
struct FFortAthenaLivingWorldTaggedSpawnActionClass
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldTaggedSpawnActionClass", meta=(Categories="Athena.AI.Lager.SpawnAction"))
	FGameplayTag SpawnActionTag;

	UPROPERTY(EditAnywhere, Category="FortAthenaLivingWorldTaggedSpawnActionClass")
	TSubclassOf<UFortAthenaLivingWorldSpawnAction> SpawnActionClass;

};

UCLASS(Abstract, EditInlineNew)
class UFortAthenaLivingWorldSpawnAction : public UObject
{
	GENERATED_BODY()

};

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortAthenaLivingWorldSpawnActionBlueprint : public UFortAthenaLivingWorldSpawnAction
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent, meta=(DisplayName="OnAllActorSpawned", ScriptName="OnAllActorSpawned"))
	void K2_OnAllActorSpawned(const TArray<AActor*>& SpawnedActor, const TScriptInterface<IFortAthenaLivingWorldPointProviderInterface>& SourcePointProvider) const;

};

