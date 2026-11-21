// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "Athena/AthenaPlayerHitPointBarBase.h"
#include "AthenaSpectatorHitPointBarBase.generated.h"

class UAthenaRemotePlayerViewData;

UCLASS(Abstract, meta=(DisableNativeTick))
class UAthenaSpectatorHitPointBarBase : public UCommonUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerData(UAthenaRemotePlayerViewData* InPlayerData);

protected:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void ChangeTextVisibility(bool bIsVisible);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnCurrentValueChanged(float InCurrentValue);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDBNOChanged(bool bInIsDBNO);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnDeltaValueChanged(float InDeltaValue);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSpectatorHitPointBarBase")
	EHealthBarType BarType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSpectatorHitPointBarBase")
	float LastToCurrentUpdateRate;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="AthenaSpectatorHitPointBarBase")
	bool bIsDBNO;

	UPROPERTY(BlueprintReadOnly, Transient, Category="AthenaSpectatorHitPointBarBase")
	TWeakObjectPtr<UAthenaRemotePlayerViewData> PlayerData;

private:
	UFUNCTION()
	void OnDBNOStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsDBNO);

	UFUNCTION()
	void OnEliminatedStateChanged(UAthenaRemotePlayerViewData* InPlayerData, bool bInIsEliminated);

	UFUNCTION()
	void OnValueDamaged(UAthenaRemotePlayerViewData* InPlayerData, float InValue, float InValueMax);

	UFUNCTION()
	void OnValueHealed(UAthenaRemotePlayerViewData* InPlayerData, float InValue, float InValueMax);

};

