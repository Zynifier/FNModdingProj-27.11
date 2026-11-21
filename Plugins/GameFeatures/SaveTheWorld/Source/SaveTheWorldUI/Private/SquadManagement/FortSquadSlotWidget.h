// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "FortUITypes.h"
#include "FortSquadSlotWidget.generated.h"

class IFortItemViewContextInterface;
class UFortItem;
class UFortMultiSizeItemCard;
class ULocalPlayer;
enum class EFortItemCardSize : uint8;

UCLASS(BlueprintType)
class UFortSquadSlotWidget : public UWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	UFortItem* GetItemInSquadSlotBP(const ULocalPlayer* LocalPlayer) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool IsSquadSlotLockedBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Widget")
	void SetCardSize(const EFortItemCardSize CardSize);

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Squad Slot Widget", meta=(ExposeOnSpawn))
	EFortItemCardSize ItemCardSize;

private:
	UPROPERTY(Export, meta=(EditInline="true"))
	TObjectPtr<UFortMultiSizeItemCard> SlottedItemCard;

	UPROPERTY()
	TScriptInterface<IFortItemViewContextInterface> ItemViewContext;

};

