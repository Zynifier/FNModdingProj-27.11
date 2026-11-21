// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Math/MathFwd.h"
#include "FortHoldableButton.h"
#include "SeasonPass/BattlePassTypes.h"
#include "FortBattlePassTileBase.generated.h"

class USizeBox;
enum class BattlePassTileAvailabilityStates : uint8;
enum class EPageItemTileSize : uint8;

UENUM(BlueprintType)
enum class BattlePassTileAvailabilityStates : uint8
{
	Invalid = 0 UMETA(Hidden),
	Available = 1,
	Owned = 2,
	Locked = 3,
};

UCLASS(Abstract, MinimalAPI)
class UFortBattlePassTileBase : public UFortHoldableButton
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	bool AreAnyGrantedItemsEquipped() const;

	UFUNCTION(BlueprintPure)
	bool IsAvailable() const;

	UFUNCTION(BlueprintPure)
	bool IsLocked() const;

	UFUNCTION(BlueprintPure)
	bool IsOwned() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnPeeked();

	UFUNCTION(BlueprintImplementableEvent)
	void OnRevealed();

protected:
	UFUNCTION(BlueprintPure)
	const BattlePassTileAvailabilityStates GetState() const;

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetRequiresBattlePass(const bool bRequiresBP);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetTileColors();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSizeChanged(const FVector2D& NewSize);

	UFUNCTION(BlueprintImplementableEvent)
	void OnStateChanged(const BattlePassTileAvailabilityStates NewState);

	UFUNCTION(BlueprintCallable)
	void SetSize(const EPageItemTileSize TileSize, const FVector2D& CellSpacing);

	UFUNCTION(BlueprintCallable)
	void SetState(const BattlePassTileAvailabilityStates NewState);

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassTileBase")
	ERewardPageType RewardPageType;

private:
	UPROPERTY(Export, meta=(BindWidget, EditInline="true"))
	TObjectPtr<USizeBox> SizeBox_Content;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassTileBase", meta=(AllowPrivateAccess))
	TMap<FName, FLinearColor> TileColors;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassTileBase", meta=(AllowPrivateAccess))
	FLinearColor OverlayDimColor;

	UPROPERTY(BlueprintReadOnly, Category="FortBattlePassTileBase", meta=(AllowPrivateAccess))
	FVector2D TileDesiredCellSpan;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassTileBase")
	float UnitHeight;

	UPROPERTY(EditDefaultsOnly, Category="FortBattlePassTileBase")
	float UnitWidth;

};

