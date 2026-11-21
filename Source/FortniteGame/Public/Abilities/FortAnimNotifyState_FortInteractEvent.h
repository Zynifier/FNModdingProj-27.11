// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "FortAnimNotifyState_FortInteractEvent.generated.h"

UCLASS(BlueprintType, Blueprintable, HideCategories=("Object", "Object"), meta=(DisplayName="FortInteract Event", ShowHiddenSelfPins))
class UFortAnimNotifyState_FortInteractEvent : public UAnimNotifyState
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortAnimNotifyState_FortInteractEvent")
	FName NotifyStateName;

};

