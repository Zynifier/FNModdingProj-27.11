// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameplayTagContainer.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_HeistDisplayCaseItemManager.generated.h"

class AFortGameStateAthena;
class UFortPlaylist;
class UFortWorldItemDefinition;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FHeistDisplayCaseItemManagerReadyDelegate);

USTRUCT(BlueprintType)
struct FFortHeistDisplayCaseItemDataTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortHeistDisplayCaseItemDataTableRow")
	TObjectPtr<UFortWorldItemDefinition> WorldItemDefinition;

};

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class HEISTBASESGAMEPLAYRUNTIME_API UFortGameStateComponent_HeistDisplayCaseItemManager : public UFortGameStateComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	UFortWorldItemDefinition* GetDisplayCaseItem(FGameplayTag DisplayCaseGroupTag);

	UFUNCTION(BlueprintPure)
	bool IsDataReady() const;

	UPROPERTY(BlueprintAssignable)
	FHeistDisplayCaseItemManagerReadyDelegate OnDisplayCaseItemManagerReady;

private:
	UFUNCTION()
	void HandlePlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UPROPERTY()
	TArray<TObjectPtr<UFortWorldItemDefinition>> AllDisplayCaseItems;

};

