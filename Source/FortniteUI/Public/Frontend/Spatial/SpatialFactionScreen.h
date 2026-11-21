// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Frontend/Spatial/SpatialScreen.h"
#include "SpatialFactionScreen.generated.h"

class USpatialFactionChoiceScreen;
class USpatialFactionProgressScreen;

UCLASS(Abstract)
class USpatialFactionScreen : public UAthenaSpatialScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnFactionChoiceRequired();

	UFUNCTION(BlueprintCallable)
	void SetAboutScreenVisited();

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionChoiceScreen> Screen_FactionChoice;

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialFactionScreen", meta=(AllowPrivateAccess, BindWidget, EditInline="true"))
	TObjectPtr<USpatialFactionProgressScreen> Screen_FactionProgress;

};

