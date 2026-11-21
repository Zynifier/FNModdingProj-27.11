// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/FortBaseAnimInstance.h"
#include "FortBaseLayerAnimInstance.generated.h"

class UFortPlayerAnimInstance;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, HideCategories=("AnimInstance"))
class UFortBaseLayerAnimInstance : public UFortBaseAnimInstance
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BlueprintOnAnimationLayerLinked();

	UFUNCTION(BlueprintImplementableEvent)
	FORTNITEGAME_API void BlueprintOnAnimationLayerUnlinked();

	UPROPERTY(Transient)
	TWeakObjectPtr<UFortPlayerAnimInstance> MainAnimInstanceWeakPtr;

	UPROPERTY(EditDefaultsOnly, Category="FortBaseLayerAnimInstance")
	uint8 bEnableLocomotionAdditives : 1;

	UPROPERTY(EditDefaultsOnly, Category="FortBaseLayerAnimInstance")
	uint8 bEnableLinkedLayerPersistence : 1;

};

