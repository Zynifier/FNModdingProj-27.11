// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortControllerComponent_CreativeFunctionalTest.generated.h"

class AActor;
class ACreativeFunctionalTest;
class UFortControllerComponent_Interaction;

UCLASS(BlueprintType, Blueprintable, HideCategories=("Trigger", "PhysicsVolume"))
class UFortControllerComponent_CreativeFunctionalTest : public UFortControllerComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool CanInteractWithActor(AActor* ActorToUse, UFortControllerComponent_Interaction* InteractComponent) const;

	UFUNCTION(BlueprintCallable)
	void SetFunctionalTest(ACreativeFunctionalTest* FunctionalTest);

	UFUNCTION(BlueprintCallable)
	bool TryInteractUseForActor(AActor* ActorToUse, UFortControllerComponent_Interaction* InteractComponent);

protected:
	UPROPERTY(BlueprintReadOnly, Replicated, Category="FortControllerComponent_CreativeFunctionalTest")
	TObjectPtr<ACreativeFunctionalTest> FunctionalTest;

};

