// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Layout/Margin.h"
#include "Athena/LTM/MinigameWidgetBase.h"
#include "FortCoreGamerObjectiveWidget.generated.h"

class UFortCoreGamerObjectiveRadial;
class UHorizontalBox;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortCoreGamerObjectiveWidget : public UMinigameWidgetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, Category="FortCoreGamerObjectiveWidget")
	TSubclassOf<UFortCoreGamerObjectiveRadial> ObjectiveRadialClass;

	UPROPERTY(EditAnywhere, Category="FortCoreGamerObjectiveWidget")
	TSubclassOf<UFortCoreGamerObjectiveRadial> DestructibleTrackerClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCoreGamerObjectiveWidget")
	FMargin ObjectivePadding;

protected:
	UFUNCTION(BlueprintPure)
	uint8 GetOwnerPlayerTeam() const;

	UFUNCTION()
	void HandleTrackedObjectiveAdded(int32 TrackedIndex);

	UFUNCTION()
	void HandleTrackedObjectiveRemoved(int32 TrackedIndex);

	UPROPERTY(BlueprintReadOnly, Export, Category="FortCoreGamerObjectiveWidget", meta=(BindWidget, EditInline="true"))
	TObjectPtr<UHorizontalBox> ObjectiveContainer;

	UPROPERTY(Transient, Export, meta=(EditInline="true"))
	TMap<int32, TObjectPtr<UFortCoreGamerObjectiveRadial>> TrackedObjectiveWidgetMap;

};

