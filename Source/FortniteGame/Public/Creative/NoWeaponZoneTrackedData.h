// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Creative/DeviceTrackedData.h"
#include "NoWeaponZoneTrackedData.generated.h"

class AFortMinigame;

UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnResetActorsDestroyedCount);

UCLASS(BlueprintType)
class UNoWeaponZoneTrackedData : public UDeviceTrackedData
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void AddTrackedDestroy();

	UFUNCTION(BlueprintPure)
	int32 GetDestroyCount() const;

	UFUNCTION(BlueprintPure)
	int32 GetMaxDestroyCount() const;

	UFUNCTION(BlueprintPure)
	int32 GetMaxDestroyCountPerTrackedDevice() const;

	UFUNCTION(BlueprintPure)
	bool IsTrackedDestroyAtLimit() const;

	UFUNCTION(BlueprintCallable)
	void SetupMinigame(AFortMinigame* InMinigame);

	UFUNCTION(BlueprintCallable)
	void TrackNewDevice();

	UFUNCTION(BlueprintCallable)
	void UntrackDevice();

	UPROPERTY(BlueprintAssignable)
	FOnResetActorsDestroyedCount OnResetActorsDestroyedCount;

protected:
	UFUNCTION()
	virtual void OnMinigameEnded();

	UFUNCTION()
	virtual void OnMinigameStarted();

	UFUNCTION()
	void StartResetDestroyCountTimer();

private:
	UPROPERTY(Transient)
	TObjectPtr<AFortMinigame> Minigame;

};

