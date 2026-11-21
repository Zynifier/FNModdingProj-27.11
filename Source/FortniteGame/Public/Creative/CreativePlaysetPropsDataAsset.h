// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CreativePlaysetPropsDataAsset.generated.h"

class UFortCreativeRealEstatePlotItemDefinition;
class UFortPlaysetItemDefinition;

UCLASS(MinimalAPI)
class UCreativePlaysetPropsDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(Exec, Category="Playset Props", meta=(CallInEditor="true"))
	void Generate();

protected:
	UPROPERTY(VisibleAnywhere, Category="Playset Props")
	TSet<FName> GeneratedActorPaths;

	UPROPERTY(EditAnywhere, Category="Playset Props")
	TArray<TObjectPtr<UFortCreativeRealEstatePlotItemDefinition>> IncludedCreativeRealEstatePlotItemDefinitions;

	UPROPERTY(EditAnywhere, Category="Playset Props")
	TArray<TObjectPtr<UFortPlaysetItemDefinition>> IncludedPlaysetItemDefinitions;

	UPROPERTY(EditAnywhere, Category="Playset Props")
	TSet<FName> ActorPaths;

};

