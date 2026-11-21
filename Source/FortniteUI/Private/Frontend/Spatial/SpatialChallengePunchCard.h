// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Frontend/Spatial/SpatialScreen.h"
#include "SpatialChallengePunchCard.generated.h"

class UAthenaChallengePunchCard;
class UDynamicEntryBox;
class UScrollBox;

UCLASS(Abstract)
class USpatialChallengePunchCard : public UAthenaSpatialScreen
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnShowFirstTimeInfo();

	UFUNCTION(BlueprintImplementableEvent)
	void SetDiscoveredCount(int32 KnownCount, int32 CompletedCount, int32 TotalCount);

	UPROPERTY(BlueprintReadOnly, Export, Category="SpatialChallengePunchCard")
	TWeakObjectPtr<UAthenaChallengePunchCard> FocusedPunchCard;

	UPROPERTY(EditDefaultsOnly, Category="SpatialChallengePunchCard")
	FDataTableRowHandle NextPunchCardInputAction;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UDynamicEntryBox> EntryBox_PunchCards;

	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<UScrollBox> Scroll_Box;

	UPROPERTY(Transient, Export)
	TArray<TWeakObjectPtr<UAthenaChallengePunchCard>> PunchCards;

	UPROPERTY(Transient)
	float LastStickInputTime;

	UPROPERTY(EditDefaultsOnly, Category="SpatialChallengePunchCard")
	float InputDelayTime;

};

