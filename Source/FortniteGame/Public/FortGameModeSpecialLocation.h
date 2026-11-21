// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "FortGameModeSpecialLocation.generated.h"

class USplineComponent;

UCLASS()
class AFortGameModeSpecialLocation : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintPure, Category="Gameplay")
	USplineComponent* GetSplineComponent() const;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Gameplay")
	FGameplayTagContainer GameplayTags;

};

