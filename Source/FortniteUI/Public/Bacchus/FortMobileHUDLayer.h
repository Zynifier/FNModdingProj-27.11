// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/PanelWidget.h"
#include "FortMobileHUDLayer.generated.h"

class UFortMobileHUDElement;

UCLASS()
class UFortMobileHUDLayer : public UPanelWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMobileHUDElement>> ActiveHUDWidgets;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TArray<TObjectPtr<UFortMobileHUDElement>> InactiveHUDWidgets;

};

