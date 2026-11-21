// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UIManager/FortUIManager.h"
#include "FortUIManager_Athena.generated.h"

class ULetoHudOverlay;

UCLASS()
class UFortUIManager_Athena : public UFortUIManager
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category="FortUIManager_Athena")
	TSubclassOf<ULetoHudOverlay> LetoHudOverlayClass;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TObjectPtr<ULetoHudOverlay> LetoHudOverlay;

	UPROPERTY(Config)
	float SidekickScreenWidthRatio;

};

