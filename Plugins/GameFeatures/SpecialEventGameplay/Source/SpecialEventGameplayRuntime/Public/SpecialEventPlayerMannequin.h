// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Customization/FortPlayerMannequin.h"
#include "SpecialEventPlayerMannequin.generated.h"

class AFortGameplayMutator;

UCLASS(MinimalAPI, BlueprintType, HideCategories=("Materials"))
class ASpecialEventPlayerMannequin : public AFortPlayerMannequin
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Special Event Mannequin")
	void DestroyUnusedSkeletalMeshComponents();

	UFUNCTION(BlueprintCallable, BlueprintCosmetic, Category="Special Event Mannequin")
	void RegisterWithSpecialEventMutator();

protected:
	UFUNCTION()
	void HandleOnMutatorAdded(AFortGameplayMutator* NewMutator);

	UPROPERTY(EditAnywhere, Category="Special Event Mannequin")
	uint8 bDisableCollisionOnBeginPlay : 1;

	UPROPERTY(EditAnywhere, Category="Special Event Mannequin")
	uint8 bDisableComponentsTickOnServer : 1;

	UPROPERTY(EditAnywhere, Category="Special Event Mannequin")
	uint8 bRegisterWithSpecialEventMutatorOnClient : 1;

	UPROPERTY(EditAnywhere, AdvancedDisplay, Category="Special Event Mannequin")
	uint8 bDestroyUnusedSkeletalMeshComponentsOnClientFirstInitialization : 1;

};

