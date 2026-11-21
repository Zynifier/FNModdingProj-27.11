// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Athena/LTM/GGWidgetBase.h"
#include "FortTypes.h"
#include "GGCenterDisplayWidgetBase.generated.h"

class AFortPlayerStateAthena;
class UFortWeaponItemDefinition;

USTRUCT(BlueprintType)
struct FGGCenterDisplayEntry : public FFortChangeMonitoringStruct
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="GGCenterDisplayEntry")
	TObjectPtr<UFortWeaponItemDefinition> WeaponAt;

	UPROPERTY(BlueprintReadOnly, Category="GGCenterDisplayEntry")
	int32 PlayersAtWeapon;

	UPROPERTY(BlueprintReadOnly, Category="GGCenterDisplayEntry")
	bool bIsEnabled;

	UPROPERTY(BlueprintReadOnly, Category="GGCenterDisplayEntry")
	bool bShowHarvestingTool;

};

UCLASS()
class UGGCenterDisplayWidgetBase : public UGGWidgetBase
{
	GENERATED_BODY()

protected:
	UFUNCTION()
	void OnLocalPlayerAwardedWeapon(UFortWeaponItemDefinition* NextWeapon);

	UFUNCTION()
	void OnOtherPlayerAwardedWeapon(AFortPlayerStateAthena* OtherPlayer, UFortWeaponItemDefinition* NextWeapon);

	UFUNCTION(BlueprintImplementableEvent)
	void UpdateDisplayWith(const TArray<FGGCenterDisplayEntry>& Entries, bool bUpdatingForLocalPlayer);

	UPROPERTY(EditAnywhere, Category="Display", meta=(ClampMin="0"))
	int32 NumberOfSlotsFlankingLocalPlayer;

	UPROPERTY()
	TArray<FGGCenterDisplayEntry> CenterDisplayEntries;

};

