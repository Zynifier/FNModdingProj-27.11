// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/Modifiers/FortAthenaMutator.h"
#include "FortAthenaMutator_ShowPlacard.generated.h"

class AActor;
class AFortAthenaMutator_ShowPlacard;

UENUM(BlueprintType)
enum class EShowPlacardPhase : uint8
{
	/** The "resting" state used when the placard is NOT currently in use */
	None = 0,
	/** Used to trigger the screen to start the show sequence */
	StartShow = 1,
	/** Waiting period before we fade out the screen before showing our placard */
	WaitBeforeInitialFadeOut = 2,
	/** The screen fade that happens right before we show the screen*/
	PreShowFadeOut = 3,
	/** Screen fades in and our UI placard is told to start showing */
	Show = 4,
	/** We have finished showing our UI placard, we tell the placard to hide and start fading out the screen */
	FadeOut = 5,
	/** After we finish showing the screen and fade out, fade back in */
	PostShowFadeIn = 6,
	/** We have finished showing the screen, broadcast OnShowPlacard_Finished*/
	DoneShowingScreen = 7,
	MAX = 8 UMETA(Hidden),
};

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowPlacard_Finished, AFortAthenaMutator_ShowPlacard*, ShowPlacardMutator);

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnShowPlacard_SetWidgetVisibility, bool, bNewVisibility);

UCLASS(BlueprintType, HideCategories=("Input", "Movement", "Collision", "Rendering", "HLOD", "WorldPartition", "DataLayers", "Transformation"), ShowCategories=("Input|MouseInput", "Input|TouchInput"))
class AFortAthenaMutator_ShowPlacard : public AFortAthenaMutator
{
	GENERATED_BODY()

public:
	UPROPERTY()
	FOnShowPlacard_Finished OnShowPlacard_Finished;

	UPROPERTY()
	FOnShowPlacard_SetWidgetVisibility OnShowPlacard_SetWidgetVisibility;

protected:
	UFUNCTION()
	void OnRep_ShowPlacardPhase();

	UPROPERTY(ReplicatedUsing=OnRep_ShowPlacardPhase)
	EShowPlacardPhase ShowPlacardPhase;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ShowPlacard", meta=(ClampMin="0"))
	float WaitBeforeInitialFadeOutDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ShowPlacard", meta=(ClampMin="0"))
	float FadeDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ShowPlacard", meta=(ClampMin="0"))
	float ShowPlacardDuration;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortAthenaMutator_ShowPlacard", meta=(ClampMin="0"))
	float ServerWaitsOnBlackScreenDuration;

	UPROPERTY(Transient)
	TWeakObjectPtr<AActor> CameraActor;

};

