// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "InfiltrationBaseWidget.generated.h"

class AFortAthenaMutator_Infiltration;
enum class EIntelStateEnum : uint8;

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UInfiltrationBaseWidget : public ULTMWidgetBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	uint8 GetAttackingTeam() const;

	UFUNCTION(BlueprintPure)
	EIntelStateEnum GetCurrentIntelState() const;

	UFUNCTION(BlueprintPure)
	int32 GetCurrentRound() const;

	UFUNCTION(BlueprintPure)
	uint8 GetDefendingTeam() const;

	UFUNCTION(BlueprintPure)
	float GetGroundTimeRemaining() const;

	UFUNCTION(BlueprintPure)
	bool GetIsCurrentlyDefended() const;

	UFUNCTION(BlueprintPure)
	int32 GetNumOfRounds() const;

	UFUNCTION(BlueprintPure)
	bool IsBeingHeldByLocalPlayer() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerAttacking() const;

	UFUNCTION(BlueprintPure)
	bool IsLocalPlayerDefending() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnGroundTimerChanged(float NewTimeRemaining);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIntelStateChanged(EIntelStateEnum NewState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnIsCurrentlyDefendedChanged(bool bNewBeingDefended);

	UFUNCTION(BlueprintImplementableEvent)
	void OnMutatorReady();

protected:
	UPROPERTY()
	TWeakObjectPtr<AFortAthenaMutator_Infiltration> CachedMutator;

};

