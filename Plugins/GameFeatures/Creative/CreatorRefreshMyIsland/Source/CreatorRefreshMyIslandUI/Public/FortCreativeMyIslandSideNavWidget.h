// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CommonActivatableWidget.h"
#include "Engine/DataTable.h"
#include "FortCreativeMyIslandSideNavWidget.generated.h"

UCLASS(Abstract, BlueprintType, Blueprintable, meta=(DisableNativeTick))
class UFortCreativeMyIslandSideNavWidget : public UCommonActivatableWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void OnClearSearchInput();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSearchInput();

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetClearSearchInputEnabled(const bool bEnabled);

	UFUNCTION(BlueprintCallable, meta=(BlueprintProtected))
	void SetSearchInputEnabled(const bool bEnabled);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeMyIslandSideNavWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle SearchInputActionRow;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="FortCreativeMyIslandSideNavWidget", meta=(AllowPrivateAccess, RowType="/Script/CommonUILegacy.CommonInputActionData"))
	FDataTableRowHandle ClearSearchInputActionRow;

};

