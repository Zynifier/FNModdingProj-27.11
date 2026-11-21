// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Building/BuildingProp.h"
#include "Creative/FortTimeWidgetInterface.h"
#include "FortCreativeTimerObjective.generated.h"

class AFortGameState;
class AFortVolume;

USTRUCT(BlueprintType)
struct FTimerObjectiveHUDData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TimerObjectiveHUDData")
	float TimeLeft;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TimerObjectiveHUDData")
	bool bIsPaused;

};

UCLASS(HideCategories=("Game|Damage"), PrioritizeCategories=("Instance"), SparseClassDataType=BuildingPropActorClassData)
class AFortCreativeTimerObjective : public ABuildingProp, public IFortTimeWidgetInterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="UserOptions", meta=(DisplayName="Maintain Interaction While Looking Around"))
	bool MaintainInteractionWhileLookingAround;

protected:
	UFUNCTION()
	void AddTimerObjectiveToVolume();

	UFUNCTION(BlueprintImplementableEvent, Category="IFortTimeWidgetInterface", meta=(DisplayName="Get Display Text Style"))
	FName BP_GetDisplayTextStyle() const;

	UFUNCTION(BlueprintImplementableEvent, Category="IFortTimeWidgetInterface", meta=(DisplayName="Get Label Text"))
	FText BP_GetLabelText() const;

	UFUNCTION(BlueprintImplementableEvent, Category="IFortTimeWidgetInterface", meta=(DisplayName="Is HUD Visible"))
	bool BP_IsHUDVisible() const;

	UFUNCTION(BlueprintCallable)
	void BroadcastUpdateToHUD();

	UFUNCTION()
	void OnGameStateSet(AFortGameState* GameState);

	UFUNCTION(BlueprintCallable)
	void SetHUDData(FTimerObjectiveHUDData NewHUDData);

private:
	UPROPERTY(Transient)
	FTimerObjectiveHUDData HUDData;

	UPROPERTY(Transient)
	TObjectPtr<AFortVolume> Volume;

};

