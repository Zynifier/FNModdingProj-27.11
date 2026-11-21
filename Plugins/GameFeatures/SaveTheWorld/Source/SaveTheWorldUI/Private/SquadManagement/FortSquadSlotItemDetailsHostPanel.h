// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Item/FortItemDetailsHostPanel.h"
#include "FortSquadSlotItemDetailsHostPanel.generated.h"

class UFortItem;
class ULocalPlayer;

UCLASS()
class UFortSquadSlotItemDetailElementWidget : public UFortItemDetailElementWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	UFortItem* GetItemInSquadSlotBP(const ULocalPlayer* LocalPlayer) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool IsSquadSlotLockedBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

protected:
	UFUNCTION(BlueprintImplementableEvent, Category="Squad Slot Management")
	void HandlePostDifferentSquadSlotSetBP();

};

UCLASS()
class UFortSquadSlotItemDetailsHostPanel : public UFortItemDetailsHostPanel
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	void GetIdOfSquadSlotToManageBP(FName& OutSquadId, int32& OutSquadSlotIndex) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	UFortItem* GetItemInSquadSlotBP(const ULocalPlayer* LocalPlayer) const;

	UFUNCTION(BlueprintPure, Category="Squad Slot Management")
	bool IsSquadSlotLockedBP() const;

	UFUNCTION(BlueprintCallable, Category="Squad Slot Management")
	void SetIdOfSquadSlotToManageBP(const FName& SquadId, const int32 SquadSlotIndex);

};

