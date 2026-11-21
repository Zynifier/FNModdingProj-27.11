// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "Components/FortControllerComponent_ExternalEmote.h"
#include "FortEmoteVolume.generated.h"

class AFortPlayerController;
class UFortQuestItemDefinition;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Collision", "Replication", "Brush", "Physics", "Object", "Blueprint", "Display", "Rendering", "Physics", "Input"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortEmoteVolume : public AVolume
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	const TArray<FEmoteActionBinding> GetGrantedEmotes() const;

	UFUNCTION(BlueprintPure)
	const FName GetRequiredObjectiveName() const;

	UFUNCTION(BlueprintPure)
	const UFortQuestItemDefinition* GetRequiredQuest() const;

	UFUNCTION(BlueprintPure)
	bool IsPlayerOverlapping(const AFortPlayerController* PlayerController) const;

	UFUNCTION(BlueprintPure)
	bool WasPlayerGrantedEmotes(const AFortPlayerController* PlayerController) const;

private:
#if WITH_EDITOR
	UFUNCTION(meta=(CallInEditor="true"))
	TArray<FName> Editor_GetValidObjectives() const;
#endif

	UPROPERTY(EditAnywhere, Category="Quest")
	TObjectPtr<UFortQuestItemDefinition> RequiredQuest;

	UPROPERTY(EditAnywhere, Category="Quest", meta=(GetOptions="Editor_GetValidObjectives"))
	FName RequiredObjective;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes", meta=(DisplayName="Emotes"))
	TArray<FEmoteActionBinding> GrantedEmotes;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes")
	bool bAllowGrantingUnownedEmotes;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes")
	bool bUseEmoteCategory;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes|Category", meta=(EditCondition="bUseEmoteCategory"))
	bool bDisplayExclusive;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes|Category", meta=(DisplayName="Name", EditCondition="bUseEmoteCategory"))
	FName EmoteCategoryName;

	UPROPERTY(EditAnywhere, Category="GrantedEmotes|Category", meta=(DisplayName="Picker Title", EditCondition="bUseEmoteCategory"))
	FText EmoteCategoryTitle;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortPlayerController>> TrackedPlayers;

	UPROPERTY(Transient)
	TSet<TObjectPtr<AFortPlayerController>> PlayersWithEmotes;

};

