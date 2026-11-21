// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "CurieMinimalTypes.h"
#include "FortHUDElementWidget.h"
#include "AthenaCurieStatusWidget.generated.h"

class AFortPlayerStateAthena;
class AFortPlayerStateZone;
class UObject;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UAthenaCurieStatusWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerState(AFortPlayerStateAthena* PlayerState);

protected:
	UFUNCTION(BlueprintPure)
	bool HasState(FGameplayTag CurieState) const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurieStateAdded(const FGameplayTag& AddedState);

	UFUNCTION()
	void OnCurieStateAttachedToSpectator(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& ElementIdentifier);

	UFUNCTION()
	void OnCurieStateDetachedFromSpectator(UObject* InOwner, FCurieContainerHandle ContainerHandle, const FGameplayTag& ElementIdentifier);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCurieStateRemoved(const FGameplayTag& RemovedState);

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* NewSpectatingTarget);

	UFUNCTION()
	void OnPlayerStatePawnChanged();

};

