// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortTypes.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_ContentGating.generated.h"

class UFortCreativeContentGatingData;
class UFortCreativeTagFilter;

USTRUCT()
struct FFortContentGatingProfileUnlock
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FString Category;

	UPROPERTY()
	TArray<FString> Subcategories;

};

USTRUCT()
struct FFortContentGatingProfile
{
	GENERATED_BODY()

public:
	UPROPERTY()
	EFortContentRating Rating;

	UPROPERTY()
	TArray<FFortContentGatingProfileUnlock> Unlocks;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlayspaceComponent_ContentGating : public UFortPlayspaceComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnRep_ContentProfileChanged();

	UPROPERTY(EditDefaultsOnly, Category="PlayspaceComponent_ContentGating")
	TSoftObjectPtr<UFortCreativeContentGatingData> ContentGatingData;

	UPROPERTY()
	TObjectPtr<UFortCreativeTagFilter> ContentFilter;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_ContentProfileChanged)
	FFortContentGatingProfile ContentProfile;

};

