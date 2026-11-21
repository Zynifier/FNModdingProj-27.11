// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Building/SpatialGameplay/SpatialEnterExitContext.h"
#include "Components/FortControllerComponent_ExternalEmote.h"
#include "GameFramework/GameplayMessageTypes.h"
#include "Playspaces/Components/FortPlayspaceComponent.h"
#include "PlayspaceComponent_CreativeModifyEmotes.generated.h"

class AActor;
class APlayerState;
class UPlayspaceComponent_CreativeModifyEmotes;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"), meta=(BlueprintSpawnableComponent))
class FORTNITEGAME_API UPlayspaceComponent_CreativeModifyEmotes : public UFortPlayspaceComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddBlockedEmote(const FString& EmoteToBlock);

	UFUNCTION(BlueprintCallable)
	void AddBlockedEmoteTag(const FGameplayTag& TagToBlock);

	UFUNCTION(BlueprintCallable)
	virtual void AddEmotesForPlayer(APlayerState* PlayerState);

	UFUNCTION(BlueprintCallable)
	void AddEmotesToPlayersInSpatialInterface();

	UFUNCTION(BlueprintCallable)
	bool AddEmoteToCategory(const FString& EmoteTemplateID, const FName& CategoryName, FEmoteActionBinding& OutCreatedEmote);

	UFUNCTION(BlueprintCallable)
	bool AddUniqueEmoteCategory(const FName& CategoryName, const FText& CategoryTitle, const FText& CategoryTitleMultipage, const bool bExclusive);

	UFUNCTION(BlueprintPure)
	static UPlayspaceComponent_CreativeModifyEmotes* GetCreativeModifyEmotesComponent(const AActor* ContextActor);

	UFUNCTION(BlueprintCallable)
	void RemoveBlockedEmote(const FString& EmoteToRemove);

	UFUNCTION(BlueprintCallable)
	void RemoveBlockedEmoteTag(const FGameplayTag& TagToRemove);

	UFUNCTION(BlueprintCallable)
	void RemoveEmoteCategory(const FName& CategoryName);

	UFUNCTION(BlueprintCallable)
	void RemoveEmoteFromCategory(const FEmoteActionBinding& EmoteToRemove, const FName& CategoryName);

	UFUNCTION(BlueprintCallable)
	void RemoveEmotesFromPlayerState(APlayerState* PlayerState, const TArray<FName>& CategoriesToRemove);

protected:
	UFUNCTION()
	virtual void OnPlayerEnteredSpatialInterface(FEventMessageTag Channel, const FPlayerEnterSpatialActorContext& PlayerEnterSpatialActorContext);

	UFUNCTION()
	virtual void OnPlayerExitedSpatialInterface(FEventMessageTag Channel, const FPlayerExitSpatialActorContext& PlayerExitSpatialActorContext);

};

