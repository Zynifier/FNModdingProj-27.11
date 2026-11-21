// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FortHUDElementWidget.h"
#include "FortHUDBuildingPossessionWidget.generated.h"

class ABuildingActor;
class UImage;

UCLASS(Abstract)
class UFortHUDBuildingPossessionWidget : public UFortHUDElementWidget
{
	GENERATED_BODY()

private:
	UFUNCTION()
	void UpdateOnBuildingFocused(ABuildingActor* FocusedBuilding);

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UImage> DotImage;

};

