// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/FortGameStateAthena.h"
#include "Athena/Modifiers/FortAthenaMutator_Barrier.h"
#include "FortHUDElementWidget.h"
#include "BarrierWidgetBase.generated.h"

class AAthenaBarrierObjective;
class AFortPlayerStateZone;
enum class EBarrierFoodTeam : uint8;

USTRUCT()
struct FBarrierObjectState
{
	GENERATED_BODY()

public:
	UPROPERTY()
	TObjectPtr<AAthenaBarrierObjective> ObjectiveActor;

	UPROPERTY()
	uint8 TeamNum;

	UPROPERTY()
	EBarrierFoodTeam FoodTeam;

	UPROPERTY()
	EBarrierObjectiveDamageState DamageState;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UBarrierWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION()
	void OnMutatorObjectUpdated(const FGameplayMutatorObjectDataArray& MutatorArray);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateHealth(bool bFriendlyTeam, float HealthPercent, EBarrierFoodTeam FoodTeam, bool bFlashBar);

	UPROPERTY()
	FBarrierObjectState FriendlyTeamState;

	UPROPERTY()
	FBarrierObjectState EnemyTeamState;

};

