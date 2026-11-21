// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavArrow.generated.h"

class UDestinationTrackerPawnComponent;

UCLASS(MinimalAPI, BlueprintType, Blueprintable, meta=(ChildCanTick))
class ANavArrow : public AActor
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Export, Category="NavArrow", meta=(EditInline="true"))
	TObjectPtr<UDestinationTrackerPawnComponent> DestinationTrackerComponent;

protected:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void HideArrow();

	UFUNCTION(BlueprintNativeEvent)
	void OnDestinationChanged();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void ShowArrow();

};

