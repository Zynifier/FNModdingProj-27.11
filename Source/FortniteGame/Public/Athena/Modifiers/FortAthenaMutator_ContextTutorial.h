// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ContextTutorial.generated.h"

class UFortContextualTutorialController;
class UFortContextualTutorialDefinition;
class USoundCue;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FContextTutorialShowHighlight, const FGameplayTagContainer&, HUDGameplayTags, bool, Show);

UCLASS(Config=Game, MinimalAPI, BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ContextTutorial : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FContextTutorialShowHighlight OnShowButtonHighlight;

private:
	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	bool bEnableTutorials;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	int32 bContextTutorialMinimumLevelOverride;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_ContextTutorial")
	TObjectPtr<USoundCue> MessageSound;

	UPROPERTY(EditAnywhere, Config, Category="FortAthenaMutator_ContextTutorial")
	int32 ConcurrentActiveContextualTutorials;

	UPROPERTY(EditAnywhere, Config, Category="FortAthenaMutator_ContextTutorial")
	float CooldownTimeBetweenContextualTutorialTips;

	UPROPERTY(EditAnywhere, Category="FortAthenaMutator_ContextTutorial", meta=(TitleProperty="TutorialType"))
	TArray<TObjectPtr<UFortContextualTutorialDefinition>> ContextualTutorialDefinitions;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	float InCombatGraceTime;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	float RayCastDistanceForNearbyEnemyCentimeter;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	float WorldMarkerPadding;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	FName WorldMarkerSockerName;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	bool bEnableWorldMarker;

	UPROPERTY(EditDefaultsOnly, Config, Category="FortAthenaMutator_ContextTutorial")
	bool bEnableHighlight;

	UPROPERTY(Transient)
	TArray<TObjectPtr<UFortContextualTutorialController>> Controllers;

};

