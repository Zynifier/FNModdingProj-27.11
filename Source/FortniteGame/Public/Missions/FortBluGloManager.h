// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Styling/SlateBrush.h"
#include "FortBluGloManager.generated.h"

class UFortItemDefinition;

UCLASS(MinimalAPI, BlueprintType, Blueprintable)
class AFortBluGloManager : public AActor
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="BluGlo")
	UFortItemDefinition* GetBluGloItemDefinition() const;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="FortBluGloManager")
	float BluGloPerMinute;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="FortBluGloManager")
	FSlateBrush BluGloIcon;

};

