// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Faction/FortFactionInfo.h"
#include "Athena/Faction/FortFactionMapping.h"
#include "Components/FortGameStateComponent.h"
#include "FortGameStateComponent_AffiliationManager.generated.h"

class AFortGameStateAthena;
class UFortActorComponent_Affiliation;
class UFortPlaylist;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortGameStateComponent_AffiliationManager : public UFortGameStateComponent
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void OnPlaylistDataReady(AFortGameStateAthena* GameState, const UFortPlaylist* Playlist, const FGameplayTagContainer& PlaylistContextTags);

	UFUNCTION()
	void OnRep_FactionInfos();

	UPROPERTY(EditDefaultsOnly, Category="Affiliation")
	bool bApplyAttitudeChangesOnAllSquadActorsInNonCreativeWithFactions;

	UPROPERTY(EditDefaultsOnly, Category="Affiliation")
	bool bApplyAttitudeChangesOnConverted;

	UPROPERTY(Transient)
	FFactionData GameParticipantFaction;

	UPROPERTY(Transient)
	TArray<FFactionData> CachedFactionData;

	UPROPERTY(Transient)
	FGameplayTagContainer CachedFactionTags;

	UPROPERTY(Transient)
	FGameplayTagContainer BlockResetSpecificRelationTags;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortActorComponent_Affiliation>> AffiliationComponents;

	UPROPERTY(Transient, ReplicatedUsing=OnRep_FactionInfos)
	TArray<FFortFactionInfo> FactionInfos;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortActorComponent_Affiliation>> AffiliationComponentsToRegister;

};

