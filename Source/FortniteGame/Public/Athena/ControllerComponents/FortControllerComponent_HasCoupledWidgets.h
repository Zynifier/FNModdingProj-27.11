// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/FortControllerComponent.h"
#include "FortUIExtensionSlot.h"
#include "FortControllerComponent_HasCoupledWidgets.generated.h"

class AController;
class UUserWidget;

USTRUCT()
struct FComponentWidgetPairings
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="ComponentWidgetPairings")
	EUIExtensionSlot Slot;

	UPROPERTY(EditAnywhere, Category="ComponentWidgetPairings")
	TSubclassOf<UUserWidget> Class;

};

UCLASS(HideCategories=("Trigger", "PhysicsVolume"))
class FORTNITEGAME_API UFortControllerComponent_HasCoupledWidgets : public UFortControllerComponent
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void HandleExitAircraft(AController* ExitingController);

	UFUNCTION()
	virtual void MakeComponentWidgetsOnAutonomous();

	UPROPERTY(EditAnywhere, Category="FortControllerComponent_HasCoupledWidgets", meta=(TitleProperty="Slot"))
	TArray<FComponentWidgetPairings> SpawnableWidgets;

};

