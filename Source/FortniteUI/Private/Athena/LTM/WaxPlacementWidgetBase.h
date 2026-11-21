// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/LTMWidgetBase.h"
#include "WaxPlacementWidgetBase.generated.h"

class AFortAthenaMutator_Wax;
class AFortPlayerStateAthena;

USTRUCT(BlueprintType)
struct FWaxPlacementData
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementData")
	int32 Placement;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementData")
	FString PlayerName;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementData")
	int32 CoinCount;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementData")
	bool bIsPlayer;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UWaxPlacementWidgetBase : public ULTMWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void NativeOnPodiumChangeOccured();

	UFUNCTION()
	void OnAnyTokenChange();

	UFUNCTION(BlueprintImplementableEvent)
	void OnPodiumChangeOccured(const TArray<AFortPlayerStateAthena*>& Leaders);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateWaxPlacements();

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementWidgetBase")
	TObjectPtr<AFortAthenaMutator_Wax> WaxMutator;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementWidgetBase")
	FWaxPlacementData FirstPlacement;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementWidgetBase")
	FWaxPlacementData SecondPlacement;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementWidgetBase")
	FWaxPlacementData ThirdPlacement;

	UPROPERTY(BlueprintReadOnly, Category="WaxPlacementWidgetBase")
	FWaxPlacementData FourthPlacement;

};

