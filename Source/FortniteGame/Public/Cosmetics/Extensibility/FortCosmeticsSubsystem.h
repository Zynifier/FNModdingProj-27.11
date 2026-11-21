// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cosmetics/Extensibility/FortCosmeticExtensibilityTypes.h"
#include "Subsystems/FortMemoryManagingGameInstanceSubsystem.h"
#include "FortCosmeticsSubsystem.generated.h"

class UCosmeticStepDependencyBuilder;
class UFortCosmeticFlowOptionSet;
class UFortCosmeticPassContext;
class UFortCosmeticStep;

USTRUCT()
struct FCosmeticFlowgraphState
{
	GENERATED_BODY()

public:
	UPROPERTY(Transient)
	TObjectPtr<UCosmeticStepDependencyBuilder> Builder;

	UPROPERTY(Transient)
	TArray<TSoftClassPtr<UFortCosmeticStep>> Steps;

};

USTRUCT()
struct FCosmeticsPassLookupKey
{
	GENERATED_BODY()


	FORTNITEGAME_API bool operator==(const FCosmeticsPassLookupKey& Other) const;
	friend FORTNITEGAME_API uint32 GetTypeHash(const FCosmeticsPassLookupKey& Value);
};

USTRUCT()
struct FExtensibilityPassContextEntry
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<UFortCosmeticPassContext> Context;

};

UCLASS(MinimalAPI)
class UFortCosmeticsSubsystem : public UFortMemoryManagingGameInstanceSubsystem
{
	GENERATED_BODY()

private:
	UPROPERTY()
	TObjectPtr<UCosmeticStepDependencyBuilder> Cache;

	UPROPERTY(Transient)
	TArray<TSoftClassPtr<UFortCosmeticStep>> ExtensionClasses;

	UPROPERTY(Transient)
	TMap<FCosmeticFlowGraphKey, FCosmeticFlowgraphState> CosmeticCategories;

	UPROPERTY()
	TArray<FExtensibilityPassContextEntry> AllocatedContexts;

	UPROPERTY()
	TMap<FCosmeticsPassLookupKey, UFortCosmeticPassContext*> ActorToVarianceFlow;

	UPROPERTY()
	TArray<UFortCosmeticPassContext*> UniquePassContexts;

	UPROPERTY(Transient)
	TMap<FCosmeticFlowOptionSetKey, TObjectPtr<UFortCosmeticFlowOptionSet>> CosmeticFlowOptionSets;

};

