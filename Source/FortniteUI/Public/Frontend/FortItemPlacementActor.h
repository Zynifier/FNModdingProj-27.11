// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputCoreTypes.h"
#include "FortItemPlacementActor.generated.h"

class AActor;
class AFortPlayerPawn;
class UWidgetComponent;

UCLASS(Abstract)
class FORTNITEUI_API AFortItemPlacementActor : public AActor
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnHeroPawnSetupCompleted();

	UFUNCTION(BlueprintImplementableEvent)
	void OnHovered();

	UFUNCTION(BlueprintImplementableEvent)
	void OnItemClicked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPreviewActorSpawned();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRemovePreviewActor();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUnhovered();

private:
	UFUNCTION()
	void HandleBoneTransformsFinalized();

	UFUNCTION()
	void HandleFinishedCharacterCustomization(AFortPlayerPawn* InPawn);

	UFUNCTION()
	void HandlePawnBeginCursorOver(AActor* TouchedActor);

	UFUNCTION()
	void HandlePawnClicked(AActor* TouchedActor, FKey ButtonPressed);

	UFUNCTION()
	void HandlePawnEndCursorOver(AActor* TouchedActor);

	UFUNCTION()
	void HandlePawnFinishedApplyingCharacterParts(AFortPlayerPawn* Pawn);

	UFUNCTION()
	void HandlePawnTouchEnd(ETouchIndex::Type FingerIndex, AActor* TouchedActor);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Export, Category="FortItemPlacementActor", meta=(AllowPrivateAccess="TRUE", EditInline="true"))
	TObjectPtr<UWidgetComponent> WidgetComponent_LoadingIndicator;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPlacementActor", meta=(AllowPrivateAccess="TRUE"))
	bool bIsActorHovered;

	UPROPERTY(BlueprintReadOnly, Transient, Category="FortItemPlacementActor", meta=(AllowPrivateAccess="TRUE"))
	TObjectPtr<AFortPlayerPawn> CurrentPawn;

};

