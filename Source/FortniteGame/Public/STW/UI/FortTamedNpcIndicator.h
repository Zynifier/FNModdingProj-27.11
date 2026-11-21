// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FortTamedNpcIndicator.generated.h"

class AActor;

UCLASS(Abstract, MinimalAPI)
class UFortTamedNpcIndicator : public UUserWidget
{
	GENERATED_BODY()

public:
	UFortTamedNpcIndicator(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

public:
	UFUNCTION(BlueprintImplementableEvent)
	void DisplayPetIndicator(bool bIsLocalPlayerOwned);

	UFUNCTION(BlueprintImplementableEvent)
	void HidePetIndicator();

	UFUNCTION(BlueprintCallable)
	void SetOwningActor(AActor* NewOwnerActor);

protected:
	UPROPERTY(BlueprintReadOnly, Category="FortTamedNpcIndicator")
	TObjectPtr<AActor> OwningActor;

};

