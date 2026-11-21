// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemPicker/FortItemPicker.h"
#include "SquadManagement/FortSquadManagement.h"
#include "FortSquadSlotItemPicker.generated.h"

enum class ESquadSlotSortType : uint8;
enum class ESquadSlotType : uint8;

UCLASS(Abstract, BlueprintType, Blueprintable)
class UFortSquadSlotItemPicker : public UFortItemPickerBase
{
	GENERATED_BODY()

public:
UDELEGATE()
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFortSquadSlotSortChanged, ESquadSlotSortType, CurrentSortType, ESquadSlotType, SquadSlotType);

public:
	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void CycleSortType();

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetSortTypes(FSquadSlotSortTypes SquadSlotSortTypes);

	UPROPERTY(BlueprintAssignable, Category="Squad Slot Management")
	FFortSquadSlotSortChanged OnSortChanged;

};

