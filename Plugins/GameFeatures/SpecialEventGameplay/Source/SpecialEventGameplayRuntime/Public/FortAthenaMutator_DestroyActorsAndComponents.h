// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "Player/FortCheatManager_Coupled.h"
#include "FortAthenaMutator_DestroyActorsAndComponents.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EDestroyActorsAndComponentsMutator_ComponentNameComparisonType : uint8
{
	/** GetName() == */
	NameEquals = 0,
	/** GetName().StartsWith() */
	NameStartsWith = 1,
	/** GetName().Contains() */
	NameContains = 2,
	/** AdditionalStatObject()->GetName().Equals() */
	AdditionalStatNameEquals = 3,
	/** AdditionalStatObject()->GetName().StartsWith() */
	AdditionalStatNameStartsWith = 4,
	/** AdditionalStatObject()->GetName().Contains() */
	AdditionalStatNameContains = 5,
};

USTRUCT(BlueprintType)
struct FDestroyActorsAndComponentsMutator_ComponentDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, Category="DestroyActorsAndComponentsMutator_ComponentDefinition", meta=(EditCondition="bDestroyOnServer || bDestroyOnClient"))
	FString ComponentName;

	UPROPERTY(EditDefaultsOnly, Category="DestroyActorsAndComponentsMutator_ComponentDefinition", meta=(EditCondition="bDestroyOnServer || bDestroyOnClient"))
	EDestroyActorsAndComponentsMutator_ComponentNameComparisonType NameComparisonType;

	UPROPERTY(EditDefaultsOnly, Category="DestroyActorsAndComponentsMutator_ComponentDefinition")
	bool bDestroyOnServer;

	UPROPERTY(EditDefaultsOnly, Category="DestroyActorsAndComponentsMutator_ComponentDefinition")
	bool bDestroyOnClient;

	UPROPERTY(EditDefaultsOnly, Category="DestroyActorsAndComponentsMutator_ComponentDefinition", meta=(EditCondition="bDestroyOnServer || bDestroyOnClient"))
	bool bPromoteChildrenOfDestroyedComponents;

};

USTRUCT(BlueprintType)
struct FDestroyActorsAndComponentsMutator_ActorDefinition
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition")
	FGameplayTagContainer Tags;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition")
	TSoftClassPtr<AActor> SoftActorClass;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition")
	bool bStartEnabled;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition")
	bool bDestroyActorOnServer;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition")
	bool bDestroyActorOnClient;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition", meta=(EditCondition="bDestroyActorOnClient"))
	bool bNetForceOnActorDestroy;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition", meta=(EditCondition="bDestroyActorOnServer || bDestroyActorOnClient"))
	bool bShouldModifyLevelOnActorDestroy;

	UPROPERTY(EditDefaultsOnly, NotReplicated, Category="DestroyActorsAndComponentsMutator_ActorDefinition", meta=(EditCondition="!bDestroyActorOnServer || !bDestroyActorOnClient"))
	TArray<FDestroyActorsAndComponentsMutator_ComponentDefinition> ComponentDefinitions;

	UPROPERTY()
	bool bCurrentlyEnabled;

	UPROPERTY()
	bool bPermanentlyDisabled;

	UPROPERTY(NotReplicated)
	TArray<TObjectPtr<AActor>> ActorsToProcess;

};

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Actor", "Cooking", "Events", "FortAthenaMutator", "HLOD", "LOD", "Mutator", "Replication", "Tick", "Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_DestroyActorsAndComponents : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void PermanentlyDisableActorDefinitions(const FGameplayTagContainer& InTags);

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly)
	void SetActorDefinitionsEnabled(const FGameplayTagContainer& InTags, const bool bEnabled);

protected:
	UPROPERTY(EditDefaultsOnly, ReplicatedUsing=OnRep_ActorDefinitions, Category="FortAthenaMutator_DestroyActorsAndComponents")
	TArray<FDestroyActorsAndComponentsMutator_ActorDefinition> ActorDefinitions;

private:
	UFUNCTION()
	void OnActorSpawned(AActor* Actor);

	UFUNCTION()
	void OnRep_ActorDefinitions(const TArray<FDestroyActorsAndComponentsMutator_ActorDefinition>& OldActorDefinitions);

	UFUNCTION()
	void OnTrackedActorDestroyed(AActor* DestroyedActor);

};

UCLASS()
class UFortCheatManager_DestroyActorsAndComponents : public UFortCheatManager_Coupled
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec)
	void DestroyActorsAndComponentsMutator_ListActorComponents(const FString& InActorName) const;

	UFUNCTION(Exec, BlueprintAuthorityOnly)
	void DestroyActorsAndComponentsMutator_SetActorDefinitionsEnabled(const FString& TagString, const bool bEnabled = true);

};

