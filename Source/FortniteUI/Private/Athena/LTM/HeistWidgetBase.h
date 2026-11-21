// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Athena/FortGameStateAthena.h"
#include "FortHUDElementWidget.h"
#include "FortSpecialActorReplicationInfo.h"
#include "HeistWidgetBase.generated.h"

class AFortPlayerStateZone;
enum class EHeistExitCraftUIState : uint8;

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EHeistBlingIconState : uint8
{
	None = 0,
	SupplyDrop = 1,
	PickupItem = 2,
	CarriedEnemy = 3,
	CarriedAlly = 4,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EHeistExitCraftIconState : uint8
{
	None = 0,
	Incoming = 1,
	Spawned = 2,
	Exited = 3,
};

UENUM(BlueprintType, meta=(IsBlueprintBase="true"))
enum class EHeistExitCraftUIState : uint8
{
	None = 0,
	OnTheWay = 1,
	Incoming = 2,
	Arrived = 3,
};

USTRUCT(BlueprintType)
struct FHeistBlingIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistBlingIconData")
	int32 IconIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistBlingIconData")
	EHeistBlingIconState IconState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistBlingIconData")
	EHeistBlingIconState PrevIconState;

};

USTRUCT(BlueprintType)
struct FHeistExitCraftIconData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftIconData")
	int32 IconIndex;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftIconData")
	EHeistExitCraftIconState IconState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftIconData")
	EHeistExitCraftIconState PrevIconState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftIconData")
	int32 SecondsUntilIncoming;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistExitCraftIconData")
	bool bTeamHasBling;

};

UCLASS(BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UHeistWidgetBase : public UFortHUDElementWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayBlingUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDisplayExitCraftUI(bool bDisplay);

	UFUNCTION(BlueprintImplementableEvent)
	void OnExitCraftsUIChanged(EHeistExitCraftUIState NewState);

	UFUNCTION()
	void OnHandleSpectatingChanged(AFortPlayerStateZone* SpectatingTarget);

	UFUNCTION()
	void OnMutatorObjectUpdated(const FGameplayMutatorObjectDataArray& MutatorArray);

	UFUNCTION()
	void OnSpecialActorAdded(const FSpecialActorRepData& SpecialActorData);

	UFUNCTION()
	void OnSpecialActorRemoved(const FSpecialActorRepData& SpecialActorData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateBlingIcon(const FHeistBlingIconData& BlingIconData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateExitCraftIcon(const FHeistExitCraftIconData& ExitCraftIconData);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateStateText(const FText& StateText, EHeistExitCraftUIState CurrState);

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdateStateTimeText(const FText& TimeText, EHeistExitCraftUIState CurrState);

	UFUNCTION()
	void SetExitCraftUIState(EHeistExitCraftUIState NewState);

	UFUNCTION()
	void UpdateAllUI();

	UPROPERTY(Transient)
	EHeistExitCraftUIState CurrExitCraftUIState;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category="HeistWidgetBase")
	bool bDisplayBlingRow;

	UPROPERTY(Transient)
	bool bCanDisplayVanUI;

	UPROPERTY(Transient)
	FGameplayTag SafeSupplyDropTag;

	UPROPERTY(Transient)
	FGameplayTag BlingItemTag;

	UPROPERTY(Transient)
	FGameplayTag CarryingBlingItemTag;

	UPROPERTY()
	int32 CurrBlingSupplyDropCount;

	UPROPERTY()
	int32 CurrBlingItemCount;

	UPROPERTY()
	int32 CurrBlingEnemyCount;

	UPROPERTY()
	int32 CurrBlingAllyCount;

};

